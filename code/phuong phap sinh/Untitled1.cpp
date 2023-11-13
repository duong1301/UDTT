#include <iostream>

using namespace std;
float b[100];

void MergeSort(float a[], int l, int r){
	if(r < l){
		int m = (l + r)/2;
		MergeSort(a,l,m);
		MergeSort(a,m + 1, r);
		for(int i = m; i >= l; i--)
			b[i] = a[i];
		for(int j = m + 1; j <=r;++j)
			b[r+m+1-j] = a[j];
		i=l;j=r;
		for(int k = l; k <=r;k++)
		if(b[i]<b[j]){
			a[k] = b[i]; i++;
		}else{
			a[k] = b[j];i--;
		}
	}
}

void show(float x[], int n){
	for(int i = 0; i < n; ++i){
		cout << x[i]<< " ";
	}
}
int main(){
	int x[]={1,5,7,100,243,567,888};
	MergeSort(x,0,6);
	show(x,7);
}
