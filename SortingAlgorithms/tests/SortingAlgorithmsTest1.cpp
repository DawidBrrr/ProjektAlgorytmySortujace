#include <gtest/gtest.h>
#include "Algorithms.h"

TEST(BubbleSortTest, HandlesEmptyList) {
    std::vector<int> input = {};
    std::vector<int> expected = {};
    EXPECT_EQ(Sorts::BubbleSort(input), expected);
}

TEST(BubbleSortTest, HandlesSingleElementList) {
    std::vector<int> input = { 1 };
    std::vector<int> expected = { 1 };
    EXPECT_EQ(Sorts::BubbleSort(input), expected);
}

TEST(BubbleSortTest, HandlesSortedList) {
    std::vector<int> input = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(Sorts::BubbleSort(input), expected);
}

TEST(BubbleSortTest, HandlesReverseSortedList) {
    std::vector<int> input = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(Sorts::BubbleSort(input), expected);
}

TEST(BubbleSortTest, HandlesUnsortedList) {
    std::vector<int> input = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    std::vector<int> expected = { 1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9 };
    EXPECT_EQ(Sorts::BubbleSort(input), expected);
}

// Testy dla MergeSort

TEST(MergeSortTest, HandlesEmptyList) {
    std::vector<int> input = {};
    std::vector<int> expected = {};
    EXPECT_EQ(Sorts::MergeSort(input), expected);
}

TEST(MergeSortTest, HandlesSingleElementList) {
    std::vector<int> input = { 1 };
    std::vector<int> expected = { 1 };
    EXPECT_EQ(Sorts::MergeSort(input), expected);
}

TEST(MergeSortTest, HandlesSortedList) {
    std::vector<int> input = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(Sorts::MergeSort(input), expected);
}

TEST(MergeSortTest, HandlesReverseSortedList) {
    std::vector<int> input = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(Sorts::MergeSort(input), expected);
}

TEST(MergeSortTest, HandlesUnsortedList) {
    std::vector<int> input = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    std::vector<int> expected = { 1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9 };
    EXPECT_EQ(Sorts::MergeSort(input), expected);
}

// Testy dla QuickSort

TEST(QuickSortTest, HandlesEmptyList) {
    std::vector<int> input = {};
    std::vector<int> expected = {};
    EXPECT_EQ(Sorts::QuickSort(input), expected);
}

TEST(QuickSortTest, HandlesSingleElementList) {
    std::vector<int> input = { 1 };
    std::vector<int> expected = { 1 };
    EXPECT_EQ(Sorts::QuickSort(input), expected);
}

TEST(QuickSortTest, HandlesSortedList) {
    std::vector<int> input = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(Sorts::QuickSort(input), expected);
}

TEST(QuickSortTest, HandlesReverseSortedList) {
    std::vector<int> input = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(Sorts::QuickSort(input), expected);
}

TEST(QuickSortTest, HandlesUnsortedList) {
    std::vector<int> input = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    std::vector<int> expected = { 1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9 };
    EXPECT_EQ(Sorts::QuickSort(input), expected);
}

// Testy dla HeapSort

TEST(HeapSortTest, HandlesEmptyList) {
    std::vector<int> input = {};
    std::vector<int> expected = {};
    EXPECT_EQ(Sorts::heapSort(input), expected);
}

TEST(HeapSortTest, HandlesSingleElementList) {
    std::vector<int> input = { 1 };
    std::vector<int> expected = { 1 };
    EXPECT_EQ(Sorts::heapSort(input), expected);
}

TEST(HeapSortTest, HandlesSortedList) {
    std::vector<int> input = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(Sorts::heapSort(input), expected);
}

TEST(HeapSortTest, HandlesReverseSortedList) {
    std::vector<int> input = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(Sorts::heapSort(input), expected);
}

TEST(HeapSortTest, HandlesUnsortedList) {
    std::vector<int> input = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    std::vector<int> expected = { 1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9 };
    EXPECT_EQ(Sorts::heapSort(input), expected);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}