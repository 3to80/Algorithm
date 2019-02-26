#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
#include <iostream>


using namespace std;
long long a[1000001];
long long mod=1000000007;
long long px[1000001];
int n,k;
inline long long power(long long x,long long y)
{
	long long t=1;
	while(y!=0)
	{
		if(y%2==1)
			t=t*x%mod;
		x=x*x%mod;
		y/=2;
	}
	return t;	
}
inline void prepare()
{
	int i;
	for(i=1;i<=k;i++)
	{
		px[i]=px[i-1]+power(i,i);
		px[i]%=mod;
	}
}
int main()
{


	FILE* tmp = freopen("./input.txt","r",stdin);
//	freopen("C-small-attempt0.out","w",stdout);
	// freopen("C-large.in","r",stdin);
	// freopen("C-large.out","w",stdout);
	int T,kk=0;


	scanf("%d",&T);
	cout<<T;
	while(T>0)
	{
		kk++;
		T--;
		scanf("%d%d",&n,&k);
		long long x1,y1,c,d,e1,e2,f;
		scanf("%lld%lld%lld%lld%lld%lld%lld",&x1,&y1,&c,&d,&e1,&e2,&f);
		int i,j;
		long long x,y;
		a[1]=(x1+y1)%f;
		for(i=2;i<=n;i++)
		{
			x=(c*x1+d*y1+e1)%f;
			y=(d*x1+c*y1+e2)%f;
			a[i]=(x+y)%f;
			x1=x;
			y1=y;
		}
		long long ans=0;
		long long la=k;
		for(i=2;i<=n+1;i++)
		{
			ans=(ans+la*(long long)(n+2-i)%mod*a[i-1]%mod)%mod;
			long long x=(power(i,k+1)-1)*power(i-1,mod-2)%mod;
			x--;
			if(x<0)
				x+=mod;
			la+=x;
			la%=mod;
		}
		printf("Case #%d: %d\n",kk,ans);
	}
	return 0;
}