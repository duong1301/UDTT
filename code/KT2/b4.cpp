#include <bits/stdc++.h>
using namespace std;

struct DienThoai{
	string nhanHieu;
	int kichThuoc;
	float giaBan;
};


void assign(DienThoai &d, string nhanHieu, int kichThuoc, float giaBan){
	d.nhanHieu = nhanHieu;
	d.kichThuoc = kichThuoc;
	d.giaBan = giaBan;
}

bool alg(DienThoai d[], int n, int s, int result[]){
	int b[n+1][s+1];
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= s; ++j)
			b[i][j] = 0;
	
	for(int i = 1; i <= n; ++i){
		int si = d[i - 1].kichThuoc;
		int vi = d[i - 1].giaBan;
		for(int j = 1; j <= s; ++j){
			if(si > j){
				b[i][j] = b[i - 1][j];
			}else{
				int vij ;
				if(b[i - 1][j] >= (vi + b[i - 1][j - si])){
					vij = b[i - 1][j];
				}else{
					vij = (vi + b[i - 1][j - si]);
				}
				b[i][j] = vij;
			}
		}
	}
	
//	for(int i =0; i <=n; ++i){
//		for(int j = 0; j <=s; ++j){
//			cout << b[i][j]<< "\t";
//		}
//		cout << endl;
//	}
	
	int i = n;
	int j = s;
	
	while(b[i][j] != 0 ){
		if(b[i][j] != b[i - 1][j]){
			i--;
			result[i] = 1;
			j = j - d[i].kichThuoc;			
		}else{
			--i;
		}
	}
	
	return b[n][s] != 0;
}

void hienThi(DienThoai d){
	cout << "Nhan hieu: "<< d.nhanHieu<< " | ";
	cout << "Kich thuoc : "<< d.kichThuoc<< " inch "<<" | ";
	cout << "Gia ban : "<< d.giaBan<<" trieu dong";
}
void hienThiDanhSach(DienThoai l[], int n){
	for(int i = 0; i <n; ++i){
		hienThi(l[i]);

		cout <<endl;
	}	
}

void hienThiKetQua(DienThoai d[], int n, int result[]){
	float amount = 0;
	for(int i = 0; i < n; ++i){
		if(result[i] != 0){
			hienThi(d[i]);
			cout << endl;
			amount += d[i].giaBan;
		}
	}	
	cout << "Tong gia tri: "<< amount<< " trieu dong ";
}

bool cmp(DienThoai a, DienThoai b){
	return a.giaBan > b.giaBan;	
}
int main(){
	int n = 5;
	int s = 10;
	DienThoai d[n];
	assign(d[0],"Samsung",5,7.0);
	assign(d[1],"Apple",3,4.5);
	assign(d[2],"Xiaomi",7,4.6);
	assign(d[3],"Oppo",4,6.5);
	assign(d[4],"Vivo",5,5.4);
	
		
	hienThiDanhSach(d, n);
	int result[n] = {0}; 
	bool hasResult = alg(d,n,s, result);
	if(hasResult){
		cout << "Danh sach dien thoai co the lay voi kich thuoc tui "<< s <<"inch la : "<< endl;
		hienThiKetQua(d,n,result);
		
	}
	return 0;
}
