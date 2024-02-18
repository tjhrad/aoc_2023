// Advent of Code 2023 Day 5: Part 2

#include "day5_2.h"

int main()
{
  std::string input_file_path = "./data/test.txt";

  std::vector<std::string> input_file_data = read_text_file(input_file_path);

  std::vector<std::vector<std::string>> split_data = split_file_data(input_file_data);
  
  auto result = smallest_location;
  std::cout << result << std::endl;

  return 0;
}

std::vector<std::vector<std::string>> split_file_data(const std::vector<std::string>& data)
{
  std::vector<std::vector<std::string>> split_data;
  std::vector<std::string> temporary_data;

  bool is_building_map = false;
  bool is_done_building_map = false;

  for (std::string s : data)
  {
    if (s.find("seeds:") != std::string::npos && !is_building_map)
    {
      temporary_data.push_back(s);
    }
    else if (s.find("map:") != std::string::npos && !is_building_map)
    {
      is_building_map = true;
      is_done_building_map = false;
    }
    else if (s.size() < 1)
    {
      is_building_map = false;
      is_done_building_map = true;
    }
    else
    {
      temporary_data.push_back(s);
    }

    if(!is_building_map && is_done_building_map)
    {
      split_data.push_back(temporary_data);
      temporary_data.clear();
      is_done_building_map = false;
    }
    
  }
  split_data.push_back(temporary_data);

  return split_data;
}