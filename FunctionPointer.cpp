#include<iostream>
#include<cstdlib>

using namespace std;

int sum(int a,int b)
{
    return a+b;
}

int sum2(int a,int(*func)(int,int)) // Just pass the function and use the function as many times as you want
{
    return (func(8,9)+a); // 8,9 could be 12,13 or even 10,11 etc etc
}

int main()
{
    int(*func)(int,int);
    func = &sum;
    int t = func(3,4);
    int y = sum2(1,func);
    cout << y << endl;
    return 0;
}
