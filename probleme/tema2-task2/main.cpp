#include <iostream>
#include <list>
#include <algorithm>
#include<math.h>
#include<fstream>
using namespace std;


struct punct{
    int x;
    int y;
};

ifstream f("lista.txt");

list<punct> AddElements(int n)
{
    list<punct> mylist;
    int aux,auy;
    punct a;
    for(int i=0;i<n;i++){
        f>>aux>>auy;
        a.x = aux;
        a.y = auy;
        mylist.push_back(a);
    }

    return mylist;
}

void listSizeAndContent(list<punct> lst)
{
    if(lst.empty()){
        cout<<"List is empty";
        return;
    }
    cout<<"List size: "<<lst.size()<<endl;

    list<punct>::const_iterator it;
    it = lst.begin();

    while(it!=lst.end()){
        cout<<(*it).x<<" "<<(*it).y<<endl;
        ++it;
    }
    cout<<endl;
}

//compar 2 puncte
bool distFromOrigin(punct a, punct b)
{
    return (sqrt(a.x*a.x + a.y*a.y) <= sqrt(b.x*b.x + b.y*b.y));
}

int main()
{
    int n;
    f>>n;
    list<punct> mylist;
    mylist = AddElements(n);

    mylist.sort(distFromOrigin);
    listSizeAndContent(mylist);
}
