// find the number of subarrays.
#include<iostream>
#include<vector>
using namespace std;


// TC: O(1)
// SC: O(1)
int solve1(vector<int>&arr){

    int n = arr.size();
    return n*(n+1)/2;

}

int main(){

    vector<int> arr ={1,2}; // [1,1], [1,2], [2,2]

    cout << solve1(arr);

    return 0;
}