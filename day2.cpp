#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;
int processing();
int processing_2();
int process_line(std::vector<int>);
int process_again(std::vector<int>,int position);

int main() { 
    std::cout << processing_2() << std::endl;
    return 0;
}

int processing(){
    std::string fileName = "input.txt";
    std::ifstream file(fileName);
    std::string line;
    std::string word;
    int sum = 0;
    int first,actual,comp ;
    bool safe;
    bool increase;
    bool actual_increase;
    bool assigned;
    while (std::getline(file, line)) {
        safe = true;
        assigned = false;
        first = actual = comp = NULL;
        std::istringstream iss(line);
        while (iss >> word) {
            if(first == NULL){
                first = (stoi(word));
            } else {
                actual = (stoi(word));
                comp = actual - first;
                actual_increase = (comp > 0)? true : false;
                if(assigned == false){
                    assigned = true;
                    increase = actual_increase;
                }
                first = actual;
                if(comp > 3 || comp < - 3 || comp == 0 || actual_increase != increase){
                    safe = false;
                    break;
                }
            }
        }
        if(safe){
            cout << line << endl;
            sum++;
        }
    }
    return sum;
}


int processing_2(){
    std::string fileName = "input.txt";
    std::ifstream file(fileName);
    std::string line;
    std::string word;
    int sum = 0;
    int first,actual,comp ;
    bool safe;
    bool increase;
    bool actual_increase;
    bool assigned;
    while (std::getline(file, line)) {
        std::vector<int> col1; 
        std::istringstream iss(line);
        while (iss >> word) {
            col1.push_back(stoi(word));
        }
        sum += process_line(col1);
    }
    

    return sum;
}

int process_line(std::vector<int> line){
    int first,actual,comp ;
    bool safe;
    bool increase;
    bool actual_increase;
    bool assigned = false;
    for(int i = 0; i<line.size(); i++){
        if(i == 0){
            first = line[i];
        } else {
            actual = line[i];
            comp = actual - first;
            actual_increase = (comp > 0)? true : false;
            if(assigned == false){
                assigned = true;
                increase = actual_increase;
            }
            first = actual;
            if(comp > 3 || comp < - 3 || comp == 0 || actual_increase != increase){
                for(int j = 0; j< line.size(); j++){
                   if(process_again(line,j) == 1){
                    return 1;
                   }
                }
                return 0;
            } 
        }
    }
    return 1;
}

int process_again(std::vector<int> line, int position){
    line.erase(line.begin()+ position);
    int first,actual,comp ;
    bool safe;
    bool increase;
    bool actual_increase;
    bool assigned = false;
    for(int i = 0; i<line.size(); i++){
        if(i == 0){
            first = line[i];
        } else {
            actual = line[i];
            comp = actual - first;
            actual_increase = (comp > 0)? true : false;
            if(assigned == false){
                assigned = true;
                increase = actual_increase;
            }
            first = actual;
            if(comp > 3 || comp < - 3 || comp == 0 || actual_increase != increase){
                return 0;
            } 
        }
    }
    return 1;
}