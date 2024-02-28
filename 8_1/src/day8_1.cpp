
#include "day8_1.h"

int main()
{
  std::string input_file_path = "./data/input.txt";

  std::vector<std::string> input_file_data = read_text_file(input_file_path);

  std::string instructions = input_file_data[0];

  std::map<std::string, std::vector<std::string>> network_map = get_network_map(input_file_data);

  int result = get_steps_to_zzz("AAA", 0, instructions, network_map);

  std::cout << result << '\n';

  return 0;
}

int get_steps_to_zzz(std::string starting_key, int starting_count, std::string instructions, std::map<std::string, std::vector<std::string>> network_map)
{
  int count = starting_count;
  std::string key = starting_key;
  for (int i=0; i<instructions.size(); i++)
  {
    std::vector<std::string> temp_vector = network_map[key];
    if (instructions[i] == 'L')
      key = temp_vector[0];
    else if (instructions[i] == 'R')
      key = temp_vector[1];

    count ++;

    if (key == "ZZZ")
      return count;
  }

  return get_steps_to_zzz(key, count, instructions, network_map);
}

std::map<std::string, std::vector<std::string>> get_network_map(const std::vector<std::string>& data)
{
  std::map<std::string, std::vector<std::string>> network_map;

  for (std::string s : data)
  {
    if (s.find("=") == std::string::npos)
      continue;

    std::vector<std::string> temporary_data = split_string(s, " ");

    std::string temporary_key = remove_nonalpha_characters(temporary_data[0]);
    std::string temporary_left = remove_nonalpha_characters(temporary_data[2]);
    std::string temporary_right = remove_nonalpha_characters(temporary_data[3]);

    std::vector<std::string> temporary_instruction_vector;
    temporary_instruction_vector.push_back(temporary_left);
    temporary_instruction_vector.push_back(temporary_right);

    network_map.insert(make_pair(temporary_key,temporary_instruction_vector));
  }

  return network_map;
}