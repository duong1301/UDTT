#include <bits/stdc++.h>

using namespace std;

struct Quat{
	string tenHang;
	string mauSac;
	int giaBan;
};

bool greedy(Quat d[], int n, int p, int ans[]){
	bool flag = false;
	for(int i = 0; i < n; ++i){
		if(d[i].giaBan <= p){
			p = p - d[i].giaBan;
			ans[i] = 1;	
			flag = true;
		}		
	}
	return flag;

}

void show(Quat q){
	cout << q.tenHang<<"|";
	cout << q.mauSac<< "|";
	cout << q.giaBan;
}

void showList(Quat d[], int n){
	for(int i = 0; i< n; ++i){
		show(d[i]);
		cout << endl;
	}	
}

void showAns(Quat d[], int ans[], int n){
	
	for(int i = 0; i < n; ++i){
		if(ans[i] !=0){
			cout <<endl;
			show(d[i]);
		}
	}
}

bool cmp(Quat a, Quat b){
	return a.giaBan > b.giaBan;
}

int main(){
	Quat d[5];
	d[0].tenHang = "toshiba";
	d[0].mauSac = "trang";
	d[0].giaBan = 300000;
	
	d[1].tenHang = "sharp";
	d[1].mauSac = "den";
	d[1].giaBan = 250000;
	
	d[2].tenHang = "vinawind";
	d[2].mauSac = "do";
	d[2].giaBan = 270000;	
	
	d[3].tenHang = "xiaomi";
	d[3].mauSac = "trang";
	d[3].giaBan = 500000;
	
	d[4].tenHang = "nobranch";
	d[4].mauSac = "trang";
	d[4].giaBan = 200000; 
	
	sort(d, d + 5, cmp);
	showList(d,5);
	int result[5] = {0};
	bool isSuccess = greedy(d,5,100000, result);
	if(isSuccess){
		cout << "Danh sach san pham mua duoc: "<< endl;
		showAns(d, result, 5);
	}else{
		cout << "Khong tim thay";
	}
	return 0;
}
