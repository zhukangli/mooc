#include<iostream>
#include<cmath>
using namespace std;
int main() {
	char s;
	cin>>s;
	if(s == 'a') {
		cout<<"zab";
	} else if(s == 'A') {
		cout<<"ZAB";
	} else if(s =='z') {
		cout<<"yza";
	} else if(s =='Z') {
		cout<<"YZA";
	} else {
		//����s-1Ϊascii�룬��ת��char�� 
		cout<<(char)(s-1)<<s<<(char)(s+1);
	}
}
