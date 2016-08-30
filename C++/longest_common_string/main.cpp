#include <iostream>
#include <string>
using namespace std;

int dp[1001][1001];

int main(){
	string str1,str2;
	cin>>str1>>str2;
	for(unsigned int i = 0; i < str1.length(); i++){
		if(str1[i] == str2[0])
			dp[i][0] = 1;
		else dp[i][0] = 0;
	}
	for(unsigned int i = 0; i < str2.length(); i++){
		if(str2[i] == str1[0])
			dp[0][i] = 1;
		else dp[0][i] = 0;
	}
	for(unsigned int i = 1; i < str1.length(); i++){
		for(unsigned int j = 1; j < str2.length(); j++){
			if(str1[i] == str2[j])
				dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = 0;
		}
	}
	for(unsigned int i = 0; i < str1.length(); i++){
		for(unsigned int j = 0; j < str2.length(); j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
}
