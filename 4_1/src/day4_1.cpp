// Advent of Code 2023 Day 1: Part 1

#include "day4_1.h"

int main()
{
  std::string file_name = "./data/input.txt";
  std::vector<std::string> file_data = read_text_file(file_name);

  std::vector<int> card_values = get_card_values(file_data);

  int result = sum_integers(card_values);

  std::cout << result << "\n";

  return 0;
}

std::vector<int> get_card_values(std::vector<std::string> card_data)
{
  std::vector<int> card_values;


  for (std::string s : card_data)
  {
    std::vector<std::string> temporary_strings = split_string(s,":");
    std::string card_name = temporary_strings[0];
    std::string raw_card_numbers = temporary_strings[1];

    std::vector<std::string> temporary_number_strings = split_string(raw_card_numbers, "|");

    std::string raw_winning_numbers = temporary_number_strings[0];
    std::string raw_numbers_you_have = temporary_number_strings[1];

    std::vector<std::string> winning_numbers_str = split_string(raw_winning_numbers, " ");
    std::vector<std::string> numbers_you_have_str = split_string(raw_numbers_you_have, " ");

    std::vector<int> winning_numbers_vector = strings_to_integers(winning_numbers_str);
    std::vector<int> numbers_you_have = strings_to_integers(numbers_you_have_str);

    std::set<int> winning_numbers(winning_numbers_vector.begin(), winning_numbers_vector.end());

    int card_value = 0;
    for (int number : numbers_you_have)
    {
      if(winning_numbers.find(number) != winning_numbers.end()){
        if(card_value == 0)
        {
          card_value = 1;
        }
        else {
          {
            card_value = card_value*2;
          }
        }
      }
    }
    card_values.push_back(card_value);

  }
  return card_values;
}

