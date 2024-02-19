#ifndef DAY6_1H
#define DAY6_1H

#include <iostream>

#include "aoc_tools.h"

std::vector<std::vector<int>> get_best_possible_distances(const std::vector<int>& times, const std::vector<int>& distances);

int calculate_result(const std::vector<std::vector<int>>& best_possible_distances);

#endif 
