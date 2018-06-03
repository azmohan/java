import java.util.Timer;
import java.util.TimerTask;

public class TestTimer {
    public static void main(String []args) {
        Timer timer = new Timer();
        timer.schedule(new MyTask(),1000,2000);
    }
}

class MyTask extends TimerTask {
    public void run() {
        System.out.println("timer is runing");
    }
}
