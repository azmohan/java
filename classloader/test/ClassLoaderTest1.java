class ClassLoaderTest1 {
    public static void main(String [] args) {
        ClassLoader loader = ClassLoaderSimple.class.getClassLoader();
        System.out.println("ClassLoader is : " + loader.toString());
        loader = String.class.getClassLoader();
        System.out.println("ClassLoader is : " + loader.toString());
    }
}
