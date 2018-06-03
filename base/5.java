class TestStringBytes {
    private static final String INFO = "学java";


    public static void main(String [] args) {
        byte[] b = INFO.getBytes();
        System.out.println("information bytes:"+b.length);
        for (int i = 0;i < b.length;i++) {
            System.out.println(b[i]);
        }
    }

}
