#include "noise2d.hpp"

namespace Lapine::Noise {
  class Clamp : public Noise2D {
  public:
    Clamp() = delete;
    Clamp(
      Noise2D& src,
      double min = -1.0,
      double max =  1.0
    ) : _min{min}, _max{max}, _src{src} {}

    virtual ~Clamp() = default;
    virtual auto noise(double x, double y) -> double override;

  private:
    const double _min;
    const double _max;
    Noise2D& _src;
  };
}
