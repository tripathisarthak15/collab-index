#include <iostream>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int mul=1,sum=0,rem,temp;
        temp=n;
        
        while(n!=0)
        {
            rem=n%10;
            sum=sum+rem;
            n=n/10;            
        }
        
        while(temp!=0)
        {
            rem=temp%10;
            mul=mul*rem;
            temp=temp/10;            
        }
        n=mul-sum;
        
        return n;
    }};

int main()
{
    Solution s1;
    cout<<"Enter Num: ";
    int num; cin>>num;
    cout<<s1.subtractProductAndSum(num);

    return 0;    
}