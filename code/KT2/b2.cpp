#include <iostream>
#include <algorithm>
using namespace std;

struct Quat {
	string tenHang;
	string mauSac;
	int giaBan;
};

int greedy(Quat d[], int n, int p, int ans[]){	
	int count = 0;
	for(int i = 0; i < n; ++i){
		if(d[i].giaBan <= p){
			p = p - d[i].giaBan;
			ans[i] = 1;
			count++;
		}
	}
	if(p == 0) return count;
	return 0;
}
void assign(Quat &q ,string tenHang, string mauSac, int giaBan){
	q.tenHang = tenHang;
	q.mauSac = mauSac;
	q.giaBan = giaBan;	
}

void hienThi(Quat q){
	cout << "Ten hang : "<< q.tenHang<< " | ";
	cout << "Mau sac : "<< q.mauSac<< " | ";
	cout << "Gia ban : "<< q.giaBan;	
	
}

void hienThiDanhSach(Quat d[], int n){
	for(int i = 0; i < n; ++i){
		hienThi(d[i]);
		cout << endl;
	}
}

void hienThiKetQua(Quat d[], int n, int ans[]){
	for(int i = 0; i < n; ++i){
		if(ans[i] != 0){
			hienThi(d[i]);
			cout << endl;
		}
	}
}
bool cmp(Quat a, Quat b){
	return a.giaBan > b.giaBan;
}
int main(){
	int n = 5;
	int p = 1150000;
	Quat d[5];
	assign(d[0],"xiaomi", "trang", 500000);
	assign(d[1],"sharp", "trang", 400000);
	assign(d[2],"toshiba", "trang", 450000);
	assign(d[3],"xiaomi", "trang", 550000);
	assign(d[4],"boosh", "trang", 600000);
	sort(d, d + n, cmp);
	hienThiDanhSach(d, n);
	int ans[n] = {0};
	int count = greedy(d,n,p,ans);
	
	if(count){
		cout << endl;
		cout <<"Can ban it nhat "<< count<< " chiec quat de thu duoc so tien dung bang "<< p<< endl;
		cout << "Danh sach quat can ban: "<< endl;
		hienThiKetQua(d,n,ans);
	}else{
		cout << "Khong co ket qua";
	}
	return 0;
}
