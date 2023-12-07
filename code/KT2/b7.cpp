#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

struct hoiThao{
	string chuDe;
	float batDau;
	float ketThuc;
};

void assign(hoiThao &h, string chuDe, float batDau, float ketThuc){
	h.chuDe = chuDe;
	h.batDau = batDau;
	h.ketThuc = ketThuc;
}
bool cmp(hoiThao a, hoiThao b){
	return a.ketThuc < b.ketThuc;
}

void hienThi(hoiThao h){
	cout << "Chu de: "<< h.chuDe<< endl ;
	cout << "bat dau: "<< h.batDau<<"|";
	cout << "ket thuc: "<< h.ketThuc;
}
void hienThi(hoiThao s[], int n){
	for(int i = 0; i < n; ++i){
		hienThi(s[i]);
		cout <<endl<< "--------"<< endl;
	}
}

int greedy(hoiThao s[], int n, int result[]){
	int count = 1;
	result[0] = 1;
	int j = 0;
	for(int i = 1; i < n; ++i){
		if(s[i].batDau >= s[j].ketThuc){
			result[i] =1;
			j = i;
			count++;
		}
	}	
	return count;
}

void hienThiKetQua(hoiThao ht[], int n, int result[]){
	for(int i = 0; i < n; ++i){
		if(result[i]){
			hienThi(ht[i]);
			cout <<endl<< "-----------"<<endl;
		}
	}	
}

int main(){
	int n = 5;
	hoiThao ht[n];
	assign(ht[0], "tim kiem viec lam", 7, 9);
	assign(ht[1], "nang cao ky nang mem", 8.5, 10);
	assign(ht[2], "ky nang viet cv", 7, 8.5);
	assign(ht[3], "hoi thao X", 9, 11.5);
	assign(ht[4], "hoi thao Y", 13, 14.5);
	hienThi(ht, n);
	cout << "sorted"<< endl;
	sort(ht,ht + n,cmp);
	hienThi(ht, n);
	int result[n] ={0};
	int max = greedy(ht,n,result);
	cout << "Ket qua: "<< endl;
	cout << "So luong hoi thao toi da: "<< max<< endl;
	hienThiKetQua(ht,n, result);
	return 0;
}
