class Test {
    private static boolean change(char a) {
        System.out.print(a);
        return true;
    }

    public static void main(String [] args) {
        int i = 0;
        for(change('a');change('b') && i < 2;change('c')) {
            i ++;
            change('d');
        }
        System.out.print('\n');

    }
}
