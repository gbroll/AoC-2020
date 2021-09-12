#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include "../utils/AOC_UTILS_FILEREADER.hpp"

struct boarding_pass {

    int row;
    int column;
    int seatId;

}; 

std::vector<boarding_pass> parse_input(std::vector<std::string> input){

    std::vector<boarding_pass> output;
    boarding_pass bpass;

    int row;
    int column;
    std::string rowInput;
    std::string columnInput;

    std::string test;

    for (int i = 0; i < input.size(); i++){
        
        test = input[i];

        //row
        rowInput = test.substr(0,7);
        std::replace(rowInput.begin(), rowInput.end(), 'F', '0');
        std::replace(rowInput.begin(), rowInput.end(), 'B', '1');

        //column
        columnInput = test.substr(7,10);
        std::replace(columnInput.begin(), columnInput.end(), 'L', '0');
        std::replace(columnInput.begin(), columnInput.end(), 'R', '1');
        
        //store in output vector
        bpass.row = stoi(rowInput,0,2);
        bpass.column = stoi(columnInput,0,2);
        bpass.seatId = bpass.row * 8 + bpass.column;
        output.push_back(bpass);

    }

    return output;

}

long solve_part1(std::vector<boarding_pass> seats){

    long SeatID_high = 0;


    for (int i = 0; i < seats.size(); i++){
        if (seats[i].seatId > SeatID_high){
            SeatID_high = seats[i].seatId;
        }
    }

    return SeatID_high;
}

int solve_part2(std::vector<boarding_pass> seats){

    std::vector<long> seatIDs;
    int result;

    for (int i = 0; i < seats.size(); i++){
        seatIDs.push_back(seats[i].seatId);  
    }

    //sort it
    sort(seatIDs.begin(), seatIDs.end());
    for (int i = 0; i < seats.size(); i++){
        if((seatIDs[i+1]-seatIDs[i])==2){
            return (seatIDs[i] + 1) ;
        }  
    }

    return 0;
}

int main() {
    
    std::string filename = "day_5_input.txt";
    std::vector<std::string> input = read_input_text(filename, true);
    std::vector<boarding_pass> seats = parse_input(input);

    int part1_result = solve_part1(seats);
    std::cout << part1_result << std::endl;

    int part2_result = solve_part2(seats);
    std::cout << part2_result << std::endl;
}