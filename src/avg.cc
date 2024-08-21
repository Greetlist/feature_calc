#include "avg.h"

Avg::Avg(int window) : BaseCalculator(window), cur_sum_(0), avg_(std::numeric_limits<double>::infinity()) {}

void Avg::AddValue(double value) {
  if (__builtin_expect(queue_.size() >= GetWindowSize(), 1)) {
    cur_sum_ = cur_sum_ - queue_.front() + value;
    queue_.pop();
  } else {
    cur_sum_ += value;
  }
  queue_.push(value);
  avg_ = cur_sum_ / queue_.size();
}

double Avg::GetValue() {
  return avg_;
}
