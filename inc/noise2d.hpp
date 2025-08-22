#pragma once

namespace Lapine::Noise {
  class Noise2D {
  public: 
    virtual ~Noise2D() = default;
    virtual auto noise(double x, double y) -> double = 0;
  };
}
