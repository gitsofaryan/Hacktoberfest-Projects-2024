#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubarraySum(vector<int> &arr) {
    int res = arr[0];
  
    // Outer loop for starting point of subarray
  	for(int i = 0; i < arr.size(); i++) {
    	int currSum = 0;
      
        // Inner loop for ending point of subarray
        for(int j = i; j < arr.size(); j++) {
        	currSum = currSum + arr[j];
          
            // Update res if currSum is greater than res
            res = max(res, currSum);
        }
    }
    return res;
}

int main() {
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << maxSubarraySum(arr);
    return 0;
}
