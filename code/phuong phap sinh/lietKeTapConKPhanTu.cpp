#include <iostream>

using namespace std;

void showConfig(int x[], int k){
	for(int i = 0; i < k; ++i){
		cout << x[i];
	}
	cout << endl;
}

void nextConfig(int x[], int k, int i){
	x[i]++;
	int floor = x[i];
	++i;
	
	for(;i < k;++i){
		x[i] = ++floor;
	}
}

void generate(int n, int k){
	if(n < k) return;
	int x[k] = {0};
	for(int i = 0; i < k; ++i){
		x[i] = i + 1;
	}
	int i;
	do{		
		showConfig(x, k);
		i = k - 1;
		while( i >= 0 && (x[i] == n - k + i + 1)) --i;
		
		if(i >= 0){
			nextConfig(x,k,i);
		}
	}while(i >= 0);
}

int main(){
	generate(7, 5);
	
	return 0;
}
