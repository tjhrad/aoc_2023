#ifndef AOC_TOOLS_H
#define AOC_TOOLS_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>

//using namespace std;


std::vector <std::string> split_string(std::string string_to_split, std::string delimeter);

int sum_integers(std::vector <int> v);

std::vector <std::string> read_text_file(std::string file_name);

#endif

