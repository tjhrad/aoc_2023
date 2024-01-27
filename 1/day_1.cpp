// Advent of Code 2023 Day 1: Part 1

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

vector <string> read_text_file(string file_name);
vector <string> remove_alpha(vector <string> string_vector);
vector <int> get_first_and_last_int(vector <string> string_vector);
int sum_integers(vector <int> vector);

int main()
{
  string file_name = "input.txt";
  vector <string> file_string_vector;
  vector <string> alpha_removed_vector;
  vector <int> calibration_values_vector;

  file_string_vector = read_text_file(file_name);
  alpha_removed_vector = remove_alpha(file_string_vector);
  calibration_values_vector = get_first_and_last_int(alpha_removed_vector);
  
  int calibration_values_sum = sum_integers(calibration_values_vector);

  cout << calibration_values_sum;

  return 0;
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

vector<int> get_first_and_last_int(vector <string> string_vector)
{
  vector <int> int_vector;
  
  /* cout << typeid(int_vector).name(); */
  for (string s : string_vector)
  {
    string temp = "";
    /* cout << s << "\n"; */
    temp += s[0];
    temp += s[s.length() - 1];
    int i = stoi(temp);
    /* cout << temp; */
    int_vector.push_back(i);
  }

  return int_vector;
}

