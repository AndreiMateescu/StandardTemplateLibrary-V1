#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    map<int,int> name_map;
    int n;
    int x;
    cout<<"Numarul de elemente: "; cin>>n;
    for (int i=0;i<n;i++){
        cin>>x;
        name_map.insert(pair<int,int>(i,x));
    }

    for(map<int,int>::iterator it = name_map.begin(); it != name_map.end(); it++)
        cout<<it->first<<" => "<<it->second<<endl;

    //vad fiecare valoare de cate ori apare
    int value;
    for (int i=0;i<n;i++){
        map<int,int>::iterator it_find = name_map.find(i);
        int nr = 0;
        for(map<int,int>::iterator it = name_map.begin(); it != name_map.end(); it++)
            if (it_find->second == it->second)
                nr++;
        if (nr > n/2 + 1){//daca e mai mare ca n/2 +1 atunci o retin si ies fortat pentru ca nu poate fi alt numar cu un numar mai mare de aparitii
            value = it_find->second;
            break;
        }
    }
    cout<<value;
}
