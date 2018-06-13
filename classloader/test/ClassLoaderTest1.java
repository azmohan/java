class ClassLoaderTest1 {
    public static void main(String [] args) {
        ClassLoader loader = ClassLoaderSimple.class.getClassLoader();
        System.out.println("ClassLoader is : " + loader.toString());
        System.out.println("Parent ClassLoader is : " + loader.getParent().toString());
        System.out.println("ExtClassLoader Parent ClassLoader is : " + loader.getParent().getParent().toString());
        loader = String.class.getClassLoader();
        System.out.println("ClassLoader is : " + loader.toString());
    }
}
