
#include "day9_1.h"


int main()
{
  std::string input_file_path = "./data/input.txt";

  std::vector<std::string> input_file_data = read_text_file(input_file_path);

  long result = calculate_result(input_file_data);

  std::cout << "Answer: " << result << '\n';

  return 0;
}


long calculate_result(const)
{
  long result = 0;

  return result;
}

long get_next_value(const std::vector<long>& input_sequence)
{
  long next_value = 0;

  return next_value;
}
