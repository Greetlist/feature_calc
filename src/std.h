#ifndef __STD_CALCULATOR_H_
#define __STD_CALCULATOR_H_

#include <cmath>
#include <iostream>

#include "base_calculator.h"
#include "avg.h"

class Std : public BaseCalculator {
public:
  explicit Std(int window);
  ~Std() = default;
  virtual void AddValue(double value) override;
  virtual double GetValue() override;
private:
  Avg square_;
  Avg normal_;
};

#endif
