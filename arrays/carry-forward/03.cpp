// Given an array, find the smallest length subarray which contains both the min
// and the max element.

/*
   0    1   2   3   4   5   6   7   8   9
   1    2   3   1   3   4   6   4   6   3

   min: 1
   max: 6

   ans:[3,6]

*/
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> get_min_max(vector<int> &arr) {

  int mini = INT_MAX, maxi = INT_MIN, min_idx = -1, max_idx = -1;
  int n = arr.size();
  for (int i = 0; i < n; ++i) {

    if (mini > arr[i]) {

      mini = arr[i];
      min_idx = i;
    }

    if (maxi < arr[i]) {

      maxi = arr[i];
      max_idx = i;
    }
  }
  return {min_idx, max_idx};
}

// TC: O(N*N)
// SC: O(1)

pair<int, int> solve1(vector<int> &arr) {

  pair<int, int> min_max = get_min_max(arr);

  if (min_max.first == min_max.second) {

    return {min_max.first, min_max.second};
  }
  int n = arr.size();
  int min_element = arr[min_max.first];
  int max_element = arr[min_max.second];

  int min_range = INT_MAX;
  pair<int, int> answer;

  vector<pair<int, int>> possible_ranges;

  for (int L = 0; L < n; ++L) {

    if (arr[L] == min_element) {
      for (int R = L + 1; R < n; ++R) {

        if (arr[R] == max_element) {

          possible_ranges.push_back({L, R});

          if (R - L + 1 < min_range) {

            min_range = R - L + 1;
            answer.first = L;
            answer.second = R;
          }
          break;
        }
      }
    } else if (arr[L] == max_element) {
      for (int R = L + 1; R < n; ++R) {

        if (arr[R] == min_element) {

          possible_ranges.push_back({L, R});

          if (R - L + 1 < min_range) {

            min_range = R - L + 1;
            answer.first = L;
            answer.second = R;
          }
          break;
        }
      }
    }
  }

  return answer;
}

// approach 2: store the info of last max and last min index
// TC: O(N)
// SC: O(1)
pair<int, int> solve2(vector<int> &arr) {

  int min_idx = -1, max_idx = -1;
  pair<int, int> min_max = get_min_max(arr);

  if (min_max.first == min_max.second) {

    return {min_max.first, min_max.second};
  }
  int n = arr.size();
  int min_element = arr[min_max.first];
  int max_element = arr[min_max.second];
  int min_range = INT_MAX;
  pair<int, int> answer;

  for (int i = n - 1; i >= 0; --i) {

    if (arr[i] == max_element) {

      max_idx = i;

    } else if (arr[i] == min_element) {

      min_idx = i;
    }

    if (min_idx != -1 && max_idx != -1) {

      int mini = min(max_idx, min_idx);
      int maxi = max(min_idx, max_idx);
      int size = maxi - mini + 1;
      if (size < min_range) {

        min_range = size;
        answer.first = mini;
        answer.second = maxi;
      }
    }
  }
  return answer;
}

int main() {

  vector<int> arr = {1, 2, 3, 1, 3, 4, 6, 4, 6, 3};

  pair<int, int> ans = solve1(arr);

  cout << " L : " << ans.first << " , R: " << ans.second << '\n';

  ans = solve2(arr);

  cout << " L : " << ans.first << " , R: " << ans.second << '\n';

  return 0;
}