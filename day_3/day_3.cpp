#include <iostream>
#include <numeric>
#include "../utils/AOC_UTILS_FILEREADER.hpp"

int countTrees(const std::vector<std::string> input, const int row_increment, const int column_increment){

    const char tree = '#';

    //get the pattern period (number of characters)
    int period = input[0].length();
    int position = 0;

    //calculate row and/or position increments


    //loop through the rows and count the number of trees. First coordinate to check should be (1,3)
    int nTrees = 0;
    for (int row = row_increment; row < input.size(); row+=row_increment){
        position = (position + column_increment) % period;
        
        if (input[row][position] == '#'){
            nTrees++;
            //std::cout << "Tree at row " << row << ", position " << position << std::endl;
        }
    }

    return nTrees;

}

int main(){

    std::string filename = "day_3_input.txt";
    std::vector<std::string> input;
    input = read_input_text(filename);
    
    int row_increment, column_increment;

    //Part 1
    row_increment = 1;
    column_increment = 3;
    int part1_nTrees = countTrees(input,row_increment, column_increment);
    std::cout << "Part 1, Number of trees encountered: " << part1_nTrees << std::endl;
    
    //Part 2
    std::vector<int> part2_nTrees;
    std::vector<int> row_increments = {1,1,1,1,2};
    std::vector<int> column_increments = {1,3,5,7,1};

    for (int i = 0; i<row_increments.size();i++){
        part2_nTrees.push_back(countTrees(input,row_increments[i],column_increments[i]));
    }

    //multiply
    long result = std::accumulate(part2_nTrees.begin(), part2_nTrees.end(),long(1),std::multiplies<long>());
    std::cout << "Part 2, Product: " << result << std::endl;


    
   

    

}