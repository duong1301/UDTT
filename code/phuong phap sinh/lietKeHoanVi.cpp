#include <iostream>

using namespace std;

void showConfig(int x[], int n){
	for(int i = 0; i< n; ++i){
		cout << x[i];
	}	
	cout << endl;
}

void nextConfig(int x[], int n, int i){
	--i;
	int k = n - 1;
	while(x[k] < x[i]) --k;
	swap(x[i], x[k]);	
	++i;
	int j = n -1;
	while (i < j){
		swap(x[i], x[j]);
		++i; --j;
	}
}

void generate(int n){
	int x[n] = {0};
	for(int i = 0; i < n; ++i){
		x[i] = i + 1;
	}
	int i = n - 1;
	do{
		showConfig(x, n);
		i = n - 1;
		while(i > 0 && x[i - 1] > x[i] )--i;
		if(i >0 ) nextConfig(x,n,i);
	}while(i >0);
}

int main(){
	generate(4);
//	//1 2 3 4 5 6
//	//1 2 3 4 6 5

//	int x[6] = {1,2,3,4,6,5};
//	nextConfig(x,6,4);
//	showConfig(x,6);
	return 0;
}
