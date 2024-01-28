// Advent of Code 2023 Day 1: Part 2

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

string get_number_from_word(string number);

vector <string> convert_words_to_numbers(vector <string> input_strings)
{
  vector <string> converted_strings;
  string valid_digit_words[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

  for (string s : input_strings)
  {
    string first_word = "";
    string last_word = "";

    int first_word_position = 10000;
    int last_word_position = 0;

    for (string word : valid_digit_words)
    {
      std::string::size_type n;
      n = s.find(word);
      if (n != std::string::npos)
      {
        if (n <= first_word_position)
        {
          first_word_position = n;
          first_word = word;
        }
      }
    }
    if(first_word != "")
    {
      s.erase(first_word_position, first_word.length());
      s.insert(first_word_position, get_number_from_word(first_word));
    }

    for (string word : valid_digit_words)
    {
      std::string::size_type n;
      n = s.find(word);
      if (n != std::string::npos)
      {
        if(n >= last_word_position)
        {
          last_word_position = n;
          last_word = word;
        }
      }
    }
    if(last_word != "")
    {
      s.erase(last_word_position, last_word.length());
      s.insert(last_word_position, get_number_from_word(last_word));
    }
    
    converted_strings.push_back(s);
  }
  return converted_strings;
}

string get_number_from_word(string number)
{
  string n;
  if (number == "one")
  {
    n = '1';
  }
  else if (number == "two")
  {
    n = '2';
  }
  else if (number == "three")
  {
    n = '3';
  }
  else if (number == "four")
  {
    n = '4';
  }
  else if (number == "five")
  {
    n = '5';
  }
  else if (number == "six")
  {
    n = '6';
  }
  else if (number == "seven")
  {
    n = '7';
  }
  else if (number == "eight")
  {
    n = '8';
  }
  else if (number == "nine")
  {
    n = '9';
  }

  return n;
}

int sum_integers(vector <int> vector)
{
  int sum = 0;
  for (int i : vector)
  {
    sum += i;
  }
  return sum;
}

vector <string> remove_alpha(vector <string> string_vector)
{
  vector <string> alpha_removed_vector;

  for (string s: string_vector)
  {
    string temp = "";
    for (char & c : s)
    {
      if (!isalpha(c))
      {
        temp = temp + c;
      }
    }
    alpha_removed_vector.push_back(temp);
  }
  return alpha_removed_vector;
}

vector <string> read_text_file(string file_name)
{
  string text;
  vector <string> file_data;
  ifstream text_file(file_name);

  if(!text_file.is_open())
  {
    cout << "ERROR: File did not open" << "\n";
    cout << file_name;
    return file_data;
  }

  while (getline (text_file, text))
  {
    file_data.push_back(text);
  }

  text_file.close();

  return file_data;
}

vector<int> get_first_and_last_integers(vector <string> text_strings)
{
  vector <int> first_and_last_integers;
  
  for (string s : text_strings)
  {
    string temp = "";
    /* cout << s << "\n"; */
    temp += s[0];
    temp += s[s.length() - 1];
    int i = stoi(temp);
    /* cout << temp; */
    first_and_last_integers.push_back(i);
  }

  return first_and_last_integers;
}

int main()
{
  string file_name = "input.txt";
  vector <string> file_strings;
  vector <string> file_strings_converted_to_numbers;
  vector <string> alpha_removed_vector;
  vector <int> calibration_values;

  file_strings = read_text_file(file_name);
  file_strings_converted_to_numbers = convert_words_to_numbers(file_strings);
  alpha_removed_vector = remove_alpha(file_strings_converted_to_numbers); 
  calibration_values = get_first_and_last_integers(alpha_removed_vector); 
  int calibration_values_sum = sum_integers(calibration_values);
  
  cout << calibration_values_sum << "\n";

  return 0;
}

