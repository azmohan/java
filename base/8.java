import java.io.BufferedReader;
import java.io.IOException;
import java.net.Socket;
import java.io.InputStreamReader;
class TestSocket {
    public void printSocket() {
        Socket socket = null;
        try {
            socket = new Socket("127.0.0.1",8888);
            BufferedReader pw = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            System.out.println(pw.readLine());
            pw.close();
        } catch(Exception e) {
            e.printStackTrace();
        } finally {
            try {
                socket.close();
            } catch(IOException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String []args) {
        TestSocket ts = new TestSocket();
        ts.printSocket();
    }
}
