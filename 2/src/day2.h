#ifndef DAY2_H
#define DAY2_H

#include <iostream>
#include <tuple>

#include "aoc_tools.h"


std::vector <int> get_possible_games(std::vector <std::string> f_strings,int n_red,int n_green,int n_blue);

int get_game_number(std::string s);

std::tuple <int,int,int> get_max_rgb(string s);

#endif 
