#include <iostream>

using namespace std;

void showConfig(int x[], int n){
	for(int i = 0; i < n; ++i){
		cout << x[i];
	}
	cout << endl;
}

void nextConfig(int x[], int n, int i){
	x[i] = 1;
	++i;
	while(i < n){
		x[i] = 0;
		++i;
	}	
}

void generate(int n){
	int x[n] = {0};
	int i;
	do{
		i = n-1;
		showConfig(x, n);
		while(x[i] == 1) --i;
		nextConfig(x,n,i);
	}while(i >= 0);
}
int main(){
	generate(4);
	return 0;
}
