#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Film
{
protected:
    string filmName;
    string type;
    double length;
public:
    Film (string, string, double);
    Film (Film&);
    virtual ~Film();

    virtual void Read (istream &in);
    virtual void Display(ostream &out);


    Film& operator=(Film &p);
    friend istream& operator>>(istream&, Film&);
    friend ostream& operator<<(ostream&, Film&);
    friend class person;
};
Film::Film (string num="", string gen="", double minutes=0)
{
    filmName=num;
    type=gen;
    try
    {
        if (minutes<0)
            throw minutes;
    }
    catch (double x)
    {
        cout<<"Error in the constructor, minutes cannot be negative numbers.\n";
        exit(EXIT_FAILURE);
    }
    length=minutes;
}
void Film::Read(istream &in)
{
    string x;
    cout<<"Film Name :";
    in>>x;
    filmName=x;
    cout<<"Film Genre :";
    in>>x;
    type=x;
    cout<<"Film length:";
    string p;
    in>>p;
    double d;
    char *q=new char [p.length()+1];
    strcpy(q,p.c_str());
    d=atof(q);
    try
    {
        if (d<0)
            throw 1;
    }
    catch (int x)
    {
        cout<<"Error in the specification of length, minutes cannot be in negative numbers.\n";
        exit(EXIT_FAILURE);
    }
    length=d;
}
void Film::Display(ostream &out)
{
    out<<"Denumire Film: "<<filmName<<"\n";
    out<<"Genul Filmului: "<<type<<"\n";
    out<<"length Filmului: "<<length<<"\n";
}
Film::Film (Film &p)
{
    filmName=p.filmName;
    type=p.type;
    length=p.length;
}
Film::~Film()
{

}
Film& Film :: operator= (Film &x)
{
    if (this!=&x)
    {
        filmName=x.filmName;
        type=x.type;
        length=x.length;
    }
    return *this;
}
istream& operator>>(istream& in,Film& f)
{
    f.Read(in);
    return in;
}

ostream& operator<<(ostream& out, Film& f)
{
    f.Display(out);
    return out;
}
///------------------------------------------------------

class person
{
protected:
    string SSN;
    string personName;
    Film *Films;
    int Nr;
public:
    person (string, string, Film*,int);
    person (person&);
    virtual ~person();

    int getNr(){return Nr;}
    virtual void Read(istream &in);
    virtual void Display(ostream &out);
    person& operator=(person &p);
    friend istream& operator>>(istream&, person&);
    friend ostream& operator<<(ostream&, person&);
    friend ifstream& operator>>(ifstream&, person&);

};

person::person (string c="",string namep="",Film *f=NULL,int Nr=0)
{
    try
    {
        for (unsigned int i=0;i<c.length();i++)
            if (c[i]<'0'||c[i]>'9')
                throw 1;
    }
    catch(int i)
    {
        cout<<"Constructor error, the SSN can only contain numbers.\n";
        exit(EXIT_FAILURE);
    }
    SSN=c;
    personName=namep;
    Films=new Film[Nr];
    for(int i=0;i<Nr;i++)
        Films[i]=f[i];

}
person::person(person &p)
{
    SSN=p.SSN;
    personName=p.personName;
    Nr=p.Nr;
    Films=new Film[Nr];
    for(int i=0;i<Nr;i++)
        Films[i]=p.Films[i];

}
person::~person()
{

}
void person::Read(istream &in)
{
    string x;
    cout<<"SSN:";
    in>>x;
    SSN=x;
    cout<<"Name:";
    in>>x;
    personName=x;
    cout<<"Number of Films: ";
    in>>Nr;
    Films=new Film[Nr];
    for(int i=0;i<Nr;i++)
        in>>Films[i];
}
void person::Display(ostream &out)
{
    out<<"SSN: "<<SSN<<"\n";
    out<<"Name: "<<personName<<"\n";
    out<<"The "<<Nr<<" films are: "<<"\n";
    int i;
    for(i=0;i<Nr-1;i++)
        out<<Films[i]<<"\n";
    if (Nr!=0)
        out<<Films[i];
}
person& person :: operator= (person &x)
{
    if (this!=&x)
    {
        SSN=x.SSN;
        personName=x.personName;
        Nr=x.Nr;
        Films=new Film[Nr];
        for(int i=0;i<Nr;i++)
            Films[i]=x.Films[i];
    }
    return *this;
}
istream& operator>>(istream& in,person& p)
{
    p.Read(in);
    return in;
}

