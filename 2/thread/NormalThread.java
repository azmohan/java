class NormalThread extends Thread {
    public NormalThread(String name) {
        super(name);
    }

    public NormalThread(Runnable runnable) {
        super(runnable);
    }
    public void run() {
        super.run();
        for(int i = 0;i < 5;i++) {
            System.out.println(Thread.currentThread().getName() + "运行  " + i);
        }
    }

    public static class TestRunnable implements Runnable {
        public void run() {
            for(int i = 0; i < 5;i++) {
                System.out.println("ThreadName:"+Thread.currentThread().getName());
            }
        }
    }

    public static void main(String[] args) {
        NormalThread thread1 = new NormalThread("Thread1");
        NormalThread thread2 = new NormalThread(new TestRunnable());
//        Thread thread = new Thread(new TestRunnable());
/* Vanzo:azmohan on: Sat, 07 Nov 2015 20:12:07 +0800
 * modify settings fun
        thread1.run();
        thread2.run();
 */
// End of Vanzo: azmohan
        thread1.start();
        thread2.start();
    }
}

