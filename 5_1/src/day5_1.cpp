// Advent of Code 2023 Day 4: Part 2

#include "day5_1.h"

int main()
{
  std::string input_file_path = "./data/test.txt";

  std::vector<std::string> input_file_data = read_text_file(input_file_path);

  //std::vector<int> card_copies = get_card_copies(input_file_data);

  //int result = sum_integers(card_copies);

  std::cout << "Result: " << result << "\n";

  return 0;
}

//create_map

//get_seed_numbers

//seed_to_soil

//soil_to_fertilizer

//fertilizer_to_water

//water_to_light

//light_to_temperature

//temperature_to_humidity

//humidity_to_location

//TODO: Add a function in aoc_tools to find the lowest number.