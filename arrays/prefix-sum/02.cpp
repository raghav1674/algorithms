// Given N elements, find out the count of equilibrium indexes.

// equilibrium indexes == arr[i-1]  == arr[i,n];

#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// TC: O(N*N)
// SC: O(1)

int solve1(vector<int> &arr) {

  int n = arr.size();
  int count = 0;

  for (int i = 0; i < n; ++i) {

    int left_sum = 0, right_sum = 0;

    // calculate left sum
    for (int L = 0; L < i; ++L) {

      left_sum += arr[L];
    }

    // calculate right sum
    for (int R = i + 1; R < n; ++R) {

      right_sum += arr[R];
    }

    if (left_sum == right_sum) {

      count++;
    }
  }
  return count;
}

// Approach 2: use prefix sum
// TC: O(N)
// SC: O(N)
int solve2(vector<int> &arr) {

  int n = arr.size();

  int prefix_sum[n];
  prefix_sum[0] = arr[0];

  int count = 0;

  for (int i = 1; i < n; ++i) {

    prefix_sum[i] = prefix_sum[i - 1] + arr[i];
  }

  for (int j = 0; j < n; ++j) {

    //[0,j]
    int left_sum = 0;
    if (j != 0) {

      left_sum = prefix_sum[j - 1];
    }
    // [j+1,n-1]
    int right_sum = 0;
    if (j != n - 1) {
      right_sum = prefix_sum[n - 1] - prefix_sum[j];
    }

    if (left_sum == right_sum) {

      count++;
    }
  }
  return count;
}

int main() {

  vector<int> arr = {-3, 2, 4, -1};

  cout << solve1(arr) << '\n';

  cout << solve2(arr) << '\n';

  return 0;
}