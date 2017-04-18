#include <iostream>
#include<vector>
#include<fstream>
using namespace std;

ifstream f("vector.txt");

//functie de tip vector care adauga n elemente dintr-un fisier
vector<int> AddElement(int n)
{
    vector<int> myvector;
    int x;
    for(int i=0;i<n;i++){
        f>>x;
        myvector.push_back(x);
    }

    return myvector;
}

int main()
{
    int n;
    f>>n;
    vector<int>myvector;
    myvector = AddElement(n);

    for(auto i:myvector)
        cout<<i<<" ";
    return 0;
}
