
#include "day8_1.h"

int main()
{
  std::string input_file_path = "./data/test.txt";

  std::vector<std::string> input_file_data = read_text_file(input_file_path);

  std::string sequence_of_instructions = input_file_data[0];

  std::map<std::string, std::vector<std::string>> network_map = get_network_map(input_file_data);

  /* for (int i=0; i<sequence_of_instructions.size(); i++)
  {
    std::cout << sequence_of_instructions[i] << '\n';
  }

  for (std::string s : input_file_data)
  {
    std::cout << s << '\n';
  } */

  long long result = 0ll;

  std::cout << result << '\n';

  return 0;
}

long long calculate_result(const std::vector<std::vector<std::string>>& hands)
{
  long long result = 0;
  for (long long i=0; i<hands.size(); i++)
  {
    long long rank = i + 1;
    result = result + (rank*stoll(hands[i][1]));

  }
  
  return result;
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