
#include "day8_1.h"


int main()
{
  std::string input_file_path = "./data/input.txt";

  std::vector<std::string> input_file_data = read_text_file(input_file_path);

  std::string instructions = input_file_data[0];

  std::map<std::string, std::vector<std::string>> network_map = get_network_map(input_file_data);

  std::vector<std::string> starting_nodes = get_starting_nodes(network_map);

  std::vector<long long> all_steps_to_end = get_all_steps_to_end(starting_nodes, instructions, network_map);

  long long result = get_lcm(all_steps_to_end);

  std::cout << "Answer: " << result << '\n';

  return 0;
}

std::vector<std::string> get_starting_nodes(std::map<std::string, std::vector<std::string>> network_map)
{
  std::vector<std::string> starting_nodes;

  for (auto const& imap : network_map)
  {
    std::string key = imap.first;
    if (key[2] == 'A')
      starting_nodes.push_back(key);
  }

  return starting_nodes;
}

long long get_lcm(std::vector<long long> all_steps_to_end)
{
  long long result = all_steps_to_end[0];

  for (int i=1; i<all_steps_to_end.size(); i++)
    result = ( ((all_steps_to_end[i] * result)) / (gcd(all_steps_to_end[i], result)) );

  return result;
}

long long gcd(long long int a, long long int b) 
{ 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
} 

std::vector<long long> get_all_steps_to_end(std::vector<std::string> starting_nodes, std::string instructions, std::map<std::string,std::vector<std::string>> network_map)
{
  std::vector<long long> all_steps_to_end;

  for (std::string node : starting_nodes)
  {
    bool end_found = false;
    long long number_of_steps = 0;
    std::string current_node = node;
    
    while(!end_found)
    {
      for (int i=0; i<instructions.size(); i++)
      {
        std::vector<std::string> temporary_nodes = network_map[current_node];
        if (instructions[i] == 'L')
          current_node = temporary_nodes[0];
        else if (instructions[i] == 'R')
          current_node = temporary_nodes[1];

        number_of_steps++;

        if (current_node[2] == 'Z')
        {
          all_steps_to_end.push_back(number_of_steps);
          end_found = true;
        }
      }
    }
    
  }

  return all_steps_to_end;
}

std::map<std::string,std::vector<std::string>> get_network_map(const std::vector<std::string>& data)
{
  std::map<std::string, std::vector<std::string>> network_map;

  for (std::string s : data)
  {
    if (s.find("=") == std::string::npos)
      continue;

    std::vector<std::string> temporary_data = split_string(s, " ");

    std::string temporary_key = remove_nonalphanumeric_characters(temporary_data[0]);
    std::string temporary_left = remove_nonalphanumeric_characters(temporary_data[2]);
    std::string temporary_right = remove_nonalphanumeric_characters(temporary_data[3]);

    std::vector<std::string> temporary_instruction_vector;
    temporary_instruction_vector.push_back(temporary_left);
    temporary_instruction_vector.push_back(temporary_right);

    network_map.insert(make_pair(temporary_key,temporary_instruction_vector));
  }

  return network_map;
}