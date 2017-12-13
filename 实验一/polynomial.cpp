#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "linkedList.h"
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;

linkList<pii> p1, p2, p3;
int n;

int main() {
	freopen("poly.txt", "r", stdin);

	cin >> n;
	while (n--) {
		p1.clear();
		p2.clear();
		p3.clear();
		p1.init();
		p2.init();
		p3.init();
		
		int coef, powr;
		
		while (cin >> coef >> powr, powr >= 0) {
			if (coef != 0)
				p1.orderedIns(pii(powr, coef));
		}
		
		while (cin >> coef >> powr, powr >= 0) {
			if (coef != 0)
				p2.orderedIns(pii(powr, coef));
		}

		Node<pii> *ptr1 = p1.head->succ, *ptr2 = p2.head->succ;

		while (ptr1 != p1.tail && ptr2 != p2.tail) {
			if (ptr1->val.fi == ptr2->val.fi) {
				if (ptr2->val.se + ptr1->val.se != 0)
					p3.orderedIns(pii(ptr2->val.fi, ptr1->val.se + ptr2->val.se));
				
				ptr1 = ptr1->succ;
				ptr2 = ptr2->succ;
			} else if (ptr1->val.fi > ptr2->val.fi) {
				p3.orderedIns(ptr2->val);
				ptr2 = ptr2->succ;
			} else {
				p3.orderedIns(ptr1->val);
				ptr1 = ptr1->succ;
			}			
		}

		while (ptr1 != p1.tail) {
			p3.orderedIns(ptr1->val);
			ptr1 = ptr1->succ;
		}

		while (ptr2 != p2.tail) {
			p3.orderedIns(ptr2->val);
			ptr2 = ptr2->succ;
		}

		p3.reverseBuild();

		Node<pii> *ptr3 = p3.head;
		
		for (ptr3 = ptr3->succ; ptr3 != p3.tail; ptr3 = ptr3->succ)
			cout << "[" << ptr3->val.se << " " << ptr3->val.fi << "]";
		cout << endl;
	}
}
