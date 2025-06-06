/*
Aim: Imagine a publishing company which does marketing for book and audio cassette versions. 
Create a class publication that stores the title (a string) and price (type float) of publications. 
From this class derive two classes: book which adds a page count (type int) and tape which adds a playing time in minutes (type float).
Write a program that instantiates the book and tape class, allows user to enter data and displays the data members. 
If an exception is caught, replace all the data member values with zero values.
*/

#include <iostream>
using namespace std;

class publication {
protected:
    string title;
    float price;

public:
    publication() : title(""), price(0.0) {}

    publication(string t, float p) : title(t), price(p) {}

    virtual void display() const = 0; // Make display a pure virtual function
};

class book : public publication {
private:
    int pages;

public:
    book() : publication(), pages(0) {}

    book(string t, int p, float pr) : publication(t, pr) {
        if (p > 0 && pr > 0.0) {
            pages = p;
        } else {
            pages = 0; // Default value for invalid input
            price = 0.0; // Default value for invalid price
        }
    }

    void display() const override {
        cout << "Book | " << title << " | " << price << " | " << pages << " pages" << endl;
    }
};

class tape : public publication {
private:
    float mins;

public:
    tape() : publication(), mins(0.0) {}

    tape(string t, float p, float pr) : publication(t, pr) {
        if (p > 0 && pr > 0.0) {
            mins = p;
        } else {
            mins = 0.0; // Default value for invalid input
            price = 0.0; // Default value for invalid price
        }
    }

    void display() const override {
        cout << "Tape | " << title << " | " << price << " | " << mins << " minutes" << endl;
    }
};

int main() {
    string title, t;
    int pages;
    float price, mins, pr;

    cout << "Enter Book Details : Title | Pages | Price" << endl;
    cin >> title >> pages >> price;

    cout << "Enter Tape Details : Title | Minutes | Price" << endl;
    cin >> t >> mins >> pr;

    book b;
    tape t1;

    try {
        b = book(title, pages, price);
        t1 = tape(t, mins, pr);
    } catch (...) {
        b.display();
        t1.display();
        b = book("", 0, 0);
        t1 = tape("", 0, 0);
    }

    b.display();
    t1.display();

    return 0;
}

