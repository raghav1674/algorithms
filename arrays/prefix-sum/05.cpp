// Given an array, find the count of special index.
/*
    special index =  if after deleting that index, the sum of even indexed
   element == sum of odd indexed elements.

            0   1   2  3  4   5
            4   3   2  7  6  -2


    pse:    4   4   6  6  12  12
    pso:    0   3   3  10 10  8

    after deleting 4:
            0   1   2  3   4
            3   2   7  6  -2

    pse:    3   3   10 10  8
    pso:    0   2   2  8   8

    after deleting 2:
            0   1   2  3   4
            4   3   7  6  -2

    pse:    4   4   11 11  9
    pso:    0   3   3   9  9

    after deleting 3:

            0   1   2  3   4
            4   2   7  6  -2

    pse:    4   4   11 11  9
    pso:    0   2   2  8   8


    so we can see , if we delete, even <-> odd.

    and till the deleted index , everything remains same. but after that changes
   happen and how much change,

    pse_delta = pse[i-1] - pso[i] //  4 - 3 = 1
    pso_delta = pso[i-1] - pse[i] //  0 - 4 = -4


    even_sum = pso[n-1] + pse_delta;
    odd_sum = pse[n-1] + pso_delta;

    eg: even_sum = pso[5] + pse_delta
                 = 8 + 1 = 11

        odd_sum  = pso[5] + pso_delta
                 = 12 +(- 4) = 8

    * only the sum after the deleted index is changing.

*/
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// TC: O(N)
// SC: O(N^2)

int solve1(vector<int> &arr) {

  int n = arr.size();
  int prefix_even_sum[n];
  prefix_even_sum[0] = arr[0];
  int prefix_odd_sum[n];
  prefix_odd_sum[0] = 0;

  int count = 0;

  for (int i = 1; i < n; ++i) {

    if (i & 1) {

      prefix_even_sum[i] = prefix_even_sum[i - 1];
      prefix_odd_sum[i] = prefix_odd_sum[i - 1] + arr[i];

    } else {
      prefix_odd_sum[i] = prefix_odd_sum[i - 1];
      prefix_even_sum[i] = prefix_even_sum[i - 1] + arr[i];
    }
  }

  for (int i = 0; i < n; ++i) {

    int pse_delta = -prefix_odd_sum[i], pso_delta = -prefix_even_sum[i];

    if (i != 0) {
      pse_delta += prefix_even_sum[i - 1];
      pso_delta += prefix_odd_sum[i - 1];
    }

    int even_sum = prefix_odd_sum[n - 1] + pse_delta;
    int odd_sum = prefix_even_sum[n - 1] + pso_delta;

    if (even_sum == odd_sum) {

      count++;
      //   cout<<"index: " <<i <<" , sum: "<< even_sum <<'\n';
    }
  }

  return count;
}

int main() {

  vector<int> arr = {4, 3, 2, 7, 6, -2};

  cout << solve1(arr) << '\n';

  return 0;
}