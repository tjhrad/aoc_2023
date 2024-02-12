// Advent of Code 2023 Day 4: Part 2

#include "day4_2.h"

int main()
{
  std::string file_name = "./data/input.txt";
  std::vector<std::string> file_data = read_text_file(file_name);

  std::vector<int> card_copies = get_card_copies(file_data);

  int result = sum_integers(card_copies);

  std::cout << "Result: " << result << "\n";

  return 0;
}

std::vector<int> get_card_copies(std::vector<std::string> card_data)
{
  std::vector<int> number_of_wins_per_card;
  std::vector<int> number_of_copies_per_card;

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

    int number_of_wins = 0;
    for (int number : numbers_you_have)
    {
      if(winning_numbers.find(number) != winning_numbers.end()){
        number_of_wins += 1;
      }
    }
    number_of_wins_per_card.push_back(number_of_wins);
    number_of_copies_per_card.push_back(1);

  }

  for (int i=0; i<number_of_copies_per_card.size(); i++)
  {
    int num_copies = number_of_copies_per_card[i];
    int number_of_wins = number_of_wins_per_card[i];

    for (int x=i; x<i+number_of_wins; x++)
    {
      number_of_copies_per_card[x+1] += num_copies;
    }
  }

  return number_of_copies_per_card;
}

