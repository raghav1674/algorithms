// Given an array , reverse it inplace.
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void swap(int &a,int &b){

    int temp = a;
    a = b;
    b = temp; 
}

// TC: O(N)
// SC: O(1)

void solve1(vector<int>&arr){

    int i = 0;
    int j = arr.size() - 1;

    while(i<j){

        ::swap(arr[i],arr[j]);
        i++;
        j--;
    }

}

int main(){


    vector<int> arr = {-3,-2,6,8,4,8,5};

    solve1(arr);

    for(int i:arr){
        cout<< i << ' ';
    }
    return 0;
}
