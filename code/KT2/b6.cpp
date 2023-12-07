#include <iostream>

using namespace std;

int * dynamic(int a[], int n, int b[], int m, int result[], int &length){
	int f[n + 1][m + 1];
	for(int i = 0; i <= n; ++i) f[i][0] = 0;
	for(int j = 0; j <= m; ++j) f[0][j] = 0;
	
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <=m; ++j){
			if(a[i - 1] == b[j - 1]){
				f[i][j] = f[i - 1][j - 1]+1;
			}else{
				if(f[i - 1][j] > f[i][j - 1])
					f[i][j] = f[i -1][j];
				else{
					f[i][j] = f[i][j - 1];
				}
			}
		}	
		
	for(int i = 0; i <= n; ++i){
		for(int j = 0; j <=m; ++j){
			cout << f[i][j]<< " ";
		}
		cout << endl;
	}
	length = f[n][m];
	int i = n; int j = m;
	int k = f[n][m] - 1;
	while(f[i][j]){
		if(a[i - 1] == b[j - 1]){
			result[k--] = a[i - 1];
		}
		if(f[i - 1][j] > f[i][j - 1]){
			--i;
		}else{
			--j;
		}	
	}

}

void timDayCon(int a[], int n, int b[], int m){
	int size = max(n,m);
	int result[size];
	dynamic(a,n,b,m,result, size);
	cout << endl;
	for(int i = 0; i < size; ++i){
		cout << *(result + i)<< " ";
	}
	
}

int main(){
	int n = 6;
	int m = 6;
	int a[] = {1,2,3,5,4,6};
	int b[] = {1,3,2,4,6,5};
	timDayCon(a,n,b,m);
	return 0;
}
