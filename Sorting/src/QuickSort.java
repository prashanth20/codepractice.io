import java.util.Arrays;

/**
 * Created by PrashantH on 21-Jun-15.
 */
public class QuickSort {
    public static void main(String[] args) {
        int[] array = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        int low = 0;
        int high = array.length - 1;
        QuickSort sorter = new QuickSort();
        sorter.sort(array, low, high);
        sorter.printSortedArray(array);
    }

    /* Quicksort is a divide and conquer algorithm. It first divides a large
       list into two smaller sub-lists and then recursively sort the two
       sub-lists. If we want to sort an array without any extra space,
       quicksort is a good option. On average, time complexity is O(n log(n)).

       The basic step of sorting an array are as follows:
       1. Select a pivot, normally the middle one.
       2. From both ends, swap elements and make all elements on the left less
          than the pivot and all elements on the right greater than the pivot.
       3. Recursively sort left part and right part
    */

    private void sort(int[] arr, int low, int high) {
        int pivot = arr[(low + high) / 2];
        int i = low, j = high;
        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }

            while (arr[j] > pivot) {
                j--;
            }

            if (i <= j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }

        if (low < j)
            sort(arr, low, j);
        if (high > i)
            sort(arr, i, high);
    }

    private void printSortedArray(int[] array) {
        System.out.println(Arrays.toString(array));
    }
}
