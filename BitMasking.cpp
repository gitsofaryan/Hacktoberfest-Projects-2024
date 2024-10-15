#include <bits/stdc++.h>
using namespace std;

// Function to find the number of ways to assign caps to
// people such tcap each person gets a unique cap
int solve(int capId, int mask, int n, int mod,
          vector<vector<int> >& dp,
          vector<vector<int> >& capToPeople)
{

    // If all people have been assigned a cap, return 1
    if (mask == (1 << n) - 1)
        return 1;

    // If all caps have been considered and not all people
    // have caps, return 0
    if (capId == 101)
        return 0;

    // Check if the result for this state is already
    // computed
    if (dp[capId][mask] != -1)
        return dp[capId][mask];

    int res = 0;

    // Try assigning the current cap to each person who
    // likes it
    for (auto people : capToPeople[capId]) {

        // Check if the person already has a cap
        if ((1 << people) & mask)
            continue;

        // Assign the current cap to the person and move to
        // the next cap
        res = (res
               + solve(capId + 1, (1 << people) | mask, n,
                       mod, dp, capToPeople))
              % mod;
    }

    // Consider the case where the current cap is not
    // assigned to anyone
    res = (res
           + solve(capId + 1, mask, n, mod, dp,
                   capToPeople))
          % mod;

    // Store the result in dp array for future reference
    return dp[capId][mask] = res;
}

// Main function to calculate the number of ways to assign
// caps to people
int numberWays(vector<vector<int> >& caps)
{

    // Map caps to the list of people who prefer them
    vector<vector<int> > capToPeople(101);
    int n = caps.size();

    // Fill the capToPeople mapping
    for (int i = 0; i < n; i++) {
        for (auto cap : caps[i]) {
            capToPeople[cap].push_back(i);
        }
    }

    // Initialize dp array and other variables
    int capId = 0, mask = 0, mod = 1e9 + 7;
    vector<vector<int> > dp(101, vector<int>((1 << n), -1));

    // Call the solve function starting from the first cap
    return solve(capId, mask, n, mod, dp, capToPeople);
}

// Driver code
int main()
{
    vector<vector<int> > caps1
        = { { 3, 4 }, { 4, 5 }, { 5 } };
    cout << numberWays(caps1) << endl;

    vector<vector<int> > caps2
        = { { 1, 2, 3 }, { 1, 2 }, { 3, 4 }, { 4, 5 } };
    cout << numberWays(caps2) << endl;

    return 0;
}
