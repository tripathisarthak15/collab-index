#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
     int largestPerimeter(vector<int>& nums) {
        
        for(int i = 0 ; i<3;i++)
        {
            cin>>nums[i];
        }
        int i=0;
        
        if(nums[i]+nums[i+1]>nums[i+2] || nums[i+2]+nums[i+1]>nums[i] || nums[i]+nums[i+2]>nums[i+1])
        return nums[i]+nums[i+1]+nums[i+2];
        
        else
            return 0;

        
    }
};

int main()
{   Solution s1;
    vector<int> vect; 
    cout<<s1.largestPerimeter(vect[]);

    return 0;
}