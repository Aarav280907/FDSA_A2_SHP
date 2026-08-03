/*A teacher has a stack of student answer sheets with marks written on them and needs to arrange them in order before entering grades. 
She tries three different methods: in the first, she repeatedly compares adjacent sheets and swaps them if they are out of order; 
in the second, she finds the lowest-marked sheet each time and places it at the front; in the third, she picks each sheet one by one and 
inserts it into its correct position among the already-arranged sheets. Implement all three methods and for each one, 
print the sorted order of marks.85137*/

#include<iostream>
#include<utility> 
#include<vector>
using namespace std;
//bubble sort ma directly swap kari devay by comparing 
void bubblesort(vector<int>&marks)
{
    int n=marks.size();
   for(int i=0;i<n-1;i++)
    {
    for (int j = 0; j < n-i-1; j++)
        {
            if (marks[j]>marks[j+1])
            {
                swap(marks[j],marks[j+1]);
            }
            
        }
    }
    
}
//selectionsort ma minindex find karvo pade first i then compare karvanu ema j<midindex hoi midindex=j levanu
//then after second for loop swap use karvanu jema i then midindex swap karvano
void selectionsort(vector<int>&marks)
{
    int n=marks.size();
    for (int i = 0; i <n-1; i++)
    {
        int midindex=i;
        for (int j = i+1; j <n; j++)
        {
            if (marks[midindex]>marks[j])
            {
                midindex=j;
            }
            
        }
        swap(marks[i],marks[midindex]);
        
    }
    
}

//insertionsort ma ek variable levano jene = size then second for loop jema declare karvanu key =array element1
//second loop leta pela j=i-1 kari devanu then condition mukvani loop ma k j>=0 && marks[j]>key to marks[j+1]=marks[j]
//then j decrease karvano last ma second loop pachi marks[j+1]=key 

void insertionSort(vector<int>& marks) {
    int n = marks.size();
    for (int i = 1; i < n; i++) {
        int key = marks[i];
        int j = i - 1;
        while (j >= 0 && marks[j] > key) {
            marks[j + 1] = marks[j];
            j--;
        }
        marks[j + 1] = key;
    }
}

void printVector(const vector<int>& marks) {
    for (int i=0;i<marks.size();i++) {
        cout << marks[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> marks = {8,5,1,3,7};

    vector<int> bubbleMarks = marks;
    bubblesort(bubbleMarks);
    cout << "Bubble Sort: ";
    printVector(bubbleMarks);

    vector<int> selectionMarks = marks;
    selectionsort(selectionMarks);
    cout << "Selection Sort: ";
    printVector(selectionMarks);

    vector<int> insertionMarks = marks;
    insertionSort(insertionMarks);
    cout << "Insertion Sort: ";
    printVector(insertionMarks);

    return 0;
}