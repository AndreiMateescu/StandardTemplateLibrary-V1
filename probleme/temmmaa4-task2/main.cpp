#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int position = -1;

map<int,string> init(int n){
    map<int,string> mymap;
    string str;
    for (int i=0;i<n;i++){
        cin>>str;
        mymap.insert(pair<int,string>(i,str));
    }
    return mymap;
}

int sizeandimension(map<int,string> mymap)
{
    return mymap.size();
}

void show(map<int,string> mymap){

    for(map<int,string>::iterator it = mymap.begin(); it != mymap.end(); ++it)
        cout<<it->first<<" => "<<it->second<<endl;
}

void reverse_show(map<int,string> mymap){

    for(map<int,string>::reverse_iterator it = mymap.rbegin(); it != mymap.rend(); ++it)
        cout<<it->first<<" => "<<it->second<<endl;
}

void addtobegin(map<int,string>& mymap)
{
    string str;
    cout<<"Dati cartea: "; cin>>str;
    mymap.insert(pair<int,string>(position,str));
    position--;
}

void addtoend(map<int,string>& mymap)
{
    string str;
    int dimension = sizeandimension(mymap);
    cout<<"Dati cartea: "; cin>>str;
    mymap.insert(pair<int,string>(dimension,str));
}

int main()
{
    map<int,string>name_map;
    int n;
    cout<<"Numarul de elemente: "; cin>>n;
    name_map = init(n);
    show(name_map);

    int i=0;
    int isUp = 0;
    int N;
    cout<<"Cate operatii doriti sa faceti ?: "; cin>>N;
    while(i<N){
        int action;
        cout<<"Actiune: "; cin>>action;
        if (action < -1)
            isUp = 1 - isUp;
        else
            if (action > -1)
                if(isUp == 0)
                    addtobegin(name_map);
                else
                    addtoend(name_map);
        i++;
    }

    if (isUp == 0)
        show(name_map);
    else
        reverse_show(name_map);

    return 0;

}
