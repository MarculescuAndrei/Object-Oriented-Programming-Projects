#pragma once
#include "Information.h"
#include<stdlib.h>
#include<string.h>
#include <iostream>
using namespace std;

class ComplexNr : public Information {

    private:
        int a;
        int b;
        // Complex Number = a+bi;

    public:

        ComplexNr():Information(){}
        ComplexNr(int a, int b){ // Basic Constructor
            this->a = a;
            this->b = b;
        }
        ComplexNr(ComplexNr &n){ // Copy Constructor
            this->a = n.a;
            this->b = n.b;
        }
        ~ComplexNr(){}; // Default Destructor

        // Operator overloading :
        friend ComplexNr operator += (ComplexNr &N1, ComplexNr const &N2);
        friend istream& operator >> (istream& in,  ComplexNr &N);
        friend ostream& operator << (ostream& out, const ComplexNr &N);
        friend bool operator == (ComplexNr const N1, ComplexNr const N2);

        // Class Specific Methods :
        int getA() const;
        int getB() const;
        void setA(int X);
        void setB(int X);

        void Addition(ComplexNr &N){
            this->a = this->a + N.getA();
            this->b = this->b + N.getB();
        }

        void secondaryDisplay(){
            if (this->getB() > 0)
                cout << endl << "Resulted number: " << this->getA() << " + " << this->getB() << "i";
            else
                cout << endl << "Resulted number: " << this->getA() << " - " << this->getB() << "i";
        }

        void mainDisplay() {
            cout << *this;
        }


};

int ComplexNr :: getA() const {
    return a;
}

void ComplexNr :: setA(int X){
    this->a = X;
}

int ComplexNr :: getB() const {
    return b;
}

void ComplexNr :: setB(int X){
    this->b = X;
}

ComplexNr operator += (ComplexNr &N1, ComplexNr const &N2){
    N1.setA(N1.getA() + N2.getA());
    N1.setB(N1.getB() + N2.getB());
}

bool operator == (ComplexNr const N1, ComplexNr const N2){
    bool Validation = true;
    if (!(N1.a == N2.a && N1.b == N2.b))
        Validation = false;
    return Validation;
}

istream& operator >> (istream& in,  ComplexNr &N){
    cout << "Real Coefficient: ";
    float R;
    cin >> R;
    cout << endl;
    N.a = R;

    cout << "Complex Coefficient: ";
    int C;
    cin >> C;
    cout << endl;
    N.b = C;

    return in;
}

ostream& operator << (ostream& out, const ComplexNr &N) {
    if (N.b > 0)
        out << N.a << " + " << N.b << "i";
    else
        out << N.a << " - " << N.b << "i";
    return out;
}


