import random 
from testcases import TESTCASES

def partition(array: list[int], low: int, high: int) -> int:
    # Randomized pivot selection to avoid O(n^2) complexity in sorted case
    pivot_index = random.randint(low, high)
    array[low], array[pivot_index] = array[pivot_index], array[low]
    pivot = array[low]
    i, j = low + 1, high

    # Hoare-style two-pointer partitioning with explicit pivot placement.
    # The pivot is isolated first, scanned using inward-moving pointers,
    # and placed into its final position at the end.

    while True:
        while i <= j and array[i] <= pivot:
            i += 1
        while j >= i and array[j] > pivot:
            j -= 1
        if i > j:
            break
        array[i], array[j] = array[j], array[i]
    array[j], array[low] = array[low], array[j]
    return j

def quicksort(array: list[int], low: int, high: int) -> None:    
    # Base case: If the subarray is empty or has just one element, there
    # is nothing left to sort. Simply end the recursive path in that direction
    if high <= low:
        return
    
    # Recursive case: Partition the array using a Hoare-style two-pointer scheme.
    # The pivot is chosen as the first element and placed into
    # its correct position after partitioning.
    partition_index = partition(array, low, high)
    # The partition_index returned by the partition function
    # is the "correct" index of the randomly picked element, which
    # is the index where it would be at in the sorted array.
    # This is the fundamental idea behind quicksort, 
    # which is simply picking an element and placing it
    # in its correct position, and then repeating the process
    # on the partitions to its left and right.
    quicksort(array, low, partition_index - 1)
    quicksort(array, partition_index + 1, high)

if __name__ == "__main__":
    for index, testcase in enumerate(TESTCASES):
        print(f"============== Testcase {index + 1} ==============")
        print(f"Before sorting: {testcase}")
        quicksort(testcase, 0, len(testcase) - 1)
        print(f"After sorting: {testcase}")