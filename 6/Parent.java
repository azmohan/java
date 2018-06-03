public class Parent implement comparable {
    private int age = 0;

    public Parent(int age) {
        this.age = age;
    }

    public int compareTo(Object o) {
        System.out.println("method parent") ;
        Parent parent = (Parent) o;
        return age > parent.age ? 1 : age < parent.age ? -1 : 0;
    }
}
