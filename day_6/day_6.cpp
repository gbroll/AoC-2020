#include <iostream>
#include <algorithm>
#include "../utils/AOC_UTILS_FILEREADER.hpp"

std::vector<std::string> parse_input(std::vector<std::string> input){

    std::string group = "";
    std::vector<std::string> parsed_input;

    for (int i = 0; i<input.size(); i++){

        if (input[i] != ""){
            group.append(input[i]);
        } else {
            //an empty row was read
            if (group != ""){
                parsed_input.push_back(group);
                group = "";
            }
        } 

    }


    
    return parsed_input;
}

std::vector<std::vector<std::string>> parse_input_part2(std::vector<std::string> input){

    std::vector<std::string> group_answers;
    std::vector<std::vector<std::string>> parsed_input;

    for (int i = 0; i<input.size(); i++){

        if (input[i] != ""){
            group_answers.push_back(input[i]);
        } else {
            //an empty row was read
            if (group_answers.size() > 0){
                parsed_input.push_back(group_answers);
                group_answers.clear();
            }
        } 

    }

    return parsed_input;

}

int solve_part1(std::vector<std::string> group_answers){

    std::string vec, unique;
    int count = 0;

    int n_unique;
    for (int i = 0; i < group_answers.size(); i++){
        
        vec = group_answers[i];
        
        //sorting vec
        sort(vec.begin(), vec.end());

        //extracting unique values, "last" is the index(?) of the last unique elemnent
        auto last = std::unique(vec.begin(), vec.end());
        vec.erase(last,vec.end());

        count += vec.size();

    }

    return count;

}

int solve_part2(std::vector<std::vector<std::string>> group_answers){

    std::vector<std::string> group;
    std::string isect, isect_new,string1, string2;

    size_t count = 0;

    for (size_t ix = 0; ix < group_answers.size(); ix++)
    {
        group = group_answers[ix];

        if (group.size() > 1){
            
            for (size_t inv_ix = 1; inv_ix < group.size(); inv_ix++){
                isect_new = "";

                if (inv_ix == 1){
                    string1 = group[0];
                } else {
                    string1 = isect;
                }
                
                std::sort(string1.begin(),string1.end());
                
                string2 = group[inv_ix];
                std::sort(string2.begin(),string2.end());

                //get the intersection of the sorted string vectors
                std::set_intersection(string1.begin(), string1.end(), string2.begin(), string2.end(),std::back_inserter(isect_new));
                isect = isect_new;
            }

        } else {
            isect = group[0];
        }

        count += isect.size();

    }
    
    return count;

}

int main(){

    std::string filename = "day_6_input.txt";
    std::vector<std::string> input = read_input_text(filename);
    
    std::vector<std::string> parsed_input = parse_input(input);
    int count = solve_part1(parsed_input);
    
    std::vector<std::vector<std::string>> parsed_input_part2 = parse_input_part2(input);
    size_t count2 = solve_part2(parsed_input_part2);

    std::cout << count << std::endl;
    std::cout << count2 << std::endl;


}