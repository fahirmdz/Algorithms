//fahirmdz GitHub

#include"pch.h"
#include"BinarySearchTraversals.h"
using namespace std;

void printDescribe(int x1, int x2) {

	cout << endl;
	for (int i = 0; i < x1; i++)
		cout << "-";
	cout << "ROOT";
	for (int i = 0; i < x2; i++)
		cout << "-";
	cout << endl << endl;

}
void main() {
	BinaryTree<int> bts;
	bts.Add(50);
	bts.Add(76);
	bts.Add(21);
	bts.Add(4);
	bts.Add(32);
	bts.Add(64);
	bts.Add(15);
	bts.Add(52);
	bts.Add(14);
	bts.Add(100);
	bts.Add(83);
	bts.Add(2);
	bts.Add(3);
	bts.Add(70);
	bts.Add(87);
	bts.Add(80);

	//===============Binary tree IN ORDER (DFS)=================
	cout << "Binary tree In Order (recursion): ";
	for (int i = 0; i < 16; i++)
		cout << BinarySearchTraversals<int>::InOrder_R(bts)->get(i) << " ";
	printDescribe(51, 24);

	cout << "Binary tree In Order (iteration, queue): ";
	for (int i = 0; i < 16; i++)
		cout << BinarySearchTraversals<int>::InOrder_I(bts)->get(i) << " ";
	printDescribe(58, 25);
	//=====================================================

	//=============Binary tree PRE ORDER (DFS)===================
	cout << "Binary tree Pre Order (recusrsion): ";
	for (int i = 0; i < 16; i++)
		cout << BinarySearchTraversals<int>::PreOrder_R(bts)->get(i) << " ";
	printDescribe(35, 42);

	cout << "Binary tree Pre Order (iteration, queue): ";
	for (int i = 0; i < 16; i++)
		cout << BinarySearchTraversals<int>::PreOrder_I(bts)->get(i) << " ";
	printDescribe(41, 42);
	//====================================================

	//============Binary tree POST ORDER (DFS)==================
	cout << "Binary tree Post Order (recursion): ";
	for (int i = 0; i < 16; i++)
		cout << BinarySearchTraversals<int>::PostOrder_R(bts)->get(i) << " ";
	printDescribe(78, 0);

	cout << "Binary tree Post Order (iteration, queue): ";
	for (int i = 0; i < 16; i++)
		cout << BinarySearchTraversals<int>::PostOrder_I(bts)->get(i) << " ";
	printDescribe(85, 0);
	//==================================================

	cout << "Binary tree Level Order (BFS): ";
	for (int i = 0; i < 16; i++)
		cout << BinarySearchTraversals<int>::LevelOrder_I(bts)->get(i) << " ";
	printDescribe(30, 42);
	//==================================================
}