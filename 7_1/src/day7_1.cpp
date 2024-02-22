// Advent of Code 2023 Day 6: Part 2

#include "day7_1.h"

int main()
{
  std::string input_file_path = "./data/input.txt";

  std::vector<std::string> input_file_data = read_text_file(input_file_path);

  return 0;
}

int calculate_result(const std::vector<long long>& best_possible_distances)
{
  int count = 0;
  for (long long race : best_possible_distances)
  {
    count++;
  }
  
  return count;
}
