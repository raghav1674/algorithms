
// Given N elements, find out the element having atleast 1 element greater than itself.

#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int get_max(vector<int> &arr) {

  int max = INT_MIN;

  for (int i = 0; i < arr.size(); ++i) {

    if (arr[i] > max) {
      max = arr[i];
    }
  }

  return max;
}

// approach 1: find the max and compare with all.
// space complexity: O(1)
// time complexity: O(N)

int solve1(vector<int> &arr) {

  int count = 0;
  int max_element = get_max(arr);

  for (int i = 0; i < arr.size(); ++i) {

    if (arr[i] < max_element) {
      count++;
    }
  }

  return count;
}



// Approach 2: find the count of max element and subtract from the total number 
// space complexity: O(1)
// time complexity: O(N)

int solve2(vector<int>&arr){

    int count_max = 0;
    int max_element = get_max(arr);

    for(int i=0;i<arr.size();++i){

        if(arr[i] == max_element){

            count_max++;
        }
    }

    return arr.size() - count_max;
}

// optimized Approach 2: we can find the max and the count of max in the same loop itself.
// space complexity: O(1)
// time complexity: O(N)

int solve3(vector<int>&arr){

    int potential_max_element = INT_MIN;
    int count = 0;
    int n = arr.size();
    for(int i=0;i<n;++i){

        if(arr[i] > potential_max_element){

            count = 1; // we have found a new potential max, reset the count to 1.
            potential_max_element = arr[i];

        }else if(arr[i] == potential_max_element){

            count += 1; // to store the count of the potential max element.
        }
    }

    return (n-count);

}


int main(){


    vector<int> arr = {-3,-2,6,8,4,8,5};

    cout<< solve1(arr) << '\n';
    cout<< solve2(arr) << '\n';
    cout<< solve3(arr) << '\n';


    return 0;
}


