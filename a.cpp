#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,mod=1e9+7;
typedef long long ll;
int n,m,k,t;
int tot;
int atk[maxn],d[maxn];
int root[maxn],ls[maxn*20],rs[maxn*20];
int cnt[maxn*20],point[maxn];
int treeCnt;
ll sum[maxn*20];
__int128 ret[maxn];
vector<int>e[maxn],bl[maxn];
void ins(int x,int &y,int l,int r,int pos,int val)
{
  cnt[y=++treeCnt]=cnt[x]+1;
  sum[y]=sum[x]+val;
  if(l==r)return;
  int mid=l+r>>1;
  if(pos<=mid)ins(ls[x],ls[y],l,mid,pos,val);
  else ins(rs[x],rs[y],mid+1,r,pos,val);
}
int merge(int x,int y,int l,int r)
{
  if(!x||!y)return x+y;
  cnt[x]+=cnt[y];
  sum[x]+=sum[y];
  if(l==r)return x;
  int mid=l+r>>1;
  ls[x]=merge(ls[x],ls[y],l,mid);
  rs[x]=merge(rs[x],rs[y],mid+1,r);
  return x;
}
int qcnt(int x,int l,int r,int L,int R)
{
  if(!x)return 0;
  if(L<=l&&r<=R)return cnt[x];
  int mid=l+r>>1,ret=0;
  if(L<=mid)ret+=qcnt(ls[x],l,mid,L,R);
  if(mid+1<=R)ret+=qcnt(rs[x],mid+1,r,L,R);
  return ret;
}
ll qsum(int x,int l,int r,int L,int R)
{
  if(!x)return 0;
  if(L<=l&&r<=R)return sum[x];
  int mid=l+r>>1;
  ll ret=0;
  if(L<=mid)ret+=qsum(ls[x],l,mid,L,R);
  if(mid+1<=R)ret+=qsum(rs[x],mid+1,r,L,R);
  return ret;
}
void dfs(int x,int y=0)
{
  ins(root[x],root[x],1,tot,atk[x],d[atk[x]]);
  for(auto z:e[x])
  {
    if(z==y)continue;
    dfs(z,x);
    ret[x]+=ret[z];
    int u=x,v=z;
    if(bl[point[u]].size()>bl[point[v]].size())
      swap(u,v);
    for(auto iter:bl[point[u]])
    {
      ret[x]+=qsum(root[v],1,tot,atk[iter]+1,tot)
            +(ll)qcnt(root[v],1,tot,1,atk[iter])*d[atk[iter]];
      bl[point[v]].push_back(iter);
    }
    point[x]=point[v];
    root[x]=merge(root[x],root[z],1,tot);
  }
}
void print(__int128 val)
{
  if(!val)return;
  print(val/10);
  putchar(val%10+'0');
}
int main()
{
  int i,j;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    scanf("%d",&atk[i]);
    d[i]=atk[i];
    bl[i].push_back(i);
    point[i]=i;
  }
  for(i=1;i<n;i++)
  {
    int x,y;
    scanf("%d%d",&x,&y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  tot=n;
  sort(d+1,d+tot+1);
  tot=unique(d+1,d+tot+1)-d-1;
  for(i=1;i<=n;i++)
  {
    atk[i]=lower_bound(d+1,d+tot+1,atk[i])-d;
  }
  dfs(1);
  for(i=1;i<=n;i++)
  {
    if(!ret[i])printf("0");
    else print(ret[i]);
    putchar(i==n?'\n':' ');
  }
  return 0; 
}   