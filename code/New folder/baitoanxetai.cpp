#include <iostream>

using namespace std;

int truckAlg(int x[], int n, int m, int r[]){
	int i = 0;
	int j = 0;
	while( m > 0 && i < n){
		m -= x[i];
		x[j] = x[i];
		++j;
		++i; 
	}
	if(i == n && m > 0){
		return 0;
	}
	
	return j;
	
}


int main(){
	int m = 38;
	int x[] = {25,12,8,6};
	int n = sizeof(x)/sizeof(int);
	int r[n];
	cout << truckAlg(x,n,m,r);
	return 0;
}
