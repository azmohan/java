class Test {
    public static void main(String [] args)  {
        String bootStr = System.getProperty("sun.boot.class.path");
        System.out.println("bootStr = " + bootStr);
        String extStr = System.getProperty("java.ext.dirs");
        System.out.println("extStr = " + extStr);
        String appStr = System.getProperty("java.class.path");
        System.out.println("appStr = " + appStr);
    }
}
