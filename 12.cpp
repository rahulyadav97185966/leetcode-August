//Pascal's Triangle II


class Solution {
public:
   vector<int> getRow(int rowIndex) {
       vector <int> ans (rowIndex + 1);              // Even from the example we can see that k-th row has k + 1 element
       for(int i = 0; i <= rowIndex; ++i)            // Because of 'Note that the row index starts from 0.' from the description, we start at i = 0
           for(int j = i; j >= 0; --j)               // We update from right to left
               ans[j] = j ? ans[j] + ans[j - 1] : 1; // If 'j' isn't 0, we apply our formula. If 'j' is 0, then we are at the first column and ans[j] should be 1.
       return ans;
   }
};
