// Company maintains employee information as employee ID,name, designation and salary. 
// Allow user to add, delete information of employee. Display information of particular employee. 
// If employee does not exist an appropriate message is displayed. If it is, then the system displays the employee details. 
// Use index sequential file to maintain the data.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Structure to store employee information
struct Employee {
    int id;
    string name;
    string designation;
    double salary;
};

// Structure for index entries
struct IndexEntry {
    int id;
    int position;
};

class EmployeeManagementSystem {
private:
    string dataFile = "employees.dat";
    string indexFile = "employees.idx";
    vector<IndexEntry> indexTable;

    // Load index from file
    void loadIndex() {
        indexTable.clear();
        ifstream inFile(indexFile, ios::binary);
        if (!inFile) {
            return; // No index file exists yet
        }

        IndexEntry entry;
        while (inFile.read(reinterpret_cast<char*>(&entry), sizeof(IndexEntry))) {
            indexTable.push_back(entry);
        }
        inFile.close();
    }

    // Save index to file
    void saveIndex() {
        ofstream outFile(indexFile, ios::binary);
        for (const auto& entry : indexTable) {
            outFile.write(reinterpret_cast<const char*>(&entry), sizeof(IndexEntry));
        }
        outFile.close();
    }

    // Sort index by employee ID
    void sortIndex() {
        sort(indexTable.begin(), indexTable.end(), 
            [](const IndexEntry& a, const IndexEntry& b) {
                return a.id < b.id;
            });
    }

    // Find position of an employee in the data file using binary search
    int findEmployeePosition(int id) {
        int left = 0;
        int right = indexTable.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (indexTable[mid].id == id) {
                return indexTable[mid].position;
            }
            
            if (indexTable[mid].id < id) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1; // Employee not found
    }

public:
    EmployeeManagementSystem() {
        loadIndex();
    }

    // Add a new employee
    void addEmployee(const Employee& emp) {
        // Check if employee with same ID already exists
        if (findEmployeePosition(emp.id) != -1) {
            cout << "Employee with ID " << emp.id << " already exists." << endl;
            return;
        }

        // Open data file in append mode
        ofstream dataOut(dataFile, ios::binary | ios::app);
        if (!dataOut) {
            cout << "Error opening data file." << endl;
            return;
        }

        // Get current position in file
        int position = dataOut.tellp();

        // Write employee data to file
        dataOut.write(reinterpret_cast<const char*>(&emp), sizeof(Employee));
        dataOut.close();

        // Add to index
        IndexEntry indexEntry = {emp.id, position};
        indexTable.push_back(indexEntry);
        
        // Sort and save index
        sortIndex();
        saveIndex();

        cout << "Employee added successfully." << endl;
    }

    // Delete an employee
    void deleteEmployee(int id) {
        int pos = findEmployeePosition(id);
        if (pos == -1) {
            cout << "Employee with ID " << id << " not found." << endl;
            return;
        }

        // Remove from index
        auto it = remove_if(indexTable.begin(), indexTable.end(),
            [id](const IndexEntry& entry) {
                return entry.id == id;
            });
        indexTable.erase(it, indexTable.end());

        // Save updated index
        saveIndex();

        cout << "Employee deleted successfully." << endl;
    }

    // Display employee information
    void displayEmployee(int id) {
        int pos = findEmployeePosition(id);
        if (pos == -1) {
            cout << "Employee with ID " << id << " not found." << endl;
            return;
        }

        // Open data file
        ifstream dataIn(dataFile, ios::binary);
        if (!dataIn) {
            cout << "Error opening data file." << endl;
            return;
        }

        // Go to employee position
        dataIn.seekg(pos);

        // Read employee data
        Employee emp;
        dataIn.read(reinterpret_cast<char*>(&emp), sizeof(Employee));
        dataIn.close();

        // Display employee information
        cout << "\n======== Employee Details ========" << endl;
        cout << "ID: " << emp.id << endl;
        cout << "Name: " << emp.name << endl;
        cout << "Designation: " << emp.designation << endl;
        cout << "Salary: $" << fixed << setprecision(2) << emp.salary << endl;
        cout << "=================================" << endl;
    }

    // Display all employees (additional utility function)
    void displayAllEmployees() {
        if (indexTable.empty()) {
            cout << "No employees found." << endl;
            return;
        }

        cout << "\n========== All Employees ==========\n" << endl;
        cout << left << setw(5) << "ID" << setw(20) << "Name" << setw(20) << "Designation" 
             << right << setw(10) << "Salary" << endl;
        cout << string(55, '-') << endl;

        ifstream dataIn(dataFile, ios::binary);
        if (!dataIn) {
            cout << "Error opening data file." << endl;
            return;
        }

        for (const auto& entry : indexTable) {
            // Go to employee position
            dataIn.seekg(entry.position);

            // Read employee data
            Employee emp;
            dataIn.read(reinterpret_cast<char*>(&emp), sizeof(Employee));

            // Display employee information
            cout << left << setw(5) << emp.id << setw(20) << emp.name << setw(20) << emp.designation 
                 << right << setw(10) << fixed << setprecision(2) << emp.salary << endl;
        }
        dataIn.close();
        cout << "\n=================================" << endl;
    }
};

// Function to get input from user
Employee getEmployeeDetails() {
    Employee emp;
    cout << "Enter Employee ID: ";
    cin >> emp.id;
    cin.ignore(); // Clear newline from input buffer
    
    cout << "Enter Name: ";
    getline(cin, emp.name);
    
    cout << "Enter Designation: ";
    getline(cin, emp.designation);
    
    cout << "Enter Salary: ";
    cin >> emp.salary;
    
    return emp;
}

int main() {
    EmployeeManagementSystem ems;
    int choice, id;

    while (true) {
        cout << "\n===== Employee Management System =====\n" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Display Employee" << endl;
        cout << "4. Display All Employees" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Employee emp = getEmployeeDetails();
                ems.addEmployee(emp);
                break;
            }
            case 2:
                cout << "Enter Employee ID to delete: ";
                cin >> id;
                ems.deleteEmployee(id);
                break;
            case 3:
                cout << "Enter Employee ID to display: ";
                cin >> id;
                ems.displayEmployee(id);
                break;
            case 4:
                ems.displayAllEmployees();
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}