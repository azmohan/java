public class BubbleSort {
    private int array[] = {8,1,3,4,6,7,9,2,5};

    // BubbleSort method core algorithm the last one is biggest
    // of smallest.
    private void bubbleSort() {
        for (int j = 0; j < array.length - 1; j++) {
            for (int i = 0;i < array.length -1 -j ;i++) {
                int first = array[i];
                int second = array[1+i];
                if (first > second) {
                    array[i] = second;
                    array[i+1] = first;
                }
            }
        }
    }

    private void quickSort() {
        for (int j = 0;j < array.length - 1;j=j+2) {
            for (int i = 1; i < array.length -1 -j; i++) {
                int before = array[i - 1];
                int me = array[i];
                int after = array[i + 1];
                int max = after;
                int index = 2;
                if (max < me) {
                    max = me;
                    index = 1;
                }
                if (max < before) {
                    max = before;
                    index = 0;
                }
                array[i + 1] = max;
                switch(index) {
                    case 0:
                        if (me > after) {
                            array[i -1] = after;
                        } else {
                            array[i - 1] = me;
                            array[i] = after;
                        }
                        break;
                    case 1:
                        if (before < after) {
                            array[i - 1] = before;
                            array[i] = after;
                        } else {
                            array[i - 1] = after;
                            array[i] = before;
                        }
                        break;
                    case 2:
                        if (before > me) {
                            array[i -1] = me;
                            array[i] = before;
                        }
                        break;
                }
            }
        }
    }

    public static void main(String[] args) {
        BubbleSort bs = new BubbleSort();
        //bs.bubbleSort();
        bs.quickSort();
        for (int i  = 0;i < bs.array.length;i++) {
            System.out.println(bs.array[i]);
        }
    }
}
