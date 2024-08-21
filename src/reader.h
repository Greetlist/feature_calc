#ifndef __READER_H_
#define __READER_H_
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <string>
#include <string_view>
#include <vector>

class Reader {
public:
  Reader(const std::string&&);
  ~Reader() = default;
  std::vector<double> ReadClose();
private:
  std::string csv_path_;
};

#endif
