#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;
int absolute_value(int value);
int processing();
int processing_2();

int main() { 
    std::cout << processing_2() << std::endl;
    return 0;
}

int processing(){
    std::string fileName = "input.txt";
    std::ifstream file(fileName);
    std::string line;
    std::vector<int> col1; 
    std::vector<int> col2; 
    std::string word;
     while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::cout << line << std::endl;
        bool isWord = false;
        while (iss >> word) {
            if(!isWord){
                col1.push_back(stoi(word));
                isWord = true;
            } else {
                col2.push_back(stoi(word));
            }
        }
    }
    stable_sort(col1.begin(), col1.end());
    stable_sort(col2.begin(), col2.end());
    int sum = 0;
    for(int i = 0; i<col1.size(); i++){
        sum+=  (col2[i] - col1[i] < 0) ?  (-col2[i]  + col1[i]) : (col2[i] - col1[i]);
    }
    return sum;
}


int processing_2(){
    std::string fileName = "input.txt";
    std::ifstream file(fileName);
    std::string line;
    std::vector<int> col1; 
    std::vector<int> col2; 
    std::string word;
     while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::cout << line << std::endl;
        bool isWord = false;
        while (iss >> word) {
            if(!isWord){
                col1.push_back(stoi(word));
                isWord = true;
            } else {
                col2.push_back(stoi(word));
            }
        }
    }
    int sum = 0;
    for(int i = 0; i<col1.size(); i++){
        int occurence = 0;
        for(int j = 0; j<col2.size(); j++){
            if (col2[j] == col1[i]) occurence++;
        }
        sum += col1[i]* occurence;
    }
    return sum;
}