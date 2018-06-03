public class IfElse {
    public static void main(String args[]) {
        if(odd(5) == 1) {
            System.out.println("odd");
        } else {
            System.out.println("else");
        }
    }

    public static int odd(int x) {return x % 2;}
}
