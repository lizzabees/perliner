#include <cmath>
#include <cstdint>
#include <cstdlib>

#include <chrono>
#include <iostream>
#include <numbers>

#include <raylib-cpp.hpp>

#include "clamp.hpp"
#include "perlin.hpp"

const int WIN_W = 640;
const int WIN_H = 480;

static auto render_noise(raylib::Image& img) -> void;
static const auto first_tick = std::chrono::steady_clock::now();

static auto sinusoid(
  double time       ,
  double freq       ,
  double amp   = 1.0,
  double phase = 0.0) -> double;

auto main(int argc, char* argv[]) -> int {
  auto win = raylib::Window{WIN_W, WIN_H, "hello"};
  win.SetTargetFPS(30);

  raylib::Image img{WIN_W, WIN_H};
  render_noise(img);
  raylib::Texture2D tex{img};

  while (!win.ShouldClose()) {
    render_noise(img);
    tex.Update(img.GetData());
    win.BeginDrawing();
    win.ClearBackground(raylib::Color::DarkGray());
    tex.Draw();
    win.EndDrawing();
  }

  return EXIT_SUCCESS;
}

static auto render_noise(raylib::Image& img) -> void {
  Lapine::Noise::Perlin perlin{};
  Lapine::Noise::Clamp  clamped{perlin};

  const int  w  = img.GetWidth();
  const int  h  = img.GetHeight();
  const auto wf = static_cast<double>(w);
  const auto hf = static_cast<double>(h);

  for (auto y = 0; y < h; y++) {
    for (auto x = 0; x < w; x++) {
      const auto dt   = static_cast<double>(x);
      const auto xf   = dt / wf;
      const auto yf   = static_cast<double>(y) / hf;

      const auto mod  = sinusoid(dt, 4.0, 2.0);
      const auto vf   = (1.0 + clamped.noise(xf, yf * mod)) / 2.0;
      const auto v    = static_cast<uint8_t>(vf * 255.0);
      img.DrawPixel(x, y, raylib::Color{v, v, v});
    }
  }
}

static auto sinusoid(
    const double time ,
    const double freq ,
    const double amp  ,
    const double phase) -> double {
  static const double tau = 2.0*std::numbers::pi;
  return amp * sin(tau * freq * time + phase);
}
