// Problem Statement :
// There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities. 
// The cost of the edge can be the time that flight takes to reach city B from A, or the amount of fuel used for the journey. Represent 
// this as a graph. The node can be represented by airport name or name of the city. Use adjacency list representation of the graph or 
// use adjacency matrix representation of the graph. Justify the storage representation used.

#include<iostream>
#include<vector>
using namespace std;

#define MAX_CITIES 10

class FlightGraph {
    private: 
        int distanceMatrix[MAX_CITIES][MAX_CITIES];
        vector<string> cityNames;
        int totalCities;

    public:
        FlightGraph(){
            totalCities = 0;

            for(int i = 0; i< MAX_CITIES; i++){
                for(int j =0; j< MAX_CITIES; j++){
                    distanceMatrix[i][j] = 0;
                }
            }
        }

        int addCity(const string& cityName){
            for(int i = 0; i< totalCities; i++){
                if(cityNames[i] == cityName){
                    return i;
                }
            }

            if(totalCities < MAX_CITIES){
                cityNames.push_back(cityName);
                return totalCities++;
            }
            return -1;
        }

        void createGraph(){
            string sourceCity;
            string destCity;
            int distance;
            char choice;

            do{
                cout << "\nEnter Source City: ";
                cin >> sourceCity;
                cout << "Enter Destination City: ";
                cin >> destCity;

                int sourceIndex = addCity(sourceCity);
                int destIndex = addCity(destCity);

                if(sourceIndex == -1 || destIndex == -1) {
                    cout << "Maximum number of cities reached!" << endl;
                    return;
                }

                cout << "Enter Distance (in km) between " << sourceCity << " and " << destCity << ": ";
                cin >> distance;

                distanceMatrix[sourceIndex][destIndex] = distance;
                distanceMatrix[destIndex][sourceIndex] = distance;

                cout << "\nDo you want to add more connections? (y/n): ";
                cin >> choice;
            }while(choice == 'y' || choice == 'Y');
        }

        void displayGraph(){
            if(totalCities == 0) {
                cout << "\nNo cities added to the graph yet!" << endl;
                return;
            }

            cout << "\nFlight Distance Matrix (in km):" << endl;
            cout << "--------------------------------" << endl;

            cout << "\t";
            for(int i = 0; i < totalCities; i++) {
                cout << cityNames[i] << "\t";
            }
            cout << endl;

            for(int i = 0; i < totalCities; i++){
                cout << cityNames[i] << "\t";
                for(int j = 0; j < totalCities; j++){
                    cout << distanceMatrix[i][j] << "\t";
                }
                cout << endl;
            }

        }
};

int main() {
    cout << "========== FLIGHT ROUTE GRAPH ==========" << endl;
    cout << "This program creates a graph of flight routes between cities" << endl;
    cout << "and displays the distance matrix between them." << endl;

    FlightGraph flightGraph;
    int choice;
    char continueChoice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add flight routes" << endl;
        cout << "2. Display distance matrix" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                flightGraph.createGraph();
                break;
            case 2:
                flightGraph.displayGraph();
                break;
            case 3:
                cout << "Thank you for using the program!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> continueChoice;
    } while(continueChoice == 'y' || continueChoice == 'Y');

    return 0;
}

// ========== FLIGHT ROUTE GRAPH ==========
// This program creates a graph of flight routes between cities
// and displays the distance matrix between them.

// Menu:
// 1. Add flight routes
// 2. Display distance matrix
// 3. Exit
// Enter your choice: 1

// Enter Source City: pune  
// Enter Destination City: mumbai
// Enter Distance (in km) between pune and mumbai: 120

// Do you want to add more connections? (y/n): y

// Enter Source City: pune
// Enter Destination City: delhi
// Enter Distance (in km) between pune and delhi: 1200

// Do you want to add more connections? (y/n): n

// Do you want to continue? (y/n): y

// Menu:
// 1. Add flight routes
// 2. Display distance matrix
// 3. Exit
// Enter your choice: 2

// Flight Distance Matrix (in km):
// --------------------------------
//         pune    mumbai  delhi
// pune    0       120     1200
// mumbai  120     0       0
// delhi   1200    0       0

// Do you want to continue? (y/n): y

// Menu:
// 1. Add flight routes
// 2. Display distance matrix
// 3. Exit
// Enter your choice: 3
// Thank you for using the program!