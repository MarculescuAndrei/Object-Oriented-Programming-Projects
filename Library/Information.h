#pragma once
#include<stdlib.h>
#include<cstring>
#include <iostream>
using namespace std;


class Information{

    protected:
        string Name;
        int ID;

    public:

        Information(){}

        void setID(int ID){
            this->ID=ID;
        }
        int getID(){
            return this->ID;
        }

        void setName(string Name){
            this->Name=Name;
        }
        string getName(){
            return this->Name;
        }

        void readName(){
            cout << "Enter the name of the Information: " << endl;
            cin >> this->Name;
        }

        void nameDelete(){
            cout << endl << "The '" << this->Name << "' Information has been deleted.";
        }

        void idDelete(){
            cout << endl << "The Information with the ID: " << this->ID << " has been deleted.";
        }

        virtual void mainDisplay()=0;
        virtual void secondaryDisplay()=0;
};


