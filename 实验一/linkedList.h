#include <iostream>
#include <algorithm>

using namespace std;

template<class T> struct Node {
	Node *prev, *succ;
	T val;

	Node() {
		prev = succ = NULL;
	}

	Node(T n) {
		val = n;
	}
};

template<class T> struct linkList {
	Node<T> *head, *tail;
	int size;

	linkList() {
		head = tail = NULL;
		size = 0;
	}

	void init() {
		size = 0;
		head = new Node<T>;
		tail = new Node<T>;
		head->succ = tail;
		tail->prev = head;
	}

	void insBefore(Node<T> *listPtr, Node<T> *temp) {		
		listPtr->prev->succ = temp;
		temp->prev = listPtr->prev;
		listPtr->prev = temp;
		temp->succ = listPtr;
		size++;
	}
					  
	void orderedIns(T n) {
		Node<T> *temp = new Node<T>(n), *listPtr;
		
		for (listPtr = head->succ; listPtr != tail; listPtr = listPtr->succ) {
			if (listPtr->val > n) {
				break;
			}
		}
		
		insBefore(listPtr, temp);	
	}

	Node<T> *find(T n) {
		Node<T> *listPtr;
		int cnt = 0;
		for (listPtr = head->succ; listPtr != tail; listPtr = listPtr->succ, cnt++) {
			if (listPtr->val == n) {
				return listPtr;
			}								   
		}

		return NULL;
	}

	bool insert(T n, int pos) {
		Node<T> *temp = new Node<T>(n), *listPtr;
		int cnt = 0;
		for (listPtr = head->succ; listPtr != tail; listPtr = listPtr->succ, cnt++) {
			if (cnt == pos) {
				insBefore(listPtr, temp);
			}
		}

		return false;
	}

	bool remove(Node<T> *listPtr) {
		if (listPtr == NULL) {
			return false;
		}
		
		listPtr->prev->succ = listPtr->succ;
		listPtr->succ->prev = listPtr->prev;
		delete listPtr;
		size--;

		return true;
	}
	
	bool remove(T n) {
		Node<T> *listPtr = find(n);
		return remove(listPtr);
	}

	int getSize() {
		return size;
	}

	void output() {
		Node<T> *listPtr;
		
		for (listPtr = head->succ; listPtr != tail; listPtr = listPtr->succ) {
			cout << "(" << (listPtr->val) << ")" << " --> ";
		}

		cout << "(NULL)" << endl;
	}

	void reverseBuild() {
		Node<T> *listPtr;
		
		for (listPtr = head; listPtr; listPtr = listPtr->prev) {
			swap(listPtr->prev, listPtr->succ);
		}

		swap(head, tail);
	}

	void clear() {
		Node<T> *listPtr, *temp;
		
		for (listPtr = head; listPtr; listPtr = temp) {
			temp = listPtr->succ;
			delete listPtr;
		}
	}
};

