import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;

public class TestExecutor {
    private static void run (ExecutorService pool) {
        for(int i = 1;i < 5;i++) {
            final int taskId = i;
            pool.execute(new Runnable() {
                public void run () {
                    for (int j = 1;j < 5;j++) {
                        try {
                            Thread.sleep(20);
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                        System.out.println("taskId:"+taskId+",j:"+j);
                    }
                }
            });
        }
        pool.shutdown();
    }

    public static final void main(String args[]) {
        ExecutorService fixedPool = Executors.newFixedThreadPool(3);
        ExecutorService cachedPool = Executors.newCachedThreadPool();
        ExecutorService singlePool = Executors.newSingleThreadExecutor();
        ScheduledExecutorService scheduledPool = Executors.newScheduledThreadPool(3);
        run(fixedPool);
        run(cachedPool);
        run(singlePool);
    }
}
