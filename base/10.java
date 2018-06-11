import java.util.ArrayList;
import java.util.List;
class Test {
    public static void main(String [] args) {
        final List<String> strList = new ArrayList<>();
        strList.add("Hello");
        strList.add(" world");
        System.out.println("strList = " + strList.toString());
        List<String> unmodifiableStrList = List.of("hello","world");
        System.out.println("unmodifiableStrList = " + unmodifiableStrList.toString());

    }

}
