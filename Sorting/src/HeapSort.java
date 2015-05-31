import java.util.Arrays;

/**
 * Created by PrashantH on 31-May-15.
 */
public class HeapSort {
    private int total;

    public static void main(String[] args) {
        Integer[] arr =  new Integer[] {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        HeapSort sorter = new HeapSort();
        sorter.sort(arr);
        sorter.printArray(arr);
    }

    /*
    Working of Heap Sort:
        First we turn input array into max_heap. By the max_heap property,
        the root has the largest key. So we record the key as the largest
        key in the input array.
        Now we replace key of the root by the key of the last node and decrement
        the size of the node by one. This may generate violation of the max heap
        property, but that can be resolved by again calling heapify. Thus we find
        second largest key, this process continues till all the elements are sorted.
     */
    private void sort(Comparable[] arr) {
        total = arr.length - 1;

        for (int i = total / 2; i >= 0; i--) {
            heapify(arr, i);
        }

        for (int i = total; i > 0; i--) {
            swap(arr, 0, i);
            total--;
            heapify(arr, 0);
        }
    }

    private void heapify(Comparable[] arr, int i) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int max = i;

        if (left <= total && arr[left].compareTo(arr[max]) > 0)
            max = left;
        if (right <= total && arr[right].compareTo(arr[max]) > 0)
            max = right;
        if (max != i) {
            swap(arr, i, max);
            heapify(arr, max);
        }
    }

    private void swap(Comparable[] arr, int i, int j) {
        Comparable tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    private void printArray(Integer[] arr) {
        System.out.println(Arrays.toString(arr));
    }
}
