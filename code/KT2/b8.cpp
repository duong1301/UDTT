#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int charInString(char x, char * str){
	int n = strlen(str);
	for(int i = 0; i < n; ++i)
		if(str[i] == x) return i;	
	return - 1;
}

bool boyer(char *p, char * t, int postion[] = NULL){
	int m = strlen(p);
	int n = strlen(t);
	int v = m - 1;
	int i = v;
	int f[n] = {0};
	int flag = false;
	while(i < n){
		int k = v;
		int j = i;
		while(p[k] == t[i] && k >= 0 && i >=0){
			--k; --i;
		}
		if(k == -1){
			f[i+1] = 1;
			i = j + m;
			flag = true;
		}else{
			i = i + v - charInString(t[i], p);
		}		
	}

	postion = f;
	return flag;
}

int zAlg(string p, string t){
	t = p +"$"+ t;
	int n = t.length();
	int z[n] = {0};
	int left = 0;
	int right = 0;

	for(int i = 0; i < n; ++i){
		if(i > right){
			left = i;
			right = i;
			while(t[right] == t[right - left]) right++;			
			z[i] = right - left;
			--right;			
		}else{
			if(z[i - left] < right - i + 1){
				z[i] = z[i - left];
			}else{
				left = i;
				while(t[right] == t[right - left]) right++;			
				z[i] = right - left;
				--right;
			}
		}
	}
	int count = 0;
	int sizeP = p.length();
	
	for(int i = 0; i <n; ++i){
		if(z[i] == sizeP) count++;
	}
	return count;
}
struct laptop{
	string tenHang;
	string cauHinh;
	float giaBan;
};

void assignLaptop(laptop &l, string tenHang, string cauHinh, float giaBan){
	l.tenHang = tenHang;
	l.cauHinh = cauHinh;
	l.giaBan = giaBan;
}

void hienThi(laptop l){
	cout <<"Ten hang: " <<l.tenHang<< endl;
	cout << "Cau hinh: "<< l.cauHinh<< endl;
	cout << "Gia ban: "<< l.giaBan<< " trieu";
}

void hienThi(laptop l[], int n){
	for(int i = 0; i < n; ++i){
		hienThi(l[i]);
		cout <<endl<<"---------"<< endl;
	}	
}

void RAM_capacity(laptop l[], int n, string cap = "16GB"){
	cap = "RAM "+cap;
	int count = 0;
	int result[n] = {0};
	for(int i = 0; i < n; ++i){
		bool isContain = boyer(&cap[0],&l[i].cauHinh[0]);
		if(isContain){
			result[i] = 1;
			count++;
		}
	}
	if(count == 0){
		cout << "--Khong tim thay lap top co RAM = "<<cap<<"--"<< endl;
		return;
	}
	cout << "--Danh sach laptop co "<< cap<< "--"<< endl;
	for(int i = 0;i < n; ++i){
		if(result[i]){
			hienThi(l[i]);
			cout <<endl<<"------" <<endl;
		}
	}	
}

void drive_type(laptop l[], int n, string type="SSD"){
	int result[n] ={0};
	int count = 0;
	
	for(int i = 0; i < n; ++i){
		bool isContain = zAlg(type,l[i].cauHinh);
		if(isContain){
			result[i] = 1;
			count++;
		}
	}
	if(count == 0){
		cout << "Khong tim thay lap top co o cung la "<< type<< endl;
		return;
	}
	cout << "--Danh sach laptop co o cung la "<<type<<"--"<< endl; 
	for(int i = 0; i < n; ++i){
		if(result[i]){
			hienThi(l[i]);
			cout << endl<<"---------"<< endl;
		}
	}
}
int main(){
	int n = 5;
	laptop d[n];
	assignLaptop(d[0],"HP","CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB",20);
	assignLaptop(d[1],"DELL","CPU 2.4GHz upto 3.6GHz-RAM 8GB-SSD 256GB",18);
	assignLaptop(d[2],"ACER","CPU 2.4GHz upto 3.5GHz-RAM 8GB-HDD 512GB",17.5);
	assignLaptop(d[3],"LENOVO","CPU 1.4GHz upto 3.6GHz-RAM 8GB-HDD 512GB",16.5);
	assignLaptop(d[4],"ASUS","CPU 1.6GHz upto 3.4GHz-RAM 16GB-SSD 512GB",19);
	cout << "Danh sach laptop: "<< endl;
	hienThi(d, n);
	cout << endl;
	RAM_capacity(d,n,"8GB");
	cout << endl;
	drive_type(d,n,"SSD");
	return 0;
}
