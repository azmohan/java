public class FatherClass {
    public FatherClass() {
        System.out.println("FatherClass created");
    }

    public static class ChildClass extends FatherClass {
        public ChildClass() {
            System.out.println("ChildClass created");
        }
    }

    public static void main(String[] args) {
        FatherClass fc = new FatherClass();
        ChildClass cc = new ChildClass();
    }
}
