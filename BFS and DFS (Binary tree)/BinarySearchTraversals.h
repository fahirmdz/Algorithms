#pragma once
#include"BinaryTree.h"
#include"ListLinked.h"
#include"StackLinked.h"
#include"QueueLinked.h"

template<class Key>
class BinarySearchTraversals {

	BinarySearchTraversals() {}

	static void recursion_PostOrder(BSNode<Key>* &node, List<Key>* list) {
		if (node != nullptr) {
			recursion_PostOrder(node->leftChild, list);
			recursion_PostOrder(node->rightChild, list);
			list->AddFirst(node->value);
		}
	}

	static void recursion_InOrder(BSNode<Key>* &node, List<Key>* list) {
		if (node != nullptr) {
			recursion_InOrder(node->leftChild, list);
			list->AddFirst(node->value);
			recursion_InOrder(node->rightChild, list);
		}
	}

	static void recursion_PreOrder(BSNode<Key>* &node, List<Key>* list) {
		if (node != nullptr) {
			list->AddFirst(node->value);
			recursion_PreOrder(node->leftChild, list);
			recursion_PreOrder(node->rightChild, list);
		}
	}

public:

	static List<Key>* PostOrder_R(BinaryTree<Key>& tree) {
		List<Key>* list = new ListLinked<Key>;
		recursion_PostOrder(tree.root, list);
		return list;
	}

	static List<Key>* InOrder_R(BinaryTree<Key>& tree) {
		List<Key>* list = new ListLinked<Key>;
		recursion_InOrder(tree.root, list);
		return list;
	}

	static List<Key>* PreOrder_R(BinaryTree<Key>& tree) {
		List<Key>* list = new ListLinked<Key>;
		recursion_PreOrder(tree.root, list);
		return list;
	}

	static List<Key>* PreOrder_I(BinaryTree<Key>& tree) {
		List<Key>* list = new ListLinked<Key>;
		StackLinked<BSNode<Key>*> stack;
		stack.add(tree.root);
		while (!stack.isEmpty()) {
			BSNode<Key>* node = stack.remove();
			if (node != nullptr) {
				list->AddFirst(node->value);
				stack.add(node->leftChild);
				stack.add(node->rightChild);
			}
		}
		return list;
	}

	static List<Key>* InOrder_I(BinaryTree<Key>& tree) {
		List<Key>* list = new ListLinked<Key>;
		StackLinked<BSNode<Key>*> stack;
		BSNode<Key>* current = tree.root;

		stack.add(tree.root);
		while (!stack.isEmpty()) {
			if (current != nullptr) {
				stack.add(current);
				current = current->leftChild;
			}
			else {
				if (stack.isEmpty())
					break;
				current = stack.remove();
				list->AddFirst(current->value);
				current = current->rightChild;
			}
		}
		return list;

	}

	static List<Key>* PostOrder_I(BinaryTree<Key>& tree) {
		List<Key>* list = new ListLinked<Key>;
		Stack<Key>* result = new StackLinked<Key>;
		StackLinked<BSNode<Key>*> stack;
		stack.add(tree.root);

		while (!stack.isEmpty()) {
			BSNode<Key>* node = stack.remove();
			if (node != nullptr) {
				result->add(node->value);
				stack.add(node->leftChild);
				stack.add(node->rightChild);
			}
		}

		while (!result->isEmpty()) {
			list->AddFirst(result->remove());
		}
		return list;
	}

	static List<Key>* LevelOrder_I(BinaryTree<Key>& tree) {
		List<Key>* list = new ListLinked<Key>;
		QueueLinked<BSNode<Key>*> queue;
		queue.add(tree.root);

		while (!queue.isEmpty()) {
			BSNode<Key>* node = queue.remove();
			if (node != nullptr) {
				list->AddFirst(node->value);
				queue.add(node->leftChild);
				queue.add(node->rightChild);
			}
		}
		return list;
	}
};
