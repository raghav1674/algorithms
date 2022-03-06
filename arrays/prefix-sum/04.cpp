// Given an array and q queries, find the sum of even indexed elements.

#include <climits>
#include <iostream>
#include <vector>
using namespace std;

/*      0 1 2 3 4 5
        1,2,3,4,5,6

        if i is even, add , else skip it.
        pse: 1,1,4,4,9,9

        [0,1]: pse[1] = 1
        [2,4]: pse[4] - pse[1] = 9 - 1 = 8

*/

// TC: O(N)
// SC: O(N)
vector<int> solve1(vector<int> &arr, vector<pair<int, int>> &q) {

  int n = arr.size();
  int qn = q.size();
  int prefix_even_sum[n];
  prefix_even_sum[0] = arr[0];

  vector<int> result;

  for (int i = 1; i < n; ++i) {

    if (i & 1) {

      prefix_even_sum[i] = prefix_even_sump[i - 1];
    } else {

      prefix_even_sum[i] = prefix_even_sum[i - 1] + arr[i];
    }
  }

  for (int i = 0; i < qn; ++i) {

    int L = q[i].first;
    int R = q[i].second;

    if (L == 0) {

      result.push_back(prefix_even_sum[R]);

    } else {

      result.push_back(prefix_even_sum[R] - prefix_even_sum[L - 1]);
    }
  }
  return result;
}