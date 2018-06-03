public class Test {
    public static void main(String args[]) {
        int i = 1,j = 10;
        do {
            if(i++ > --j) continue;
            System.out.println("i = " + i + ",j = " + j);
        } while (i < 5) ;
    }
}
