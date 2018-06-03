public class Child extends Parent {
    public Child() {
        super(3);
    }

    public int compareTo(Object o) {
        System.out.println("method of Child") ;
        return 1;
    }

    public static void main (String args[]) {

    }

}
