#include "MathFunctions.h"

#include <cmath>

// Wrap the mysqrt include in a precompiled ifdef based on USE_MYMATH
#ifdef USE_MYMATH
#include "mysqrt.h"
#endif

namespace mathfunctions {
double sqrt(double x)
{
  // If USE_MYMATH is defined, use detail::mysqrt, otherwise, use std::sqrt.
#ifdef USE_MYMATH
  return detail::mysqrt(x);
#else
  return std::sqrt(x);
#endif
}
}
