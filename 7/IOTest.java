import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class IOTest {
    public static void main (String args[]) throws Exception {
        String str = "中国人" ;
        FileOutputStream fos = new FileOutputStream("1.txt") ;
        fos.write(str.getBytes("UTF-8"));
        fos.close();

        FileWriter fw = new FileWriter("2.txt") ;
        fw.write(str);
        fw.close();

        PrintWriter pw = new PrintWriter("3.txt","utf-8") ;
        pw.write(str) ;
        pw.close();

        FileReader fr = new FileReader("1.txt");
        char[] buf = new char[1024];
        int len = fr.read(buf);
        String myStr = new String(buf,0,len);
        System.out.println(myStr);

        FileInputStream mfr = new FileInputStream("1.txt");
        byte[] array = new byte[1024];
        int size = mfr.read(array);
        String aStr = new String(array,0,size,"utf-8");
        System.out.println("array content:"+aStr);

        BufferedReader br = new BufferedReader(new InputStreamReader(
                    new FileInputStream("1.txt")));
        String bStr = br.readLine();
        br.close();
        System.out.println("buffer reader:"+bStr);

    }
}
