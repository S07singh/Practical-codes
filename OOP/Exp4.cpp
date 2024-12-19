// Aim: Write a C++ program that creates an output file, writes information to it, 
// closes the file and opens it again as an input file and reads the information from the file.

#include <iostream>
#include <fstream> // For fstream
#include <string>
using namespace std;

int main() {
    fstream file;             // fstream object for both input and output
    // string filename = "example.txt";
    string dataToWrite = "This is a sample text written using fstream.";
    string dataRead;

    //     // Step 1: Take data input from the user
    // cout << "Enter the data to write to the file: ";
    // getline(cin, dataToWrite); // Take input from the user

    // Step 1: Open the file in output mode and write data
    file.open("example.txt", ios::out); // Open file in write mode
    if (!file) {
        cerr << "Error: Unable to open file for writing." << endl;
        return 1;
    }

    file << dataToWrite; // Write data to the file
    cout << "Data written to the file successfully." << endl;

    file.close(); // Close the file after writing

    // Step 2: Open the file in input mode and read data
    file.open("example.txt", ios::in); // Open file in read mode
    if (!file) {
        cerr << "Error: Unable to open file for reading." << endl;
        return 1;
    }

    getline(file, dataRead); // Read the data from the file
    cout << "Data read from the file: " << dataRead << endl;

    file.close(); // Close the file after reading

    return 0;
}
