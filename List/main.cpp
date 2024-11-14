#include <iostream>
#include "List.h"
using namespace std;

bool func(int value)
{
    return value > 5;
}


bool func1(int value)
{
    return value < 5;
}

int main()
{
    List list;
    list.push_back(10);
    list.push_back(1);
    list.push_back(-5);
    list.push_front(0);
    list.show();
    List list2(list);
    list.clear();
    list.show();
    list2.show();
    /*cout << list.front() << endl;*/
    list2.insert(4, 7);
    list2.push_back(1);
    list2.push_back(1);
    list2.push_back(1);
    list2.show();
    bool(*fptr)(int value) = func;

    cout <<list.replace(func, 0) << endl;
    list.show();
    return 0;
}
