import java.lang.reflect.Constructor;
public class ClassLoaderTest {
    public static void main(String [] args) {
        try {
            String path = "/home/azmohan/java/classloader/test";
            String className = "ClassLoaderSimple";
            PathClassLoader load1 = new PathClassLoader(path);
            PathClassLoader load2 = new PathClassLoader(path);
            Class<?> clazz1 = load1.loadClass(className);
            Class<?> clazz2 = load2.loadClass(className);
            Object obj1 = clazz1.newInstance();
            Object obj2 = clazz2.newInstance();
            System.out.println("object 1 classloader = " + clazz1.getClassLoader());
            System.out.println("object 2 Classloader = " + clazz2.getClassLoader());
            clazz1.getMethod("setClassLoaderSimple",Object.class).invoke(obj1,obj2);

            Class<?> strClazz = load1.loadClass("java.lang.Float");
            System.out.println("strClazz classloader = " + strClazz.getClassLoader());
            Constructor constructor = strClazz.getConstructor(String.class);
            Float floatObject = (Float)constructor.newInstance("3.12");
            System.out.println("float value = " + floatObject);
        } catch (Exception e) {
            System.out.println("Exception e:" + e.toString());
        }
    }
}
