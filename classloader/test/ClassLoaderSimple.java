public class ClassLoaderSimple {
    private ClassLoaderSimple instance;
    public void setClassLoaderSimple(Object obj) {
        try {
            instance = (ClassLoaderSimple) obj;
        } catch(Exception e) {
            System.out.println("Exception e = " + e.toString());
        }
        System.out.println("invoke setClassLoaderSimple");
    }
}
