#include <iostream>
using namespace std;
#include <string>

class Publication {
protected:
    string title;
    float price;
public:
    Publication() : title(""), price(0.0) {}

    virtual void getdata() {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    virtual void putdata() const {
        cout << "Title: " << title <<endl;
        cout << "Price: Rs " << price << endl;
    }
};

class Book : public Publication {
private:
    int page_count;
public:
    Book() : Publication(), page_count(0) {}

    void getdata() override {
        Publication::getdata();
        cout << "Enter page count: ";
        cin >> page_count;
    }

    void putdata() const override {
        Publication::putdata();
        cout << "Page Count: " << page_count <<endl;
    }
};

class Tape : public Publication {
private:
    float playing_time;
public:
    Tape() : Publication(), playing_time(0.0) {}

    void getdata() override {
        Publication::getdata();
        cout << "Enter playing time in minutes: ";
        cin >> playing_time;
    }

    void putdata() const override {
        Publication::putdata();
    cout << "Playing Time: " << playing_time << " minutes" <<endl;
    }
};

int main() {
    char choice;
    do {
        cout << "Enter data for a (b)ook or a (t)ape (or (q)uit): ";
        cin >> choice;

        if (choice == 'b' || choice == 'B') {
            Book book;
            book.getdata();
            cout << "\nData for the book:" <<endl;
            book.putdata();
        } else if (choice == 't' || choice == 'T') {
            Tape tape;
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
