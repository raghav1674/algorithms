// Given a array find the number of leader in the array.

// leader element: greater than all elements on its right.
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// TC: O(N)
// SC: 0(1)
int solve1(vector<int> &arr) {

  int n = arr.size();
  int right_max = arr[n - 1];
  int count = 1; // as the right most element will always be leader

  for (int i = n - 2; i >= 0; --i) {

    if (right_max < arr[i]) {

      right_max = arr[i];
      cout << arr[i] << '\n';
      count++;
    }
  }
  return count;
}

int main() {

  vector<int> arr = {15, -1, 7, 2, 5, 4, 2, 3};

  cout << solve1(arr) << '\n';

  return 0;
}