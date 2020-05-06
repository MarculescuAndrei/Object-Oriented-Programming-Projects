#pragma once
#include "Information.h"
#include<stdlib.h>
#include<string.h>
#include <iostream>
using namespace std;

class Text : public Information {

    private:
        string Txt;

    public:

        Text():Information(){} // Empty Constructor
        Text(const char* Txt){ // Constructor
            this->Txt = Txt;
        }
        ~Text(){};

        // Operator Overloading:
        friend istream& operator >> (istream& in, Text &T);
        friend ostream& operator << (ostream& out, const Text &T);
        friend bool operator == (Text const T1, Text const T2);

        string getText(){
            return this->Txt;
        }

        void mainDisplay(){
            cout << *this;
        }

        void secondaryDisplay(){
            cout << endl << "New text resulted: " << this->getText();
        }

        void TextAddition(Text &T){
            this->Txt = this->Txt + T.getText();
        }
};

bool operator == (Text const T1, Text const T2){
    if (T1.Txt == T2.Txt)
        return true;
    else
        return false;
}

istream& operator >> (istream& in, Text &T){
    cout << "Write your text: " << endl;
    in.get();
    getline(in, T.Txt);
    return in;

}

ostream& operator <<(ostream& out, const Text &T){
    out << "The text is: " << T.Txt;
    return out;
}
