// aoc_tools.cpp
#include "aoc_tools.h"

std::vector <std::string> split_string(std::string string_to_split, std::string delimiter)
{
  std::vector <std::string> output_strings;

  size_t pos = 0;
  std::string substring;
  while ((pos = string_to_split.find(delimiter)) != std::string::npos) {
    substring = string_to_split.substr(0, pos);
    output_strings.push_back(substring);
    string_to_split.erase(0, pos + delimiter.length());
  }
  output_strings.push_back(string_to_split);

  return output_strings;
}

int sum_integers(std::vector <int> v)
{
  int sum = 0;
  for (int i : v)
  {
    sum += i;
  }
  return sum;
}

std::vector <std::string> read_text_file(std::string file_name)
{
  std::string text;
  std::vector <std::string> file_data;
  std::ifstream text_file(file_name);

  if(!text_file.is_open())
  {
    std::cout << "ERROR: File did not open" << "\n";
    std::cout << file_name << "\n";
    return file_data;
  }

  while (getline (text_file, text))
  {
    file_data.push_back(text);
  }

  text_file.close();

  return file_data;
}


