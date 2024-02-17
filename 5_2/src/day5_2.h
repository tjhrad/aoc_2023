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

std::vector<std::vector<long long>> get_seed_ranges(const std::string& data);

long long get_smallest_location_reverse(const std::vector<std::vector<long long>>& seeds, const std::vector<std::vector<std::vector<long long>>>& maps);

long long get_value_from_map_reverse(long long k,const std::vector<std::vector<long long>>& m);

long long get_max_from_map(const std::vector<std::vector<long long>>& map);

#endif 
