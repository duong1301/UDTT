#include <iostream>
#include <limits.h>
using namespace std;

void daycon(int x[], int n){
	n +=2;
	int a[n]={0};
	int L[n] = {0};
	int T[n] = {0};
	for(int i = 0;i<(n - 2); ++i){
		a[i + 1] = x[i];
	}
	a[0] = INT_MIN;
	a[n - 1] = INT_MAX;
	L[n - 1] = 1;
	for(int i = n - 1; i >=0; --i){
		int jmax = n-1 ;
		for(int j = i + 1; j < n; ++j){			
			if(a[i] < a[j] && L[j] > L[jmax] ){
				jmax = j;
			}
			L[i] = L[jmax] + 1;
			T[i] = jmax;
		}
	}
	
	int i = 0;
	while(i < n -2){
		i = T[i];
		cout << a[i]<< " ";		
	}
}


int main(){
	int n = 10;
	int x[] = {5,2,3,4,9,10,5,6,7,8};
	daycon(x, n);
	return 0;
}
