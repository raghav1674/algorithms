// return the sum of all subarrays.

/* contribution Technique:
where we calculate the contribution of each element in the array
towards all the subarray and
multiply by that we get the sum of that individual element

eg: [1,2,3]

    [1,1] [1,2] [1,3]
    [2,2] [2,3]
    [3,3]

    contribution of 1 is 3.
                    2 is 4.
                    3 is 3.

    total sum = submission of contri * number
              = 1 * 3 + 2 * 4 + 3 * 3 = 3 + 8 + 9 = 20.

    i element will contribute in :
       i
    1  2  3:  [1,2] [1,3] [2,2] [2,3] = 2 * 2 = 4
          i
    1  2  3: [1,3] [2,3] [3,3]  (i+1)*(n-i) = 3  *  1 = 3

    0   i   N-1

    subarray = [L,R]
    so L can be from 0 to i ie (i+1) and
       R can be from i to N-1 ie (N-i)

    so probablity is (i+1)*(n-i)

*/

#include <iostream>
#include <vector>
using namespace std;

int solve1(vector<int> &arr) {

  int n = arr.size();

  int sum = 0;

  for (int i = 0; i < n; ++i) {

    sum += ((i + 1) * (n - i) * arr[i]);
  }

  return sum;
}

int main() {

  vector<int> arr = {1, 2, 3}; // [1,1], [1,2], [2,2]

  cout << solve1(arr);

  return 0;
}