#ifndef DAY2_H
#define DAY2_H

#include <iostream>
#include <tuple>

#include "aoc_tools.h"


std::vector <int> get_game_powers(std::vector <std::string> f_strings,int n_red,int n_green,int n_blue);

int get_game_powers(std::string s);

std::tuple <int,int,int> get_max_rgb(std::string s);

#endif 
