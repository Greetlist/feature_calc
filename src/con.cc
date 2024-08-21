#include "con.h"

Con::Con(int window) : avg_x_(window), avg_y_(window), avg_xy_(window),
  std_x_(window), std_y_(window) {}

void Con::AddValue(double x, double y) {
  avg_x_.AddValue(x);
  avg_y_.AddValue(x);
  avg_xy_.AddValue(x * y);
  std_x_.AddValue(y);
  std_y_.AddValue(y);
}

double Con::GetValue() {
  double avgs = avg_xy_.GetValue() - avg_x_.GetValue() * avg_y_.GetValue();
  double stds = std_x_.GetValue() * std_y_.GetValue();
  if (stds < epsilon) return 0.00;
  return avgs / stds;
}
