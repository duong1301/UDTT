#include <iostream>
#include <cstring>

using namespace std;

int charInString(char x, char *s){
	int size = strlen(s);
	for(int i = 0; i < size; ++i){
		if(x == s[i]) return i;
	}
	return - 1;	
}

int boyer(char *P, char *T)
{
	int sizeP = strlen(P);
	int sizeT = strlen(T);
	int v = sizeP - 1;	
	int i = v;	
	while(i < sizeT){
		int k = v;
		int m = i;
		while(P[k] == T[m] && k >= 0){
			k--; m--;			
		}
		if(k == - 1) return m + 1;
		i = i + v - charInString(T[i], P);
	}
	return -1;
}
int main(){
	char  P[] = "namsau";
	char  T[] = "mothaibabonnamsau";
	cout << boyer(P, T);
	
	return 0;
}
