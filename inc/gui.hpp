#pragma once

namespace Lapine {
  struct Gui {
    float xfreq  = 1.00f;
    float yfreq  = 1.00f;
    float amp    = 1.00f;
    float phase  = 0.00f;

    auto run() -> void;
  };
}
