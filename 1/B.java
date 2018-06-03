class B extends A {
    private String mS;
    public int getNum(){return 2;}
    public int getNum(int num) {return num+2;}
//    public void getNum(int num) {System.out.println("void num:"+num);}
    public int getNum(double d) {return 1;}
    private float getNum(float f) {return 2.0f;}
//    public int getNum(int num,int sum) {return sum;}

    public int getSum(int a,int b) {return 1;}
    public static final void main(String args[]) {
        B b = new B();
        System.out.println("Num 1:"+b.getNum());
//        System.out.println("Num 2:"+b.getNum(2));
        System.out.println("Num 3:"+b.getNum(3.0f));
 //       System.out.println("Num 4:"+b.getNum(3));
        int a = 0xfffffff1;
        int c = ~a;
        System.out.println(c);
        String s = null;
        System.out.println(s);
        System.out.println(b.mS);
    }
}
