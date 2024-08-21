#ifndef __MIN_CALCULATOR_H_
#define __MIN_CALCULATOR_H_

#include <queue>
#include <vector>
#include <map>
#include <limits>

#include "base_calculator.h"

struct MinCompare {
  bool operator()(std::pair<double, long>& a, std::pair<double, long>& b) {
    return a.first > b.first;
  }
};

class Min : public BaseCalculator {
public:
  explicit Min(int window);
  ~Min() = default;
  virtual void AddValue(double value) override;
  virtual double GetValue() override;
private:
  long index_;
  std::priority_queue<std::pair<double, long>, std::vector<std::pair<double, long>>, MinCompare> queue_;
};

#endif
