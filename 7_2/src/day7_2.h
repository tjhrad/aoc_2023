#ifndef DAY7_2H
#define DAY7_2H

#include <iostream>
#include <algorithm>

#include "aoc_tools.h"

long long calculate_result(const std::vector<std::vector<std::string>>& hands);

std::vector<std::vector<std::string>> split_hands_and_bids(const std::vector<std::string>& data);

int get_hand_strength(const std::string& hand);

int compare_each_card(const std::string& hand1,const std::string& hand2);

int get_card_value(const char& card);

bool compare_hands(const std::vector<std::string>& hand1,const std::vector<std::string>& hand2);

#endif 
