#include <bits/stdc++.h>
using namespace std;
vector <int> v[505];
vector <pair <int,int> > p;
int dis[505];
int main (void) {
	int n,i;
	FILE * fin = fopen ("point.in","r");
	FILE * fout = fopen("point.out","w");
	fscanf (fin,"%d%d",&n,&i);
	p.clear();
	memset (dis,0,sizeof (dis));
	for (int j = 0;j < n;j++) {
		int x,y;
		fscanf (fin,"%d%d",&x,&y);
		p.push_back(make_pair (x,y));
	}
	for (int j = 0;j < n;j++) 
		for (int k = 0;k < n;k++) {
			if (j == k) continue;
			if (p[j].first <= p[k].first && p[j].second <= p[k].second) v[j].push_back(k);
		}
	int ans = 0;
	for (int j = 0;j < n;j++) {
			dis[j] = 1;
			queue <int> q;
			q.push(j);
			while (!q.empty()) {
				int f = q.front();q.pop();
				int siz = v[f].size();
				for (int k = 0;k < siz;k++) {
					if (p[v[f][k]].first-p[j].first+p[v[f][k]].second-p[j].second <= i + dis[f]) {
						dis[v[f][k]] = max(dis[f]+1,dis[v[f][k]]);
						q.push(v[f][k]);
					}
				}
			}
			for (int k = 0;k < n;k++) ans = max(ans,dis[k]+i);
			memset (dis,0,sizeof (dis));
	}
	fprintf (fout,"%d\n",ans);
	return 0;
}
