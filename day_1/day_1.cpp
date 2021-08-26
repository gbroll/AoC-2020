
#include <iostream>
#include <vector>
#include "../utils/AOC_UTILS_FILEREADER.hpp"

int day_1_solver(std::vector<int> input, int targetSum, int &firstIndex, int &secondIndex){

    for (firstIndex; firstIndex < input.size(); firstIndex++){

            for (secondIndex = firstIndex + 1; secondIndex < input.size(); secondIndex ++){

                if ((input[firstIndex] + input[secondIndex]) == targetSum){

                    std::cout << input[firstIndex] << " " << input[secondIndex] << std::endl;

                    return input[firstIndex] * input[secondIndex];

                }

            }

    }

    return -1;
}

int day_1_part2_solver(std::vector<int> input, int &firstIndex, int &secondIndex, int &thirdIndex){

    for (thirdIndex = 0; thirdIndex < input.size(); thirdIndex ++){
        
        firstIndex = thirdIndex + 1;

        int result = day_1_solver(input, 2020 - input[thirdIndex], firstIndex, secondIndex);

        if (result > 0){

            return result * input[thirdIndex];

        }

    }

    return -1;
    
}

int main(){

    std::cout << "This is the main program" << std::endl;

    std::string filename = "day_1_input.txt";
    std::vector<int> input = read_input_text(filename);

    //std::cout << input[0] << "\n" << input[1] << std::endl;

    //part 1
    int firstIndex = 0;
    int secondIndex = 0;
    int result;
    result = day_1_solver(input, 2020, firstIndex, secondIndex);
    
    std::cout << "========== Part 1 ==========" << std::endl;
    std::cout << firstIndex << " " << secondIndex << std::endl;
    std::cout << result << std::endl;

    //part 2
    firstIndex = 0;
    secondIndex = 0;
    int thirdIndex = 0;

    result = day_1_part2_solver(input, firstIndex, secondIndex, thirdIndex);
    std::cout << "========== Part 2 ==========" << std::endl;
    std::cout << firstIndex << " " << secondIndex << " " << thirdIndex << std::endl;
    std::cout << result << std::endl;

}