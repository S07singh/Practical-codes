// Aim: Write a C++ program using STL for sorting and searching user-defined 
// records such as Item records (Item code, name, cost, quantity, etc.) 
// using vector container.

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Item {
public:
    int code;
    string name;
    float cost;
    int quantity;

    // Default constructor
    Item() : code(0), name(""), cost(0.0), quantity(0) {}

    // Method to input data
    void getData() {
        cout << "Enter code: ";
        cin >> code;
        cin.ignore();  // To consume the newline character left in the buffer
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter cost: ";
        cin >> cost;
        cout << "Enter quantity: ";
        cin >> quantity;
    }

    // Method to display item details
    void display() const {
        cout << "Code: " << code
             << ", Name: " << name
             << ", Cost: " << cost
             << ", Quantity: " << quantity << endl;
    }
};

// Function to display all items in the vector
void displayItems(const vector<Item>& items) {
    for (const auto& item : items) {
        item.display();
    }
}

// Comparison function to sort by item code
bool compareByCode(const Item& item1, const Item& item2) {
    return item1.code < item2.code;
}

// Comparison function to sort by item cost
bool compareByCost(const Item& item1, const Item& item2) {
    return item1.cost < item2.cost;
}

// Function to sort items by code
void sortItemsByCode(vector<Item>& items) {
    sort(items.begin(), items.end(), compareByCode);
}

// Function to sort items by cost
void sortItemsByCost(vector<Item>& items) {
    sort(items.begin(), items.end(), compareByCost);
}

// Function to search for an item by code
Item* search(vector<Item>& items, int code) {
    for (auto& item : items) {
        if (item.code == code) {
            return &item;
        }
    }
    return nullptr;
}

int main() {
    vector<Item> items;
    int n;

    // Get the number of items to store
    cout << "Enter the number of items to store: ";
    cin >> n;

    // Input item data
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for item " << i + 1 << ":\n";
        Item item;
        item.getData();
        items.push_back(item);
    }

    // Display all entered items
    cout << "Items entered: " << endl;
    displayItems(items);

    // Search for an item by code
    int searchCode;
    cout << "\nEnter the code of the item to search for: ";
    cin >> searchCode;

    Item* foundItem = search(items, searchCode);
    if (foundItem) {
        cout << "\nItem found:\n";
        foundItem->display();
    } else {
        cout << "\nItem with code " << searchCode << " not found.\n";
    }

    // Choose sorting option
    int choice;
    cout << "\nChoose sorting option:\n1. Sort by Code\n2. Sort by Cost\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        sortItemsByCode(items);  // Sort by code
        cout << "\nItems sorted by Code:\n";
        displayItems(items);
    } else if (choice == 2) {
        sortItemsByCost(items);  // Sort by cost
        cout << "\nItems sorted by Cost:\n";
        displayItems(items);
    } else {
        cout << "\nInvalid choice. No sorting performed.\n";
    }

    return 0;
}
