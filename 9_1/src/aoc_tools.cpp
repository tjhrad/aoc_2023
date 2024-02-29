
#include "aoc_tools.h"

std::string remove_nonalph_characters(std::string s)
{
  //std::string ouput_string = "";
  int j = 0;
  for (int i = 0; i < s.size(); i++) 
  {
      // Store only valid characters
      if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >='a' && s[i] <= 'z'))
      { 
          s[j] = s[i];
          j++;
      }
  }

  return s.substr(0, j);
}

std::string remove_nonalphanumeric_characters(std::string s)
{
  //std::string ouput_string = "";
  int j = 0;
  for (int i = 0; i < s.size(); i++) 
  {
      // Store only valid characters
      if ((s[i] >= 'A' && s[i] <= 'Z') || 
          (s[i] >='a' && s[i] <= 'z') ||
          (s[i] >='0' && s[i] <= '9'))
      { 
          s[j] = s[i];
          j++;
      }
  }

  return s.substr(0, j);
}

std::vector<int> get_integers_from_string(const std::string& input_data)
{
  std::stringstream ss;
  std::vector<int> integers;

  ss << input_data;

  std::string temp_string;
  int current_integer;
  while (!ss.eof())
  {
    ss >> temp_string;

    if (std::stringstream(temp_string) >> current_integer)
      integers.push_back(current_integer);
  }  

  return integers;
}

std::vector<int> strings_to_integers(const std::vector<std::string>& input_strings)
{
  std::vector<int> output_integers;

  for (std::string s : input_strings)
  {
    std::string::iterator end_pos = std::remove(s.begin(), s.end(), ' ');
    s.erase(end_pos, s.end());

    if(s.size() > 0)
    {
      output_integers.push_back(std::stoi(s));
    }
  }

  return output_integers;
}

std::vector<long long int> strings_to_long_long_int(const std::vector<std::string>& input_strings)
{
  std::vector<long long int> output_integers;

  for (std::string s : input_strings)
  {
    std::string::iterator end_pos = std::remove(s.begin(), s.end(), ' ');
    s.erase(end_pos, s.end());

    if(s.size() > 0)
    {
      output_integers.push_back(std::stoll(s));
    }
  }

  return output_integers;
}

long long combine_integers_in_string(const std::string& input_data)
{
  std::stringstream ss;
  std::string combined_integers = "";

  ss << input_data;

  std::string temp_string;
  int current_integer;
  while (!ss.eof())
  {
    ss >> temp_string;

    if (std::stringstream(temp_string) >> current_integer)
      combined_integers += std::to_string(current_integer);
  }  

  long long result = std::stoll(combined_integers);

  return result;
}


std::vector<std::vector<char>> strings_to_chars(const std::vector<std::string>& strings)
{
  std::vector<std::vector<char>> converted_chars;

  for (std::string s : strings)
  {
    std::vector<char> characters( s.begin(), s.end() );
    converted_chars.push_back(characters);
  }

  return converted_chars;
}


std::vector<std::string> split_string(std::string string_to_split,std::string delimiter)
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

int sum_integers(const std::vector<int>& v)
{
  int sum = 0;
  for (int i : v)
  {
    sum += i;
  }
  return sum;
}

std::vector<std::string> read_text_file(const std::string& file_name)
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

std::vector<std::vector<int>> subtract_2d_vectors(const std::vector<std::vector<int>>& vector1, const std::vector<std::vector<int>>& vector2)
{
  std::vector<std::vector<int>> result;

  if(vector1.size() != vector2.size())
  {
    std::cout << vector1.size() << "\n";
    std::cout << vector2.size() << "\n";
    throw std::invalid_argument("Vector sizes do not match!!");
  }

  for ( int i=0; i<vector1.size(); i++ )
  {
    std::vector<int> temporary_result;
    for ( int x=0; x<vector1[i].size(); x++ )
    {
      temporary_result.push_back(vector1[i][x]-vector2[i][x]);
    }
    result.push_back(temporary_result);
  }

  return result;
}

std::vector<std::vector<int>> multiply_2d_vectors(const std::vector<std::vector<int>>& vector1, const std::vector<std::vector<int>>& vector2)
{
  std::vector<std::vector<int>> result;

  if(vector1.size() != vector2.size())
  {
    std::cout << vector1.size() << "\n";
    std::cout << vector2.size() << "\n";
    throw std::invalid_argument("Vector sizes do not match!!");
  }

  for ( int i=0; i<vector1.size(); i++ )
  {
    std::vector<int> temporary_result;
    for ( int x=0; x<vector1[i].size(); x++ )
    {
      temporary_result.push_back(vector1[i][x]*vector2[i][x]);
    }
    result.push_back(temporary_result);
  }

  return result;
}

