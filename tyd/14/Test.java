public class Test {
    public static void main(String args[]) {
        float f = 4.2f;
        Float g = new Float(4.2f);
        Double d = new Double(4.2);
        System.out.println("f = g :" + (f == g));
        System.out.println("g = g :" + (g == g));
        System.out.println("d = f :" + (d == f));
        System.out.println("d.equals(f) :" + d.equals(f));
        System.out.println("d.equals(g) :" + d.equals(g));
        System.out.println("g.equals(4.2):" + g.equals(4.2));
    }
}
