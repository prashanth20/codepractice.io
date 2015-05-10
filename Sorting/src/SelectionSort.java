/**
 * Created by PrashantH on 10-May-15.
 */
public class SelectionSort {
    public static void main(String[] args) {
        int[] array = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        SelectionSort sorter = new SelectionSort();
        sorter.sort(array);
    }
    /*
    Selection sort Algorithm works as follows:
    In this sorting algorithm, we first scan through entire array and find the smallest element
    in the array, then we replace the smallest element with the first element. The process
    continues till we position, which are all in the proper position.
    */
    private void sort(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            int small = i;
            for (int j = i + 1; j < array.length; j++) {
                if (array[small] > array[j]) {
                    small = j;
                }
            }
            int temp = array[small];
            array[small] = array[i];
            array[i] = temp;
        }
        printSortedArray(array);
    }

    private void printSortedArray(int[] array) {
        for (int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
        }
    }
}
