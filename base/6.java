class StaticValue {
    static int i;
    static int x = 20,y = 30;
    static boolean b = x > 50 && y > 60 || x > 50 && y < -60
        || x < -50 && y > 60 || x < -50 && y < -60;


    public static void main(String [] args) {
        System.out.println(i);
        System.out.println(b);
    }
}
