class Test {
    public static final void main(String [] args) {
        Thread thread = new Thread() {
            @Override
            public void run() {

            }
        };

        thread.start();
        thread.start();
    }
}
