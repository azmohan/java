class Outter extends Inner {
    public Outter(String str) {
        System.out.println("Outter class invoke one String param construct");
    }

    public static void main(String [] args) {
        Outter out = new Outter("azmohan");
    }
}
