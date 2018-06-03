public class Outer {
    public class Inner {

    }

    public void doSomething() {
        final int a = 10;
        class InnerMethod {
            public void setOuter() {
                System.out.println(a);
            }
        }

        InnerMethod im = new InnerMethod();
        im.setOuter();
    }

    public class Car {
        public void drive() {
            System.out.println("drive a car");
        }
    }

    public static final void appendStringBuffer(StringBuffer sb) {
        sb.append(" Ok");
    }

    public static final void appendString(String s){
        //s.append(" Ok");
    }

    public static void main(String args[]) {
        Outer o = new Outer();
        o.doSomething();
        String s = "Hello";
        Object old = s;
        System.out.println(old);
        s = s + " World";
        Object now = s;
        System.out.println(now);
        System.out.println(s);

/* Vanzo:azmohan on: Wed, 25 Feb 2015 18:20:43 +0800
 * modify settings fun
        String str = "azmohan,jessica,lily,keke";
        String [] array = str.split(",");
        System.out.println(str.length());
        for(int i = 0;i < array.length;i++) {
            System.out.println("index = "+i+",result = " +array[i]);
        }

ok:
        for(int i=0;i<10;i++) {
            for(int j=0;j<10;j++) {
                System.out.println("i="+i+",j="+j);
                if(j==2) {
                    break ok;
                }
            }
        }
 */
// End of Vanzo: azmohan


/* Vanzo:azmohan on: Wed, 25 Feb 2015 18:46:14 +0800
 * modify settings fun
        try {
            for(int i=0;i<10;i++) {
                for(int j=0;j<5;j++) {
                    System.out.println("try i="+i+";j="+j);
                    if(j == 3) {
                        throw new Exception();
                    }
                }
            }
        } catch(Exception e) {
            System.out.println(e);
        }
 */
// End of Vanzo: azmohan


/* Vanzo:azmohan on: Wed, 25 Feb 2015 18:46:34 +0800
 * modify settings fun
        int arr[][] = {{1,2,3},{4,5,6},{8,9}};

        boolean found = false;
        for(int i=0;i<arr.length && !found;i++) {
            for(int j=0;j<arr[i].length;j++) {
                System.out.println("i="+i+",j="+j);
                if(arr[i][j] == 5) {
                    found = true;
                    break;
                }
            }
        }
 */
// End of Vanzo: azmohan

        int a = Integer.MAX_VALUE;
        int b = Integer.MAX_VALUE;
        int sum = a + b;
        System.out.println("a="+a+",b="+b+",sum="+sum);


        final StringBuffer sb= new StringBuffer("immutable");
        //sb = new StringBuffer("");
        sb.append(" broken!");
        System.out.println(sb);

        Outer.appendStringBuffer(sb);
        System.out.println("appendStringBuffer sb="+sb);

        Outer.appendString((String) sb.toString());
        System.out.println("appendString sb="+sb);
    }
}
