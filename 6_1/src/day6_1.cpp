// Advent of Code 2023 Day 6: Part 1

#include "day6_1.h"

int main()
{
  std::string input_file_path = "./data/input.txt";

  std::vector<std::string> input_file_data = read_text_file(input_file_path);

  std::vector<std::string> split_time_string = split_string(input_file_data[0],":");
  std::vector<std::string> split_distance_string = split_string(input_file_data[1],":");

  std::vector<int> times = get_integers_from_string(split_time_string[1]);
  std::vector<int> distances = get_integers_from_string(split_distance_string[1]);

  std::vector<std::vector<int>> best_possible_distances = get_best_possible_distances(times,distances);
  
  auto result = calculate_result(best_possible_distances);
  
  std::cout << result << '\n';

  return 0;
}

int calculate_result(const std::vector<std::vector<int>>& best_possible_distances)
{
  std::vector<int> all_counts;

  for (std::vector<int> race : best_possible_distances)
  {
    int count = 0;
    for (int i : race)
    {
      count++;
    }
    all_counts.push_back(count);
  }

  int result = 1;
  for (int count : all_counts)
  {
    result = result * count;
  }

  return result;
}

std::vector<std::vector<int>> get_best_possible_distances(const std::vector<int>& times, const std::vector<int>& distances)
{
  std::vector<std::vector<int>> best_distances;

  for (int i = 0; i < times.size(); i++)
  {
    std::vector<int> temporary_distances;
    for (int x = 1; x < times[i]; x++)
    {
      int distance = x*(times[i]-x);
      if (distance > distances[i])
        temporary_distances.push_back(distance);
    }
    best_distances.push_back(temporary_distances);
  }

  return best_distances;
}