ostream& operator<<(ostream& out, person& p)
{
    p.Display(out);
    return out;
}
///-------------------------------------------------
class personnel:public person
{
protected:
    double* incomePercentage;
public:
    personnel(string, string, Film*,int, double*);
    personnel(personnel&);
    ~personnel();

    void Read(istream &in);
    void Display(ostream &out);

    personnel& operator=(personnel &p);
    friend istream& operator>>(istream&, personnel&);
    friend ostream& operator<<(ostream&, personnel&);

    friend ifstream& operator>>(ifstream&, personnel&);
};
personnel::personnel(string c="",string namep="",Film* f=NULL,int n=0,double percent[]=0):person(c,namep,f,n)
{
    if (f)
    {
    incomePercentage=new double[Nr];
    for (int i=0;i<Nr;i++)
        incomePercentage[i]=percent[i];

    }
}
personnel::personnel(personnel &p):person(p)
{
   incomePercentage=new double[p.Nr];
    for (int i=0;i<p.Nr;i++)
        incomePercentage[i]=p.incomePercentage[i];
}
personnel::~personnel()
{

}
void personnel::Read(istream &in)
{
    person::Read(in);
    incomePercentage=new double[Nr];
    for (int i=0;i<Nr;i++)
    {
        cout<<"Introduce the income percentage for personnel "<<i+1<<": ";
        string p1;
        in>>p1;
        double d;
        char *q=new char [p1.length()+1];
        strcpy(q,p1.c_str());
        d=atof(q);
        try
        {
            if (d<0||d>100)
                throw 1;
        }
        catch (int i)
        {
            cout<<"Error at the income percentage selection, it has to be within 0% and 100%.\n";
            exit(EXIT_FAILURE);
        }
        incomePercentage[i]=d;
    }
}
void personnel::Display(ostream &out)
{
    person::Display(out);
    int i;
    for (i=0;i<Nr-1;i++)
        out<<"Income percentage for personnel "<<i+1<<": "<<incomePercentage[i]<<"\n";
    if (Nr!=0)
    out<<"Income percentage for personnel "<<i+1<<": "<<incomePercentage[i]<<"\n";
}
personnel& personnel :: operator=(personnel &x)
{
    if(this!=&x)
    {
        person::operator=(x);
        for (int i=0;i<x.Nr;i++)
            incomePercentage[i]=x.incomePercentage[i];
    }
    return *this;
}
istream& operator>>(istream& in,personnel& p)
{
    p.Read(in);
    return in;
}

ostream& operator<<(ostream& out, personnel& p)
{
    p.Display(out);
    return out;
}

///-------------------------------------------------
class director:public personnel
{
    double* fixedSum;
public:
    director(string, string, Film*,int, double*, double*);
    director(director&);
    ~director();

    void Read(istream &in);
    void Display(ostream &out);

