import java.util.Date;

public class Test extends Date {
    public void test() {
        System.out.println(super.getClass().getName());
    }

    public void testSuper() {
        System.out.println(super.getSuperClass().getName());
    }

    public static void main (String args[]) {
        new Test().test();
        Test t = new Test();
        t.testSuper();

        System.out.println("String equals:"+new String("abc").equals(new String("abc")));
        System.out.println("StringBuffer equals:"+new StringBuffer("abc").equals(new StringBuffer("abc")));

        /*
        long begin = System.currentTimeMillis();
        StringBuffer sb = new StringBuffer();
        for(int i=0;i<1000000;i++){
            sb.append(i);
        }
        System.out.println("sb space time:"+(System.currentTimeMillis()-begin));

        long sBegin = System.currentTimeMillis();
        String s = new String();
        for(int i=0;i<1000000;i++) {
            s = s + i;
        }
        System.out.println("s space time:"+(System.currentTimeMillis()-sBegin));
        */

        String likeType = "23";
        String pattern = "[a-zA-Z0-9]*[" + likeType + "]{1}[a-zA-Z0-9]*";
        String sourceStr = "adfjaslfj23ldfalst";
        System.out.println(sourceStr.matches(likeType));

        String like = "%%%23%%%*";
        String source = "423236664";
        like = like.replaceAll("%","\\\\d").replaceAll("\\*","\\\\d\\*");
        System.out.println(like);
        System.out.println(source.matches(like));

    }
}
