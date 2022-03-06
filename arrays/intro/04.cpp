// Given an array, rotate the array right K times.

#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void swap(int &a,int &b){

    int temp = a;
    a = b;
    b = temp; 
}


void reverse(vector<int>&arr,int l,int h){

   while(l<h){
       
       ::swap(arr[l],arr[h]);
       l++;h--;
   }
}

/*
    [1,2,3,4,-1]
    k = 3
    [3,4,-1,1,2]

    1: [-1,4,3,2,1] (0,n)
    2: [3,4,-1,2,1] (0,k-1)
    3: [3,4,-1,1,2] (k,n)

*/

// TC: O(N)
// SC: O(1)

void solve1(vector<int>&arr,int K){

    int n = arr.size();
    // if K > N; then K = K%N;
    K = K%n;
    ::reverse(arr,0,n-1);
    ::reverse(arr,0,K-1);
    ::reverse(arr,K,n-1);

}

int main(){


    vector<int> arr = {1,2,3,4,-1};
    int K = 3;
    solve1(arr,K);

    for(int i:arr){
        cout<< i << ' ';
    }
    return 0;
}
