#pragma once
#include"PrioritetniRed.h"

template<class T>
class PrioritetniRedHeap :public PrioritetniRed<T> {
	int max, n;
	T* N;
	int GetLijevoDijete(int i) { return i * 2; }
	int GetDesnoDijete(int i) { return i * 2 + 1; }
	int GetRoditelj(int i) { return i / 2; }

	bool DaLiImaLijevoDijete(int i) { return GetLijevoDijete(i) <= n; }
	bool DaLiImaDesnoDijete(int i) { return GetDesnoDijete(i) <= n; }

	bool JeLiList(int i) { return !DaLiImaLijevoDijete(i); }

	void RotirajPoIndexu(int i, int j) { swap(N[i], N[j]); }
	void RotirajPoReferenci(T& a, T& b) { swap(a, b); }

	void BubbleUp(int i) {
		if (i == 1)
			return;
		int roditelj = GetRoditelj(i);
		
		if (N[roditelj] < N[i]) {
			RotirajPoReferenci(N[roditelj], N[i]);
			BubbleUp(roditelj);
		}
	}

	void BubbleDown(int i) {
		int maxI = i;
		
		int LD = GetLijevoDijete(i);
		int DD = GetDesnoDijete(i);

		if (2 * i > n)
			return;

		if (N[LD] > N[i])
			maxI = LD;

		if (2 * i <= n)
			if (N[DD] > N[maxI])
				maxI = DD;
		if (maxI != i) {
			RotirajPoIndexu(maxI, i);
			BubbleDown(maxI);
		}
	}

public:
	PrioritetniRedHeap(int max = 5) {
		this->max = max;
		n = 0;
		N = new T[max];
	}

	void Dodaj(T x) {
		if (max == n)
			return;
		n++;
		N[n] = x;
		BubbleUp(n);
	}

	T Ukloni() {
		if (isEmpty())
			throw exception("PRHeap prazan..\n");
		T value = N[1];
		N[1] = N[n--];
		BubbleDown(1);
	}

	bool isEmpty() { return n == 0; }

	void print() {
		if(isEmpty())
			throw exception("PRHeap prazan..\n");
		for (int i = 1; i <= n; i++)
			cout << N[i] << " ";
	}

};