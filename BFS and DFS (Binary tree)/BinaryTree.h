#pragma once
#include<iostream>
#include"BSNode.h"
using namespace std;

template <class Key>
class BinaryTree {
	
	void recursion_RecycleBinaryTree(BSNode<Key>*& node) {
		if (node != nullptr) {
			recursion_RecycleBinaryTree(node->rightChild);
			recursion_RecycleBinaryTree(node->leftChild);
			delete node;
			node = nullptr;
		}
	}
	BSNode<Key>* recursion_Search(BSNode<Key>* node, Key value) {
		if (node == nullptr)
			return nullptr;

		if (isEqual(node->value, value))
			return node;
		if (isHigher(node->value, value))
			return recursion_Search(node->leftChild, value);
		else
			return recursion_Search(node->rightChild, value);
	}
	bool isEqual(Key value1, Key value2) {
		return value1 == value2;
	}
	bool isHigher(Key value1, Key value2) {
		return value1 > value2;
	}
	bool recursion_Add(BSNode<Key>*& node, Key value) {
		if (node == nullptr) {
			node = new BSNode<Key>(value);
			return true;
		}
		if (isEqual(node->value, value))
			return false;

		if (isHigher(node->value, value))
			return recursion_Add(node->leftChild, value);
		else
			return recursion_Add(node->rightChild, value);
	}

public:

	BSNode<Key>* root;

	BinaryTree():root(nullptr){}

	bool Add(Key value) {
		if (root == nullptr)
			root = new BSNode<Key>(value);
		return recursion_Add(root, value);
	}

	void recycleRoot() {
		recursion_RecycleBinaryTree(root);
	}

	BSNode<Key>* search(Key value) {
		return recursion_Search(root, value);
	}

	bool contains(Key value) {
		return search(value) != nullptr;
	}
};