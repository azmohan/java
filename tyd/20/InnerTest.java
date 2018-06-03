public class InnerTest {
    public static void main(String args[]) {
        EnclosingOne eo = new EnclosingOne();
        InsideOne ei0 = eo.new InsideOne();
        eo.InsideOne ei1 = eo.new InsideOne();
        InsideOne ei2 = EnclosingOne.new InsideOne();
        InsideOne ei3 = eo.new InsideOne();

        EnclosingOne.InsideOne ei4 = eo.new InsideOne();
    }
}
