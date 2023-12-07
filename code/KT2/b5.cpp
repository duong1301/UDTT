#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int charInString(char x, char *s){
	for(int i = 0; i < strlen(s); ++i)
		if(x == s[i]) return i;
	return -1;	
}

void coppyArr(string src[], string dest[], int n){
	for(int i = 0; i < n; ++i){
		dest[i] = src[i];
	}	
}

int boyer(char * p, char * t){
	int m = strlen(p);
	int n = strlen(t);
	int v = m - 1;
	int i = v;
	int count = 0;
	int x[n] = {0};
	while(i < n){
		int k = i;
		int j = v;
		while(t[k] == p[j] && j >= 0){
			k--; j--;
		}
		if(j < 0){
			++k;
			x[k] = 1;
			count++;
			i = i + m;			
		}else{
			i = i + v - charInString(t[k], p);
		}
	}	
	
	
	return count;
}
bool cmp(string a, string b){
	return a.length() > b.length();	
}
int greedy(string d[], int n,int k, int result[]){
	int count = 0;
	for(int i = 0; i < n; ++i){
		if(d[i].length() <= k){
			result[i] = 1;
			k = k - d[i].length();
			count++;
		}
	}
		
	if(0 == k) return count;
	return 0;
}

void showList(string s[], int n){
	for(int i = 0; i < n; ++i){
		cout << s[i]<<"| length = "<<s[i].length()<< endl;
	}	
}

int contain(string d[], int result[], int n, string word){
	int count = 0;
	for(int i = 0; i < n; ++i){						
		if(boyer(&word[0],&d[i][0])){
			result[i] = 1;
			count++;
		}
	}	
	return count;
}

void z_alg(char * str, int z[]){
	int n = strlen(str);
	
	int left = 0;
	int right = 0;
	for(int i = 1; i < n; ++i){
		
		if(i > right){
			left = i;
			right = i;
			while(str[right] == str[right - left]){
				right++;
			}	
			
			z[i] = right - left;
			--right;
		}else{
			if(z[i-left] < right -i+1){
				z[i] = z[i - left];
			}else{
				left = i;
				while(str[right] == str[right - left]){
				right++;
			}	
			
			z[i] = right - left;
			--right;
			}
		}
	}
			
}

int checkSubstring(string s, string str){
	string x = s+"$"+str;
	int k = s.length();
	int count = 0;
	int n = x.length();
	int z[n] = {0};
	z_alg(&x[0],&z[0]);	
	for(int i = 0; i < n; ++i){
		if(z[i] == k){
			count++;
		}	
	}
	return count;	
}

int main(){

	int n = 5;
	string d[n];
	int k = 55;
	d[0] = "child";
	d[1] = "she has a child, her child is 10 years old";
	d[2] = "she has 2 children a boy and a girl";
	d[3] = "that is her child";
	d[4] = "her daughter is so cute";
	string d2[n];
	coppyArr(d,d2,n);
	 
	sort(d, d + n, cmp);
	showList(d,n);
	int result[n] = {0};
	int count = greedy(d,n,k,result);
	cout << endl;
	if(count){
		cout << "Voi k = "<<k<<" Can su dung it nhat "<< count << " xau : "<< endl;
		for(int i = 0 ; i < n; ++i){
			if(result[i] != 0){
				cout << d[i]<<"| length = "<< d[i].length()<< endl;
			}
		}
	}else{
		cout << "k = "<< k <<" Khong tim thay phuong an"<< endl;
	}
	
	cout << endl<<"contain child";
	count = contain(d,result,n,"child");
	cout << endl;
	if(count){
		cout << "tu child xuat hien trong "<< count<<" xau: "<< endl;
		for(int i = 0; i < n; ++i){
			if(result[i])cout << d[i]<< endl;
		}
	}
	cout << endl<< "xau d[0]: '"<<d2[0]<<"' xuat hien trong : "<< endl;
	for(int i = 1; i < n; ++i){
		int count = checkSubstring(d2[0], d2[i]);
		if(count){
			cout <<"Xau "<<i<<": '"<< d2[i]<<"'| "<< count<< " lan"<< endl;
		}
		
	}
	
	
	return 0;
}
