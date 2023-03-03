#include <iostream>
#include "SortingFunctions.h"
using namespace std;


int main()
{
    int A[] = { 11,13,7,12,16,9,24,5,10,3 };
    int n = size(A);

    SortingFunctions::ShellSort(A, n);
    SortingFunctions::display(A, n);

    cout << "hey can\n";


    return 0;


}
