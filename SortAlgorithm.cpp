#include <iostream>
#include <vector>
using namespace std;
/**
* mergeSort quickSort
*
**/

// merge numbers[p..r]
void mergeSort(vector &numbers, int p, int r)
{
    if (p < r) {
		int q = (p + r) / 2;
		mergeSort(numbers, p, q);
		mergeSort(numbers, q + 1, r);
		merge(numbers, p, q, r);
	}
}

void merge(vector &numbers, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	vector left, right;
	int i, j;
	for (i = 0; i < n1; ++ i)
		left.push_back(numbers[p + i]);
	for (i = 0; i < n2; ++ i)
		right.push_back(nubmers[q + 1 + i]);
	i = 0, j = 0;
	for (int k = p; k <= r; k ++) {
		if (left[i] <= right[j])
			numbers[k] = left[i ++];
		else
			numbers[k] = right[j ++];
	}
}



int main()
{
} 
