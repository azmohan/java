import java.sql.Timestamp;
import java.util.Date;
public class Test{

    public static final void main(String []args){
        Timestamp stamp = new Timestamp(new Date().getTime());
        System.out.println("stamp:"+stamp.toString());
    }
}
