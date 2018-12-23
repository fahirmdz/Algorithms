#pragma once

template<class Key>
class BSNode {
public:
	Key value;
	BSNode* leftChild;
	BSNode* rightChild;

	BSNode(Key value) {
		this->value = value;
		this->leftChild = nullptr;
		this->rightChild = nullptr;
	}
};