// Advent of Code 2023 Day 7: Part 2

#include "day7_2.h"

int main()
{
  std::string input_file_path = "./data/input.txt";

  std::vector<std::string> input_file_data = read_text_file(input_file_path);

  std::vector<std::vector<std::string>> hands = split_hands_and_bids(input_file_data);

  std::sort(hands.begin(), hands.end(), compare_hands);

  for (std::vector<std::string> v : hands)
  {
    std::cout << v[0] << ' ';
    std::cout << v[1] << '\n';
  }

  long long result = calculate_result (hands);

  std::cout << result << '\n';

  return 0;
}

long long calculate_result(const std::vector<std::vector<std::string>>& hands)
{
  long long result = 0;
  for (long long i=0; i<hands.size(); i++)
  {
    long long rank = i + 1;
    result = result + (rank*stoll(hands[i][1]));

  }
  
  return result;
}

bool compare_hands(const std::vector<std::string>& hand1,const std::vector<std::string>& hand2)
{
  int hand1_strength = get_hand_strength(hand1[0]);
  int hand2_strength  = get_hand_strength(hand2[0]);

  if (hand1_strength == hand2_strength)
  {
    int stronger_card = compare_each_card(hand1[0], hand2[0]);

    if (stronger_card == 1)
      return false;
    else if (stronger_card == 2)
      return true;
    else if (stronger_card == 0)
    {
      std::cout << "WARNING! SOMETHING WENT WRONG WITH THE CARD COMPARISON." << '\n';
      return false;
    }
  }

  return (hand1_strength<hand2_strength);
  
}

int compare_each_card(const std::string& hand1,const std::string& hand2)
{
  for (int i=0; i<hand1.size(); i++)
  {
    int value1 = get_card_value(hand1[i]);
    int value2 = get_card_value(hand2[i]);

    if (value1>value2)
      return 1;
    else if (value2>value1)
      return 2;
  }

  return 0;
}

int get_card_value(const char& card)
{
  if (isdigit(card))
  {
    int value = card - '0';
    return value;
  }

  if( card == 'T')
    return 10;
  else if (card == 'J')
    return 1;
  else if (card == 'Q')
    return 11;
  else if (card == 'K')
    return 12;
  else if (card == 'A')
    return 13;

  return 0;
}

int get_hand_strength(const std::string& hand)
{
  /* std::string hand_type = ""; */
  int hand_strength = 0;

  std::vector<int> card_counts;

  int jack_count = 0;
  for (int i = 0; i<hand.size(); i++)
  {
    int current_card_count = 0;
    bool check_next = true;

    if(hand[i] == 'J')
      jack_count++;

    for (int x = 0; x<hand.size(); x++)
    {

      if(hand[i] == hand[x] && x < i)
        check_next = false;

      if(hand[i] == 'J')
      {
        check_next = false;
      }
        

      if(hand[i] == hand[x] && check_next)
      {
        if(x != i)
          current_card_count++;
      }
      else if (hand[x] == 'J' && check_next)
      {
        if(x != i)
          current_card_count++;
      }
    }

    card_counts.push_back(current_card_count);

  }

  std::cout << hand << '\n';
  std::cout << "Jacks: " << jack_count << '\n';
  for (int i : card_counts)
  {
    std::cout << i << " ";
  }
  std::cout << '\n';

  std::sort(card_counts.begin(), card_counts.end());

  int max_count = card_counts[4];
  int second_max_count = card_counts[3];

  if(max_count == 4)
  {
    hand_strength = 7;
  }
  else if (max_count == 3)
  {
    hand_strength = 6;
  }
  else if (max_count == 2)
  {
    if (jack_count == 1 && second_max_count == 2)
      hand_strength = 5;
    else if (jack_count == 1 && second_max_count == 1)
      hand_strength = 4;
    else if (jack_count == 2 && second_max_count == 2)
      hand_strength = 4;
    else if (jack_count == 0 && second_max_count == 1)
      hand_strength = 5;
    else if (jack_count == 0 && second_max_count == 0)
      hand_strength = 4;
  }
  else if (max_count == 1)
  {
    if(jack_count == 0 && second_max_count == 1)
      hand_strength = 3;
    else if (jack_count == 0 && second_max_count == 0)
      hand_strength = 2;
    else if (jack_count == 1 && second_max_count == 1)
      hand_strength = 2;
  }
  else if (max_count == 0)
  {
    hand_strength = 1;
  }

  if (jack_count == 5)
    hand_strength = 7;

  return hand_strength;
}

std::vector<std::vector<std::string>> split_hands_and_bids(const std::vector<std::string>& data)
{
  std::vector<std::vector<std::string>> split_data;

  for (std::string s : data)
  {
    std::vector<std::string> temp_data = split_string(s, " ");

    std::vector<std::string> hand_data;

    hand_data.push_back(temp_data[0]);
    hand_data.push_back(temp_data[1]);

    split_data.push_back(hand_data);
  }

  return split_data;
}
