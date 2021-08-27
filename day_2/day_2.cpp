#include <iostream>
#include <vector>
#include <regex>

#include "../utils/AOC_UTILS_FILEREADER.hpp"

struct pw_data{
    int mn,mx;
    char chr;
    std::string password;
};

pw_data parse_input(std::string stringIn){

    pw_data pw_struct;

    //check for correctly formatted data
    //rexex string matching (1 or more digit),hyphen,(1 or more digit), space, (1 literal a-z), and (the password containing one or more literals a-z) 
    std::regex regex("([0-9]+)-([0-9]+)\\s([a-z]):\\s([a-z]+)"); 


    std::smatch matches;
    if (!std::regex_search(stringIn, matches, regex)){
        std::cout << "No match" <<std::endl;
    }



    pw_struct.mn = stoi(matches[1].str());
    pw_struct.mx = stoi(matches[2].str());
    pw_struct.chr = ((matches[3]).str())[0];
    pw_struct.password = matches[4].str();

   

    return pw_struct;

}


bool part_1_pw_is_valid(pw_data pw_struct){

    //count the number of the current character in the password
    int count;
    count = std::count(pw_struct.password.begin(),pw_struct.password.end(),pw_struct.chr);

    return (count>=pw_struct.mn && count<=pw_struct.mx);

}

bool part_2_pw_is_valid(pw_data pw_struct){

    //check characters at specified positions
    int x = pw_struct.password[pw_struct.mn-1] == pw_struct.chr;
    int y = pw_struct.password[pw_struct.mx-1] == pw_struct.chr;

    return ((x+y) == 1);

}

int main(){

    std::string filename = "day_2_input.txt";
    pw_data pw_struct;
    int n_valid_part_1_passwords = 0;
    int n_valid_part_2_passwords = 0;

    std::vector<std::string> input = read_input_text(filename);

    for (int row = 0; row < input.size(); row++){

        std::cout << input[row] << std::endl;
        pw_struct = parse_input(input[row]);

        if (part_1_pw_is_valid(pw_struct)){
            n_valid_part_1_passwords++;
        }

        if (part_2_pw_is_valid(pw_struct)){
            n_valid_part_2_passwords++;
        }


    }

    std::cout << n_valid_part_1_passwords << std::endl;
    std::cout << n_valid_part_2_passwords << std::endl;

}