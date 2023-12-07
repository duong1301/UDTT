#include <iostream>
#include <cstring>
using namespace std;


string alg(string a, string b){
	int m = a.length();
	int n = a.length();
	int x[m + 1][n + 1];
	for(int i = 0; i <=m; ++i)
		for(int j = 0; j <=n; ++j)
			x[i][j] = 0;
			
	for(int i = 1; i <=m; ++i)
		for(int j = 1; j <=n; ++j){
			if(a[i - 1] == b[j - 1]) x[i][j] = x[i - 1][j - 1] + 1;
			else{
				x[i][j] = max(x[i - 1][j], x[i][j - 1]);
			}
		}
	string str = "";
	int i = m;
	int j = n;
	while(i > 0 && j >0){
		if(a[i - 1] == b[j - 1]){
			str = a[i - 1] + str;
			i--; j--;			
		}else{
			if(x[i][j - 1] > x[i - 1][j]){
				j--;
			}else{
				i--;
			}
		}
	}	
	for(int i = 0; i <=m; i++){
		for(int j = 0; j <=n; ++j)
			cout << x[i][j]<<"  ";
		cout << endl;
	}
	return str;
}

int main(){
	string a = "122233wasd4413";
	string b = "wqsdfasd123";
	string s = alg(a,b);
	cout << s;
	
	return 0;
}
