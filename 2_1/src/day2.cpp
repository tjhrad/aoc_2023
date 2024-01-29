// Advent of Code 2023 Day 1: Part 1

#include "day2.h"

int main()
{
  std::string file_name = "./data/input.txt";
  
  int number_red = 12;
  int number_green = 13;
  int number_blue = 14;

  std::vector <std::string> file_strings;
  std::vector <int> possible_games;
 
  file_strings = read_text_file(file_name);
  
  possible_games = get_possible_games(file_strings, number_red, number_green, number_blue);

  int sum = sum_integers(possible_games);

  std::cout << "Sum of possible games: " << sum << "\n";
      
  return 0;
}

std::vector <int> get_possible_games(std::vector <std::string> f_strings,int n_red,int n_green,int n_blue)
{
  std::vector <int> possible_games;
  
  
  for (std::string s : f_strings)
  {
    int max_red, max_green, max_blue;
    int game_number = get_game_number(s);
    std::tie(max_red, max_green, max_blue) = get_max_rgb(s);
    if(max_red <= n_red && max_green <= n_green && max_blue <= n_blue)
    {
      possible_games.push_back(game_number);
    }

  }

  return possible_games;
}

std::tuple <int,int,int> get_max_rgb(std::string s)
{
  int max_red = 0;
  int max_blue = 0;
  int max_green = 0;
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

      
      if (color.find("red") != std::string::npos)
      {
        
        if (std::stoi(color_and_number[1]) > max_red)
        {
          max_red = std::stoi(color_and_number[1]);
        }
      }
      else if (color.find("green") != std::string::npos)
      {
        if (std::stoi(color_and_number[1]) > max_green)
        {
          max_green = std::stoi(color_and_number[1]);
        }
      }
      else if (color.find("blue") != std::string::npos)
      {
        if (std::stoi(color_and_number[1]) > max_blue)
        {
          max_blue = std::stoi(color_and_number[1]);
        }
      }
      
    }

  }
  return std::make_tuple(max_red, max_green, max_blue);
}

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

