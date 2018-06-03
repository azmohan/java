import java.io.IOException;
class ExceptionTest {
    public static void main (String args[]) {
        try {
            methodA();
        } catch (IOException e) {
            System.out.println("caught Exception");
        } catch (Exception e) {
            System.out.println("caught IOException");
        }
    }

    private static void methodA () throws IOException,Exception {
        /*
        if(true)
            throw new IOException("IOException");
            */
        throw new IOException();
//        throw new Exception();
    }
}
