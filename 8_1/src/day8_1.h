#ifndef DAY8_1H
#define DAY8_1H

#include <iostream>
#include <map>

#include "aoc_tools.h"

std::map<std::string, std::vector<std::string>> get_network_map(const std::vector<std::string>& data);

int get_steps_to_zzz(std::string starting_key, int starting_count, std::string instructions, std::map<std::string, std::vector<std::string>> network_map);

#endif 
