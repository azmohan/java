public class ConstOver {
    public ConstOver(int x,int y,int z) {}
    ConstOver() {}
//    protected int ConstOver() {retrun -1;}
    private ConstOver(int z,float y,byte x) {}
    public void ConstOver(float x,byte y,byte z) {}
//    public Object ConstOver(int x,int y, float z) {}

    public static void main(String args[]) {
        ConstOver a = new ConstOver();
//        ConstOver b = new ConstOver(3.0f,1,1);
//        ConstOver c = new ConstOver(1,3.0,1);
    }
}
