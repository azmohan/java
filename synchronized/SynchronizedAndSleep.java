import java.text.SimpleDateFormat;
import java.util.Date;
public class SynchronizedAndSleep {
    private static Object mLock = new Object();
    private static boolean sRunnableOneHandled;

    public static String getTimeStamp() {
        SimpleDateFormat sf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        return sf.format(new Date());
    }

    public static class RunnableOne implements Runnable {
        @Override
        public void run() {
            synchronized(mLock) {
                System.out.println("runnable one current thread = " + Thread.currentThread().getName());
                System.out.println("runnable one current time : " + getTimeStamp());
                try {
                    Thread.sleep(5000);
                    sRunnableOneHandled = true;
                    System.out.println("sleep over!");
                    System.out.println("sleep over current time : " + getTimeStamp());
                    mLock.notifyAll();
                } catch(InterruptedException e) {
                }
            }
        }
    }

    public static class RunnableTwo implements Runnable {
        @Override
        public void run() {
            synchronized(mLock) {
                System.out.println("runnable two current thread = " + Thread.currentThread().getName());
                System.out.println("runnable two current time : " + getTimeStamp());
                try {
                    if (!sRunnableOneHandled) {
                        System.out.println("begin to wait");
                        mLock.wait();
                    }
                    System.out.println("wait over!");
                } catch (InterruptedException e) {
                    System.out.println("wait exception : " + e.toString());
                }
            }
        }
    }

    /*
     * this demo in order to tell us:
     * 1. thread get lock,then sleep,don't release this lock.
     * 2. thread get lock,then wait,will release this lock
     * 3. when one thread get lock, another will block on this lock.
     * 4. thread invoke lock's wait,also block this thread,until another
     * thread invoke lock notify or notifyAll,will wake up blocked thread.
     * */

    public static final void main(String [] args) {
        sRunnableOneHandled = false;
        Thread one = new Thread(new RunnableOne(),"thread1");
        Thread two = new Thread(new RunnableTwo(),"thread2");
        two.start();
        one.start();
    }


}
