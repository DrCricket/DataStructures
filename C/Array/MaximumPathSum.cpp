#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;


/*****  sum of the maximum sum path to reach from beginning of any array to end of any of the two arrays ****/
vector<int> intersection(int arr1[],int arr2[],int n1,int n2)
{
    vector<int> v;
    int i=0,j=0;
    while(i<n1 && j<n2)
    {
        if(arr1[i] < arr2[j]){i++;}
        if(arr1[i] > arr2[j]){j++;}
        else{v.push_back(arr1[i]);i++;j++;}
    }
    return v;
}

int sum(int arr1[],int arr2[],int n1,int n2)
{
    vector<int> v = intersection(arr1,arr2,n1,n2);
    /***** Search , sum , max - TOO LONG ********/

}


int sum_max(int arr1[],int arr2[],int n1,int n2)
{
    int i=0,j=0;
    int sum_1=0,sum_2=0,maxsum=0;
    while(i<n1&&j<n2)
    {
        if     (arr1[i]<arr2[j]){sum_1+=arr1[i++];}
        else if(arr1[i]>arr2[j]){sum_2+=arr2[j++];}
        else   {maxsum += max(sum_1,sum_2)+arr1[i++]; // Assuming only one common element at once (not a streak)
        j++;
        sum_1=0;
        sum_2=0;}
    }

    while(i<n1){sum_1+=arr1[i++];}
    while(j<n2){sum_2+=arr2[j++];}
    maxsum += max(sum_1,sum_2);

    return maxsum;
}

int main()
{
    int ar1[] = {2, 3, 7, 10, 12, 15, 30, 34};
    int ar2[] = {1, 5, 7, 8, 10, 15, 16, 19};

    cout << sum_max(ar1,ar2,8,8) << endl;

}
