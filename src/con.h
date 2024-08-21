#ifndef __CON_CALCULATOR_H_
#define __CON_CALCULATOR_H_

#include <cmath>
#include <iostream>

#include "base_calculator.h"
#include "avg.h"
#include "std.h"

class Con {
public:
  explicit Con(int window);
  ~Con() = default;
  void AddValue(double x, double y);
  double GetValue();
private:
  Avg avg_x_;
  Avg avg_y_;
  Avg avg_xy_;
  Std std_x_;
  Std std_y_;
  static constexpr double epsilon = 1e-6;
};

#endif
