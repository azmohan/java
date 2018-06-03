public class B extends A {
    B() {
        System.out.println("B constructor");
    }

    B(String name) {
        super(name);
        System.out.println("B constructor one param");
    }

    public static void main(String args[]) {
        B b = new B("azmohan");
    }
}
