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
}
