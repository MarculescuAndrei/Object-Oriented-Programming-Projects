#include <iostream>
using namespace std;

class Vector {

private:

    int v[100];
    int len;

public:

    friend class VectorDeVectori;

    int getLen(){ return len;}
    int *getVec(){ return v;}

    void setVec(int x[100]){
        for(int i = 0; i < len; i++)
            v[i] = x[i];
    }



    Vector(int len, int init); // Constructor pt initializarea cu un nr dat pe toate componentele
    ~Vector(); // Destructor
    Vector(int x[], int n); // Constructor de initializare
    Vector(const Vector & Vec); // Constructor de copiere
    friend ostream& operator<<(ostream&, const Vector&); // Supraincarcarea operatorului <<
    friend istream& operator>>(istream&, Vector&); // Supraincarcarea operatorului >>

};

ostream& operator<<(ostream& out, const Vector& Ob){
    out << Ob.v[0];
    for(int i = 1; i < Ob.len; i++){
        out << ", " << Ob.v[i];
    }
    return out;
}

istream& operator>>(istream &in, Vector& Ob){
    int n;
    cout << "n = ";
    in>>n;
    Ob.len=n;
    for( int i = 0; i < n; i++){
        in>>Ob.v[i];
    }
    return in;
}

Vector :: Vector(int dim, int init){
    len = dim;
    for (int i = 0; i < len; i++){
        v[i] = init;
    }
}

Vector :: ~Vector(){
    len=0;
}

Vector :: Vector(int x[], int n){
    len = n;
    for (int i = 0; i < len; i++)
    {
        v[i] = x[i];
    }
}

Vector :: Vector(const Vector & Ob){
    int n = Ob.len;
    for( int i = 0; i < n; i++){
        v[i]=Ob.v[i];
    }
}

class VectorDeVectori {

private:



public:
    int len2;
    Vector *v2[100];
    VectorDeVectori(Vector x[], int n);
    VectorDeVectori(int len2, Vector *x);
    ~VectorDeVectori();
    VectorDeVectori(VectorDeVectori &y);

    int getLen(){ return len2; }

    Vector getVec(int i){ return *v2[i]; }

    int** Matrice(VectorDeVectori v3){

        int n = v3.len2;
        int** M;
        M = new int*[100];

        for (int index = 0; index < 100; index++)
            M[index] = new int[100];

        int m = v3.v2[0]->getLen();

        for(int i = 0; i < n; i++){
            if (v3.v2[i]->getLen() > m)
                m = v3.v2[i]->getLen();
        }
        int j;
        for(int i = 0; i < n; i++)
            for( j = 0; i < m; i++)
                M[i][j] = 0;

        for(int i = 0; i < n; i++)
            for(j = 0; j < v3.v2[i]->getLen(); j++)
                M[i][j] = v3.v2[i]->v[j];

        return M;
    }


    int** operator+(VectorDeVectori& Ob1){

        int n;

        int **M2;
        M2 = new int*[100];

        for (int index = 0; index < 100; index++)
            M2[index] = new int[100];

        if (this->len2 > Ob1.len2)
            n = this->len2;
        else
            n = Ob1.len2;

        int m = 0;

        for(int i = 0; i < Ob1.len2; i++)
            if ( m < Ob1.v2[i]->getLen())
                m = Ob1.v2[i]->getLen();

        for(int i = 0; i < this->len2; i++)
            if ( m < this->v2[i]->getLen())
                m = this->v2[i]->getLen();

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                M2[i][j] = 0;

        for(int i = 0; i < Ob1.len2; i++)
            for(int j = 0; j < Ob1.v2[i]->getLen(); j++)
                M2[i][j] += Ob1.v2[i]->v[j];

        for(int i = 0; i < this->len2; i++)
            for(int j = 0; j < this->v2[i]->getLen(); j++)
                M2[i][j] += this->v2[i]->v[j];

        return M2;
    }
};

VectorDeVectori :: VectorDeVectori(int len2, Vector *x)
{
    int n = len2;
    for(int i = 0; i < n; i++){
        v2[i] = x;
    }
}

VectorDeVectori :: ~VectorDeVectori(){ // Destructor
    len2 = 0;
}

VectorDeVectori :: VectorDeVectori(VectorDeVectori &y){ // Constructor de copiere

    len2 = y.len2;
    for(int i = 0; i < len2; i++){
        v2[i]=y.v2[i];
    }
}

VectorDeVectori :: VectorDeVectori(Vector x[], int n){ //Constructor de initializare
    len2 = n;
    for( int i = 0; i < len2; i++){
        v2[i] = &x[i];
    }
}

void  Afiseaza(int**C, VectorDeVectori Ob1, VectorDeVectori Ob2)
{
    int n;
    if (Ob2.len2 > Ob1.len2)
        n = Ob2.len2;
    else
        n = Ob1.len2;

    int m = 0;

    for(int i = 0; i < Ob1.len2; i++)
        if ( m < Ob1.v2[i]->getLen())
            m = Ob1.v2[i]->getLen();

    for(int i = 0; i < Ob2.len2; i++)
        if ( m < Ob2.v2[i]->getLen())
            m = Ob2.v2[i]->getLen();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << C[i][j] << ' ';
        cout << '\n';
    }
}

int main(){


    int x1[] = {1, 2}, n1 = 2;
    int x2[] = {1, 2, 3}, n2 = 3;
    int x3[] = {4}, n3 = 1;
    int x4[] = {4, 5, 6, 2}, n4 = 4;
    int x5[] = {3, 8}, n5 = 2;

    Vector V1(x1, n1);
    Vector V2(x2, n2);
    Vector V3(x3, n3);
    Vector V4(x4, n4);
    Vector V5(x5, n5);

    Vector VX[] = {Vector(x1, n1), Vector(x2, n2)};
    Vector VY[] = {Vector(x3, n3), Vector(x4, n4), Vector(x5, n5)};

    VectorDeVectori A(VX, 2);
    VectorDeVectori B(VY, 3);
    int** C = B + A;

    Afiseaza(C, A, B);

return 0;

}
