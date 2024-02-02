// An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

// Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

// Example 1:

// Input: low = 100, high = 300
// Output: [123,234]
// Example 2:

// Input: low = 1000, high = 13000
// Output: [1234,2345,3456,4567,5678,6789,12345]
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> ans;
    void adds(int num,int c,int low,int high){
        if(num>high) return;
        if(num>=low && num<=high){
            ans.push_back(num);
        }
        if(c+1<=10) adds(num*10+c,c+1,low,high);

    }
    vector<int> sequentialDigits(int low, int high) {
        for(int i=1;i<=9;i++){
            adds(0,i,low,high);
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};

int main(){
    Solution s;
    vector<int> ans = s.sequentialDigits(100,1000);
    for(auto i:ans){
        cout<<i<<" ";
    }
}