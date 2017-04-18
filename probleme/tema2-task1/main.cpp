#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

//creaza o lista. Daca pozitia este mai mica decat nrelem/2, atunci adauga in spate, altfel adauga in fata
list<int> createAndInitializeList(int nrElems)
{
    list<int> l;
    for(int i=0;i<nrElems;i++){
        if(i < nrElems/2)
            l.push_back(i);
        else
            l.push_front(i);
    }

    return l;
}

void listSizeAndContent(list<int> lst)
{
    if(lst.empty()){
        cout<<"List is empty";
        return;
    }
    cout<<"List size: "<<lst.size()<<endl;

    list<int>::const_iterator it;
    it = lst.begin();

    while(it!=lst.end()){
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;
}

bool IsEven(int n)
{
    if(n%2 == 0)
        return true;
    else
        return false;
}

//functia palindrom
bool palindrom(int n)
{
    int invers=0;
    int aux = n;
    while(aux!=0){
        invers = invers*10 + aux%10;
        aux = aux/10;
    }

    if(n == invers)
        return true;
    else
        return false;
}

int main ()
{
    list<int> list1 = createAndInitializeList(10);
    list<int> list2 = createAndInitializeList(5);
    list<int> list3(5,33);

    cout<<"Initial list 1: "<<endl;
    listSizeAndContent(list1);

    cout<<endl;
    cout<<"Initial list 2: "<<endl;
    listSizeAndContent(list2);

    cout<<endl;
    cout<<"Initial list 3: "<<endl;
    listSizeAndContent(list3);
    cout<<endl;

    list<int>::iterator it = find(list1.begin(),list1.end(),0);
    list<int>::iterator it_a = find(list2.begin(),list2.end(),3);
    list<int>::iterator it_b = list2.end();

    list1.splice(it, list2,it_a,it_b);
    cout<<"List 1 after splice: "<<endl;
    listSizeAndContent(list1);
    cout<<"List 2 after splice: "<<endl;
    listSizeAndContent(list2);

    list1.sort();
    cout<<endl<<endl;
    cout<<"List 3 before merge: "; listSizeAndContent(list3);
    list3.merge(list1); cout<<endl;
    cout<<"List 3 before merge: "; listSizeAndContent(list3);
    cout<<endl;

    list3.unique();
    cout<<"List 3 after unique: "; listSizeAndContent(list3);

    list3.remove_if(IsEven);
    cout<<"List 3: "; listSizeAndContent(list3);

    list3.remove_if(palindrom);
    cout<<"List 3: "; listSizeAndContent(list3);
}
