public class B extends A {
    public int a;
    public void set(){}
    public void print(String str) {
        System.out.println("this is not final method");
    }
    public void print() {
    }

    public static void main(String []args) {
        B b = new B();
        b.print();
//        System.out.println(A.b);
    }
}
