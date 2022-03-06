// Given N elements, find out if there exists a pair i,j where A[i] + A[j] == k
// and i!=j.
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
// approach 1: simply iterate two for loops and compare.
// TC: O(N^2)
// SC: O(1)
bool solve1(vector<int> &arr, int K) {

  int n = arr.size();
  for (int i = 0; i < n; ++i) {

    for (int j = 0; j < n; ++j) {

      if (i != j) {

        if (arr[i] + arr[j] == K) {

          return true;
        }
      }
    }
  }

  return false;
}

// approach 2: we don't need to iterate over where i == j and also only on one
// half either (i,j) or  (j,i).
// TC: O(N^2)
// SC: O(1)

bool solve2(vector<int> &arr, int K) {

  int n = arr.size();

  for (int i = 0; i < n - 1; ++i) {

    for (int j = i + 1; j < n; ++j) {

      if (arr[i] + arr[j] == K) {

        return true;
      }
    }
  }
  return false;
}

int main() {

  vector<int> arr = {1, 2, 3, 5, 0};
  int K = 100;
  cout << boolalpha << solve1(arr, K) << '\n';
  cout << solve2(arr, K) << '\n';

  return 0;
}
