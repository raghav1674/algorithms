// Print all the subarrays.

#include <iostream>
#include <vector>
using namespace std;

// TC: O(N^3)
// SC: O(1)
// and printing cannot be optimized here.
void solve1(vector<int> &arr) {

  int n = arr.size();

  for (int L = 0; L < n; ++L) {

    for (int R = L; R < n; ++R) {

      cout << "[" << arr[L] << "," << arr[R] << "]: { ";
      for (int k = L; k <= R; ++k) {

        cout << arr[k] << " ";
      }
      cout << "} " << endl;
    }
  }
}

int main() {

  vector<int> arr = {1, 2,3}; // [1,1], [1,2], [2,2]

  solve1(arr);

  return 0;
}