from testcases import TESTCASES
def mergesort(array: list[int], left: int, right: int):
    if left == right:
        return # Just backtrack out of the leaf node, because there is nothing to be done on a single element
    mid = (left + right) // 2
    mergesort(array, left, mid)
    mergesort(array, mid + 1, right)
    merge(array, left, right)

def merge(array: list[int], left: int, right: int):
    # Step 1: Allocate intermediate memory
    buffer = [0] * (right - left + 1)
    
    # Step 2: Use two pointers to store the elements of the two sub-arrays in sorted order
    mid = (left + right) // 2
    p1, p2, i = left, mid + 1, 0
    while p1 <= mid and p2 <= right:
        if array[p1] <= array[p2]:
            buffer[i] = array[p1]
            p1 += 1
        else:
            buffer[i] = array[p2]
            p2 += 1
        i += 1
    while p1 <= mid:
        buffer[i] = array[p1]
        i += 1
        p1 += 1
    while p2 <= right:
        buffer[i] = array[p2]
        i += 1
        p2 += 1
    
    # Step 3: Write the sorted buffer into the original array
    for i in range(len(buffer)):
        array[left + i] = buffer[i]
    

if __name__ == "__main__":
    for index, testcase in enumerate(TESTCASES):
        print(f"========================= Testcase {index + 1} =========================")
        print(f"Before sorting: {testcase}")
        mergesort(testcase, 0, len(testcase) - 1)
        print(f"After sorting: {testcase}")