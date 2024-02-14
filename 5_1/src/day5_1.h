#ifndef DAY5_1H
#define DAY5_1H

#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <ranges>

#include "aoc_tools.h"


std::vector<std::vector<std::string>> split_file_data(const std::vector<std::string>& data);

std::map<int,int> create_map(const std::vector<std::string>& data);

std::vector<std::map<int,int>> get_maps(const std::vector<std::vector<std::string>>& data);

std::vector<int> get_seeds(const std::string& data);

std::vector<int> get_locations(const std::vector<int>& seeds, const std::vector<std::map<int,int>>& maps);

int get_value_from_map(int k,std::map<int,int> m);

#endif 
