public class SubClass extends BaseClass {
    private float x = 2.0f;

//    float getVar() {return x;}
//    public float getVar() {return x;}
//    public double getVar() {return 3.0d;}
    protected float getVar() {return x;}
    public float getVar(float f) {return x;}
}
