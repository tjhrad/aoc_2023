// Advent of Code 2023 Day 1: Part 1

#include "day2.h"

int main()
{
  std::string file_name = "./data/test.txt";
  
  int number_red = 12;
  int number_green = 13;
  int number_blue = 14;

  std::vector <std::string> file_strings;
  std::vector <int> possible_games;
 
  file_strings = read_text_file(file_name);
  
  possible_games = get_possible_games(file_strings, number_red, number_green, number_blue);
      
  return 0;
}

std::vector <int> get_possible_games(std::vector <std::string> f_strings,int n_red,int n_green,int n_blue)
{
  std::vector <int> possible_games;
  
  /* std::cout << n_red << "\n"; */
  /* std::cout << n_green << "\n"; */
  /* std::cout << n_blue << "\n"; */

  for (std::string s : f_strings)
  {
    int game_number = get_game_number(s);
    //int max_red, max_green, max_blue get_max_rgb(s);
  }

  return possible_games;
}

std::tuple <int,int,int> get_max_rgb(string s)
{
  int max_red, max_blue, max_green = 0;
  std::vector <std::string> substrings;
  std::vector <std::string> game_rounds;

  substrings = split_string(s,":");
  game_rounds = split_string(substrings[1], ";"); 

  for (std::string round : game_rounds)
  {
    std::vector <std::string> colors;
    colors = split_string(round,",");

    for (std::string color : colors)
    {
      int number;
      std::vector <std::string> color_and_number;
      color_and_number = split_string(color," ");

      if (color.find("red") != std::string:npos)
      {

      }
      else if (color.find("green") != std::string:npos)
      {

      }
      else if (color.find("blue") != std::string:npos)
      {

      }
    }

  }
  return {max_red, max_blue, max_green};
}

//int get_color_max_value

int get_game_number(std::string s)
{
  std::vector <std::string> substrings;
  std::vector <std::string> substrings2;
  std::string game_string;
  int number;

  substrings = split_string(s, ":");

  game_string = substrings[0];

  substrings2 = split_string(game_string, " ");

  number = stoi(substrings2[1]);
  return number;
}

