import java.io.ByteArrayOutputStream;
import java.io.InputStream;
import java.io.IOException;
import java.io.File;
import java.io.FileInputStream;


public class PathClassLoader extends ClassLoader {
    private String pathUrl;

    public PathClassLoader(String path) {
        super(null);
        pathUrl = path;
        System.out.println("pathUrl = " + pathUrl);
    }

    @Override
    protected Class<?> findClass(String name) throws ClassNotFoundException {
        Class clazz = null;
        byte[] classData = getClassData(name);
        if (classData == null) {
            throw new ClassNotFoundException();
        }
        clazz = defineClass(name,classData,0,classData.length);
        System.out.println("findClass class = " + clazz.toString());
        return clazz;
    }

    private byte[] getClassData(String name) {
        String classPath = classNameToPath(name);
        File file = new File(classPath);
        byte[] buff = new byte[1024*4];
        int len = -1;
        InputStream is = null;
        System.out.println("getClasData classPath:" + classPath);
        try {
            is = new FileInputStream(file);
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            while ((len = is.read(buff)) != -1) {
                baos.write(buff,0,len);
            }
            return baos.toByteArray();
        } catch (Exception e) {
            System.out.println("Exception e : " + e.toString());
        } finally {
            if (is != null) {
                try {
                    is.close();
                } catch (IOException e) {
                    System.out.println("Exception e : " + e.toString());
                }
            }
        }
        return null;
    }

    private String classNameToPath(String name) {
        return pathUrl + "/" + name.replace(".","/") + ".class";
    }
}
