import java.util.Arrays;

/**
 * Created by PrashantH on 18-May-15.
 */
public class BubbleSort {
    public static void main(String[] args) {
        int[] array = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        BubbleSort sorter = new BubbleSort();
        sorter.sort(array);
    }

    /*
     Bubble Sort works as follows:
     It starts from left and compares each element with its neighbour,
     if it is greater than that then swaps with it. This process continues
     for n-1 iterations.
     So by end of each iteration, largest element goes to the end of
     array.
    * */
    private void sort(int[] array) {
        for (int i = 0; i <= array.length; i++) {
            for (int j = 1; j <= (array.length - 1); j++) {
                if (array[j-1] > array[j]) {
                    int temp = array[j-1];
                    array[j-1] = array[j];
                    array[j] = temp;
                }
            }
        }
        printSortedArray(array);
    }

    private void printSortedArray(int[] array) {
        System.out.println(Arrays.toString(array));
    }
}
