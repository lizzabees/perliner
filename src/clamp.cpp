#include "clamp.hpp"

namespace Lapine::Noise {
  auto Clamp::noise(double x, double y) -> double {
    auto val = _src.noise(x, y);
    return (val < _min) ? _min : (val > _max) ? _max : val;
  }
}
