def heapify(arr, n, i):
    largest = i
    left= 2*i + 1
    right = 2*i + 2

    if left < n and arr[left] > arr[largest]:
        largest = left

    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def build_max_heap(arr):
    n = len(arr)
    for i in range(n//2-1,-1,-1):
        heapify(arr, n, i)

def print_array(arr):
    for val in arr:
        print(val, end=' ')
    print()

if __name__ == "__main__":
    n = int(input("Enter number of elements: "))
    print("Enter the elements:")
    arr = [int(input()) for _ in range(n)]

    build_max_heap(arr)

    print("Max Heap:")
    print_array(arr)
    