import java.util.ArrayList;
import java.util.List;
class Test {
    public final static void main(String [] args) {
        final List<String> strList = new ArrayList<>();
        strList.add("Hello");
        strList.add(" world");

        List<String> unmodifiableStrList = List<String>.of("Hello"," world");
        unmodifiableStrList.add("again");

    }
}
