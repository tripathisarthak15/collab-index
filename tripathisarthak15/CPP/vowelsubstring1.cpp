#include<iostream>
#include<vector>
using namespace std;


int isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return 1;
	}
	return 0;
}
vector<int> kSubstringVowels(string s, int k) {
	int n = s.length();
	vector<int> vowels(n + 1 - k);
	int count = 0;
	for (int i = 0; i < k; i++) {
		count += isVowel(s[i]);
	}
	vowels[0] = count;
	for (int i = k; i < n; i++) {
		count = count - isVowel(s[i - k]) + isVowel(s[i]);
		vowels[i - k + 1] = count;
	}
	return vowels;
}

int main()
{   string s1; int n;
    cin>>s1>>n;
    cout<<kSubstringVowels(s1,n);
    return 0;
}
