// Advent of Code 2023 Day 3: Part 2

#include "day3_1.h"

int main()
{
  std::string file_name = "./data/input.txt";
  std::vector<std::string> file_data = read_text_file(file_name);

  std::vector<std::vector<char>> file_data_as_chars = strings_to_chars(file_data);
  std::vector<std::vector<char>> asterisk_matrix = get_asterisk_matrix(file_data_as_chars);
  std::vector<std::vector<char>> codes_matrix = get_codes_matrix(file_data_as_chars);
  
  std::vector<std::vector<std::vector<char>>> separated_code_matrices = split_matrix(codes_matrix);
  std::vector<std::vector<std::vector<char>>> separated_asterisk_matrices = split_matrix(asterisk_matrix);
  
  std::vector<int> gear_ratios = get_gear_ratios(separated_code_matrices, separated_asterisk_matrices);



  int result = sum_integers(gear_ratios);

  std::cout << result << "\n";

  return 0;
}


std::vector<int> get_gear_ratios(std::vector<std::vector<std::vector<char>>> code_matrices, std::vector<std::vector<std::vector<char>>> asterisk_matrices)
{
  std::vector<int> gear_ratios;
  
  //for (std::vector<std::vector<char>> asterisk_matrix : asterisk_matrices)
  for (int index=0; index<asterisk_matrices.size(); index++)
  {
    std::vector<std::vector<int>> temporary_binary_map;
    std::vector<std::vector<int>> product_matrix;
    int code;
    std::vector<int> temporary_codes;


    temporary_binary_map = code_matrix_to_binary_map(asterisk_matrices[index]);

    for (std::vector<std::vector<char>> code_matrix : code_matrices)
    {
      //std::vector<int> temporary_codes;
      code = get_code(code_matrix);
      std::vector<std::vector<int>> code_matrix_binary = char_matrix_to_binary(code_matrix);

      product_matrix = multiply_2d_vectors(code_matrix_binary, temporary_binary_map);


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
        temporary_codes.push_back(code);
      }
      if(temporary_codes.size() > 2)
      {
        break;
      }
    }
    if(temporary_codes.size() == 2)
    {
      int ratio = temporary_codes[0]*temporary_codes[1];
      gear_ratios.push_back(ratio);
      temporary_codes.clear();
    }
    
  }
  ///

  return gear_ratios;
}

int get_code(std::vector<std::vector<char>> code_matrix)
{
  int code;
  std::string code_string = "";

  for (std::vector<char> v : code_matrix)
  {
    for (char i : v)
    {
      if (isdigit(i))
      {
        code_string += i;
        //code_string += std::to_string(i);
      }
    }
  }

  code = std::stoi(code_string);

  return code;
}

std::vector<std::vector<int>> char_matrix_to_binary(std::vector<std::vector<char>> char_matrix)
{
  std::vector<std::vector<int>> temporary_binary_matrix;

  for(std::vector<char> v : char_matrix)
  {
    std::vector<int> temporary_binary_vector;
    for (char c : v)
    {
      if (isdigit(c))
      {
        temporary_binary_vector.push_back(1);
      }
      else 
      {
        temporary_binary_vector.push_back(0);
      }
    }
    temporary_binary_matrix.push_back(temporary_binary_vector);
  }
  return temporary_binary_matrix;
}

std::vector<std::vector<int>> code_matrix_to_binary_map(std::vector<std::vector<char>> code_matrix)
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
      if (code_matrix[y][x] == '.')
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

std::vector<std::vector<std::vector<char>>> split_matrix(std::vector<std::vector<char>> codes_matrix)
{
  std::vector<std::vector<std::vector<char>>> split_matrices;
  bool is_done = false;
  
  while(!is_done)
  {
    bool is_building_code = false;
    bool has_built_code = false;

    std::vector<std::vector<char>> temporary_matrix;

    //for(std::vector<char> v : codes_matrix)
    for(int x = 0; x<codes_matrix.size(); x++)
    {
      std::vector<char> temporary_vector;
      //for(char i : v)
      if(is_building_code)
      {
        has_built_code = true;
        is_building_code = false;
      }
      for (int i = 0; i<codes_matrix[x].size(); i++)
      {
        //if (isdigit(i))
        if(isdigit(codes_matrix[x][i]))
        {
          if(!is_building_code && !has_built_code)
          {
            is_building_code = true;
            temporary_vector.push_back(codes_matrix[x][i]);
            codes_matrix[x][i] = '.';
          }
          else if (is_building_code)
          {
            temporary_vector.push_back(codes_matrix[x][i]);
            codes_matrix[x][i] = '.';
          }
          else if (has_built_code)
          {
            temporary_vector.push_back('.');
          }
        }
        else if (codes_matrix[x][i] == '.')
        {
          if(is_building_code)
          {
            is_building_code = false;
            has_built_code = true;
          }
          temporary_vector.push_back(codes_matrix[x][i]);
        }
      }

      temporary_matrix.push_back(temporary_vector);

    }
    //codes_matrix = subtract_2d_vectors(codes_matrix, temporary_matrix);
    split_matrices.push_back(temporary_matrix);

    bool has_digit = false;
    for(int x = 0; x<codes_matrix.size(); x++)
    {
      for (int i = 0; i<codes_matrix[x].size(); i++)
      {
        if(isdigit(codes_matrix[x][i]))
        {
          has_digit = true;
        }
      }
    }


    if(!has_digit)
    {
      is_done = true;
    }
}

  return split_matrices;

}

std::vector<std::vector<char>> get_codes_matrix(std::vector<std::vector<char>> char_matrix)
{
  std::vector<std::vector<char>> codes_matrix;

  for (std::vector v : char_matrix)
  {
    std::vector<char> char_vector;
    for (char c : v)
    {
      if ( isdigit(c) )
      {
        //std::string s(1,c);
        char_vector.push_back(c);
      }
      else 
      {
        char_vector.push_back('.');
      }
    }
  codes_matrix.push_back(char_vector);
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

std::vector<std::vector<char>> get_asterisk_matrix(std::vector<std::vector<char>> char_matrix)
{
  std::vector<std::vector<char>> binary_matrix;

  for (std::vector v : char_matrix)
  {
    std::vector<char> binary_vector;
    for (char c : v)
    {
      if (c == '*')// (isalpha(c) || isdigit(c) || c == '.')
      {
        binary_vector.push_back('1');
      }
      else 
      {
        binary_vector.push_back('.');
      }
    }
    binary_matrix.push_back(binary_vector);
  }

  return binary_matrix;
}

