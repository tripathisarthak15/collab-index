#include <iostream>
using namespace std;

class Solution {
    public:
        bool isHappy(int n) {
            int sum=0;
            int rem,i=1;
            while(sum!=1||n>0)
            {
                if(i>10)break;
                rem=n%10;
                sum=sum+(rem*rem);
                n/=10;
            if(n==0)
            {
                if(sum==1) 
                return true;
                n=sum;
                sum=0;
                i++;}}
                return false;
}
};

int main()
{
    Solution s1;
    int num;
    cout<<"Enter Number: "; cin>>num;
    if(s1.isHappy(num)==1)
    cout<<"Happy Number";
    else
    cout<<"Not a happy number :_(";
    return 0;
}