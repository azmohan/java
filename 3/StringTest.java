public class StringTest {
    static int test() {
        int x = 1;
        try {
            return x;
        } finally {
            ++x;
        }
    }

    int test1() {
        int x = 1;
        try {
            return x;
        } finally {
            x++;
            System.out.println("test1 finally x="+x);
        }
    }

    int test2() {
        try {
            return 1;
        } finally {
            return 2;
        }
    }

    void test3(int a) {
        try {
            if(a == 1) {
                throw new Exception();
            }
        } catch(Exception e) {
                System.out.println(e);
        } finally {
                System.out.println("excute finally");
        }

    }

    public static final void main(String args[]) {
        String s1 = "a";
        String s2 = s1 + "b";
        // compile precompile s3 = "ab"
/* Vanzo:azmohan on: Fri, 02 Jun 2017 11:24:58 +0800
 * modify settings fun
        String s3 = "a" + "b";
        System.out.println(s2 == "ab");
        System.out.println(s3 == "ab");

        System.out.println(new StringTest().test1());
        System.out.println(StringTest.test());
        System.out.println(new StringTest().test2());
 */

// End of Vanzo: azmohan
/* Vanzo:azmohan on: Wed, 25 Feb 2015 15:03:26 +0800
 * modify settings fun
 */
        int a = 0;
        System.out.println("args length:"+args.length);
        if(args.length >= 1) {
            a = Integer.parseInt(args[0]);
        }
        new StringTest().test3(a);
// End of Vanzo: azmohan
    }
}
