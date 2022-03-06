// Given an array, construct a prefix even sum array and prefix odd sum array.
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

/*      0 1 2 3 4 5
        1,2,3,4,5,6

        if i is even, add , else skip it.
        pse: 1,1,4,4,9,9
        pso: 0,2,2,6,6,12


*/

// TC: O(N)
// SC: O(N^2)

pair<int *, int *> solve1(int *arr, int n) {

  int *prefix_even_sum = new int[n];
  prefix_even_sum[0] = arr[0];
  int *prefix_odd_sum = new int[n];
  prefix_odd_sum[0] = 0;

  for (int i = 1; i < n; ++i) {

    // if its odd , skip it.
    if (i & 1) {

      prefix_even_sum[i] = prefix_even_sum[i - 1];

      prefix_odd_sum[i] = prefix_odd_sum[i - 1] + arr[i];

    } else {
      prefix_even_sum[i] = prefix_even_sum[i - 1] + arr[i];
      prefix_odd_sum[i] = prefix_odd_sum[i - 1];
    }
  }

  return {prefix_even_sum, prefix_odd_sum};
}

int main() {

  int arr[] = {1, 2, 3, 4, 5, 6};
  int size = sizeof arr / sizeof arr[0];
  pair<int *, int *> result = solve1(arr, size);
  for (int i = 0; i < size; ++i) {

    cout << *(result.first + i) << ' ';
  }

  cout << '\n';
  for (int i = 0; i < size; ++i) {

    cout << *(result.second + i) << ' ';
  }

  return 0;
}