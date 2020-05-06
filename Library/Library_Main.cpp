#include <iostream>
#include "Number.h"
#include "Text.h"
#include "Information.h"
#include "ComplexNr.h"
#include "Address.h"
#include <vector>
using namespace std;

int IDnr = 0;

class Library{

    private:

        vector<Information*> lst;

    public:

        Library(){}

        // Addition Methods:
        void Add();
        void AddAddress(string Name);
        void AddNumber(string Name);
        void AddText(string Name);
        void AddComplexNr(string Name);

        // Recovery Methods:
        void Recovery();
        void IDRecovery();
        void NameRecovery();

        // Search Methods:
        void Search();
        void SearchComplexNr();
        void SearchText();
        void SearchAddress();
        void SearchNumber();

        // Removal Methods:
        void Delete();
        void DeleteByName();
        void DeleteByID();

};

// Addition Methods :

void Library :: Add(){
    IDnr++;
    int Sw, OK = 1;
    string name;

    cout << endl << "Introduce the name of your information: ";
    cin >> name;
    int found = 0, index = 0;

    for (int i = 0; i < lst.size(); i++)
        if (name == lst[i]->getName()){
            index = i;
            found = 1;
        }
    if (found  == 0){

        while(OK == 1){
            cout << endl << " ______________________________ ";
            cout << endl << "Choose your type of information: ";
            cout << endl << "1 = Number";
            cout << endl << "2 = Text";
            cout << endl << "3 = Address";
            cout << endl << "4 = Complex Number";
            cout << endl << " ______________________________ ";
            cout << endl << "Choice: ";
            cin >> Sw;


            switch(Sw){
                case 1:AddNumber(name);
                    OK = 0;
                    break;
                case 2:AddText(name);
                    OK = 0;
                    break;
                case 3:AddAddress(name);
                    OK = 0;
                    break;
                case 4:AddComplexNr(name);
                    OK = 0;
                    break;
                default : cout << endl << "Choose a valid number";
            }
        }
    }
    else {

        if (dynamic_cast<Number*>(lst[index])){
            cout << endl << "There is an information with this name already, the new number will be added to the current one.";
            Number* N = new Number;
            Number* M = dynamic_cast<Number*>(lst[index]);

            cin >> *N;
            M->setNum(M->getNum() + N->getNum());
            M->secondaryDisplay();
            lst[index] = M; }

        if (dynamic_cast<Text*>(lst[index])) {
            cout << endl << "There is an information with this name already, the new text will be added to the current one.";
            Text* N = new Text;
            Text* M = dynamic_cast<Text*>(lst[index]);

            cin >> *N;
            M->TextAddition(*N);
            M->secondaryDisplay();
            lst[index] = M; }

        if (dynamic_cast<Address*>(lst[index])){
            cout << endl << "-- ERORR! --";
        }

        if (dynamic_cast<ComplexNr*>(lst[index])){
            cout << endl << "There is an information with this name already, the new complex number will be added to the current one.";
            ComplexNr* N = new ComplexNr;
            ComplexNr* M = dynamic_cast<ComplexNr*>(lst[index]);
            cin >> *N;

            M->Addition(*N);
            M->secondaryDisplay();
            lst[index] = M; }
    }
}

void Library :: AddAddress(string name){
    Address* A = new Address;
    A->setName(name);

    cin >> *A;
    A->setID(IDnr); cout << endl << "The information ID is: " << IDnr;
    lst.push_back(A);
}

void Library :: AddNumber(string name){
    Number* N = new Number;
    N->setName(name);

    cin >> *N;
    N->setID(IDnr); cout << endl << "The information ID is: " << IDnr;
    lst.push_back(N);
}

void Library :: AddText(string name){
    Text* T = new Text;
    T->setName(name);

    cin >> *T;
    T->setID(IDnr); cout << endl << "The information ID is: " << IDnr;
    lst.push_back(T);
}

void Library :: AddComplexNr(string name){
    ComplexNr* N = new ComplexNr;
    N->setName(name);

    cin >> *N;
    N->setID(IDnr); cout << endl << "The information ID is: " << IDnr;
    lst.push_back(N);
}

// Recovery Methods :

void Library :: Recovery(){

    int Sw, OK = 1;
    while(OK == 1){
        cout << endl << " ______________________________ ";
        cout << endl << "You can access the information by: ";
        cout << endl << "1 = Name";
        cout << endl << "2 = ID";
        cout << endl << " ______________________________ ";
        cout << endl << "Choice: ";
        cin >> Sw;
    switch(Sw){
        case 1: NameRecovery();
            OK = 0;
            break;
        case 2: IDRecovery();
            OK = 0;
            break;
        default: cout << endl << "Choose a valid number."; } }
}

void Library :: NameRecovery(){
    string NameChecker;
    cout << endl << "Give the name: ";
    cin >> NameChecker;

    int OK = 0;
    for (int i = 0; i < lst.size(); i++)
    if (lst[i]->getName() == NameChecker){
        OK = 1;
        lst[i]->mainDisplay(); }

    if (OK == 0)
        cout << endl << "No information in the library has this name.";
}

void Library :: IDRecovery(){
    int IDChecker;
    cout << endl << "Give the name: ";
    cin >> IDChecker;

    int OK = 0;
    for (int i = 0; i < lst.size(); i++)
    if (lst[i]->getID() == IDChecker){
        OK = 1;
        lst[i]->mainDisplay(); }

    if (OK == 0)
        cout << endl << "No information in the library has this ID.";
}

// Search Methods :

