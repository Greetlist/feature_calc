#ifndef __MAX_CALCULATOR_H_
#define __MAX_CALCULATOR_H_

#include <queue>
#include <vector>
#include <map>
#include <limits>

#include "base_calculator.h"

struct MaxCompare {
  bool operator()(std::pair<double, long>& a, std::pair<double, long>& b) {
    return a.first < b.first;
  }
};

class Max : public BaseCalculator {
public:
  explicit Max(int window);
  ~Max() = default;
  virtual void AddValue(double value) override;
  virtual double GetValue() override;
private:
  long index_;
  std::priority_queue<std::pair<double, long>, std::vector<std::pair<double, long>>, MaxCompare> queue_;
};

#endif
