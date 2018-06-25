class Test {
    public static final void main(String [] args) {
        Runnable task = () -> {System.out.println("Hello World");};
        Thread thread = new Thread(task);
        thread.start();
        try {
            thread.join();
        } catch (InterruptedException e) {
            System.out.println("Exception e : " + e.toString());
        }
    }
}
