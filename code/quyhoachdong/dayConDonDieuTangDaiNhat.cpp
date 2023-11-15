#include <iostream>
#include <limits.h>

using namespace std;

void showArr(int x[], int n){
	for(int i = 0; i <n; ++i)
		cout << x[i]<< " ";
	cout << endl;	
}

void result(int x[], int T[], int n){
	int k = T[0];
	while(k != n + 1){	
		int item = x[k];
		cout << item << " ";
		k = T[k];
	}
}

void alg(int x[], int n){
	int L[n + 2] = {1};
	int a[n + 2] = {0};
	int T[n + 2] = {n + 1};
	for(int i = 0; i < n; ++i){
		a[i + 1] = x[i];
	}
	L[n + 1] = 1;
	a[0] = INT_MIN;
	a[n + 1] = INT_MAX;
	
	for(int i = n  ; i >= 0; --i){
		int j = n + 1;
		while(j > i){
			if(a[i] < a[j] &&L[j] + 1 > L[i] ){				
					L[i] = L[j] + 1;
					T[i] = j;					
			}
			--j;	
		}		
	}
//	for(int i = n;i >= 0;i--){
//		int jmax = n + 1;
//		for(int j = i + 1;j <=n + 1;j++){
//			if(a[j] > a[i] && L[j] > L[jmax])
//				jmax = j;
//		}
//		L[i] = L[jmax] + 1;
//		T[i] = jmax;
//	}
	showArr(L, n + 2);
	showArr(T,n + 2);
	
	result(a,T,n);

}

int main(){
	int x[] = {1,8,3,4,9,10,5,11,7};
	alg(x,9);
	return 0;
}
