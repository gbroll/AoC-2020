
#include <iostream>
#include <vector>
#include <fstream>

 
std::vector<int> read_input_text_as_int(const std::string filename){

  
    std::cout << "Reading " << filename << std::endl;

    std::vector<int> result;
    std::string stringIn;

    std::ifstream file(filename);

    if (file.is_open()){
        
        while (!file.eof()){

            std::getline(file,stringIn);
            //std::cout << stringIn << std::endl;
            if (!stringIn.empty()){
                    result.push_back(stoi(stringIn));
                }
        }
        file.close();

    } else {

        std::cout << "Unable to open file." << std::endl;

    }

    return result;

}


std::vector<std::string> read_input_text(const std::string filename){

    std::cout << "Reading " << filename << std::endl;

    std::vector<std::string> result;
    std::string stringIn;

    std::ifstream file(filename);

    if (file.is_open()){
        
        while (!file.eof()){

            std::getline(file,stringIn);
            //std::cout << stringIn << std::endl;
            if (!stringIn.empty()){
                    result.push_back(stringIn);
                }
        }
        file.close();

    } else {

        std::cout << "Unable to open file." << std::endl;

    }

    return result;



}