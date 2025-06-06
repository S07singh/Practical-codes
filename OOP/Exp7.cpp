// Aim: Write a program in C++ to use map associative container. 
// The keys will be the names of states and the values will be the populations of the states. 
// When the program runs, the user is prompted to type the name of a state. 
// The program then looks in the map, using the state name as an index and returns the population of the state.

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    typedef map<string, int> mapType;
    mapType populationMap;
    populationMap.insert(pair<string, int>("Maharashtra", 7026357));
    populationMap.insert(pair<string, int>("Rajasthan", 6578936));
    populationMap.insert(pair<string, int>("Karnataka", 6678993));
    populationMap.insert(pair<string, int>("Punjab", 5789032));
    populationMap.insert(pair<string, int>("West Bengal", 6676291));

    mapType::iterator iter;
    cout << "========Population of states in India==========\n";
    cout << "\n Size of populationMap: " << populationMap.size() << "\n";
    string state_name;
    cout << "\n Enter name of the state: ";
    cin >> state_name;
    iter = populationMap.find(state_name);
    if (iter != populationMap.end())
        cout << state_name << "'s population is " << iter->second;
    else
        cout << "Key is not in populationMap" << "\n";
    
    populationMap.clear();
    return 0;
}

/*
Input:
Enter name of the state: Maharashtra

Output:
Maharashtra's population is 7026357

Input:
Enter name of the state: Gujarat

Output:
Key is not in populationMap

*/