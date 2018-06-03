import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class ExecutorServiceTest {
    public static void main(String args[]) {
        String s = "abcdefghi0123456789";
        String sub = s.substring(0,4);
        String sub1 = s.substring(4,9);
        System.out.println(sub);
        System.out.println(sub1);
        ExecutorService service = Executors.newCachedThreadPool();
        List<Future<String>> result = new ArrayList<Future<String>>();

        for(int i = 0;i < 10;i++) {
            Future<String> future = service.submit(new TaskWithResult(i));
            result.add(future);
        }
        service.shutdown();

        for(Future<String> fs : result) {
            try {
                System.out.println(fs.get());
            } catch(InterruptedException e) {
                e.printStackTrace();
            } catch(ExecutionException e) {
                service.shutdownNow();
                e.printStackTrace();
                return;
            }
        }
    }
}

    class TaskWithResult implements Callable<String> {
        private int id;
        public TaskWithResult(int id) {
            this.id = id;
        }

        public String call() throws Exception {
            System.out.println("call method invodeed:" + Thread.currentThread().getName());

            if(new Random().nextBoolean()) {
                throw new TaskException("meet error in task:" + Thread.currentThread().getName());
            }
            for(int i = 9999999;i>0;i--) {
            }
            return "call method invodeed,id:" + id + ",threadname:" + Thread.currentThread().getName();
        }
    }

    class TaskException extends Exception {
        public TaskException(String msg) {
            super(msg);
        }
    }
