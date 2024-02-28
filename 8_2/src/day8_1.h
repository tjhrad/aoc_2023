#ifndef DAY8_1H
#define DAY8_1H

#include <iostream>
#include <numeric>
#include <map>

#include "aoc_tools.h"

long long get_lcm(std::vector<long long> all_steps_to_end);

long long gcd(long long int a, long long int b);
  
std::map<std::string, std::vector<std::string>> get_network_map(const std::vector<std::string>& data);

std::vector<long long> get_all_steps_to_end(std::vector<std::string> starting_nodes, std::string instructions, std::map<std::string,std::vector<std::string>> network_map);

std::vector<std::string> get_starting_nodes(std::map<std::string, std::vector<std::string>> network_map);

#endif 
