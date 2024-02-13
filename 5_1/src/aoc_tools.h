#ifndef AOC_TOOLS_H
#define AOC_TOOLS_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>


std::vector<int> strings_to_integers(std::vector<std::string> input_strings);

std::vector<std::vector<char>> strings_to_chars(std::vector<std::string> strings);

std::vector <std::string> split_string(std::string string_to_split, std::string delimeter);

int sum_integers(std::vector <int> v);

std::vector <std::string> read_text_file(std::string file_name);

std::vector<std::vector<int>> subtract_2d_vectors(std::vector<std::vector<int>> vector1, std::vector<std::vector<int>> vector2);

std::vector<std::vector<int>> multiply_2d_vectors(std::vector<std::vector<int>> vector1, std::vector<std::vector<int>> vector2);

#endif

