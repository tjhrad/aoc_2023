#ifndef AOC_TOOLS_H
#define AOC_TOOLS_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

std::string remove_nonalpha_characters(std::string s);

std::vector<int> strings_to_integers(const std::vector<std::string>& input_strings);

std::vector<long long int> strings_to_long_long_int(const std::vector<std::string>& input_strings);

long long combine_integers_in_string(const std::string& input_data);

std::vector<std::vector<char>> strings_to_chars(const std::vector<std::string>& strings);

std::vector <std::string> split_string(std::string string_to_split,std::string delimiter);

int sum_integers(const std::vector<int>& v);

std::vector <std::string> read_text_file(const std::string& file_name);

std::vector<std::vector<int>> subtract_2d_vectors(const std::vector<std::vector<int>>& vector1, const std::vector<std::vector<int>>& vector2);

std::vector<std::vector<int>> multiply_2d_vectors(const std::vector<std::vector<int>>& vector1, const std::vector<std::vector<int>>& vector2);

std::vector<int> get_integers_from_string(const std::string& input_data);

#endif

