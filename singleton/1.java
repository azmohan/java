class Singleton {
    private static Singleton sInstance = new Singleton();

    private Singleton() {}

    public static Singleton getInstance() {
        return sInstance;
    }
}