    director& operator=(director &p);
    friend istream& operator>>(istream&, director&);
    friend ostream& operator<<(ostream&, director&);
};
director::director(string c="",string namep="",Film* f=NULL,int n=0,double percent[]=0,double suma[]=0):personnel(c,namep,f,n,percent)
{
    if (f)
    {
    fixedSum=new double[Nr];
    for (int i=0;i<Nr;i++)
        fixedSum[i]=suma[i];
    }
}
director::director(director &p):personnel(p)
{
    fixedSum=new double[p.Nr];
    for (int i=0;i<p.Nr;i++)
        fixedSum[i]=p.fixedSum[i];
}
director::~director()
{

}
void director::Read(istream &in)
{
    personnel::Read(in);
    fixedSum=new double[Nr];
    for (int i=0;i<Nr;i++)
    {
        cout<<"Introduce the fixed amount of money for employee "<<i+1<<": ";
        string p1;
        in>>p1;
        double d;
        char *q=new char [p1.length()+1];
        strcpy(q,p1.c_str());
        d=atof(q);
        fixedSum[i]=d;
    }
}
void director::Display(ostream &out)
{
    personnel::Display(out);
    int i;
    for (i=0;i<Nr-1;i++)
        out<<"The fixed sum for personnel "<<i+1<<": "<<fixedSum[i]<<"\n";
    if (Nr!=0)
    out<<"The fixed sum for personnel "<<i+1<<": "<<fixedSum[i]<<"\n";
}
director& director :: operator=(director &x)
{
    if(this!=&x)
    {
        personnel::operator=(x);
        for (int i=0;i<x.Nr;i++)
            fixedSum[i]=x.fixedSum[i];
    }
    return *this;
}

istream& operator>>(istream& in,director& p)
{
    p.Read(in);
    return in;
}

ostream& operator<<(ostream& out, director& p)
{
    p.Display(out);
    return out;
}
///-------------------------------------------------
class actor:public personnel
{
    bool* mainActor;
public:
    actor(string, string, Film*,int, double*,bool*);
    actor(actor&);
    ~actor();

    bool getMainActor(int i){return mainActor[i];}
    void Read(istream &in);
    void Display(ostream &out);

    actor& operator=(actor &p);
    friend istream& operator>>(istream&, actor&);
    friend ostream& operator<<(ostream&, actor&);
};
actor::actor(string c="",string namep="",Film* f=NULL,int n=0,double percent[]=0,bool princ[]=0):personnel(c,namep,f,n,percent)
{
    if (f)
    {
    mainActor=new bool[Nr];
    for (int i=0;i<Nr;i++)
        mainActor[i]=princ[i];
    for (int i=0;i<Nr;i++)
        if (mainActor[i]==1)
            incomePercentage[i]=10;
    }
}
actor::actor(actor &p):personnel(p)
{
    mainActor=new bool[p.Nr];
    for (int i=0;i<p.Nr;i++)
        mainActor[i]=p.mainActor[i];
}
actor::~actor()
{

}
void actor::Read(istream &in)
{
    personnel::Read(in);
    mainActor=new bool[Nr];
    for (int i=0;i<Nr;i++)
    {
        cout<<"Main actor for the movie number "<<i+1<<": ";
        bool d;
        in>>d;
        mainActor[i]=d;
        if (d!=0)
            incomePercentage[i]=10;
    }
}
void actor::Display(ostream &out)
{
    personnel::Display(out);
    int i;
    for (i=0;i<Nr-1;i++)
        out<<"Main actor for the movie number "<<i+1<<": "<<mainActor[i]<<"\n";
    if (Nr!=0)
    out<<"Main actor for the movie number  "<<i+1<<": "<<mainActor[i];
    out<<"\n";
}
actor& actor :: operator=(actor &x)
{
    if(this!=&x)
    {
        personnel::operator=(x);
        for (int i=0;i<x.Nr;i++)
            mainActor[i]=x.mainActor[i];
    }
    return *this;
}

istream& operator>>(istream& in,actor& p)
{
    p.Read(in);
    return in;
}

ostream& operator<<(ostream& out, actor& p)
{
    p.Display(out);
    return out;
}

///-------------------------------------------------
class technician:public personnel
{
    string* specialization;
public:
    technician(string, string, Film*,int, double*,string*);
    technician(technician&);
    ~technician();

    void Read(istream &in);
    void Display(ostream &out);

