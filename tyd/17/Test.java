public class Test {
    public static void stringReplace(String text) {
        text = text.replace("j","i");
        System.out.println(text);
    }

    public static void bufferReplace(StringBuffer text) {
        //text = text.replace("j","i");
        text = text.append("c");
    }

    public static void main(String args[]) {
        String txtStr = new String("java");
        StringBuffer txtBuffer = new StringBuffer("java");
        stringReplace(txtStr);
        bufferReplace(txtBuffer);
        System.out.println(txtStr + txtBuffer);
    }
}
