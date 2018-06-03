public class Test implements Foo {
    public static void main (String []args) {
        int i ;
        Test test = new Test();
        i = test.k;
        i = Test.k;
        i = Foo.k;
    }
}
