#ifndef DAY2_H
#define DAY2_H

#include <iostream>

#include "aoc_tools.h"


std::vector<std::vector<char>> strings_to_chars(std::vector<std::string> strings);

std::vector<std::vector<int>> chars_to_binary_matrix(std::vector<std::vector<char>>);

std::vector<std::vector<int>> get_codes_matrix(std::vector<std::vector<char>> char_matrix);

std::vector<std::vector<std::vector<int>>> split_code_matrices(std::vector<std::vector<int>> codes_matrix);

std::vector<std::vector<int>> code_matrix_to_binary_map(std::vector<std::vector<int>> code_matrix);

std::vector<int> get_valid_codes(std::vector<std::vector<std::vector<int>>> code_matrices, std::vector<std::vector<int>> binary_symbols);

int get_code(std::vector<std::vector<int>> code_matrix);

#endif 
