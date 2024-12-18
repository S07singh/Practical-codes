#include <iostream>
#include <string>
using namespace std;

// Base class: publication
class publication {
protected:
    string title;
    float price;

public:
    // Default constructor
    publication() : title(""), price(0.0) {}

    // Virtual functions for data input and output
    virtual void getdata() {
        try {
            cout << "Enter title: ";
            cin.ignore(); // To handle leftover newline character
            getline(cin, title);
            
            cout << "Enter price: ";
            cin >> price;
            if (price < 0) {
                throw invalid_argument("Price cannot be negative.");
            }
        } catch (exception &e) {
            cout << "Exception: " << e.what() << endl;
            reset();
        }
    }

    virtual void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }

    // Reset function to set all members to zero/default values
    virtual void reset() {
        title = "";
        price = 0.0;
    }
};

// Derived class: book
class book : public publication {
private:
    int page_count;

public:
    // Default constructor
    book() : publication(), page_count(0) {}

    // Override getdata()
    void getdata() override {
        try {
            publication::getdata(); // Call base class getdata
            cout << "Enter page count: ";
            cin >> page_count;
            if (page_count < 0) {
                throw invalid_argument("Page count cannot be negative.");
            }
        } catch (exception &e) {
            cout << "Exception: " << e.what() << endl;
            reset();
        }
    }

    // Override putdata()
    void putdata() const override {
        publication::putdata(); // Call base class putdata
        cout << "Page Count: " << page_count << endl;
    }

    // Override reset
    void reset() override {
        publication::reset(); // Reset base class members
        page_count = 0;
    }
};

// Derived class: tape
class tape : public publication {
private:
    float play_time;

public:
    // Default constructor
    tape() : publication(), play_time(0.0) {}

    // Override getdata()
    void getdata() override {
        try {
            publication::getdata(); // Call base class getdata
            cout << "Enter playing time (in minutes): ";
            cin >> play_time;
            if (play_time < 0) {
                throw invalid_argument("Playing time cannot be negative.");
            }
        } catch (exception &e) {
            cout << "Exception: " << e.what() << endl;
            reset();
        }
    }

    // Override putdata()
    void putdata() const override {
        publication::putdata(); // Call base class putdata
        cout << "Playing Time: " << play_time << " minutes" << endl;
    }

    // Override reset
    void reset() override {
        publication::reset(); // Reset base class members
        play_time = 0.0;
    }
};

int main() {
    char choice;
    do {
        cout << "Enter data for a (b)ook or a (t)ape (or (q)uit): ";
        cin >> choice;

        if (choice == 'b' || choice == 'B') {
            book book;
            book.getdata();
            cout << "\nData for the book:" <<endl;
            book.putdata();
        } else if (choice == 't' || choice == 'T') {
            tape tape;
            tape.getdata();
            cout << "\nData for the tape:" <<endl;
            tape.putdata();
        } else if (choice == 'q' || choice == 'Q') {
            break;
        } else {
            cout << "Invalid choice, please enter 'b' for book, 't' for tape, or 'q' to quit." << std::endl;
        }

    cout << "\nDo you want to enter another publication? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
