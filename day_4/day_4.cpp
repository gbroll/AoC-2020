#include <iostream>
#include <vector>
#include <optional>
#include <regex>
#include "../utils/AOC_UTILS_FILEREADER.hpp"

/* class Passport {

public:
    //constructor
    Passport(std::string passport_data_string){

        
        int nMatches = 0;

        for (int i = 0; i < dKeys.size(); i++){
            std::regex regex("\\s" + dKeys[0] + ":[\\w]+\\s");
            std::smatch matches;
            if (!std::regex_search(passport_data_string, matches, regex)){
                //do nothing
            } else {
                nMatches++;
            }
        }
        if (nMatches == dKeys.size()){
            valid = true;
        } else {
            valid = false;
        }


    };


private:

    //fields/properties/members to be populated
    std::optional<int> birth_year, issue_year, exp_year;
    std::optional<std::string> height,hair_color, eye_color, passport_id, country_id;
    bool valid;

}; */

std::vector<std::string> parse_input(std::vector<std::string> input){

    //returns a new vector string, but one element for each passport

    std::vector<std::string> passports;      //vector with passwords to be populated
    int passport_number = 0;                 //to be incremented

    std::string passport_data_string = "";   

    for (int row = 0; row < input.size(); row++){

        if (input[row] != ""){
            passport_data_string.append(input[row]);
            passport_data_string.append(" ");
        }
        
        if (passport_data_string != ""){       
            if (input[row] == "" | row == (input.size()-1)){
                passport_number++;
                passports.push_back(passport_data_string);
                passport_data_string = "";
            }
        }
    }

    //std::cout << passports.size() << std::endl;
    return passports;
}

int validate_passports(std::vector<std::string> passports, std::vector<std::string> requiredKeys){

    //returns the number of valid passports (part 1)
    int nValidPassports = 0;
    int nMatches;
    for (int passNumber = 0; passNumber < passports.size(); passNumber++){

        nMatches = 0;

        for (int i = 0; i < requiredKeys.size(); i++){
            std::regex regex("(?:\\s|^)" + requiredKeys[i] + ":");
            std::smatch matches;
            if (!std::regex_search(passports[passNumber], matches, regex)){
                //do nothing
            } else {
                nMatches++;
                //std::cout << requiredKeys[i] << std::endl;
            }
        }
        if (nMatches == requiredKeys.size()){
            nValidPassports++;
        } 

    }

    return nValidPassports;

}

int validate_passports(std::vector<std::string> passports, std::vector<std::string> requiredKeys, std::vector<std::string> rules){

 //returns the number of valid passports (part 1)
    int nValidPassports = 0;
    int nMatches;
    for (int passNumber = 0; passNumber < passports.size(); passNumber++){

        nMatches = 0;

        for (int i = 0; i < requiredKeys.size(); i++){
            std::string regex_string = "(?:\\s|^)" + requiredKeys[i] + ":" + rules[i];

            std::regex regex(regex_string);
            std::smatch matches;
            if (!std::regex_search(passports[passNumber], matches, regex)){
                //do nothing
            } else {
                nMatches++;
                //std::cout << requiredKeys[i] << std::endl;
            }
        }
        if (nMatches == requiredKeys.size()){
            nValidPassports++;
        } 

    }

    return nValidPassports;


}

int main (){
    
    std::string filename = "day_4_input.txt";
    std::vector<std::string> input = read_input_text(filename,false);
    std::vector<std::string> passports = parse_input(input);

    //Part 1
    std::vector<std::string> required_keys = {"byr","iyr","eyr","hgt","hcl","ecl","pid"};
    int nValidPasswords = validate_passports(passports, required_keys);
    std::cout << passports.size() << std::endl;
    std::cout << nValidPasswords << std::endl;

    //Part 2
    //add regex rules for checking intervals etc;
    std::vector<std::string> rules = {
        "(?:19[2-9][0-9]|200[0-2])",                                //byr
        "(?:201[0-9]|2020)",                                        //iyr
        "(?:202[0-9]|2030)",                                        //eyr
        "(?:1[5-8][0-9]cm|19[0-3]cm|59in|6[0-9]in|7[0-6]in)",       //hgt
        "#(?:[a-f0-9]{6})",                                         //hcl
        "(?:amb|blu|brn|gry|grn|hzl|oth)",                          //ecl
        "(?:[0-9]{9}\\s)"                                           //pid
    };

    int nValidPasswords_2 = validate_passports(passports, required_keys,rules);
    std::cout << nValidPasswords_2 << std::endl;
}