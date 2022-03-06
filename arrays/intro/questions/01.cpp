#include <climits>
#include <iostream>
#include <vector>
using namespace std;


/* 
    You are given an integer array A. 
    You have to find the second largest 
    element/value in the array or report that no such element exists.

    1 <= |A| <= 10^5    
    0 <= A[i] <= 10^9


    Analysis: 1 sec , O(N^2) , not feasible, O(N), feasible 10^5 go for it.

    Dry run:

     2  1  2 

     2
     INT_MIN

     2
     1

     2
     2
*/




int solve1(vector<int>&arr){

    int n = arr.size();

    int largest = INT_MIN; 
    int second_largest = INT_MIN;

    for(int i=0;i<n;++i){


        if(arr[i] > largest){

            second_largest = largest;
            largest = arr[i];
        }

        else if(arr[i] > second_largest){

            second_largest = arr[i];
        }

    }

    return second_largest;

}

int main(){


    vector<int>arr ={2,1,2};

    cout << solve1(arr);

    return 0;
}

