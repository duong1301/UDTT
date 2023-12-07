#include <iostream>
#include <cstring>

using namespace std;

void z_alg(char * s, int z[]){
	int n = strlen(s);
	int left = 0; 
	int right = 0;
	for(int i = 1; i< n; ++i){
		if(i > right){
			left = right = i;
			while(right < n && s[right - left] == s[right]) right++;
			z[i] = right - left;
			right--;
		}
		else if(z[i - left] < right - i + 1){
			z[i] = z[i - left];
		}else{
			left  = i;
			while(right < n && s[right - left] == s[right]) right++;
			z[i] = right - left;
			right--;			
		}		
	}	
}
int main(){
	
	char str[] = "sdf$kjlewkjrkwjrklwfmsdnfandklasdfklglakdlnjkgbsdfwalwdjlakfjliwdsdfohiodlqwkenrklqwbsdfqrgqdfwg";
	int z[strlen(str)] = {0};
	z_alg(str, z);
	for(int i = 0; i < strlen(str); ++i){
		cout<< z[i]<< " ";
	}
	return 0;
}
