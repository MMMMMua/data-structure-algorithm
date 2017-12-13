#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int maxn = 101, maxm = maxn * maxn * 2, inf = 0x3f3f3f3f;

int pre[maxn];
string str[maxn];
int n, edg;
int a[maxn][maxn];
int to[maxm], la[maxn], nt[maxm], w[maxm];

void add_edge(int x, int y, int z) {
	to[++edg] = y, nt[edg] = la[x], la[x] = edg, w[edg] = z;
}

void printPath(int n) {
	if (n == 1) {
		cout << str[n];
		return;
	}
	printPath(pre[n]);
	cout << "," << str[n];
}

void dijkstra() {
	static bool vis[maxn];
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
		cout << " path:";
		printPath(i);
		cout << " value=" << d[i] << endl;
	}
	
}
int main() {
	freopen("ex3_Graph2.txt", "r", stdin);
	freopen("ex3_Graph.out", "w", stdout);

	scanf("nodeNum:%d\n", &n);
	getline(cin, str[0]);
	for (int i = 1; i <= n; ++i)
		cin >> str[i];
	for (int i = 1; i <= n; ++i) {
		cin >> str[0];
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			if (a[i][j] != -1)
				add_edge(i, j, a[i][j]);
		}
	}

	dijkstra();
}

