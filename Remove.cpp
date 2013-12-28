#include "Remove.h"
#include "Drop.h"
#include "Wait.h"
#include "Image.h"
#include "Utils.h"
#include "FallOjama.h"

namespace Py {
	namespace Ev {
		namespace Gm {
			const std::array<Point, 4> Remove::d = { Point(0, 1), Point(1, 0), Point(0,-1), Point(-1, 0) };
			void Remove::draw() const {
				const auto& field = param->field;
				rect->setPos(0, 0).setSize(32 * field.width(), 32 * field.height()).draw(Palette::Black);
				for (int y = field.TH; y < field.height(); y++) {
					for (int x = 0; x < field.width(); x++) {
						int rx = x;
						int ry = y - field.TH;
						if (field.get(x, y).color == Puyo::E) continue;
						if (remove[y][x]) {
							const auto width = [](double r) {
								return (32 + 16 * (1 - r));
							};
							const auto height = [](double r) {
								return (32 * r);
							};
							int sw = static_cast<int>(width(r.rate()));
							int sh = static_cast<int>(height(r.rate()));
							int cx = rx * 32 + 16;
							int cy = ry * 32 + 16;
							(rect->setSize(sw, sh).setCenter(cx, cy))(Image::getImage(field.get(x, y).color)).draw();
							Graphics::Set2DBlendState(BlendState::Additive());
							for (int i = 0; i < 4; i++) {
								(rect->setSize(sw, sh).setCenter(cx, cy))(Image::getImage(field.get(x, y).color)).draw(Alpha(std::min<unsigned>(255, static_cast<unsigned>(255 * (r.rate() + 0.5)))));
							}
							font->draw(Format(param->chain, L"chain!"), 50, 50,Alpha(static_cast<unsigned>(255*r.rate())));
							Graphics::Set2DBlendState(BlendState::Default());
						}
						else {
							Image::getImage(field.get(x, y).color).draw(rx * 32, ry * 32);
						}
					}
				}
			}
			std::vector<Point> Remove::vis(const Point& p) {
				std::vector<Point> ps;
				ps.push_back(p);
				used[p.y][p.x] = true;
				for (const Point& v : d) {
					const auto np = p + v;
					if (np.y >= 0 && !used[np.y][np.x] && param->field(np).color == param->field(p).color) {
						used[np.y][np.x] = true;
						for (const Point& vp : vis(np)) {
							ps.push_back(vp);
						}
					}
				}
				//font->draw(Format(param->chainScore));
				return ps;
			}
			Ptr Remove::update() {
				Field& f = param->field;
				if (r.done()) {
					int removeCount = 0;
					int connectPoint = 0;
					int colorNum = 0;
					static const std::array<int, 19> chainBonus = { 0, 8, 16, 32, 64, 96, 128, 160, 192, 224, 256, 288, 320, 352, 384, 416, 448, 480, 512 };
					static const std::array<int, 8> connectBonus = { 0,2,3,4,5,6,7,10 };
					static const std::array<int, 5> colorBonus = { 0,3,6,12,24 };
					for (int i = 0; i < f.height() - 1; i++) {
						for (int j = 1; j < f.width()-1; j++) {
							if (!used[i][j] && f(j,i).color > 0) {
								std::vector<Point> ps = vis(Point(j, i));
								if (ps.size() >= 4) {
									removeCount += ps.size();
									connectPoint += connectBonus[std::min<int>(11, ps.size()) - 4];
									colorNum |= 1 << (f(j, i).color - 1);
									for (const Point& v : ps) {
										for (const Point& w : d) {
											const Point& b = v + w;
											if (param->field(b).color == Puyo::J) {
												remove[b.y][b.x] = true;
											}
										}
										remove[v.y][v.x] = true;
									}
									r.start();
								}
							}
						}
					}
					if (r.done()) {
						param->chainScore += param->chainScoreExt;
						param->chainScoreExt = param->chainScore % 70;
						int ojama = param->chainScore / 70;
						int min = std::min(param->nowOjama, ojama);
						param->nowOjama -= min;
						ojama -= min;
						for (Param* const p : param->enemy) {
							p->nowOjama += ojama;
						}
						if (param->chain == 0 && param->nowOjama > 0) {
							return std::make_shared<FallOjama>(param);
						}
						else {
							return std::make_shared<Wait>(param);
						}
					}
					param->chainScore += removeCount * 10 * std::max(1, connectPoint + colorBonus[Utils::bitCount(colorNum) - 1] + chainBonus[param->chain]);
					++(param->chain);
				}
				if (!r.update()) {
					for (int i = 0; i < f.height() - 1; i++) {
						for (int j = 1; j < f.width() - 1; j++) {
							if (remove[i][j]) {
								f(j, i) = Puyo::E;
							}
						}
					}
					return std::make_shared<Drop>(param);
				}
				return getPtr();
			}
		}
	}
}