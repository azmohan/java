class MaximumTest {
    public static <T extends Comparable<T>> T maximum(T x,T y,T z) {
        T max = x;
        if (y.compareTo(max) > 0) {
            max = y;
        }

        if (z.compareTo(max) > 0) {
            max = z;
        }
        return max;
    }

    public static void main(String [] args) {
        System.out.printf("%d , %d and %d max number is %d\n",3,4,5,maximum(3,4,5));
        System.out.printf("%  .1f   %.1f and %.1f max float number is % .1f\n",3.0,4.0,5.0,maximum(3.0f,4.0f,5.0f));
        System.out.printf("%.1f, %.1f and %.1f max float number is %.1f\n",3.0,4.0,5.0,maximum(3.0,4.0,5.0));
        //System.out.printf( "%.1f, %.1f 和 %.1f 中最大的数为 %.1f\n\n", 6.6, 8.8, 7.7, maximum( 6.6, 8.8, 7.7  ) );
        System.out.printf("%s , %s and %s max string numbber is %s\n","pear","apple","orange",maximum("pear","apple","orange"));
    }
}
