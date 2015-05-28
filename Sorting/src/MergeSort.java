/**
 * Created by PrashantH on 28-May-15.
 */
public class MergeSort {
    private int[] m_array;
    public static void main(String[] args) {
        int[] array = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        MergeSort sorter = new MergeSort(array);
        sorter.sort(0, array.length - 1);
        sorter.printSortedArray();
    }

    /*
    Merge Sort Works as follows:
    It works based on the divide and conquer strategy, i.e it breaks
    down the array into single element and combines/merges each individual
    element. While merging it sorts two parts, and places them sorted array.
    This process continues until all the divided parts are merged.
     */
    
    public MergeSort(int[] array) {
        m_array = array;
    }

    private void sort(int left, int right) {
        // If left is greater than right then, array is sorted.
        if (left < right) {
            int mid = (left + right) / 2;
            sort(left, mid);
            sort(mid + 1, right);
            merge(left, mid, right);
        }
    }

    private void merge(int left, int mid, int right) {
        int[] tempArray = new int[right - left + 1];
        int i = left;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= right) {
            if (m_array[i] <= m_array[j]) {
                tempArray[k] = m_array[i];
                i++; k++;
            } else {
                tempArray[k] = m_array[j];
                j++; k++;
            }
        }

        while (j <= right) {
            tempArray[k++] = m_array[j++];
        }

        while (i <= mid) {
            tempArray[k++] = m_array[i++];
        }

        for (k = 0; k < tempArray.length; k++) {
            m_array[left + k] = tempArray[k];
        }
    }

    private void printSortedArray() {
        for (int i = 0; i < m_array.length; i++) {
            System.out.println(m_array[i]);
        }
    }
}
