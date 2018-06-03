public class X {
    public Object m() {
        Object o = new Float(3.14f);
        Object[] oa = new Object[1];
        oa[0] = o;
        o = null;
        oa[0] = null;
        System.out.println(oa[0]);
        return oa[0];
    }

    public static final void main(String [] args) {
        X x = new X();
        x.m();
    }
}
