// Advent of Code 2023 Day 5: Part 2

#include "day5_2.h"

int main()
{
  std::string input_file_path = "./data/input.txt";

  std::vector<std::string> input_file_data = read_text_file(input_file_path);

  std::vector<std::vector<std::string>> split_data = split_file_data(input_file_data);

  std::string seeds_string = split_data[0][0];

  std::vector<long long int> seeds = get_seeds(seeds_string);

  split_data.erase(split_data.begin());

  std::vector<std::vector<std::vector<long long>>> conversion_maps = get_maps_as_vectors(split_data);

  std::vector<long long int> locations = get_all_locations(seeds,conversion_maps);
  
  auto result = std::min_element(std::begin(locations), std::end(locations));//sum_integers(card_copies);
  if (std::end(locations)!=result)
        std::cout << *result << '\n';

  return 0;
}

std::vector<std::vector<std::string>> split_file_data(const std::vector<std::string>& data)
{
  std::vector<std::vector<std::string>> split_data;
  std::vector<std::string> temporary_data;

  bool is_building_map = false;
  bool is_done_building_map = false;

  for (std::string s : data)
  {
    if (s.find("seeds:") != std::string::npos && !is_building_map)
    {
      temporary_data.push_back(s);
    }
    else if (s.find("map:") != std::string::npos && !is_building_map)
    {
      is_building_map = true;
      is_done_building_map = false;
    }
    else if (s.size() < 1)
    {
      is_building_map = false;
      is_done_building_map = true;
    }
    else
    {
      temporary_data.push_back(s);
    }

    if(!is_building_map && is_done_building_map)
    {
      split_data.push_back(temporary_data);
      temporary_data.clear();
      is_done_building_map = false;
    }
    
  }
  split_data.push_back(temporary_data);

  return split_data;
}

std::vector<long long int> get_seeds(const std::string& data)
{
  std::vector<std::string> temp = split_string(data,":");
  std::vector<std::string> seeds_as_strings = split_string(temp[1]," ");
  std::vector<long long int> temporary_seeds = strings_to_long_long_int(seeds_as_strings);

  std::vector<long long int> seeds_as_integers;
  for (int x=0; x<temporary_seeds.size(); x += 2)
  {
    long long starting_seed_number = temporary_seeds[x];
    long long starting_seed_range = temporary_seeds[x+1];
    for (long long i=starting_seed_number; i<(starting_seed_number+starting_seed_range); i++)
    {
      seeds_as_integers.push_back(i);
    }

  }

  return seeds_as_integers;
}

std::vector<std::vector<std::vector<long long>>> get_maps_as_vectors(const std::vector<std::vector<std::string>>& data)
{
  std::vector<std::vector<std::vector<long long>>> maps;

  for (std::vector<std::string> v : data)
  {
    std::vector<std::vector<long long>> temporary_vector;
    for(std::string s : v)
    {
      std::vector<std::string> values_as_strings = split_string(s," ");
      std::vector<long long> temporary_map_long_longs = strings_to_long_long_int(values_as_strings);
      temporary_vector.push_back(temporary_map_long_longs);
    }
    maps.push_back(temporary_vector);
  }

  return maps;
}

std::vector<long long int> get_all_locations(const std::vector<long long int>& seeds, const std::vector<std::vector<std::vector<long long>>>& maps)
{
  long long int soil = 0;
  long long int fertilizer = 0;
  long long int water = 0;
  long long int light = 0;
  long long int temperature = 0;
  long long int humidity = 0;
  long long int location = 0;

  std::vector<long long int> locations;

  for (long long int seed : seeds)
  {
    soil = get_value_from_map(seed, maps[0]);
    fertilizer = get_value_from_map(soil, maps[1]);
    water = get_value_from_map(fertilizer, maps[2]);
    light = get_value_from_map(water, maps[3]);
    temperature = get_value_from_map(light, maps[4]);
    humidity = get_value_from_map(temperature, maps[5]);
    location = get_value_from_map(humidity, maps[6]);

    locations.push_back(location);
  }

  return locations;
}

long long int get_value_from_map(long long int k,const std::vector<std::vector<long long>>& m)
{
  long long int value = k;

  for(std::vector<long long> v : m)
  {
    if(k >= v[1] && k <= (v[1]+v[2]))
    {
      long long int difference = k-v[1];
      value = v[0] + difference;
    }
  }
  return value;
}