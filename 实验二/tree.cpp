#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cassert>

using namespace std;

template<class T> struct treeNode {
	T val;
	treeNode *ch[2];

	treeNode() {
		ch[0] = ch[1] = NULL;
	}

	treeNode(T v) {
		val = v;
		ch[0] = ch[1] = NULL;
	}
};

template<class T> struct Tree {
	treeNode<T> *root;

	Tree() {
		root = NULL;
	}

	
	void init(T val) {
		root = new treeNode<T>(val);		
	}

	treeNode<T> *_find(T v, treeNode<T> *p) {
		if (p == NULL) {
			return NULL;
		}
		if (p->val == v) {
			return p;
		}
		treeNode<T> *l = _find(v, p->ch[0]);
		treeNode<T> *r = _find(v, p->ch[1]);

		if (l != NULL) {
			return l;
		}
		else {
			return r;
		}
	}

	
	treeNode<T> *find(T v) {
		return _find(v, root);
	}

	void insert(T &n, T &p, int t) {
		treeNode<T> *ptr = find(p); 
		
		assert(ptr != NULL);
		assert(ptr->ch[t] == NULL);
		
		ptr->ch[t] = new treeNode<T>(n);
	}

	void _preOrder(treeNode<T> *p) {
		if (p == NULL) {
			return;
		}

		cout << p->val << " ";
		_preOrder(p->ch[0]);
		_preOrder(p->ch[1]);		
	}

	void preOrder() {
		_preOrder(root);
	}
	
	void _inOrder(treeNode<T> *p) {
		if (p == NULL) {
			return;
		}

		_inOrder(p->ch[0]);
		cout << p->val << " ";
		_inOrder(p->ch[1]);
	}

	void inOrder() {
		_inOrder(root);
	}
	
	void _postOrder(treeNode<T> *p) {
		if (p == NULL) {
			return;
		}

		_postOrder(p->ch[0]);
		_postOrder(p->ch[1]);
		cout << p->val << " ";
	}

	void postOrder() {
		_postOrder(root);
	}
	
	void levelOrder() {
		queue<treeNode<T>*> q;
		q.push(root);
		while (q.size()) {
			if (q.front()) {
				cout << q.front()->val << " ";
				q.push(q.front()->ch[0]);
				q.push(q.front()->ch[1]);
			}
			q.pop();
		}		
	}
};

string n, p;
string t;
Tree<string> tree;

int main() {
	freopen("ex2_tree1.txt", "r", stdin); // 打开文件
	
	while (cin >> n >> p >> t) { // 读入三个 string 类, 其实就是三个字符串,  string 类是字符串的一个封装, 和字符串非常相似. cin 函数会自动检测读入数据的类型
		if (t == "-1") { // 如果读入的数是 "-1"
			tree.init(n); // 说明这个树没有初始化, 新建一个节点. 设为根
		}
		else {
			if (t == "L") { // 如果一个点是另一点的左儿子
				tree.insert(n, p, 0); // 剩下的不说了.
			}
			else {
				tree.insert(n, p, 1);
			}
		}
	}

	tree.preOrder();
	cout << endl;
	
	tree.inOrder();
	cout << endl;
	
	tree.postOrder();
	cout << endl;
	
	tree.levelOrder();
	cout << endl;
}


















