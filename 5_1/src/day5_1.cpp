// Advent of Code 2023 Day 4: Part 2

#include "day5_1.h"

int main()
{
  std::string input_file_path = "./data/input.txt";

  std::vector<std::string> input_file_data = read_text_file(input_file_path);

  std::vector<std::vector<std::string>> split_data = split_file_data(input_file_data);

  //TODO: the seed numbers are too big?? I think Throwing out of range error.
  std::string seeds_string = split_data[0][0];

  /* for (std::vector<std::string> v : split_data)
  {
    for (std::string s : v)
    {
      std::cout << s << std::endl;
    }
    std::cout << std::endl;
  } */
  std::vector<int> seeds = get_seeds(seeds_string);

  split_data.erase(split_data.begin());

  std::vector<std::map<int,int>> conversion_maps = get_maps(split_data);

  std::vector<int> locations = get_locations(seeds,conversion_maps);

  /* for(std::map<int,int> m : conversion_maps)
  {
    std::map<int, int>::iterator it = m.begin();
    while (it != m.end()) 
    {
        std::cout << "Key: " << it->first<< ", Value: " << it->second << std::endl;
        ++it;
    }
  } */
  
  auto result = std::min_element(std::begin(locations), std::end(locations));//sum_integers(card_copies);
  if (std::end(locations)!=result)
        std::cout << *result << '\n';

/*   int result = 0;
  std::cout << "Result: " << result << "\n"; */

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

std::vector<int> get_seeds(const std::string& data)
{
  std::cout << "HERE" << std::endl;
  std::vector<std::string> temp = split_string(data,":");
  std::cout << "HERE" << std::endl;
  std::vector<std::string> seeds_as_strings = split_string(temp[1]," ");
  std::cout << "HERE" << std::endl;
  std::vector<int> seeds_as_integers = strings_to_integers(seeds_as_strings);
  std::cout << "HERE" << std::endl;
  return seeds_as_integers;
}

std::vector<std::map<int,int>> get_maps(const std::vector<std::vector<std::string>>& data)
{
  std::vector<std::map<int,int>> maps;

  for (std::vector<std::string> v : data)
  {
    std::map<int,int> temporary_map = create_map(v);
    maps.push_back(temporary_map);
  }

  return maps;
}

std::map<int,int> create_map(const std::vector<std::string>& data)
{
  std::map<int,int> data_map;

  for (std::string s : data)
  {
    std::vector<std::string> raw_values = split_string(s, " ");
    std::vector<int> raw_as_integers = strings_to_integers(raw_values);

    int b = raw_as_integers[0];
    for (int a=raw_as_integers[1]; a<(raw_as_integers[1]+raw_as_integers[2]); a++)
    {
      data_map.insert({a,b});

      b++;
    }
  }

  return data_map;
}

std::vector<int> get_locations(const std::vector<int>& seeds, const std::vector<std::map<int,int>>& maps)
{
  int soil = 0;
  int fertilizer = 0;
  int water = 0;
  int light = 0;
  int temperature = 0;
  int humidity = 0;
  int location = 0;

  std::vector<int> locations;

  for (int seed : seeds)
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

int get_value_from_map(int k,std::map<int,int> m)
{
  int value = k;
  if(m.count(k))
  {
    value = m[k];
  }

  return value;
}

//create_map

//get_seed_numbers

//int convert_number(input_value, map)

//seed_to_soil
//soil_to_fertilizer
//fertilizer_to_water
//water_to_light
//light_to_temperature
//temperature_to_humidity
//humidity_to_location

//TODO: Add a function in aoc_tools to find the lowest number.