class Singleton {
    private static Singleton sInstance;

    private Singleton() {}

    public static Singleton getInstance() {
        if (sInstance == null) {
            sInstance = new Singleton();
        }
        return sInstance;
    }
}
