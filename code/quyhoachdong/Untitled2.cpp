#include <iostream>

using namespace std;

void show(int x[], int n){
	for(int i =0; i < n; ++i)
		cout << x[i]<< " ";
	cout << endl;
}

int * foo(){
	int a[]={1,2,3,4};
	cout << a<< endl;
	show(a, 4);
	return a;
}

int main(){
	
	int * p = foo();

	cout << *(p + 3)<<" ";
	
	
	return 0;
}
