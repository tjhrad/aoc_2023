// Advent of Code 2023 Day 5: Part 2

#include "day5_2.h"

int main()
{
  std::string input_file_path = "./data/input.txt";

  std::vector<std::string> input_file_data = read_text_file(input_file_path);

  std::vector<std::vector<std::string>> split_data = split_file_data(input_file_data);

  std::string seeds_string = split_data[0][0];

  std::vector<std::vector<long long>> seed_ranges = get_seed_ranges(seeds_string);

  split_data.erase(split_data.begin());

  std::vector<std::vector<std::vector<long long>>> conversion_maps = get_maps_as_vectors(split_data);

  long long int smallest_location = get_smallest_location_reverse(seed_ranges,conversion_maps);
  
  auto result = smallest_location;
  std::cout << result << std::endl;

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

std::vector<std::vector<long long>> get_seed_ranges(const std::string& data)
{
  std::vector<std::string> temp = split_string(data,":");
  std::vector<std::string> seeds_as_strings = split_string(temp[1]," ");
  std::vector<long long int> temporary_seeds = strings_to_long_long_int(seeds_as_strings);

  std::vector<std::vector<long long>> seed_ranges;
  for (int x=0; x<temporary_seeds.size(); x += 2)
  {
    long long starting_seed_number = temporary_seeds[x];
    long long starting_seed_range = temporary_seeds[x+1];
    long long maximum_seed_number = starting_seed_number + starting_seed_range;
    std::vector<long long> range;

    range.push_back(starting_seed_number);
    range.push_back(maximum_seed_number);
    seed_ranges.push_back(range);
  }
  return seed_ranges;
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

long long int get_smallest_location_reverse(const std::vector<std::vector<long long>>& seed_ranges, const std::vector<std::vector<std::vector<long long>>>& maps)
{
  long long int soil = 0;
  long long int fertilizer = 0;
  long long int water = 0;
  long long int light = 0;
  long long int temperature = 0;
  long long int humidity = 0;
  long long int seed = 0;

  long long int smallest_location=0;

  long long max_location = get_max_from_map(maps[6]);

  for (long long current_location = 0; current_location <= max_location; current_location++)
  {
    humidity = get_value_from_map_reverse(current_location, maps[6]);
    temperature = get_value_from_map_reverse(humidity, maps[5]);
    light = get_value_from_map_reverse(temperature, maps[4]);
    water = get_value_from_map_reverse(light, maps[3]);
    fertilizer = get_value_from_map_reverse(water, maps[2]);
    soil = get_value_from_map_reverse(fertilizer, maps[1]);
    seed = get_value_from_map_reverse(soil, maps[0]);

    for (std::vector<long long> range : seed_ranges)
    {
      if( seed >= range[0] && seed <= range[1] )
      {
        return current_location;
      }
    }
  }

  std::cout << "No best location found :( " << std::endl;

  return smallest_location;
}

long long get_max_from_map(const std::vector<std::vector<long long>>& map)
{
  long long maximum = 0;

  for (std::vector<long long> v: map)
  {
    long long max_of_range = v[0]+v[2];
    if (max_of_range)
    {
      maximum = max_of_range;
    }
  }

  return maximum;
}

long long int get_value_from_map_reverse(long long int k,const std::vector<std::vector<long long>>& m)
{
  long long int value = k;

  for(std::vector<long long> v : m)
  {
    if(k >= v[0] && k < (v[0]+v[2]))
    {
      long long int difference = k-v[0];
      value = v[1] + difference;
    }
  }
  return value;
}