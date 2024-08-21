#include "std.h"

Std::Std(int window) : BaseCalculator(window), square_(window), normal_(window) {}

void Std::AddValue(double value) {
  square_.AddValue(value * value);
  normal_.AddValue(value);
}

double Std::GetValue() {
  double s = square_.GetValue();
  double n = normal_.GetValue();
  return sqrt(abs(s - n));
}
