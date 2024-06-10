#include "Algorithms.h"

//BubbleSort
std::vector<int> Sorts::BubbleSort(std::vector<int> list)
{
	int n = list.size();

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (list[j] > list[j + 1])
			{
				//zamiana miejscami
				int temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
				
		}
	}
	return list;
}
//MergeSort
std::vector<int> Sorts::Merge(std::vector<int>& left, std::vector<int>& right) {
    std::vector<int> result;
    size_t leftIndex = 0, rightIndex = 0;

    while (leftIndex < left.size() && rightIndex < right.size()) {
        if (left[leftIndex] < right[rightIndex]) {
            result.push_back(left[leftIndex]);
            leftIndex++;
        }
        else {
            result.push_back(right[rightIndex]);
            rightIndex++;
        }
    }

    while (leftIndex < left.size()) {
        result.push_back(left[leftIndex]);
        leftIndex++;
    }

    while (rightIndex < right.size()) {
        result.push_back(right[rightIndex]);
        rightIndex++;
    }

    return result;
}

std::vector<int> Sorts::MergeSort(std::vector<int> list) {
    if (list.size() <= 1) {
        return list;
    }

    size_t middle = list.size() / 2;
    std::vector<int> left(list.begin(), list.begin() + middle);
    std::vector<int> right(list.begin() + middle, list.end());

    left = MergeSort(left);
    right = MergeSort(right);

    return Merge(left, right);
}
//QuickSort
int Sorts::partition(std::vector<int>& list, int low, int high) {
    int pivot = list[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (list[j] < pivot) {
            i++;
            std::swap(list[i], list[j]);
        }
    }
    std::swap(list[i + 1], list[high]);
    return i + 1;
}

void Sorts::quickSortUtil(std::vector<int>& list, int low, int high) {
    if (low < high) {
        int pi = partition(list, low, high);
        quickSortUtil(list, low, pi - 1);
        quickSortUtil(list, pi + 1, high);
    }
}

std::vector<int> Sorts::QuickSort(std::vector<int>& list) {
    std::vector<int> sortedArr = list;
    int size = sortedArr.size();
    quickSortUtil(sortedArr, 0, size - 1);
    return sortedArr;
}
//HeapSort 
void Sorts::heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // Inicjalizujemy najwiêkszy jako korzeñ
    int left = 2 * i + 1; // lewy = 2*i + 1
    int right = 2 * i + 2; // prawy = 2*i + 2

    // Jeœli lewy liœæ jest wiêkszy ni¿ korzeñ
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Jeœli prawy liœæ jest wiêkszy ni¿ najwiêkszy dotychczasowy element
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Jeœli najwiêkszy nie jest korzeniem
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Rekurencyjnie przekszta³camy poddrzewo w kopiec
        heapify(arr, n, largest);
    }
}
std::vector<int> Sorts::heapSort(std::vector<int> arr) {
    int n = arr.size();

    // Budujemy kopiec (przekszta³camy tablicê w kopiec)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Wyci¹gamy elementy jeden po drugim z kopca
    for (int i = n - 1; i > 0; i--) {
        // Przenosimy bie¿¹cy korzeñ (najwiêkszy element) na koniec
        std::swap(arr[0], arr[i]);

        // Wywo³ujemy heapify na zredukowanym kopcu
        heapify(arr, i, 0);
    }

    return arr;
}