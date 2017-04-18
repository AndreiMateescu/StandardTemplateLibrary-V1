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
    //folosesc o un alt element de tip map
    map<int,int>mymap;
    for (int i=0;i<n;i++){
        if(mymap.find(name_map[i]) == mymap.end())
            mymap[name_map[i]] = 1;
        else
            mymap[name_map[i]]++;
    }

    int ok = 0;
    int value;
    for (map<int,int>::iterator it = mymap.begin(); it != mymap.end(); ++it){
        if (it->second > n/2 + 1){
            value = it->first;
            ok = 1;
            break;
        }
    }
    if (ok == 1)
        cout<<value;
    else
        cout<<"Nu s-a gasit";
}
