#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

/************ Find the number of zeroes in an array having only 1s and 0s **********************/




int binZero(int arr[],int low,int high)
{
    if(low <= high)
    {
        int mid = (high+low)/2;

        if(arr[mid] == 0 && (arr[mid-1] == 1 || mid==0))
        {
            return mid;
        }
        if(arr[mid] == 1){return binZero(arr,mid+1,high);}
        else{return binZero(arr,low,mid-1);}
    }
    return -1;
}

int pos(int arr[],int n)
{
    int pos = binZero(arr,0,n-1);
    return pos;
}
int main()
{
    int arr[] = {1,1,1,1,1,0,0 };
    cout << pos(arr,7) << endl;

}
