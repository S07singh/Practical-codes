#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;

public:
    // Constructor with default arguments
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Friend functions for input and output
    friend ostream & operator<<(ostream &out, Complex const &obj);
    friend istream & operator>>(istream &in, Complex &obj);

    // Overload the + operator
    Complex operator+(Complex const &obj) const {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }

    // Overload the * operator
    Complex operator*(Complex const &obj) const {
        Complex res;
        res.real = (real * obj.real) - (imag * obj.imag);
        res.imag = (real * obj.imag) + (imag * obj.real);
        return res;
    }
};

// Overload the << operator for output
ostream & operator<<(ostream &out, Complex const &obj) {
    out << obj.real;
    if (obj.imag >= 0) {
        out << "+i" << obj.imag;
    } else {
        out << "-i" << -obj.imag;
    }
    return out;
}

// Overload the >> operator for input
istream & operator>>(istream &in, Complex &obj) {
    cout << "\nEnter Real part: ";
    in >> obj.real;
    cout << "\nEnter Imaginary part: ";
    in >> obj.imag;
    return in;
}

int main() {
    Complex c1, c2, c3, c4;

    cout << "\nEnter First Number:";
    cin >> c1;

    cout << "\nEnter Second Number:";
    cin >> c2;

    c3 = c1 + c2;
    cout << "\nThe Addition = " << c3 << endl;

    c4 = c1 * c2;
    cout << "\nThe Multiplication = " << c4 << endl;

    cout << "\n\n";
    return 0;
}

