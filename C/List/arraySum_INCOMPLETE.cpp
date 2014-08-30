#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<queue>
#include<vector>

using namespace std;

/*********** Check if two elements sum to a given value *****************************/

int median(int arr[])
{
    int size = sizeof(arr)/sizeof(arr[0]);
    priority_queue< int , std::vector<int> , greater<int> > minHeap;
    priority_queue< int , std::vector<int> > maxHeap;
    int mincount=0,maxcount=0;
    maxHeap.push(arr[0]);
    maxcount++;

    for(int i=1;i<size;i++)
    {
        if(maxcount == mincount)
        {
            if(arr[i] > minHeap.top())
            {
                minHeap.push(arr[i]);
                mincount++;
            }else{maxHeap.push(arr[i]);
            maxcount++;}
        }
        else if(maxcount > mincount)
        {
            if(arr[i] > maxHeap.top())
            {
                minHeap.push(arr[i]);
                mincount++;
            }else{minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(arr[i]);
            mincount++;
            }
        }
        else
        {
            if(arr[i] < minHeap.top())
            {
                maxHeap.push(arr[i]);
                maxcount++;
            }else{maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(arr[i]);
            maxcount++;
            }
        }
    }

        if((maxcount+mincount)%2 == 0)
        {
            return ((maxHeap.top()+minHeap.top())/2);
        }
        else{ return (maxcount>mincount?maxHeap.top():minHeap.top());}
}
int main()
{
    int arr[20] = {1,4,2,3,6,7,45,65,13,78,90,87,47,92,30,55,21,61,79,22};
    cout << median(arr) << endl;

}
