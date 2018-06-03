class Counter implements Runnable {
    private int count;

    public Counter() {
        count = 0;
    }

    public void countAdd() {
        synchronized(this) {
            for(int i = 0;i < 5;i++)
        }
    }
}
