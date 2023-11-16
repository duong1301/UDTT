#include <iostream>

using namespace std;

int fibo(int n, int a[]){
	a[1] = a[2] = 1;
	for(int i = 3; i <=n; ++i){
		a[i] = a[i - 1] + a[i - 2];
		
	}
	
	return a[n];
}

void showArr(int x[], int n){
	for(int i = 1; i < n; ++i){
		cout << x[i]<< " ";
	}
}

int main(){
	int x[6];
	cout << fibo(5,x);
	showArr(x,6);
	return 0;
}
