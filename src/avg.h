#ifndef __AVG_CALCULATOR_H_
#define __AVG_CALCULATOR_H_

#include <queue>
#include <limits>

#include "base_calculator.h"

class Avg : public BaseCalculator {
public:
  explicit Avg(int window);
  ~Avg() = default;
  virtual void AddValue(double value) override;
  virtual double GetValue() override;
private:
  double cur_sum_;
  double avg_;
  std::queue<double> queue_;
};

#endif
