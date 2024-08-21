#include "reader.h"

Reader::Reader(const std::string&& csv_path) : csv_path_(csv_path) {}

std::vector<double> Reader::ReadClose() {
  std::ifstream input(csv_path_);
  if (!input.is_open()) {
    std::cout << "Open [" << csv_path_ << "] Error, Exit" << std::endl;
    std::exit(1);
  }

  std::vector<double> res;
  int line_index = 0;
  while (true) {
    std::string line;
    std::getline(input, line);
    std::stringstream line_stream(line);
    std::string cell;
    if (line_index++ == 0) continue;

    int close_index = 5;
    int cell_index = 0;
    std::string stock_code;
    std::string exchange;
    while (std::getline(line_stream, cell, ',')) {
      if (cell_index == close_index) {
        res.push_back(std::stod(cell));
      }
      cell_index++;
    }
    if (input.eof()) {
      break;
    }
  }
  return res;
}
