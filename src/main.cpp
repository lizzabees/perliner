#include <cmath>
#include <cstdint>
#include <cstdlib>

#include <chrono>
#include <iostream>
#include <numbers>

#include <raylib-cpp.hpp>

#include "clamp.hpp"
#include "gui.hpp"
#include "perlin.hpp"

const int WIN_W = 640;
const int WIN_H = 480;

static auto render_noise(raylib::Image& img, const Lapine::Gui& gui) -> void;
static auto last_tick = 
  std::chrono::time_point_cast
  <std::chrono::milliseconds>
  (std::chrono::steady_clock::now());

static auto sinusoid(
  double time       ,
  double freq       ,
  double amp   = 1.0,
  double phase = 0.0) -> double;

auto main(int argc, char* argv[]) -> int {
  auto win = raylib::Window{WIN_W, WIN_H, "hello"};
  win.SetTargetFPS(30);

  Lapine::Gui gui;
  raylib::Image img{WIN_W, WIN_H};
  render_noise(img, gui);
  raylib::Texture2D tex{img};

  while (!win.ShouldClose()) {
    render_noise(img,gui);
    tex.Update(img.GetData());
    win.BeginDrawing();
    win.ClearBackground(raylib::Color::DarkGray());
    tex.Draw();
    gui.run();
    win.EndDrawing();
  }

  return EXIT_SUCCESS;
}

static auto render_noise(raylib::Image& img, const Lapine::Gui& gui) -> void {
  Lapine::Noise::Perlin perlin{};
  Lapine::Noise::Clamp  clamped{perlin};

  const int  w  = img.GetWidth();
  const int  h  = img.GetHeight();
  const auto wf = static_cast<double>(w);
  const auto hf = static_cast<double>(h);

  const auto xfreq = static_cast<double>(gui.xfreq);
  const auto yfreq = static_cast<double>(gui.yfreq);
  const auto amp   = static_cast<double>(gui.amp);
  const auto phase = static_cast<double>(gui.phase);

  const auto now =
    std::chrono::time_point_cast
    <std::chrono::milliseconds>
    (std::chrono::steady_clock::now());
  const auto dt = (now - last_tick).count();
  if (dt > 6'000.0) last_tick = now;

  for (auto y = 0; y < h; y++) {
    for (auto x = 0; x < w; x++) {
      const auto xf   = static_cast<double>(x) / hf;
      const auto yf   = static_cast<double>(y) / hf;

      const auto xmod = sinusoid(dt / 1'000.0, xfreq, amp, phase);
      const auto ymod = sinusoid(dt / 1'000.0, yfreq, amp, phase);
      const auto vf   = (1.0 + clamped.noise(xf, yf * ymod)) / 2.0;
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
  return amp * sin((tau/4.0) * freq * time + phase);
}
