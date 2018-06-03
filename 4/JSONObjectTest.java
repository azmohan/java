import org.json.JSONException;
import org.json.JSONObject;
import org.json.JSONStringer;
import org.junit.Test;

public class JSONObject {

    public static void test() {
        System.out.println(prepareJSONObject());
        System.out.println(prepareJSONObject2());
    }

    private static String prepareJSONObject() {
        JSONObject stu = new JSONObject();
        try {
            stu.put("name","azmohan");
            stu.put("id",20141124);
            stu.put("phone","18101623105");
        } catch (JSONException e) {
            e.printStackTrace();
        }

        return stu.toString();
    }

    private static String prepareJSONObject2() {
        JSONStringer jsonStringer = new JSONStringer();
        try {
            jsonStringer.object();
            jsonStringer.key("name");
            jsonStringer.value("azmohan");
            jsonStringer.key("id");
            jsonStringer.value(20141124);
            jsonStringer.key("phone");
            jsonStringer.value("18101623105");
            jsonStringer.endObject();
        } catch (JSONException e) {
            e.printStackTrace();
        }

        return jsonStringer.toString();
    }

    public static final void main(String args[]) {
        JSONObject.test();
    }
}
