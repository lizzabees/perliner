#include <format>

#include <raylib.h>
#include "raygui.h"

#include "gui.hpp"
#include "style_lavanda.h"

namespace Lapine {
  auto Gui::run() -> void {
    const auto anchor    = Rectangle { 400, 48 };
    const auto xfreqText = std::format("x frequency: {0}hz", xfreq);
    const auto yfreqText = std::format("y frequency: {0}hz", yfreq);
    const auto ampText   = std::format("amplitude: {0}", amp);
    const auto phaseText = std::format("phase: {0}", phase);

  
    GuiLoadStyleLavanda();

    GuiGroupBox(
      Rectangle { anchor.x, anchor.y + 8, 232, 224 },
      "modulation"
    );

    // x-frequency
    GuiLabel(
      Rectangle { anchor.x + 24, anchor.y + 24, 192, 24 },
      xfreqText.c_str()
    );

    GuiSlider(
      Rectangle { anchor.x + 24, anchor.y + 48, 192, 24 }, 
      nullptr, nullptr, &xfreq, 0.0f, 10.0f
    );

    // y frequency
    GuiLabel(
      Rectangle { anchor.x + 24, anchor.y + 72, 192, 24 },
      yfreqText.c_str()
    );

    GuiSlider(
      Rectangle { anchor.x + 24, anchor.y + 96, 192, 24 },
      nullptr, nullptr, &yfreq, 0.0f, 10.0f
    );

    // amplitude
    GuiLabel(
      Rectangle { anchor.x + 24, anchor.y + 120, 192, 24 },
      ampText.c_str()
    );

    GuiSlider(
      Rectangle { anchor.x + 24, anchor.y + 144, 192, 24 },
      nullptr, nullptr, &amp, 0.0f, 10.0f
    );

    // phase
    GuiLabel(
      Rectangle { anchor.x + 24, anchor.y + 168, 192, 24 },
      phaseText.c_str()
    );

    GuiSlider(
      Rectangle { anchor.x + 24, anchor.y + 192, 192, 24 },
      nullptr, nullptr, &phase, 0.0f, 1.0f
    );
  }
}

