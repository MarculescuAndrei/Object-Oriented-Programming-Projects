#pragma once
#include "Information.h"
#include<stdlib.h>
#include<string.h>
#include <iostream>
using namespace std;

class Address : public Information {

    private:

        char Country[30];
        char County[30];
        char City[30];
        char Street[30];
        int Number;

    public:

        Address() : Information(){} // Basic Constructor
        ~Address(){}; // // Default Destructor

        // Operator Overloading:
        friend istream& operator >> (istream& in, Address &X);
        friend ostream& operator <<(ostream& out, const Address &X);
        friend bool operator ==(Address const X, Address const Y);

        void mainDisplay(){
            this -> addressDisplay();
        }

        void secondaryDisplay(){
            cout << endl << "This name has been used already, you cannot add this information again";

        }

        void addressDisplay(){
            cout << endl << "Country: " << this -> Country;
            cout << endl << "County: " << this -> County;
            cout << endl << "City: " << this -> City;
            cout << endl << "Street: " << this -> Street;
            cout << " Number: " << this -> Number;
        }
};

istream& operator >> (istream& in, Address &X){

            cout << "Country: ";
            in >> X.Country;

            cout << "County: ";
            in >> X.County;

            cout << "City: ";
            in >> X.City;

            cout << "Street: ";
            in >> X.Street;

            cout << "Number: ";
            int NumberChecker;
            cin >> NumberChecker;

            try{
                if(cin.fail())
                   throw "ERROR";
            }
            catch (string ERROR){
                cout << ERROR << endl;
            }

            X.Number = NumberChecker;

            return in; }

ostream& operator <<(ostream& out, const Address &X){
    out << "The address is :" << X.Country << "," << X.County << "," << X.City << ", Street: " << X.Street << ", Number: " << X.Number;
    return out;
}

bool operator ==(Address const X, Address const Y) {
    bool verification = true;
    if (!(strcmp(X.Country,Y.Country)==0 && strcmp(X.City,Y.City)==0 && strcmp(X.County,Y.County)==0 && strcmp(X.Street,Y.Street)==0 && X.Number==Y.Number))
        verification = false;
    return verification;
}
