#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define ii pair<int,int>
#define fi first
#define se second 
//#define pb push_back
const int oo=1e9;
const int Mod=1e9+7;
const long long OO=1e18;
const int N=1e5+5;
vector<int>ad[N];
vector<ii>Ad[N];
int n,m,k,s,t,p[N],dis[N], d[N];
int check(int val)
{
	queue<int>S;
	S.push(s);
	for(int i=1; i<=n; i++)dis[i]=-1;
	dis[s]=0;
	while(S.size())
	{
		int u=S.front();
		if(u==t)return true;
		S.pop();
		if(dis[u]==val)continue;		
		for(int v:ad[u])
		{
			int tmp=dis[u]+1;
			if(d[v])tmp=0;
			if(dis[v]==-1 || tmp<dis[v])
			{
				dis[v]=tmp;
				S.push(v);
			}
		}
	}
	return dis[t]!=-1;
}
int main()
{
	if(fopen("trash.inp", "r"))
		freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
	//else freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1; i<=k; i++)
	{
		int x;
		cin>>x;
		d[x]=1;
	}
	for(int i=1; i<=m; i++)
	{
		int x,y;
		cin>>x>>y;
		ad[x].push_back(y);
		ad[y].push_back(x);
	}
	cin>>s>>t;
	int low=1, high=n,ans=-1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(check(mid))ans=mid, high=mid-1;
		else low=mid+1;
	}
	cout<<ans;
}
