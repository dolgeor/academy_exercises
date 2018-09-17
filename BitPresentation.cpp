#include <iostream>
#include <cmath>
 
using namespace std;
void printShortInBin(short s){
  	short temp;
  	for(int i=15;i>=0;i--)
  	{ 	
        	temp=s>>i&1;
        	cout<<temp;
        	if(i%8==0)cout<<" ";
  	}
}
void printIntInBin(int n){
  	int temp;
  	for (int i = 31;i >= 0;i--)
  	{
        	temp = n >> i & 1;
        	cout << temp;
        	if (i == 31)cout << " ";
        	if (i == 23)cout << " ";
  	}
  	cout << endl;
}
int floatInIntBin(float s) {
  	/*char *p;
  	p=(char*)&s;
  	int n=*(p+3);
  	for(int j=2;j>=0;j--){
        	n=n<<8;
        	n+=*(p+j);
  	}
  	return n;*/
  	return *((int*)&s);
}
float binToFloat(int n){
  	float res=0;
  	int sign=(n >> 31 & 1)==1?-1:1;
  	n=n<<1;
  	int e=(n>>24&0x000000FF)-127;
  	n = n << 7;
  	n=n|1<<31;
  	for(int j=0;j>-32;j--){
        	res+=pow(2,j+e)*(n >>(31+j)  & 1);}
  	res*=sign;
  	
  	return res;
}
 
int main() {
  	short s;
  	float f;
 
  	cout<<"Input Short = ";
  	cin>>s;
  	printShortInBin(s);
 
  	cout << "\nInput Float = ";
  	cin >> f;
  	printIntInBin(floatInIntBin(f));
  	cout << binToFloat(floatInIntBin(f)) << endl;
 
  	system("pause");
  	return 0;
}