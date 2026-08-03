/*A paint shop has buckets labeled with one of three colour codes — 0, 1, or 2 — but they are stored in a random order.
 The shop owner wants all 0s together, then all 1s, then all 2s, without using any extra storage. 
Given the list of colour codes, rearrange them in place and print the result.*/

#include<iostream>
#include<vector>

using namespace std;

void insertionsort(vector<int>& arr)
{
    int n=arr.size();
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main()
{
    vector<int> colors={2,0,1,2,1,0,0,2,1,0,2};
    insertionsort(colors);
    cout<<"Sorted Colors:";
    for(int i=0;i<colors.size();i++)
    {
        cout<<colors[i]<<" ";
    }
    cout<<endl;
    return 0;
}
