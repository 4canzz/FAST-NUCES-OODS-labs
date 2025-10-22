#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <class DT>
class BNode {
private:
	DT data;
	BNode<DT>* leftchild;
	BNode<DT>* rightchild;
public:
	BNode() : leftchild(NULL), rightchild(NULL), data(DT()) {}
	void setLeftChild(BNode<DT>* x) { leftchild = x; }
	BNode<DT>* getLeftChild() { return leftchild; }
	void setRightChild(BNode<DT>* x) { rightchild = x; }
	BNode<DT>* getRightChild() { return rightchild; }
	void setData(DT pdata) { data = pdata; }
	DT getData() { return data; }
};

template <class DT>
class BinaryTree {
private:
	BNode<DT>* root;
public:
	BinaryTree() : root(NULL) {}

	void BuildTree(DT *Arr, int size){
		if (Arr == NULL) return;
		BNode<DT> **ptr = new BNode<DT>*[size];
		for (int i = 1; i < size; i++){
			if (Arr[i] == 0) ptr[i] = NULL; 
			else{
				ptr[i] = new BNode<DT>();
				ptr[i] -> setData(Arr[i]);
			}
		}
		for (int i = 1; i < size; i++){
			if (2 * i < size) ptr[i]->setLeftChild(ptr[2 * i]);
			if (2 * i + 1 < size) ptr[i]->setRightChild(ptr[2 * i + 1]);
		}
		root = ptr[1];
	}

	void PreOrder() {
		if (!root) return;
		stack<BNode<DT>*> s;
		s.push(root);
		while (!s.empty()) {
			BNode<DT>* node = s.top();
			s.pop();
			cout << node->getData() << " ";
			if (node->getRightChild()) s.push(node->getRightChild());
			if (node->getLeftChild()) s.push(node->getLeftChild());
		}
		cout << endl;
	}

	void InOrder() {
		if (!root) return;
		stack<BNode<DT>*> s;
		BNode<DT>* curr = root;
		while (curr != NULL || !s.empty()) {
			while (curr != NULL) {
				s.push(curr);
				curr = curr->getLeftChild();
			}
			curr = s.top();
			s.pop();
			cout << curr->getData() << " ";
			curr = curr->getRightChild();
		}
		cout << endl;
	}

	void PostOrder() {
		if (!root) return;
		stack<BNode<DT>*> s1, s2;
		s1.push(root);
		while (!s1.empty()) {
			BNode<DT>* node = s1.top();
			s1.pop();
			s2.push(node);
			if (node->getLeftChild()) s1.push(node->getLeftChild());
			if (node->getRightChild()) s1.push(node->getRightChild());
		}
		while (!s2.empty()) {
			cout << s2.top()->getData() << " ";
			s2.pop();
		}
		cout << endl;
	}

	void LevelOrder() {
		if (!root) return;
		queue<BNode<DT>*> q;
		q.push(root);
		while (!q.empty()) {
			BNode<DT>* node = q.front();
			q.pop();
			cout << node->getData() << " ";
			if (node->getLeftChild()) q.push(node->getLeftChild());
			if (node->getRightChild()) q.push(node->getRightChild());
		}
		cout << endl;
	}

	int calculateHeightItr() {
		if (!root) return 0;
		queue<BNode<DT>*> q;
		q.push(root);
		int height = 0;

		while (!q.empty()) {
			int levelSize = q.size();
			while (levelSize-- > 0) {
				BNode<DT>* node = q.front();
				q.pop();
				if (node->getLeftChild()) q.push(node->getLeftChild());
				if (node->getRightChild()) q.push(node->getRightChild());
			}
			height++;
		}
		cout << height << endl;
		return height;
	}
};

int main() {
	BinaryTree<int>* BT;
	BT = new BinaryTree<int>;

	int arr[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 12, 13, 14 };
	BT->BuildTree(arr, 15);

	cout << "*************************************" << endl;
	cout << "InOrder (iterative) is " << endl;
	BT->InOrder();
	cout << "*************************************" << endl;
	cout << "PreOrder (iterative) is " << endl;
	BT->PreOrder();
	cout << "*************************************" << endl;
	cout << "PostOrder (iterative) is " << endl;
	BT->PostOrder();
	cout << "*************************************" << endl;
	cout << "LevelOrder (iterative) is " << endl;
	BT->LevelOrder();
	cout << "*************************************" << endl;
	cout << "Height of the binary tree is " << endl;
	BT->calculateHeightItr();
	system("pause");
	return 0;

}
