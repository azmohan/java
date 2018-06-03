public class Student extends Person {
    public void setName(String name) {
        mName = name;
    }

    public static void main(String[] args) {
        Person person = new Student();
        person.setName("keke");
        person.printName();
    }
}
