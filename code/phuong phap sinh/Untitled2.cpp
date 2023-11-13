#include <iostream>

using namespace std;

void quick_sort(int a[], int left, int right){
	if(left < right){
		int k = (left + right)/2;
		int t = a[k];
		int i = left, j = right;
		do{
			while (a[i] < t) i = i + 1;
			while (a[j] > t) j = j - 1;
			if(i <=j){
				swap(a[i], a[j]);	
				i++;
				j--; 
			}
		}while(i <=j);
		quick_sort(a, left, j);
		quick_sort(a, i, right);
	}
}

void show(int x[], int n){
	for(int i = 0; i < n; ++i){
		cout << x[i]<<" ";
	}cout << endl;
}
int main(){
	int x[] ={1,2,3,4,12,3,5,6,6,4,4};
	quick_sort(x,0,10);
	show(x,11);
	return 0;
	
}
