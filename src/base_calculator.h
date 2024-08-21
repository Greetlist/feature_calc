#ifndef __BASE_CALCULATOR_H_
#define __BASE_CALCULATOR_H_

class BaseCalculator {
public:
  explicit BaseCalculator(int w) : window_size_(w) {}
  virtual ~BaseCalculator() {}
  virtual void AddValue(double value) {}
  virtual double GetValue() {}
  inline int GetWindowSize() {return window_size_;}
private:
  int window_size_;
};

#endif
