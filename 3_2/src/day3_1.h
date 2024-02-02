#ifndef DAY2_H
#define DAY2_H

#include <iostream>

#include "aoc_tools.h"


std::vector<std::vector<char>> strings_to_chars(std::vector<std::string> strings);

std::vector<std::vector<char>> get_asterisk_matrix(std::vector<std::vector<char>>);

std::vector<std::vector<char>> get_codes_matrix(std::vector<std::vector<char>> char_matrix);

std::vector<std::vector<std::vector<char>>> split_matrix(std::vector<std::vector<char>> codes_matrix);

std::vector<std::vector<int>> code_matrix_to_binary_map(std::vector<std::vector<char>> code_matrix);

std::vector<int> get_gear_ratios(std::vector<std::vector<std::vector<char>>> code_matrices, std::vector<std::vector<std::vector<char>>> binary_symbols);

int get_code(std::vector<std::vector<char>> code_matrix);

std::vector<std::vector<int>> char_matrix_to_binary(std::vector<std::vector<char>> char_matrix);

#endif 
