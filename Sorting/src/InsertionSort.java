import java.util.Arrays;

/**
 * Created by PrashantH on 07-May-15.
 */
public class InsertionSort {
    public static void main(String[] args) {
        int[] array = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        InsertionSort sorter = new InsertionSort();
        sorter.sort(array);
    }

    /*
    Insertion sort works as follows :
    We start with sorted array, here we assume that all the element till i-1 are already sorted.
    Then we pick one element at a time and compare it with already sorted array i.e i -1 from right
    to left, whenever we find the correct place for the new element, we will insert it in sorted
    array at that position.
    */
    public void sort(int[] array) {
        for (int i = 1; i < array.length; i++) {
            int j = i - 1;
            int key = array[i];
            while (j >= 0 && array[j] > key) {
                array[j+1] = array[j];
                j--;
            }
            array[j+1] = key;
        }
        printSortedArray(array);
    }

    private void printSortedArray(int[] array) {
        System.out.println(Arrays.toString(array));
    }
}
