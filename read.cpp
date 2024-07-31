#include<bits/stdc++.h>
using namespace std;
int readint(){
	char c;int n=0,x=1;
	cin.get(c);
	while((c>'9'||c<'0')&&c!='-')cin.get(c);
	if(c=='-')x=-1;
	else n=n*10+c-'0';
	cin.get(c);
	while(c<='9'&&c>='0'){n=n*10+c-'0';cin.get(c);}
	return n*x;
}
int main(){
	int a,b;
	a=readint(),b=readint();
	cout<<a<<endl<<b;
	return 0;
}
