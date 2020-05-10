#pragma once
#include "Information.h"
#include<stdlib.h>
#include<string.h>
#include <iostream>
using namespace std;

class Number : public Information {

    private:

        int Value;

    public:

        Number():Information(){} // Empty Constructor
        Number(int X){ // Constructor
            this->Value = X;
        }
        ~Number(){}; // Default Destructor

        int getNum() const {
            return Value;
        }
        void setNum(int X){
            this->Value = X;
        }

        // Operator Overloading :
        friend Number operator += ( Number &N1, Number const &N2);
        friend istream& operator >> (istream& in, Number &N);
        friend ostream& operator << (ostream& out, const Number &N);
        friend bool operator == (Number const N1, Number const N2);

        void mainDisplay(){cout << "You recovered the number: " << this->Value;};
        void secondaryDisplay(){};

};

Number operator += ( Number &N1, Number const &N2){
    N1.setNum(N1.getNum() + N2.getNum());
}

bool operator == (Number const N1, Number const N2){

    if (N1.Value == N2.Value)
        return true;
    else
        return false;
}

istream& operator >> (istream& in, Number &N){
    cout << "Add a number: ";
    int Nr;
    cin>>Nr;
    try{
        if (cin.fail())
            throw "ERROR";
    }
    catch (char* ERROR){
        cout << ERROR << endl;
    }
    N.Value = Nr;

    return in;
}

ostream& operator << (ostream& out, const Number &N){
    out << "The numeric value is: " << N.Value;
    return out;
}
