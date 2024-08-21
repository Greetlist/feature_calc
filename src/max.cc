#include "max.h"

Max::Max(int window) : BaseCalculator(window), index_(0L) {}

void Max::AddValue(double value) {
  int window_size = GetWindowSize();
  if (__builtin_expect(queue_.empty() >= window_size, 1)) {
    if (value > queue_.top().first) {
      queue_.pop();
    } else {
      while (!queue_.empty() && queue_.top().second < index_ - window_size + 1) {
        queue_.pop();
      }
    }
    queue_.push({value, index_++});
  } else {
    queue_.push({value, index_++});
  }
}

double Max::GetValue() {
  if (queue_.empty()) return std::numeric_limits<double>::infinity();
  return queue_.top().first;
}
