public class InsertionSort {
    int array [] = {1,4,5,8,9,6,3,2,7};

    private void insertionSort() {
        for (int i = 1;i < array.length;i++) {
            int t = array[i];
            for (int j = i-1;j >=0 && t > array[j];j--) {
                array[j+1] = array[j];
                array[j] = t;
            }
        }
    }

    public static void main(String[] args) {
        InsertionSort is = new InsertionSort();
        is.insertionSort();
        for (int i = 0;i < is.array.length; i++) {
            System.out.println(is.array[i]);
        }
    }
}
