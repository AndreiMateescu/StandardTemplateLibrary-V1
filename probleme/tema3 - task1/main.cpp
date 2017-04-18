#include <set>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>

using namespace std;

// Define a structure for a rectangle: x1, y1, x2, y2
// Define a constructor for the rectangle
struct rect
{
    int x1;
    int x2;
    int y1;
    int y2;

    // TODO create rectangle
};

rect init(int x1, int y1, int x2, int y2)
{
    rect r;
    r.x1 = x1;
    r.y1 = y1;
    r.x2 = x2;
    r.y2 = y2;

    return r;
}

int area(const rect& r)
{
    return (r.x2-r.x1)*(r.y2-r.y1);
    // TODO calculate area L x l (L = x2-x1; l = y2-y2)
}

// Define operators: ==, <, based on the rectangle area
bool operator==(const rect& r1, const rect& r2)
{
    return area(r1) == area(r2);
}

bool operator<(const rect& r1, const rect& r2)
{
    return area(r1) < area(r2);
}

ostream& operator<<(ostream& os, const rect r)
{
    os << "(" << r.x1 << "," << r.y1 << ":" << r.x2 << "," << r.y2 << ")";
    return os;
}

// Implement a method that  creates and initialize a set of 4 rectangles
set<rect> initSet(rect r1, rect r2, rect r3, rect r4)
{
    // TODO create and insert into set
    set<rect> s;
    s.insert(r1);
    s.insert(r2);
    s.insert(r3);
    s.insert(r4);

    return s;
}

// Implement a method that output the content of the set using copy
void outputSet(set<rect> s)
{
    cout << "Set size: " << s.size()<< endl;

    copy(s.begin(), s.end(), ostream_iterator<rect>(cout, "; "));

    cout << endl;
}

void setDemo()
{

    set<rect> s3;

    rect r1 = init(0,0,10,10),
        r2 = init(0,0,20,20),
        r3 = init(0,0,30,30),
        r4 = init(0,0,40,40),
        r5 = init(10,10,20,20),
        r6 = init(10,10,30,30),
        r7 = init(0,0,15,15),
        r8 = init(0,0,25,25);


    set<rect>s1 = initSet(r1,r2,r3,r4);
    set<rect>s2 = initSet(r5,r6,r7,r8);

    set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(s3,s3.begin()));
    outputSet(s3);
    s3.clear();
    outputSet(s3);
    set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(s3,s3.begin()));
    outputSet(s3);

    // Make the intersection of s1 and s2 and output the result in set s3

    // Erase content of s3

    // Make the union of s1 and s2

    // Test inclusions of s1 in s3
}

int main ()
{
    setDemo();
}

