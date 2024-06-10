


#include <vector>


class Sorts
{
public:
	//bubblesort
	static std::vector<int> BubbleSort(std::vector<int> list);
	//mergesort
	static std::vector<int> Merge(std::vector<int>& left, std::vector<int>& right);
	static std::vector<int> MergeSort(std::vector<int> list);
	//quickSort
	static int partition(std::vector<int>& list, int low, int high);
	static void quickSortUtil(std::vector<int>& list, int low, int high);
	static std::vector<int> QuickSort(std::vector<int>& list);
	//HeapSort
	static void heapify(std::vector<int>& arr, int n, int i);
	static std::vector<int> heapSort(std::vector<int> arr);



};