    technician& operator=(technician &p);
    friend istream& operator>>(istream&, technician&);
    friend ostream& operator<<(ostream&, technician&);
};
technician::technician(string c="",string namep="",Film* f=NULL,int n=0,double percent[]=0,string spec[]=0):personnel(c,namep,f,n,percent)
{
    if (f)
    {
    specialization=new string[Nr];
    for (int i=0;i<Nr;i++)
        specialization[i]=spec[i];
    }
}
technician::technician(technician &p):personnel(p)
{
    specialization=new string[Nr];
    for (int i=0;i<p.Nr;i++)
        specialization[i]=p.specialization[i];
}
technician::~technician()
{

}
void technician::Read(istream &in)
{
    personnel::Read(in);
    specialization=new string[Nr];
    for (int i=0;i<Nr;i++)
    {
        cout<<"Specialization for the movie number "<<i+1<<": ";
        string d;
        in>>d;
        specialization[i]=d;
    }
}
void technician::Display(ostream &out)
{
    personnel::Display(out);
    int i;
    for (i=0;i<Nr-1;i++)
        out<<"Specialization for the movie number "<<i+1<<": "<<specialization[i]<<"\n";
    if (Nr!=0)
        out<<"Specialization for the movie numberl "<<i+1<<": "<<specialization[i];
    out<<"\n";
}
technician& technician :: operator=(technician &x)
{
    if(this!=&x)
    {
        personnel::operator=(x);
        for (int i=0;i<x.Nr;i++)
            specialization[i]=x.specialization[i];
    }
    return *this;
}

istream& operator>>(istream& in,technician& p)
{
    p.Read(in);
    return in;
}

ostream& operator<<(ostream& out, technician& p)
{
    p.Display(out);
    return out;
}


template <class T> class DistributionFirm
{
    T *v;
    int Nr;
public:
    DistributionFirm(T *p=NULL, int n=0)
    {
        Nr=n;
        if (n!=0){
            v=new T[n];
            for(int i=0;i<n;i++)
            {
                v[i]=p[i];
            }
        }
    }
    DistributionFirm(DistributionFirm &a)
    {
        Nr=a.Nr;
        v=new T[Nr];
        for(int i=0;i<Nr;i++)
        {
            v[i]=a.v[i];
        }
    }
    ~DistributionFirm()
    {
        delete [] v;
    }

    int getNr();
    T get_v(int i) {return v[i];}
    friend istream& operator >>(istream &in, DistributionFirm <T> &g)
    {
        cout<<"Introduce the number of personnel: ";
        in>>g.Nr;
        g.v=new T[g.Nr];
        cout<<"Introduce a worker: \n";
        for(int i=0;i<g.Nr;i++){
           in>>g.v[i];
           cout<<"\n";
        }
        return in;
    }
    friend ostream& operator <<(ostream &out, DistributionFirm<T> &g)
    {
        out<<"In the Distribution Firm there are the following "<<g.Nr<<" people: "<<"\n";
        for(int i=0;i<g.Nr;i++)
            out<<g.v[i]<<"\n";
        return out;
    }
};

template <class T> int DistributionFirm<T>::getNr(){
    return Nr;
}

template <> class DistributionFirm <actor>
{
    actor* v;
    int Nr;
    int MainActorNr;
public:
    DistributionFirm(actor *p=NULL, int n=0)
    {
        MainActorNr=0;
        Nr=n;
        v=new actor[n];
        for(int i=0;i<n;i++)
        {
            v[i]=p[i];
            for (int j=0;j<v[i].getNr();j++)
                if (v[i].getMainActor(j)==1)
                    {MainActorNr+=1;
                    break;}
        }
    }
    DistributionFirm(DistributionFirm &a)
    {
        Nr=a.Nr;
        MainActorNr=0;
        v=new actor[Nr];
        for(int i=0;i<Nr;i++)
        {
            v[i]=a.v[i];
            for (int j=0;j<v[i].getNr();j++)
                if (v[i].getMainActor(j)==1)
                    MainActorNr+=1;
        }
    }
    ~DistributionFirm()
    {
        delete [] v;
    }

    int getNr() {return Nr;}
    actor get_v(int i) {return v[i];}
    friend istream& operator >>(istream &in, DistributionFirm <actor> &g)
    {
        cout<<"Introduce the number of implicated actors: ";
        in>>g.Nr;
        g.v=new actor[g.Nr];
        cout<<"Introduce elements: ";
        for(int i=0;i<g.Nr;i++)
        {
            in>>g.v[i];
            for (int j=0;j<g.v[i].getNr();j++)
                if (g.v[i].getMainActor(j)==1)
                    {g.MainActorNr+=1;
                    break;}
           cout<<"\n";
        }
        return in;
    }
    friend ostream& operator <<(ostream &out, DistributionFirm<actor> &g)
    {
        out<<"In the Distribution Firm there are "<<g.Nr<<" implicated actors.\n";
        for(int i=0;i<g.Nr;i++)
            out<<g.v[i]<<"\n";
        out<<"Out of them, "<<g.MainActorNr<<" are main actors.\n";
        return out;
    }
};


