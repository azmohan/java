public class MultiThread {
    public static final void main(String args[]) {
        new Thread(new Thread1()).start();
        try {
            Thread.sleep(10);
        } catch(InterruptedException e) {
            e.printStackTrace();
        }

        new Thread(new Thread2()).start();
    }

    private static class Thread1 implements Runnable {
        public void run() {
            synchronized(MultiThread.class) {
                System.out.println("enter thread 1 ...");
                System.out.println("thread 1 is waiting");
/* Vanzo:azmohan on: Wed, 25 Feb 2015 15:35:10 +0800
 * modify settings fun
 */
                try {
                    MultiThread.class.wait();
                } catch(InterruptedException e) {
                    e.printStackTrace();
                }
// End of Vanzo: azmohan
            }
            System.out.println("thread 1 is going on ...");
            System.out.println("thread 1 is being over!");
        }
    }

    private static class Thread2 implements Runnable {
        public void run() {
            synchronized(MultiThread.class) {
                System.out.println("enter thread 2 ...");
                System.out.println("thread 2 notify other thread can release wait status ...");
                MultiThread.class.notify();
                System.out.println("thread 2 is sleeping 50 ms");
                try {
                    Thread.sleep(500);
                } catch(InterruptedException e) {
                    e.printStackTrace();
                }

                System.out.println("thread 2 is going on ...");
                System.out.println("thread 2 is being over!");
            }
        }
    }
}
