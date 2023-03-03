#pragma once
#include "Node.h"
class SortingFunctions
{
public :
	static void swap(int* i, int* j);
	static void display(int A[], int n);
	static int partition(int A[], int l, int h);
	static void merge(int A[], int l, int mid, int h);
	static int findmax(int A[], int n);
	static void insert(Node** ptrBins, int index);
	static void insertRadix(Node** ptrBins, int index, int value);
	static int Delete(Node** ptrBins, int index);
	static void BubbleSort(int A[], int n);
	static void InsertionSort(int A[], int n);
	static void SelectionSort(int A[], int n);
	static void QuickSortMain(int A[], int l, int h);
	static void QuickSort(int A[], int n);
	static void IMergeSort(int A[], int n);
	static void RMergeSortMain(int A[], int l, int h);
	static void CountSort(int A[], int n);
	static void BinSort(int A[], int n);
	static void RadixSort(int A[], int n);
	static void ShellSort(int A[], int n);
	static void RMergeSort(int A[], int n);

};

