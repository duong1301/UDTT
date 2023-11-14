#include <iostream>
#include <bits/stdc++.h> 

using namespace std;



int alg(int n){
	int m = n;
	int f[m + 1][n + 1];
	// truong hop suy bien
	for(int i = 0; i <=m; ++i)
		for(int j = 0; j <= n; ++j){
			f[i][j] = 0;
		}
	
	for(int i = 0; i <=m; ++i){
		f[i][0] = 1;
	}
	
	//
	for(int i = 1; i <=m ; ++i){
		for (int j = 1; j <=n; ++j){
			if(i > j){
				f[i][j] = f[i - 1][j];
			}else{
				f[i][j] = f[i - 1][j] + f[i][j - i];
			}
		}
	}
	
	// hien thi bang phuong an
	
	for(int i = 0; i <=m; ++i){
		for(int j = 0; j <= n; ++j){
			cout << f[i][j]<< " ";
		}
		cout << endl;
	}
	
	return f[m][n];
}

int main(){
	cout << alg(7);
	return 0;
}
