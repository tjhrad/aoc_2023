#ifndef DAY8_1H
#define DAY8_1H

#include <iostream>
#include <map>

#include "aoc_tools.h"

long long calculate_result(const std::vector<std::vector<std::string>>& hands);

std::map<std::string, std::vector<std::string>> get_network_map(const std::vector<std::string>& data);

#endif 
