#ifndef DAY5_2H
#define DAY5_2H

#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <ranges>

#include "aoc_tools.h"


std::vector<std::vector<std::string>> split_file_data(const std::vector<std::string>& data);

std::vector<std::vector<std::vector<long long>>> get_maps_as_vectors(const std::vector<std::vector<std::string>>& data);

std::vector<long long int> get_seeds(const std::string& data);

std::vector<long long int> get_all_locations(const std::vector<long long int>& seeds, const std::vector<std::vector<std::vector<long long>>>& maps);

long long int get_value_from_map(long long int k,const std::vector<std::vector<long long>>& m);

#endif 
