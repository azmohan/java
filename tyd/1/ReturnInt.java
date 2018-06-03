public class ReturnInt {
    private double method(byte x,double y) {
        return (short) x/y *2;
    }

    public static final void main(String []args) {
        ReturnInt ai = new ReturnInt();
        double y = 3.14;
        byte x = 1;
        double s = ai.method(x,y);
        System.out.println(s);
    }
}
