// Print the sum of all the subarrays.

#include <iostream>
#include <vector>
using namespace std;

// approach 1: based on Prefix Sum
// TC: O(N^2)
// SC: O(N)
// and printing cannot be optimized here.
void solve1(vector<int> &arr) {

  int n = arr.size();
  int prefix_sum[n];
  prefix_sum[0] = arr[0];

  for (int i = 1; i < n; ++i) {

    prefix_sum[i] = prefix_sum[i - 1] + arr[i];
  }

  for (int L = 0; L < n; ++L) {

    for (int R = L; R < n; ++R) {

      cout << "[" << L << "," << R << "]: ";
      if (L == 0) {

        cout << prefix_sum[R] << '\n';
      } else {

        cout << (prefix_sum[R] - prefix_sum[L - 1]) << '\n';
      }
    }
  }
}

// approach 2: why to have a prefix sum ? just keep a variable adding into it
// TC: O(N^2)
// SC: O(1)
void solve2(vector<int> &arr) {

  int n = arr.size();
  int totalSum = 0;
  for (int L = 0; L < n; ++L) {
    int sum = 0;
    for (int R = L; R < n; ++R) {

      sum += arr[R];

      cout << "[" << L << "," << R << "]: " << sum << '\n';
    }
  }
}

// approach 3:



int main() {

  vector<int> arr = {1, 2, 3}; // [1,1], [1,2], [2,2]

  cout << "APPROACH 1\n";
  solve1(arr);
  cout << "APPROACH 2\n";
  solve2(arr);


  return 0;
}