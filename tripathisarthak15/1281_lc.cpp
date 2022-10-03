#include <iostream>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int mul=1,sum=0;
        
        
        while(n!=0)
        {
            sum=sum+(n%10);
            mul=mul*(n%10);
            n=n/10;            
        }
        return mul-sum;
    }};

int main()
{
    Solution s1;
    cout<<"Enter Num: ";
    int num; cin>>num;
    cout<<s1.subtractProductAndSum(num);

    return 0;    
}