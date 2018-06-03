interface A {int x = 0;}
class B {int x = 1;}
class C extends B implements A {
    public void pX() {
        System.out.println(super.x);
//        System.out.println(x);
    }

/* Vanzo:azmohan on: Sun, 07 May 2017 14:54:01 +0800
 * modify settings fun
    int b(final int i) {
        return i++;
    }
 */
// End of Vanzo: azmohan

    int c(Integer i) {
        return ++i;
    }

    public static void main(String[] args) {
        new C().pX();
 //       new C().b(3);
    }
}
