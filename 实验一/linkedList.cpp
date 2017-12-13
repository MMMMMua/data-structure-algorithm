#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include "linkedList.h"

using namespace std;

linkList<int> List;
int n;

int main() {
	freopen("input.txt", "r", stdin);

	List.init();

	while (cin >> n) {
		List.orderedIns(n);
	}

	List.output();
	List.reverseBuild();
	List.output();
	List.remove(6);
	List.output();
	cout << List.getSize() << endl;
	cout << List.find(13) << endl;
	cout << List.find(6) << endl;
	List.insert(20, 5);
	List.output();
}
