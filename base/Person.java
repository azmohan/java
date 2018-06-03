public class Person {
    protected String mName;
    private boolean mSex;

    protected void setName(String name) {
        mName = name;
    }
    protected void printName() {
        System.out.println(mName);
    }
}
