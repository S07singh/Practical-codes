#include <iostream>
#include <cstring> // Include this for strcpy
using namespace std;

class person_additional_info {
    char address[20], license[20], insurance[20];
    long int contact;

public:
    person_additional_info() // Default constructor
    {
        strcpy(address, "XYZ");
        strcpy(license, "XY-0000000000");
        strcpy(insurance, "XY00000000X");
        contact = 0000000000; // Fixed initialization
    }

    ~person_additional_info() // Destructor
    {
        cout << "I am in Destructor of person_additional_info" << endl;
    }

    friend class person; // Declaration of friend class
};

// Definition of friend class
class person {
    char name[20], dob[10], blood[10];
    float ht, wt;
    static int count; // Static variable
    person_additional_info *pai;

public:
    person() // Default constructor
    {
        strcpy(name, "XYZ");
        strcpy(dob, "dd/mm/yy");
        strcpy(blood, "A+");
        ht = 0;
        wt = 0;
        pai = new person_additional_info;
    }

    person(const person &p1) // Copy constructor
    {
        strcpy(name, p1.name);
        strcpy(dob, p1.dob);
        strcpy(blood, p1.blood);
        ht = p1.ht;
        wt = p1.wt;
        pai = new person_additional_info;
        strcpy(pai->address, p1.pai->address);
        strcpy(pai->license, p1.pai->license);
        strcpy(pai->insurance, p1.pai->insurance);
        pai->contact = p1.pai->contact;
    }

    static void showcount() // Static member function
    {
        cout << "\nNo of records count = " << count << "\n";
    }

    ~person() // Destructor
    {
        cout << "\nI am in Destructor of person" << endl;
        delete pai; // Ensure we delete the dynamically allocated person_additional_info
    }

    void getdata(const char name[20]); // Function declaration
    inline void display(); // Inline function declaration
};

void person::getdata(const char name[20]) {
    strcpy(this->name, name); // this pointer
    cout << "\nEnter date of birth: ";
    cin >> dob;
    cout << "\nEnter blood group: ";
    cin >> blood;
    cout << "\nEnter height: ";
    cin >> ht;
    cout << "\nEnter weight: ";
    cin >> wt;
    cout << "\nEnter address: ";
    cin.ignore(); // To clear the newline character left by previous input
    cin.getline(pai->address, 20); // Use getline for string input
    cout << "\nEnter License number: ";
    cin >> pai->license;
    cout << "\nEnter Insurance policy number: ";
    cin >> pai->insurance;
    cout << "\nEnter Contact number: ";
    cin >> pai->contact;
    count++;
}

// Inline function definition
void person::display() {
    cout << "\t" << name;
    cout << "\t" << dob;
    cout << "\t" << blood;
    cout << "\t" << ht;
    cout << "\t" << wt;
    cout << "\t" << pai->address;
    cout << "\t" << pai->license;
    cout << "\t" << pai->insurance;
    cout << "\t" << pai->contact << endl;
}

int person::count; // Static variable definition

int main() {
    person *p1, *p2;
    int ch;
    p1 = new person; // Call default constructor & dynamic memory allocation
    p2 = new person(*p1); // Call copy constructor

    cout << "\tName";
    cout << "\tDob";
    cout << "\tBlood";
    cout << "\tHt";
    cout << "\tWt";
    cout << "\tAddress";
    cout << "\tLicense";
    cout << "\tInsurance";
    cout << "\tContact" << endl;

    cout << "Default Constructor Value: \n";
    p1->display();
    
    cout << "Copy Constructor Value: \n";
    p2->display();

    int n;
    cout << "\nEnter how many records you want: ";
    cin >> n;

    person *p3 = new person[n]; // Dynamically allocate array of objects
    char name[20];
    int x = 0;

    do {
        cout << "\nWelcome to Personal Database System";
        cout << "\n1. Enter the record";
        cout << "\n2. Display the record";
        cout << "\n3. Exit";
        cin >> ch;

        switch (ch) {
        case 1:
            if (x < n) {
                cout << "\nEnter the Name: ";
                cin >> name;
                p3[x].getdata(name);
                person::showcount(); // Calls static function
                x++;
            } else {
                cout << "Record limit reached." << endl;
            }
            break;

        case 2:
            cout << "\tName";
            cout << "\tDob";
            cout << "\tBlood";
            cout << "\tHt";
            cout << "\tWt";
            cout << "\tAddress";
            cout << "\tLicense";
            cout << "\tInsurance";
            cout << "\tContact" << endl;
            for (int i = 0; i < x; i++) {
                p3[i].display(); // Calls inline function
            }
            break;

        case 3:
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
        cout << endl;
    } while (ch != 3);

    delete p1; // Dynamic memory de-allocation
    delete p2;
    delete[] p3; // Delete the array of objects
    return 0;
}

