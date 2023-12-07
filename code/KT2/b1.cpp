#include <iostream>
#include <algorithm>

using namespace std;
struct Quat{
	string tenHang;
	string mauSau;
	int giaBan;
};

void hienThi(Quat q){
	cout <<"ten hang : "<< q.tenHang<< " | ";	
	cout << "Mau sac : "<< q.mauSau<< " | ";
	cout << "Gia ban : "<< q.giaBan;
}

void hienThiDanhSach(Quat list[], int n){
	for(int i = 0; i < n; ++i){
		hienThi(list[i]);
		cout << endl;
	}	
}

void hienThiKetQua(Quat list[], int n, int ans[]){
	int amount = 0;
	for(int i = 0; i < n; ++i){
		if(ans[i] != 0){
			hienThi(list[i]);
			cout << endl;
			amount += list[i].giaBan;
		}
	}	
	cout << "Tong so tien: "<< amount;
}

int greedy(Quat d[], int n, int p, int ans[]){
	int count = 0;
	for(int i = 0; i < n; ++i){
		if(d[i].giaBan <= p){
			p = p - d[i].giaBan;
			ans[i] = 1;
			count++;
		}
	}
	return count;	
}

bool cmp(Quat a, Quat b){
	return a.giaBan < b.giaBan;	
}
int main(){
	int n = 5;
	int p = 1400000;
	Quat d[5];
	d[0].tenHang = "xiaomi";
	d[0].mauSau = "Trang";
	d[0].giaBan = 500000;
	
	d[1].tenHang = "toshiba";
	d[1].mauSau = "den";
	d[1].giaBan = 400000;
	
	d[2].tenHang = "sharp";
	d[2].mauSau = "den";
	d[2].giaBan = 450000;
	
	d[3].tenHang = "boosh";
	d[3].mauSau = "den";
	d[3].giaBan = 600000;
	
	d[4].tenHang = "xiaomi";
	d[4].mauSau = "den";
	d[4].giaBan = 550000;
	
	sort(d, d + n,cmp);
	cout << "Danh sach mat hang: "<< endl;
	hienThiDanhSach(d, n);
	int selected[n] = {0};
	int count = greedy(d,n,p,selected);
	if(count == 0){
		cout << "Khong co ket qua"<< endl;
	}else{
		cout << "Danh sach quat co the mua voi so tien: "<< p<< endl;
		hienThiKetQua(d,n,selected);
	}
	
	return 0;
}
