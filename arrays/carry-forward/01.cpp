// Given a string, count the pairs of i,j where s[i] = 'a' and s[j] = 'g' and
// i<j.

// approach 1: for each a count all g after that.

#include <climits>
#include <iostream>
#include <string>

using namespace std;

// TC: O(N^2)
// SC: O(1)
int solve1(string &s) {

  int count = 0;
  int n = s.size();
  for (int i = 0; i < n; ++i) {

    if (s[i] == 'a') {

      for (int j = i + 1; j < n; ++j) {

        if (s[j] == 'g') {

          count++;
        }
      }
    }
  }
  return count;
}

// carry forward the count of a
// TC: O(N)
// SC: O(1)

int solve2(string &s) {

  int count_a = 0;
  int count = 0;
  int n = s.size();

  for (int i = 0; i < n; ++i) {

    if (s[i] == 'a') {
      count_a++;
    } else if (s[i] == 'g') {

      count += count_a;
    }
  }

  return count;
}

int solve3(string &s) {

  int count_g = 0;
  int count = 0;
  int n = s.size();

  for (int i = n-1; i >= 0; i--) {

    if (s[i] == 'g') {
      count_g++;
    } else if (s[i] == 'a') {

      count += count_g;
    }
  }

  return count;
}

int main() {

  string s = "baagdcag";

  cout << solve1(s) << '\n';
  cout << solve2(s) << '\n';
  cout << solve3(s) << '\n';


  return 0;
}
