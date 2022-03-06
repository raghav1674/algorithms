// Given N elements and Q queries, find the sum b/w L and R.
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// Approach 1: simply loop b/w L and R and calculate sum on the go.
// TC: O(Q*(R-L+1)) == O(Q*N)
// SC: O(1)
vector<int> solve1(vector<int> &arr, vector<pair<int, int>> &q) {

  int n = arr.size();
  int qn = q.size();

  vector<int> result;

  for (int i = 0; i < qn; ++i) {

    int L = q[i].first;
    int R = q[i].second;
    int sum = 0;
    for (int j = L; j <= R; ++j) {

      sum += arr[j];
    }
    result.push_back(sum);
  }
  return result;
}

// Approach 2: can we store the sum before hand and just lookup ?

/*

    1,2,3,4

    sum[0,0] = 1
    sum[0,1] = 2 + 1
    sum[0,3] = 3 + 2 + 1
    sum[0,4] = 4 + 3 + 2 + 1

    in general:
        ps[0,I] = ps[I-1] + A[I]

    find sum[2,4] ?
     sum[2,4] = ps[4,0] - ps[1,0]
     sum[0,3] = ps[0,3]

     in general:
        sum[L,R] = ps[R] - ps[L-1]
        sum[0,R] = ps[R]

*/

// TC: O(Q*1) = O(Q)
// SC: O(N)
vector<int> solve2(vector<int> &arr, vector<pair<int, int>> &q) {

  int n = arr.size();
  int qn = q.size();
  int prefix_sum[n];

  vector<int> result;

  prefix_sum[0] = arr[0];

  for (int i = 1; i < n; ++i) {

    prefix_sum[i] = prefix_sum[i - 1] + arr[i];
  }

  for (int j = 0; j < qn; ++j) {

    int L = q[j].first;
    int R = q[j].second;

    int sum = 0;

    // sum[0,R] = ps[R]
    if (L == 0) {

      result.push_back(prefix_sum[R]);
    } else {
      // sum[L,R] = ps[R] - ps[L-1]
      result.push_back((prefix_sum[R] - prefix_sum[L - 1]));
    }
  }
  return result;
}

int main() {

  vector<int> arr = {1, 2, 3, 4, 5};

  vector<pair<int, int>> queries = {{1, 2}, {0, 4}, {1, 3}, {0, 0}};

  for (int i : solve1(arr, queries)) {

    cout << i << ' ';
  }

  cout<<'\n';

  for(int i: solve2(arr,queries)){

      cout<< i << ' ';
  }

  return 0;
}