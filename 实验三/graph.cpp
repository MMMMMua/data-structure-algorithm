#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;


void dijkstra() {
	static bool vis[maxn];
	static int prev[maxn];
	static int d[maxn];
	for (int i = 1; i <= n; ++i)
		d[i] = inf;
	d[1] = 0, d[0] = inf;

	for (int i = 1; i < n; ++i) {
		int x = 0;
		for (int j = 1; j <= n; ++j)
			if (!vis[j] && d[j] < d[x])
				x = j;
		
		vis[x] = true;
		
		for (int j = la[x]; j; j = nt[j])
			if (d[to[j]] > d[x] + w[j])
				d[to[j]] = d[x] + w[j], pre[to[j]] = x;
	}

	for (int i = 2; i <= n; ++i) {
		cout << str[1] << "->" << str[i];
								  
	}
	
}
int main() {
	freopen("ex3_Graph.txt", "r", stdin);
	freopen("ex3_Graph.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> str[i];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			if (a[i][j] != -1)
				add_edge(i, j, a[i][j]);
		}

	dijkstra();
}

