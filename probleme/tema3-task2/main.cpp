#include <set>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>

using namespace std;

struct film{
    string nume;
    int an;
};

ifstream f("film.txt");

//creez setul cu n elemente de tip film
set<film> init_set(int n)
{
    film a;
    string nume;
    int an;
    set<film> myset;
    for (int i=0;i<n;i++){
        f>>nume;
        f>>an;
        a.nume = nume;
        a.an = an;
        myset.insert(a);
    }

    return myset;
}

//avand in vedere ca pentru tipul film, operatorul < nu este supraincarcat
bool operator<(const film& a, const film& b)
{
    return a.nume < b.nume || (a.nume == b.nume && a.an < b.an);
}

int main ()
{
    int n;
    f>>n;
    int k[100];
    for(int i=0;i<n;i++)
        f>>k[i];

    //formez un vector de seturi
    vector<set<film>> my_vector_set;
    set<film> myset;
    for(int i=0;i<n;i++){
        myset = init_set(k[i]);
        my_vector_set.push_back(myset);
    }

    //afisez sa verific daca datele sunt introduse cum trebuie
    for(int i=0;i<my_vector_set.size();i++){
        for(set<film>::iterator it = my_vector_set[i].begin();it != my_vector_set[i].end();it++)
            cout<<it->nume<<" "<<it->an<<endl;
            cout<<endl;
    }

    set<film> setulmeu; //setul in fiecare tin fiecare intersectie a lui i cu i+1
    for (int i=0;i<my_vector_set.size()-1;i++)
        set_intersection(my_vector_set[i].begin(),my_vector_set[i].end(),my_vector_set[i+1].begin(),my_vector_set[i+1].end(),inserter(setulmeu,setulmeu.begin()));

    cout<<"Setul meu: "<<endl;
    for(set<film>::iterator it= setulmeu.begin(); it != setulmeu.end(); ++it)
        cout<<it->nume<<" "<<it->an<<endl;

}
