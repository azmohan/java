public class TestFinally {
    public int getReturn() {
        try {
            return 1;
        } finally {
            return 2;
        }
    }

    public static void main(String [] args) {
        TestFinally test = new TestFinally();
        System.out.println(test.getReturn());
    }
}
