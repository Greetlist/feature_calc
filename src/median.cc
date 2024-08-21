#include "median.h"

Median::Median(int window) :
  BaseCalculator(window), 
  median_(std::numeric_limits<double>::infinity()),
  small_size_(0), big_size_(0) {}

void Median::AddValue(double value) {
  if (__builtin_expect(queue_.size() >= GetWindowSize(), 1)) {
    double delete_value = queue_.front();
    queue_.pop();
    if (DeleteAtSmall(delete_value) || DeleteAtBig(delete_value));
  }

  if (value > median_) {
    big_[value]++;
    big_size_++;
  } else {
    small_[value]++;
    small_size_++;
  }
  queue_.push(value);
  Rebalance();
  if(small_size_ == big_size_) {
    median_ = (small_.begin()->first + big_.begin()->first) / 2.00;
  } else {
    median_ = small_size_ > big_size_ ? small_.begin()->first : big_.begin()->first;
  }
}

double Median::GetValue() {
  return median_;
}

bool Median::DeleteAtSmall(double delete_value) {
  auto it = small_.find(delete_value);
  if (it == small_.end()) return false;

  if (it->second == 1) small_.erase(it);
  else it->second--;
  small_size_--;
  return true;
}

bool Median::DeleteAtBig(double delete_value) {
  auto it = big_.find(delete_value);
  if (it == big_.end()) return false;

  if (it->second == 1) big_.erase(it);
  else it->second--;
  big_size_--;
  return true;
}

void Median::Rebalance() {
  int ssize = small_.size(), bsize = big_.size();
  while (abs(small_size_ - big_size_) > 1) {
    if (small_size_ > big_size_) {
      double value = small_.begin()->first;
      DeleteAtSmall(value);
      big_[value]++;
      big_size_++;
    } else {
      double value = big_.begin()->first;
      DeleteAtBig(value);
      small_[value]++;
      small_size_++;
    }
  }
}
