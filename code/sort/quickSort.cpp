#include <iostream>

using namespace std;
void quickSort(int x[], int left, int right){
	if(left >= right) return;
	int l = left;
	int r = right;
	int m = (left + right)/2;
	int midVal = x[m];	
	while(l < r){
		while(x[l] < midVal && l < r ) ++l;
		while(x[r] > midVal  && l < r) --r;
		if(l < r) {
			swap(x[l], x[r]);			
		}
		l++; 
		r--;
	}	
	quickSort(x, left,r);
	quickSort(x, l, right);
}

void show(int x[], int n){
	for(int i = 0; i< n; ++i)
		cout << x[i]<<" ";
	cout << endl;
}
int main(){
	int x[] = {5,0};
	
	int n = sizeof(x)/sizeof(int);
	show(x, n);
	quickSort(x,0,n - 1);
	show(x, n);
	return 0;
}
