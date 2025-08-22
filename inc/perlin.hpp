#pragma once

#include <cstdint>

#include <array>

#include "noise2d.hpp"

namespace Lapine::Noise {
  class Perlin : public Noise2D {
  public:
    using Permutations = std::array<uint8_t, 512>;
    const static Permutations DEFAULT_PERMUTATIONS;

  private:
    using Gradient = std::array<double, 3>;
    const static std::array<const Gradient, 16> GRADIENTS;

    const Permutations& _perms;
    
    inline auto fastFloor(double x) -> int {
      return (x > 0.0) ? static_cast<int>(x) : static_cast<int>(x) - 1;
    }

    inline auto fade(double t) -> double {
      return t * t * t * (t * (t * 6.0 - 15.0) + 10.0);
    }
    
    inline auto lerp(double t, double a, double b) -> double {
      return a + t * (b - a);
    }

    inline auto dot(int hash, double x, double y) -> double {
      hash &= 15;
      return GRADIENTS[hash][0]*x + GRADIENTS[hash][1]*y;
    }

  public:
    Perlin() : _perms{DEFAULT_PERMUTATIONS} {}
    Perlin(const Permutations& perms) : _perms{perms} {}
    
    virtual ~Perlin() = default;

    auto noise(double x, double y) -> double override;
  };
};
