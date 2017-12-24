#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

int a[11];

void qsort(int l, int r) {
	if (l >= r)
		return;
	int p = a[rand() % (r-l+1) + l];
	int x = l, y = r;
	
	while (x <= y) {
		while (a[x] < p) x++;
		while (a[y] > p) y--;
		if (x <= y) {
			swap(a[x], a[y]);
			x++, y--;
		}
	}		
		
	qsort(l, y), qsort(x, r);
}

int main() {
	freopen("in2.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	for (int i = 1; i <= 10; ++i)
		cin >> a[i];
	qsort(1, 10);

	for (int i = 1; i <= 10; ++i)
		cout << a[i] << " ";
}
		   
