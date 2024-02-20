// Advent of Code 2023 Day 6: Part 2

#include "day6_2.h"

int main()
{
  std::string input_file_path = "./data/input.txt";

  std::vector<std::string> input_file_data = read_text_file(input_file_path);

  std::vector<std::string> split_time_string = split_string(input_file_data[0],":");
  std::vector<std::string> split_distance_string = split_string(input_file_data[1],":");

  long long time = combine_integers_in_string(split_time_string[1]);
  long long distance = combine_integers_in_string(split_distance_string[1]);

  std::vector<long long> best_possible_distances = get_best_possible_distances(time,distance);
  
  auto result = calculate_result(best_possible_distances);
  
  std::cout << result << '\n';

  return 0;
}

int calculate_result(const std::vector<long long>& best_possible_distances)
{
  int count = 0;
  for (long long race : best_possible_distances)
  {
    count++;
  }
  
  return count;
}

std::vector<long long> get_best_possible_distances(const long long& time, const long long& distance)
{
  std::vector<long long> best_distances;

  for (long long x = 1; x < time; x++)
  {
    long long d = x*(time-x);
    if (d > distance)
      best_distances.push_back(d);
  }

  return best_distances;
}