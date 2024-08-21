#ifndef __MEDIAN_CALCULATOR_H_
#define __MEDIAN_CALCULATOR_H_

#include <limits>
#include <map>
#include <queue>
#include <iostream>

#include "base_calculator.h"

class Median : public BaseCalculator {
public:
  explicit Median(int window);
  ~Median() = default;
  virtual void AddValue(double value) override;
  virtual double GetValue() override;
private:
  double median_;
  int small_size_;
  int big_size_;
  std::map<double, int, std::greater<double>> small_;
  std::map<double, int> big_;
  std::queue<double> queue_;
  void Rebalance();
  bool DeleteAtSmall(double);
  bool DeleteAtBig(double);
};

#endif
