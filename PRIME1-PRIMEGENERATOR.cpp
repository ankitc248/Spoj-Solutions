/*
PRIME GENERATOR-PRIME1
SOLUTION BY RAMAN SHARMA
*/
#include <bits/stdc++.h>
int prime(long a)
{if(a==1)
return 0;
else if(a<4)
return 1;
else if(a%2==0)
return 0;
else if(a%3==0)
return 0;
else
for(int i=5; i<=sqrt(a); i+=6)
{if(a%i==0)return 0;
if(a%(i+2)==0)return 0;
}
return 1;
}

using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{long m,n;
	cin>>m>>n;
	for(long i=m; i<=n; i++)
	{if(prime(i))
	cout<<i<<endl;}
	cout<<endl;}
	return 0;
}
