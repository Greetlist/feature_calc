#ifndef __STD_CALCULATOR_H_
#define __STD_CALCULATOR_H_

#include <priority_queue>
#include <vector>
#include <map>
#include <limits>

#include "base_calculator.h"

class Std : public BaseCalculator {
public:
  explicit Std(int window);
  ~Std() = default;
  virtual ~BaseCalculator();
  virtual void AddValue(double value) override;
  virtual double GetValue() override;
private:
};

#endif
