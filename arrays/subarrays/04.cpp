// Return the maximum subarray sum.
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// TC: O(N^2)
// SC: O(1)

// can use kadane algo for this. which will be in O(N) and O(1)
int solve1(vector<int> &arr) {

  int max_element = INT_MIN;

  int n = arr.size();

  for (int L = 0; L < n; ++L) {

    int sum = 0;
    for (int R = L; R < n; ++R) {

      sum += arr[R];
      max_element = max(max_element, sum);
    }
  }

  return max_element;
}



int main() {

  vector<int> arr = {1, -2, 45, -1}; // [45] == 45

  cout << solve1(arr) << '\n';
  return 0;
}