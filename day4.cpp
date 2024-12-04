#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;
int processing();
int check_line(vector <string> lines, int positionV);
int check_line_2(vector <string> lines, int positionV);
int check_verticale_line(vector <string> lines, int positionV, int positionH);
int check_horizontale_line(vector <string> lines, int positionV, int positionH);
int check_diagonale_line(vector <string> lines, int positionV, int positionH);
int check_diagonale_line_2(vector <string> lines, int positionV, int positionH);

int main() { 
    std::cout << processing() << std::endl;
    return 0;
}

int processing(){
    std::string fileName = "input.txt";
    vector <string> lines;
    string line;    
    ifstream fin(fileName);
    int sum = 0;
    while(getline(fin,line)){
        lines.push_back(line);
    }
    for (int i = 0; i < lines.size(); i++) {
            sum+=check_line_2(lines, i);

        }
    return sum;
}

int check_line(vector <string> lines, int positionV){
    int num = 0;
    string line = lines[positionV];
    for(int i = 0; i < line.length(); i++){
        if(line[i] == 'X'){
            num+= check_horizontale_line(lines, positionV,i);
            num+= check_verticale_line(lines, positionV,i);
            num+= check_diagonale_line(lines, positionV,i);
        }
    }
    return num;
}

int check_line_2(vector <string> lines, int positionV){
    int num = 0;
    string line = lines[positionV];
    for(int i = 0; i < line.length(); i++){
        if(line[i] == 'A'){
            num+= check_diagonale_line_2(lines, positionV,i);
        }
    }
    return num;
}

int check_verticale_line(vector <string> lines, int positionV, int positionH){
    int num = 0;
    string line = lines[positionV];
    if(positionV + 3 < lines.size()){
            if(lines[positionV+1][positionH] == 'M' && lines[positionV+2][positionH] == 'A' && lines[positionV+3][positionH] == 'S'){
                num ++;
            }  
        }
        if(positionV - 3 >= 0){
            if(lines[positionV-1][positionH] == 'M' && lines[positionV-2][positionH] == 'A' && lines[positionV-3][positionH] == 'S') {
                num ++;
            }
    }
    return num;
}

int check_diagonale_line(vector <string> lines, int positionV, int positionH){
    int num = 0;
    string line = lines[positionV];
    if(positionV + 3 < lines.size()){
            if(positionH + 3 < line.length()){
                if(lines[positionV+1][positionH+1] == 'M' && lines[positionV+2][positionH+2] == 'A' && lines[positionV+3][positionH+3] == 'S'){
                    num ++;
                }  
            }
            if(positionH - 3 >= 0){
                if(lines[positionV+1][positionH-1] == 'M' && lines[positionV+2][positionH-2] == 'A' && lines[positionV+3][positionH-3] == 'S'){
                    num ++;
                }  
            }
        }
    if(positionV - 3 >= 0){
            if(positionH + 3 < line.length()){
                if(lines[positionV-1][positionH+1] == 'M' && lines[positionV-2][positionH+2] == 'A' && lines[positionV-3][positionH+3] == 'S'){
                    num ++;
                }  
            }
            if(positionH - 3 >= 0){
                if(lines[positionV-1][positionH-1] == 'M' && lines[positionV-2][positionH-2] == 'A' && lines[positionV-3][positionH-3] == 'S'){
                    num ++;
                }  
            }
        }
    return num;
}
    

int check_horizontale_line(vector <string> lines, int positionV, int positionH){
    int num = 0;
    string line = lines[positionV];
    if(positionH + 3 < line.length()){
            if(line[positionH+1] == 'M' && line[positionH+2] == 'A' && line[positionH+3] == 'S'){
                num ++;
            }  
        }
        if(positionH - 3 >= 0){
            if(line[positionH-1] == 'M' && line[positionH-2] == 'A' && line[positionH-3] == 'S') {
                num ++;
            }
}
return num;
}

int check_diagonale_line_2(vector <string> lines, int positionV, int positionH){
    string line = lines[positionV];
    if(positionV + 1 < lines.size() &&  positionV - 1 >= 0 && positionH + 1 < line.length() && positionH - 1 >= 0){
        if(lines[positionV-1][positionH-1] == 'M' && lines[positionV+1][positionH+1] == 'S' 
        && lines[positionV+1][positionH-1] == 'M' && lines[positionV-1][positionH+1] == 'S'){
                return 1;
            } 
        if(lines[positionV-1][positionH+1] == 'M' && lines[positionV+1][positionH-1] == 'S' 
        && lines[positionV+1][positionH+1] == 'M' && lines[positionV-1][positionH-1] == 'S'){
                return 1;
            }
        if(lines[positionV+1][positionH-1] == 'M' && lines[positionV-1][positionH+1] == 'S' 
        && lines[positionV+1][positionH+1] == 'M' && lines[positionV-1][positionH-1] == 'S'){
                return 1;
            }
        if(lines[positionV-1][positionH-1] == 'M' && lines[positionV+1][positionH+1] == 'S' 
        && lines[positionV-1][positionH+1] == 'M' && lines[positionV+1][positionH-1] == 'S'){
                return 1;
            } 
        }    
    return 0;
}