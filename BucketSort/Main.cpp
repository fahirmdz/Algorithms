//fahirmdz GitHub

#include"pch.h"
#include"BucketSort.h"
using namespace std;

void main() {
	//testing functions

	int niz[] = { 10,58,90,1,8,12,29,45 };
	Sortiraj<int>(niz,sizeof(niz)/sizeof(niz[0]));
	for (int i = 0; i < 9; i++)
		cout << niz[i] << " ";

}