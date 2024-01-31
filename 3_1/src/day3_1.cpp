// Advent of Code 2023 Day 1: Part 1

#include "day3_1.h"

int main()
{
  std::string file_name = "./data/input.txt";
  std::vector<std::string> file_data = read_text_file(file_name);

  std::vector<std::vector<char>> file_data_as_chars = strings_to_chars(file_data);
  std::vector<std::vector<int>> symbols_binary_matrix = chars_to_binary_matrix(file_data_as_chars);
  std::vector<std::vector<int>> codes_matrix = get_codes_matrix(file_data_as_chars);
  std::vector<std::vector<std::vector<int>>> separated_code_matrices = split_code_matrices(codes_matrix);
  std::vector<int> valid_codes = get_valid_codes(separated_code_matrices, symbols_binary_matrix);

  for (int code : valid_codes)
  {
    std::cout << code << "\n";
  }

  int result = sum_integers(valid_codes);

  std::cout << result << "\n";

  return 0;
}

//TODO: Currently the code does not account for 0s in codes such as -- 101... Refactor the algo to account for this.

std::vector<int> get_valid_codes(std::vector<std::vector<std::vector<int>>> code_matrices, std::vector<std::vector<int>> binary_symbols)
{
  std::vector<int> valid_codes;
  
  for (std::vector<std::vector<int>> code_matrix : code_matrices)
  {
    std::vector<std::vector<int>> temporary_binary_map;
    std::vector<std::vector<int>> product_matrix;
    int code;

    temporary_binary_map = code_matrix_to_binary_map(code_matrix);

    for (std::vector<int> v : temporary_binary_map)
    {
      for (int i : v)
      {
        std::cout << i;
      }
      std::cout << "\n";
    }
    std::cout << "\n";

    code = get_code(code_matrix);
    product_matrix = multiply_2d_vectors(binary_symbols, temporary_binary_map); 


    int sum = 0;
    for (std::vector<int> v : product_matrix)
    {
      for (int i : v)
      {
        sum += i;
      }
    }
    if (sum > 0)
    {
      valid_codes.push_back(code);
    }
  }

  return valid_codes;
}

int get_code(std::vector<std::vector<int>> code_matrix)
{
  int code;
  std::string code_string = "";

  for (std::vector v : code_matrix)
  {
    for (int i : v)
    {
      if (i > 0)
      {
        code_string += std::to_string(i);
      }
    }
  }

  code = std::stoi(code_string);

  return code;
}

std::vector<std::vector<int>> code_matrix_to_binary_map(std::vector<std::vector<int>> code_matrix)
{
  std::vector<std::vector<int>> binary_matrix;
  std::vector<int> stored_y_indices;
  std::vector<int> stored_x_indices;
  int max_y = code_matrix.size();
  int max_x = code_matrix[0].size();

  for ( int y=0; y<code_matrix.size(); y++ )
  {
    std::vector<int> temporary_result;
    for ( int x=0; x<code_matrix[y].size(); x++ )
    {
      if (code_matrix[y][x] == 0)
      {
        temporary_result.push_back(0);
      }
      else 
      {
        temporary_result.push_back(1);
        stored_y_indices.push_back(y);
        stored_x_indices.push_back(x);
      }
    }
    binary_matrix.push_back(temporary_result);
  }

  for ( int i=0; i<stored_y_indices.size(); i++ )
  {
    int x = stored_x_indices[i];
    int y = stored_y_indices[i];

    if (x > 0)
    {
      binary_matrix[y][x-1] = 1;
      if(y > 0)
      {
        binary_matrix[y-1][x-1] = 1;
      }
      if(y < max_y - 1)
      {
        binary_matrix[y+1][x-1] = 1;
      }
    }
    
    if (y > 0)
    {
      binary_matrix[y-1][x] = 1;

      if (x < max_x - 1)
      {
        binary_matrix[y-1][x+1] = 1;
      }
    }

    if (x < max_x - 1)
    {
      binary_matrix[y][x+1] = 1;
      if (y < max_y - 1)
      {
        binary_matrix[y+1][x+1] = 1;
      }
    }

    if (y < max_y - 1)
    {
      binary_matrix[y+1][x] = 1;
    }

   
  }

  return binary_matrix;
}

std::vector<std::vector<std::vector<int>>> split_code_matrices(std::vector<std::vector<int>> codes_matrix)
{
  std::vector<std::vector<std::vector<int>>> split_matrices;
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

    }
    codes_matrix = subtract_2d_vectors(codes_matrix, temporary_matrix);
    split_matrices.push_back(temporary_matrix);


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

