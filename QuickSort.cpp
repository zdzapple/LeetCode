#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int partition(vector<int>& numbers, int p, int r)
{
	int pivot = numbers[r];
	// i is the last index so that numbers[i] <= pivot;
	// j is the index behind the last index so that numbers[j-1] >= pivot
	int i, j;
	i = p - 1;
	for (j = p; j <= r - 1; ++ j)
	{
		if (numbers[j] <= pivot) {
			i ++;
			// exchange numbers[i] and numbers[j]
			int temp = numbers[j];
			numbers[j] = numbers[i];
			numbers[i] = temp;
		}
	}
	// exchange numbers[i+1] and numbers[r];
	int temp = numbers[r];
	numbers[r] = numbers[i + 1];
	numbers[i+1] = temp;
	return i + 1;
}

// sort numbers[p...r]
void quickSort(vector<int>& numbers, int p, int r)
{
	if (p < r) {
		int q = partition(numbers, p, r);
		quickSort(numbers, p, q-1);
		quickSort(numbers, q+1, r);
	}
}

int main()
{
	int num[] = {2, 8, 7, 1, 3, 5, 6, 4};
	vector<int> numbers(num, num + sizeof(num) / sizeof(int));
	quickSort(numbers, 0, numbers.size() - 1);
	for (int i = 0; i < numbers.size(); ++ i)
		cout << numbers[i] << endl;
	return 0;
}
