import java.io.*;
class B extends A {
    public B() {
        System.out.println("B");
    }
    public int count(char c,int i,double d) {
        return c*(int)d;
    }
    /*
    public static void main (String[] args) {
        B b = new B();
        try {
            DataInputStream din = new DataInputStream(new BufferedInputStream(
                    new FileInputStream("employee.dat")));
            System.out.println(din);

        } catch(Exception e) {

        }
        Integer a = new Integer(3);
        Integer c = new Integer(3);
        System.out.println(a == c);
    }
    */
    public static void main (String args[]) throws Exception {
        String s = "Jessica";
        char c = s.charAt(6);
        System.out.println(c);
        System.out.println(Math.random());
        char d = new Character('a');
        char f = 97;
        char g = 'a';
        System.out.println(d);
        for(int i = 0;i < args.length;i++){
            System.out.println("main args,i:"+i+",args:"+args[i]);
        }
        /*
        File f = new File("/","autoexec.bat");
        DataInputStream din = new DataInputStream(new FileInputStream("employee"));
        InputStreamReader in = new InputStreamReader(System.in);
        OutputStreamWriter out = new OutputStreamWriter(System.out);
        */
        int a = 0;
        try {
            System.out.println("throw before");
            if(a == 1) {
                throw new IOException();
            }
            System.out.println("throw after");
        } catch(IOException e) {
            System.out.println("IOException");
            return;
        } catch(Exception ioe) {
            System.out.println("Exception");
        } finally {
            System.out.println("final");
        }
        System.out.println("nothing");
        short s1 = 1;
        s1 = (short)(s1 + 1);
        s1 += 1;
        s1 = s1 + (short) 1;
    }
}
