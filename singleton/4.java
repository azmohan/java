class Singleton {
    private Singleton() {}

    public static Singleton getInstance() {
        return SingletonHolder.sInstance;
    }

    private static class SingletonHolder {
        private static Singleton sInstance = new Singleton();
    }
}