void type(personnel *&p, int &i) {
    string s;
    cout<<"\n";
    cout<<"Introduce the post of the personnel number "<<i+1<<": ";
    cin>>s;
    try
    {
        if(s=="director")
        {
                p=new director;
                cin>>*p;
                i++;
        }
        else
            if(s=="actor")
            {
                p=new actor;
                cin>>*p;
                i++;
            }
            else
                if(s=="technician")
                {
                    p=new technician;
                    cin>>*p;
                    i++;
                }
                else
                    throw 10;
    }
    catch (bad_alloc var)
    {
        cout << "Allocation Failure\n";
        exit(EXIT_FAILURE);
    }
    catch(int j)
    {
        cout<<"You have not introduced a valid post, you need to specify technician, director or actor.\n ";
    }
}
void menu_output()
{
    cout<<"\nDISTRIBUTION FIRM\n";
    cout<<"\nMENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1 = Read the information for the people that are implicated";
    cout<<"\n";
    cout<<"2 = Introduce Directors";
    cout<<"\n";
    cout<<"3 = Introduce Technicians.";
    cout<<"\n";
    cout<<"4 = Introduce Actors";
    cout<<"\n";
    cout<<"5 = Firm Statistics";
    cout<<"\n";
    cout<<"0 = EXIT!";
    cout<<"\n";
}
void menu()
{
    int option;
    option=0;
    int n=0;
    personnel **v;
    do
    {
        menu_output();
        cout<<"\n Your choice: ";
        cin>>option;
        if (option==1)
        {
            cout<<"Give the number of employees to introduce: ";
            cin>>n;
            v=new personnel*[n];
            if (n>0)
            {
                for(int i=0;i<n;)
                    type(v[i],i);
                cout<<"\n Displaying the previous employee additions:\n";
                for(int i=0;i<n;i++)
                   {
                        cout<<"\n"<<*v[i];
                        cout<<"--------------------------\n";
                   }
            }
            else
                cout<<"The given number has to be positive.\n";
        }
        if (option==2)
        {
            DistributionFirm <director> x;
            cin>>x;
            cout<<x;
        }
        if (option==3)
        {
            DistributionFirm <technician> x;
            cin>>x;
            cout<<x;
        }
        if (option==4)
        {
            DistributionFirm <actor> x;
            cin>>x;
            cout<<x;
        }
        if (option==5)
        {
            int NrDir,NrAct,NrTech;
            NrDir=NrAct=NrTech=0;
            if (n>0){
            for(int i=0;i<n;i++)
            {

                director *p1=dynamic_cast<director*>(v[i]);

                actor *p2=dynamic_cast<actor*>(v[i]);

                technician *p3=dynamic_cast<technician*>(v[i]);

                if (p1)
                    NrDir++;
                if (p2)
                    NrAct++;
                if (p3)
                    NrTech++;
            }
            cout<<"Number of directors: "<<NrDir<<"\n";
            cout<<"Number of actors: "<<NrAct<<"\n";
            cout<<"Number of technicians: "<<NrTech<<"\n";}
            else{
                cout<<"Nothing has been added yet, add something with action 1 \n";
            }
        }
        if (option==0)
        {
            cout<<"\nEXIT\n\n";
        }
        if (option<0||option>5)
        {
            cout<<"\nInvalid Selection\n";
        }
        cout<<"\n";
        system("pause");
        system("cls");
    }
    while(option!=0);
}
int main()
{
    menu();
    return 0;
}
