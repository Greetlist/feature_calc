#include <iostream>

#include "reader.h"
#include "min.h"
#include "max.h"
#include "avg.h"
#include "std.h"
#include "median.h"
#include "con.h"

using namespace std;

int main(int argc, char** argv) {
  int test_size = 20;
  int window_size = 10;
  Reader r("/home/greetlist/workspace/data_storage/raw/day/SSE/600640.SH.csv");
  vector<double> close = r.ReadClose();
  vector<double> test(test_size, 0.00);
  copy(close.begin(), close.begin()+test_size, test.begin());
  //Min calc(window_size);
  //Max calc(window_size);
  //Avg calc(window_size);
  //Median calc(window_size);
  //Std calc(window_size);
  Con calc(window_size);
  for (auto d : test) {
    calc.AddValue(d, d);
    std::cout << calc.GetValue() << std::endl;
  }
  return 0;
}
