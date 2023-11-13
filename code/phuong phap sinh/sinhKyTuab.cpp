#include <iostream>

using namespace std;

long C(int k, int n){
	if((k == 0) ||(k == n))
		return 1;
	return C(k, n - 1) + C(k - 1, n - 1);
}
int main(){
	cout << C(3,4);
	return 0;
}
