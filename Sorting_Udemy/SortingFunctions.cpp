#include "SortingFunctions.h"
#include "Node.h"
#include <iostream>
using namespace std;

void SortingFunctions::swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;

}

void SortingFunctions::display(int A[], int n) {
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
}

int SortingFunctions::findmax(int A[], int n) {
	int max=A[0];
	for (int i = 1; i < n; i++) {
		if (A[i] > max)
			max = A[i];
	}
	return max;
}

int SortingFunctions::partition(int A[], int l, int h) {
	int pivot = A[l];
	int i = l;
	int j = h;

	do {
		do { i++; } while (A[i] <= pivot);
		do { j--; } while (A[j] > pivot);

		if (i < j)
			swap(&A[i], &A[j]);
	} while (i < j);
	swap(&A[l], &A[j]);
	return j;
}

void SortingFunctions::merge(int A[], int l, int mid, int h) {
	int i = l;
	int j = mid + 1;
	int k = l;
	int B[100]; /*assuming and array with 100 elements*/

	while (i <= mid && j <= h) {
		if (A[i] < A[j])
			B[k++] = A[i++];
		else
			B[k++] = A[j++];
	}
	for (; i <= mid; i++)
		B[k++] = A[i];
	for (; j <= h; j++)
		B[k++] = A[j];

	for (int i = l; i <= h; i++) {
		A[i] = B[i];
	}
}

void SortingFunctions::insert(Node** ptrBins, int index) {
	Node* temp = new Node;
	temp->value = index;
	temp->next = NULL;

	if (ptrBins[index] == NULL) {
		ptrBins[index] = temp;
	}
	else {
		Node* p = ptrBins[index];
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = temp;
	}

}

void SortingFunctions::insertRadix(Node** ptrBins, int index, int value) {
	Node* temp = new Node;
	temp->value = value;
	temp->next = NULL;

	if (ptrBins[index] == NULL) {
		ptrBins[index] = temp;
	}
	else {
		Node* p = ptrBins[index];
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = temp;
	}

}

int SortingFunctions::Delete(Node** ptrBins, int index) {
	Node* p = ptrBins[index];
	ptrBins[index] = ptrBins[index]->next;
	int x = p->value;
	delete p;
	return x;
}

void SortingFunctions::BubbleSort(int A[], int n)
{
	int flag;
	for (int i = 0; i < n - 1; i++) {
		flag = 0;
		for (int j = 0; j < n - 1 - i; j++) {
			if (A[j] > A[j + 1]) {
				swap(&A[j], &A[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;

	}

}

void SortingFunctions::InsertionSort(int A[], int n){
	int i;
	int j;
	int x;
	for (i = 1; i < n; i++) {
		j = i - 1;
		x = A[i];
		while (j > -1 && A[j] > x) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x;
	}
}

void SortingFunctions::SelectionSort(int A[], int n) {
	int i;
	int j;
	int k;

	for (i = 0; i < n-1; i++) {
		for (j=k=i; j < n; j++)
			if (A[j] < A[k])
				k = j;
			swap(&A[i], &A[k]);
	}
}

void SortingFunctions::QuickSortMain(int A[], int l, int h) {
	int j;
	if (l < h) {
		j = partition(A, l, h);
		QuickSortMain(A, l, j);
		QuickSortMain(A, (j+1), h);
	}

}

void SortingFunctions::QuickSort(int A[], int n) {
	int h = n;
	int l = 0;
	QuickSortMain(A, l, h);

}

void SortingFunctions::IMergeSort(int A[], int n) {
	int p,l,h,mid,i;

	for (p = 2; p <= n; p = p * 2) {
		for (i = 0; i + p - 1 < n; i = i + p) {
			l = i;
			h = i + p - 1;
			mid = (l + h) / 2;
			merge(A, l, mid, h);
		}
	}
	if (p / 2 < n)
		merge(A, 0, p / 2-1, n-1);

}

void SortingFunctions::RMergeSort(int A[], int n) {
	int l = 0;
	int h = n - 1;
	RMergeSortMain(A, l, h);
}

void SortingFunctions::RMergeSortMain(int A[], int l, int h) {
	int mid;
	if (l < h) {
		mid = (l + h) / 2;
		RMergeSortMain(A, l, mid);
		RMergeSortMain(A, (mid + 1), h);
		merge(A, l, mid, h);
	}
}

void SortingFunctions::CountSort(int A[], int n) {
	int max;
	int i;
	int j;
	int* C;
	max = findmax(A, n);
	C = new int[max + 1];

	for (i = 0; i < (max + 1); i++)
		C[i] = 0;

	for (i = 0; i < n; i++)
		C[A[i]]++;

	i = 0;
	j = 0;

	while (i < (max + 1)) {
		if (C[i] > 0) {
			A[j++] = i;
			C[i]--;
		}
		else
			i++;
	}
}

void SortingFunctions::BinSort(int A[], int n){
	int max, i, j;
	max = findmax(A, n);
	Node** Bins = new Node* [max + 1];

	for (i = 0; i < max+1; i++)
		Bins[i] = NULL;
	for (i = 0; i < n; i++) {
		insert(Bins, A[i]);
	}
	i = 0;
	j = 0;
	while (i < (max + 1)) {
		while (Bins[i] != NULL)
			A[j++] = Delete(Bins,i);
		i++;
	}
	
	delete[] Bins;
}

void SortingFunctions::RadixSort(int A[], int n) {
	int max, i, j;
	int pass=1;
	max = findmax(A, n);
	Node** Bins = new Node * [n];

	while (max / 10 > 0) {
		max = max / 10;
		pass = pass + 1;
	}

	for (int k = 0; k < pass; k++) {
		for (i = 0; i < n; i++)
			Bins[i] = NULL;

		for (i = 0; i < n; i++) {
			insertRadix(Bins, int(A[i]/(pow(10,k))) % 10, A[i]);
		}
		i = 0;
		j = 0;
		while (i < n) {
			while (Bins[i] != NULL)
				A[j++] = Delete(Bins, i);
			i++;
		}	
	}
	delete[] Bins;
}

void SortingFunctions::ShellSort(int A[], int n) {
	int gap, i, j,temp;

	for (gap = n / 2; gap >= 1; gap /= 2) {
		for (i = gap; i < n; i++) {
			temp = A[i];
			j = i - gap;
			while (j >= 0 && A[j] > temp) {
				A[j + gap] = A[j];
				j = j - gap;
			}
			A[j + gap] = temp;

		}
	}

}


