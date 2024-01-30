// Advent of Code 2023 Day 1: Part 1

#include "day3_1.h"

int main()
{
  std::string file_name = "./data/test.txt";
  std::vector<std::string> file_data = read_text_file(file_name);

  std::vector<std::vector<char>> file_data_as_chars = strings_to_chars(file_data);
  std::vector<std::vector<int>> symbols_binary_matrix = chars_to_binary_matrix(file_data_as_chars);
  std::vector<std::vector<int>> codes_matrix = get_codes_matrix(file_data_as_chars);
  std::vector<std::vector<std::vector<int>>> separated_code_matrices = split_code_matrices(codes_matrix);



  //std::vector<int> get_valid_codes(file_data_as_chars, symbols_binary_matrix);

  for (std::vector<std::vector<int>> v : separated_code_matrices)
  {
    for(std::vector<int> v2 : v)
    {
      for (int i : v2)
      {
        std::cout << i;

      }
      std::cout << "\n";
    }
    std::cout << "\n\n";
  }

  return 0;
}

std::vector<std::vector<std::vector<int>>> split_code_matrices(std::vector<std::vector<int>> codes_matrix)
{
  std::vector<std::vector<std::vector<int>>> split_matrices;
  //int current_code;
  //std::string current_code_as_string = "";
  bool is_done = false;
  
  while(!is_done)
  {
    bool is_building_code = false;
    bool has_built_code = false;

    std::vector<std::vector<int>> temporary_matrix;

    for(std::vector<int> v : codes_matrix)
    {
      std::vector<int> temporary_vector;
      for(int i : v)
      {
        if (i != 0)
        {
          if(!is_building_code && !has_built_code)
          {
            is_building_code = true;
            temporary_vector.push_back(i);
          }
          else if (is_building_code)
          {
            temporary_vector.push_back(i);
          }
          else if (has_built_code)
          {
            temporary_vector.push_back(0);
          }
        }
        else if (i == 0)
        {
          if(is_building_code)
          {
            is_building_code = false;
            has_built_code = true;
          }
          temporary_vector.push_back(i);
        }
      }

      temporary_matrix.push_back(temporary_vector);
      /* split_matrices.push_back(temporary_matrix); */
      /* for(std::vector<int> v : temporary_matrix) */
      /* { */
      /*   for (int i : v) */
      /*   { */
      /*     std::cout << i; */
      /*   } */
      /*   std::cout << "\n\n"; */
      /* } */
      /* codes_matrix = subtract_2d_vectors(codes_matrix, temporary_matrix); */

    }
    codes_matrix = subtract_2d_vectors(codes_matrix, temporary_matrix);
    split_matrices.push_back(temporary_matrix);

    /* for(std::vector<int> v : codes_matrix) */
    /*   { */
    /*     for (int i : v) */
    /*     { */
    /*       std::cout << i; */
    /*     } */
    /*     std::cout << "\n\n"; */
    /*   } */

    int sum = 0;
    for(std::vector<int> v : codes_matrix)
    {
      for (int i : v)
      {
        sum += i;
      }
    }

    if(sum ==  0)
    {
      is_done = true;
    }
  }

  return split_matrices;

}


std::vector<std::vector<int>> get_codes_matrix(std::vector<std::vector<char>> char_matrix)
{
  std::vector<std::vector<int>> codes_matrix;

  for (std::vector v : char_matrix)
  {
    std::vector<int> int_vector;
    for (char c : v)
    {
      if ( isdigit(c) )
      {
        std::string s(1,c);
        int_vector.push_back(stoi(s));
      }
      else 
      {
        int_vector.push_back(0);
      }
    }
   codes_matrix.push_back(int_vector);
  }

  return codes_matrix;

}

/* std::vector<int> get_valid_codes(std::vector<int> codes_matrix, std::vector<int> symbols_binary_matrix) */
/* { */
/**/
/* } */

std::vector<std::vector<char>> strings_to_chars(std::vector<std::string> strings)
{
  std::vector<std::vector<char>> converted_chars;

  for (std::string s : strings)
  {
    std::vector<char> characters( s.begin(), s.end() );
    converted_chars.push_back(characters);
  }

  return converted_chars;
}

std::vector<std::vector<int>> chars_to_binary_matrix(std::vector<std::vector<char>> char_matrix)
{
  std::vector<std::vector<int>> binary_matrix;

  for (std::vector v : char_matrix)
  {
    std::vector<int> binary_vector;
    for (char c : v)
    {
      if (isalpha(c) || isdigit(c) || c == '.')
      {
        binary_vector.push_back(0);
      }
      else 
      {
        binary_vector.push_back(1);
      }
    }
    binary_matrix.push_back(binary_vector);
  }

  return binary_matrix;
}

