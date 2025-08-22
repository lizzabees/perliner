#include <cstdint>
#include <cstdlib>

#include <raylib-cpp.hpp>

#include "clamp.hpp"
#include "perlin.hpp"

const int WIN_W = 640;
const int WIN_H = 480;

static auto render_noise(raylib::Image& img, double scale = 1.0) -> void;

int main(int argc, char* argv[]) {
  auto win = raylib::Window{WIN_W, WIN_H, "hello"};
  win.SetTargetFPS(30);

  raylib::Image img{WIN_W, WIN_H};
  render_noise(img, 16.0);
  raylib::Texture2D tex{img};

  while (!win.ShouldClose()) {
    win.BeginDrawing();
    win.ClearBackground(raylib::Color::DarkGray());
    tex.Draw();
    win.EndDrawing();
  }

  return EXIT_SUCCESS;
}

static auto render_noise(raylib::Image& img, double scale) -> void {
  Lapine::Noise::Perlin perlin{};
  Lapine::Noise::Clamp  clamped{perlin};

  int  w  = img.GetWidth();
  int  h  = img.GetHeight();
  auto wf = static_cast<double>(w);
  auto hf = static_cast<double>(h);

  for (auto y = 0; y < h; y++) {
    for (auto x = 0; x < w; x++) {
      auto xf = static_cast<double>(x) / wf;
      auto yf = static_cast<double>(y) / hf;
      auto vf = (1.0 + clamped.noise(xf * scale, yf * scale)) / 2.0;
      auto v  = static_cast<uint8_t>(vf * 255.0);
      img.DrawPixel(x, y, raylib::Color{v, v, v});
    }
  }
}
