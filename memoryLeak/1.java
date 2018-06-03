import java.util.HashMap;
import java.util.Map;

class MemoryLeak {
    public static void main(String [] args) {
        Map<Key,String> map = new HashMap<Key,String>(1000);
        int counter = 0;
        while(true) {
            map.put(new Key("dummyKey"),"value");
            counter ++;
            if (counter % 1000 == 0) {
                System.out.println("map size : "+map.size());
                System.out.println("Free memory after count " + counter
                        + " is "+ getFreeMemory() + "MB");
                sleep(1000);
            }
        }
    }

    static class Key {
        private String key;

        public Key(String key) {
            this.key = key;
        }
    }

    public static void sleep(long time) {
        try {
            Thread.sleep(time);
        } catch (InterruptedException e) {
            System.out.println("exception : " + e.toString());
        }
    }

    public static long getFreeMemory() {
        return Runtime.getRuntime().freeMemory() / (1024 * 1024);
    }
}
