#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int sum=0;
        char p='0';
        for(auto i=s.begin(); i!=s.end(); i++) {
            switch(*i) {
            case 'I':
                sum=sum+1;
                break;
            case 'V':
                sum=sum+5;
                if(p=='I')
                    sum=sum-2;
                break;
            case 'X':
                sum=sum+10;
                if(p=='I')
                    sum=sum-2;

            case 'L':
                sum=sum+50;
                if (p == 'X') sum =sum-20;
                break;
            case 'C':
                sum =sum+ 100;
                if (p == 'X') sum=sum- 20;
                break;
            case 'D':
                sum =sum+500;
                if (p == 'C') sum=sum-200;
                break;
            case 'M':
                sum=sum+1000;
                if (p== 'C') sum =sum-200;
                break;
            }
            p = *i;
        }
        return sum;
    }
};

int main()
{
    Solution s1;
    string str;
    cout<<"Enter Roman Number: "; cin>>str;
    cout<<"Integer Equivalent: "<<s1.romanToInt(str);
    return 0;
}