#ifndef AOC_UTILS_FILEREADER
#define AOC_UTILS_FILEREADER
#include <vector>


std::vector<int> read_input_text_as_int(const std::string filename);
std::vector<std::string> read_input_text(const std::string filename, const bool skip_empty_lines = false);

#endif