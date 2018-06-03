class Person {
    int arr[] = new int[10];

    // guassion algorithm
    private static void jisuan(int n) {
        int sum = 0;
        if (n % 2 == 0) {
            sum = -(n / 2);
            System.out.println(" " + sum);
        } else {
            sum = -(n - 1) / 2 + n;
            System.out.println(" " + sum);
        }
    }

    public static void main(String args[]) {
        jisuan(100);
    }
}
