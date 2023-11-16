#include <iostream>

using namespace std;

void show2dArr(int x[], int row, int col){
	for(int i = 0; i < row; ++i){
		for(int j = 0; j < col; ++j){
			cout << x [+ i*col + j]<< " ";
		}
		cout << endl;
	}
	
}

void showAns(int x[], int v[], int w[], int m, int n){
	int r = n + 1;
	int c = m + 1;
	const int max = x[r*c -1];
	cout <<"max = "<< max;	
	
	int i = n;
	int j = m;
	while(i != 0){
		if(x[i*c + j] != x[(i - 1)*c +j]){
			cout << i<< " ";
			j= j - w[i];
		}
		--i;
	}
	
}

int alg(int weight[], int value[], int m, int n, int r[]){
	int w[n+1];
	int v[n+1];
	int row = n + 1;
	int col = m + 1;	
	for(int i = 0;i < n; ++i){
		w[i + 1] = weight[i];
		v[i+ 1] = value[i];
	}	
	int t[(6 + 1)*(4 + 1)]={0};
	for(int i = 1; i < row; ++i){
		int wi = w[i];
		int vi = v[i];
		for(int j = 1;j < col; ++j){
			int preV = t[(i - 1)*col +j];
			t[i*col + j] = preV;
			if(j >= wi){
				int newV = t[(i - 1)*col + j-wi] + vi;
				if(newV > preV)
				t[i*col + j] = newV;				
			}			
							
		}
	}
	show2dArr(t,row, col);
	showAns(t,v,w,n,m);	
	return t[row*col - 1];
}


int main(){
	int w[]={2,1,4,3};
	int v[]={3,3,4,2};	
	int r[4];
	alg(w,v,6,4,r);
	
	
	return 0;
}
