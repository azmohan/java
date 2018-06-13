import java.util.List;
import java.util.ArrayList;
class GenericTest {
    public static void main(String[] args) {
        List<String> name = new ArrayList<String>();
        List<Integer> age = new ArrayList<Integer>();
        List<Number> number = new ArrayList<Number>();
        List<Object> object = new ArrayList<Object>();

        name.add("lily");
        age.add(18);
        number.add(181);
        object.add(new Object());

        getData(name);
        getData(age);
        getData(number);

     //   getUperNumber(name);
        getUperNumber(number);
        getUperNumber(object);

        getBelowNumber(name);

        getBelowNumber(object);
    }

    public static void getData(List<?> data) {
        System.out.println("data : " + data.get(0));
    }

    public static void getUperNumber(List< ? extends Number> data) {
        System.out.println("data : " + data.get(0));
    }

    public static void getBelowNumber(List < ? super String> data) {
        System.out.println("data : " + data.get(0));
    }

    /**
     * <? extends T> 表示该通配符所代表的类型是T类型的子类。
     * < ? super T> 表示该通配符所代表的类型是T类型的父类。
     * 不管是父类，还是子类都包含它自己。
     * java的泛型只是编译时的一个策略，不支持原始(primitive)类型。
     *
     * */
}
