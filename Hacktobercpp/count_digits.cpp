/*Given a number n. Count the number of digits in n which evenly divide n. Return an integer, total number of digits of n which divides n evenly.

Note :- Evenly divides means whether n is divisible by a digit i.e. leaves a remainder 0 when divided.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evenlyDivides(int N) {
        int count = 0;
        int temp = N;

        while (temp > 0) {
            int last_digit = temp % 10;
            temp = temp / 10;

            // Check if the last digit is non-zero and divides N
            if (last_digit != 0 && N % last_digit == 0) {
                count++;
            }
        }

        return count;
    }
};

// Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }

    return 0;
}
