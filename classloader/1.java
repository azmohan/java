class Test {
    public static final void main(String [] args) {
        URL[] urls = sun.misc.Launcher.getBootstrapClassPath().getURLs();
        for (int i = 0; i < urls.length; i++) {
            System.out.println(urls.toExternalform());
        }
    }
}
