public class TestString {
    public static void main(String [] args) {
        String s1 = "Monday";
        String s2 = "Monday";
        String s3 = new String("Monday");

        System.out.println("s1 == s2:"+(s1==s2));
        System.out.println("s1 == s3:"+(s1==s3));
        System.out.println("s1.equals(s3):"+s1.equals(s3));

        s3 = s3.intern();
        System.out.println("s1 == s3:"+(s1==s3));
    }
}
