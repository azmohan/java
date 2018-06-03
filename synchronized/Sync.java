class SyncThread implements Runnable {
    private int count;

    public SyncThread() {
        count = 0;
    }

    public void run() {
        // a thread access synchronized codes block,other threads access this
        // will be blocked.
        // thread is primitive unit,cpu run codes. cpu core only run thread.
        // thread concurrent techlogicy
        synchronized(this) {
            for(int i = 0;i < 5;i++) {
                try {
                    System.out.println(Thread.currentThread().getName()+
                            " : "+ (count++));
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public int getCount() {
        return count;
    }

    public static void main(String [] args) {
        SyncThread syncThread = new SyncThread();
        Thread thread1 = new Thread(syncThread,"SyncThread1");
        Thread thread2 = new Thread(syncThread,"SyncThread2");
        thread1.start();
        thread2.start();
/* Vanzo:azmohan on: Wed, 15 Feb 2017 16:06:30 +0800
 * modify settings fun
        Thread thread3 = new Thread(new SyncThread(),"SyncThread3");
        Thread thread4 = new Thread(new SyncThread(),"SynchThread4");
        thread3.start();
        thread4.start();
 */
// End of Vanzo: azmohan
    }
}