void Library :: Search(){
    int Sw, OK = 1;

    while(OK == 1){
        cout << endl << " ______________________________ ";
        cout << endl << "Choose the type of information you want to search: ";
        cout << endl << "1 = Number";
        cout << endl << "2 = Text";
        cout << endl << "3 = Address";
        cout << endl << "4 = Complex Number";
        cout << endl << " ______________________________ ";
        cout << endl << "Choice: ";
        cin >> Sw;

        switch(Sw){
            case 1: SearchNumber();
                OK = 0;
                break;
            case 2: SearchText();
                OK = 0;
                break;
            case 3: SearchAddress();
                OK = 0;
                break;
            case 4: SearchComplexNr();
                OK = 0;
                break;
            default: cout << "Choose a valid number.";} }
}

void Library :: SearchNumber(){
    Number* N = new Number;
    cin >> *N;
    int OK = 0;

    for( int i = 0; i < lst.size(); i++){

        if(dynamic_cast<Number*>(lst[i])){
            Number* M = dynamic_cast<Number*>(lst[i]);

            if(*N == *M){
                OK = 1;
                cout << endl << "The information you searched for: " << M->getNum();
                cout << endl << "Name: " << M->getName();
                cout << endl << "ID: " << M->getID(); }
        }
    }
}

void Library :: SearchText(){
    Text* T1 = new Text;
    cin >> *T1;
    int OK = 0;

    for (int i = 0; i < lst.size(); i++){
        if(dynamic_cast<Text*>(lst[i])){
            Text* T2 = dynamic_cast<Text*>(lst[i]);
            if (*T1 == *T2){
                OK = 1;
                cout << endl << "The information you searched for: " << T2->getText();
                cout << endl << "Name: " << T2->getName();
                cout << endl << "ID: " << T2->getID(); }
        }
    }
}

void Library :: SearchAddress(){
    Address* A1 = new Address;
    cin >> *A1;
    int OK = 0;

    for (int i = 0; i < lst.size(); i++){
        if(dynamic_cast<Address*>(lst[i])){

            Address* A2 = dynamic_cast<Address*>(lst[i]);
            if (*A1 == *A2){
                OK = 1;
                cout << endl << "The information you searched for: ";
                A2->addressDisplay();
                cout << endl << "Name: " << A2->getName();
                cout << endl << "ID: " << A2->getID(); }
        }
    }
}

void Library :: SearchComplexNr(){
    ComplexNr* N = new ComplexNr;
    cin >> *N;
    int OK = 0;

    for (int i = 0; i < lst.size(); i++){
        if(dynamic_cast<ComplexNr*>(lst[i])){

            ComplexNr* M = dynamic_cast<ComplexNr*>(lst[i]);
            if (*N == *M){
                OK = 1;
                cout << endl << "The information you searched for: ";

                    if (N->getB() < 0)
                        cout << endl << M->getA() << " - " << M->getB()  << "i";
                    else
                        cout << endl << M->getA() << " + " << M->getB()  << "i";

                cout << endl << "Name: " << M->getName();
                cout << endl << "ID: " << M->getID(); }
        }
    }
}

// Removal Methods :

void Library :: Delete(){
    int Sw, OK = 1;

    while(OK == 1){
        cout << endl << " ______________________________ ";
        cout << endl << "Choose how to search for the information that you want to remove: ";
        cout << endl << "1 = Name";
        cout << endl << "2 = ID";
        cout << endl << " ______________________________ ";
        cout << endl << "Choice: ";
        cin >> Sw;

    switch (Sw){
        case 1: DeleteByName();
                OK = 0;
                break;
        case 2: DeleteByID();
                OK = 0;
                break;
        default: cout << endl << "Choose a valid number."; }
    }
}

void Library :: DeleteByName(){
    string NameChecker;
    cout << "Give the name: ";
    cin >> NameChecker;

    int OK = 0;
    for(int i = 0; i < lst.size(); i++)
        if(lst[i]->getName() == NameChecker){
            OK = 1;

            cout << endl << "The information with the name: " << lst[i]->getName() << " has been deleted.";
            lst.erase(lst.begin() + i); }

         if (OK == 0)
            cout << endl << "There doesn't exist any information with this name.";
}

void Library :: DeleteByID(){
    int IDChecker;
    cout << "Give the ID: ";
    cin >> IDChecker;

    int OK = 0;
    for(int i = 0; i < lst.size(); i++)
        if(lst[i]->getID() == IDChecker){
            OK = 1;

            cout << endl << "The information with the ID: " << lst[i]->getID() << " has been deleted.";
            lst.erase(lst.begin() + i); }

         if (OK == 0)
            cout << endl << "There doesn't exist any information with this ID.";
}


// Main Program :


int main()
{
    Library* X = new Library;
    int Sw, OK = 1;

    do{

        cout << endl << " ---- Virtual Library ---- ";
        cout << endl << " Make Your Choice : ";
        cout << endl << "1 = Add Information";
        cout << endl << "2 = Recover Information";
        cout << endl << "3 = Search Information";
        cout << endl << "4 = Delete Information";
        cout << endl << "0 = Exit!" << endl;
        cout << "Your Choice: ";

        cin >> Sw;
        switch(Sw){

            case 1: X->Add();
                    break;

            case 2: X->Recovery();
                    break;

            case 3: X->Search();
                    break;

            case 4: X->Delete();
                    break;

            case 5: OK = 0;
                    break;
            default: cout << endl << "Choose a valid number!";
        }

        cout << endl;
    }while(OK == 1);

return 0;
}
