#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;
int processing_1(string updates, vector <int> before_list, vector <int> after_list);
int processing_2(string updates, vector <int> before_list, vector <int> after_list);
vector <int> get_afters(int number, vector <int> before_list, vector <int> after_list);
vector <int> get_befores(int number, vector <int> before_list, vector <int> after_list);
int process_before(int pos, vector <int> afters, vector <int> update);
int process_after(int pos, vector <int> afters, vector <int> update);
vector <int> process_before_2(int pos , vector <int> afters, vector <int> update);
vector <int> process_after_2(int pos, vector <int> afters, vector <int> update);
vector<int> split (const string &s, char delim);
int processing();
const char COMA = ',';
const string SEP = "|";
const string ENDL = "\n";

int main() { 
    std::cout << processing() << std::endl;
    return 0;
}

int processing(){
    std::string fileName = "input.txt";
    vector <int> before_list;
    vector <int> after_list;
    vector <string> updates;
    string line;    
    ifstream fin(fileName);
    while(getline(fin,line)){
        if(line.find(SEP) != std::string::npos){
            before_list.push_back(stoi(line.substr(0, line.find(SEP))));
            after_list.push_back(stoi(line.substr(line.find(SEP)+1, line.find(ENDL))));
        } else {
            if(line != ""){
                updates.push_back(line);
            }
        }
    }
    int sum = 0;
    for(int i = 0; i< updates.size(); i++){
        sum += processing_2(updates[i],before_list,after_list);
    }
    return sum;
}

int processing_1(string updates, vector <int> before_list, vector <int> after_list){
    vector <int> update = split(updates, COMA);
    vector <int> befores;
    vector <int> afters;
    cout << update[0] << endl;
    for(int i = 0; i< update.size(); i++){
        int number = update[i];
        befores = get_befores(number,before_list,after_list);
        afters = get_afters(number,before_list,after_list);
        int res1 = process_before(i, afters, update);
        int res2 = process_after(i, befores, update);
        if(res1 == 0 || res2 == 0) return 0;
    }
    int res = update[(int)(update.size()/2)];
    return 0; 
}


int processing_2(string updates, vector <int> before_list, vector <int> after_list){
    vector <int> update = split(updates, COMA);
    vector <int> temp = update;
    vector <int> befores;
    vector <int> afters;
    int flag = 0;
    for(int i = 0; i< update.size(); i++){
        int number = update[i];
        befores = get_befores(number,before_list,after_list);
        afters = get_afters(number,before_list,after_list);
        temp = process_before_2(i, afters, update);
        process_after_2(i, befores, update);
        if(temp.size() != 0){
            update = temp;
            flag++;
            i = 0;
        }
    }
    if(flag == 0){
        return 0;
    }
    cout << "found !" << endl;
     for(int i = 0; i< update.size();i++){
        cout << update[i] << " ";
    }
    cout << endl;
    int res = update[(int)(update.size()/2)];
    return res; 
}

vector<int> split (const string &s, char delim) {
    vector<int> result;
    stringstream ss (s);
    string item;
    while (getline (ss, item, delim)) {
        result.push_back(stoi(item));
    }
    return result;
}

vector <int> get_befores(int number, vector <int> before_list, vector <int> after_list){
    vector <int> befores;
    for(int i = 0; i< before_list.size();i++){
        if(after_list[i] == number) befores.push_back(before_list[i]);
    }
    return befores;
}

vector <int> get_afters(int number, vector <int> before_list, vector <int> after_list){
    vector <int> afters;
    for(int i = 0; i< before_list.size();i++){
        if(before_list[i] == number) afters.push_back(after_list[i]);
    }
    return afters;
}

int process_before(int pos, vector <int> afters, vector <int> update){
    for(int i = pos - 1; i>=0; i--){
        for(int j = 0; j< afters.size(); j++){
            if(update[i] == afters[j]) return 0;
        }
    }
    return 1;
}

int process_after(int pos, vector <int> befores, vector <int> update){
    for(int i = pos + 1; i< update.size(); i++){
        for(int j = 0; j< befores.size(); j++){
            if(update[i] == befores[j]) return 0;
        }
    }
    return 1;
}

vector <int> process_before_2(int pos, vector <int> afters, vector <int> update){
    for(int i = pos - 1; i>=0; i--){
        for(int j = 0; j< afters.size(); j++){
            if(update[i] == afters[j]){
                update[i] = update[pos];
                update[pos] = afters[j];
                return update;
            }
        }
    }
    return vector <int>();
}

vector <int>  process_after_2(int pos, vector <int> befores, vector <int> update){
    for(int i = pos + 1; i<update.size(); i++){
        for(int j = 0; j< befores.size(); j++){
            if(update[i] == befores[j]){
                update[i] = update[pos];
                update[pos] = befores[j];
                return update;
            }
        }
    }
    return vector <int>();
}