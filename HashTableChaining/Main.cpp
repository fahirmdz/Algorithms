//fahirmdz GitHub

#include"pch.h"
#include"HashTableChaining.h"

void do_search(HashTableChaining A, int x) {
	if (A.Search(x))
		cout << "Number " << x << " is in hash table..\n";
	else
		cout << "Number " << x << " isn't in hash table..\n";
}
void main() {

	HashTableChaining htc;
	
	htc.Add(1);
	htc.Add(33);
	htc.Add(56);
	htc.Add(98);
	htc.Add(100);
	htc.Add(132);
	htc.Add(191);

	if (htc.Remove(100))
		cout << "Element 100 removed from hash table..\n";

	do_search(htc, 200); //IS NOT
	do_search(htc, 100); //IS NOT
	do_search(htc, 132); //IS
	do_search(htc, 191); //IS
	do_search(htc, 5);   //IS NOT
}