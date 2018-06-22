import java.io.File;
import java.io.InputStream;
import java.io.FileInputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileOutputStream;
import java.nio.channels.FileChannel;

class Test {
    public static void copyFileByStream(File dest,File source) throws IOException {
        try (InputStream inputStream = new FileInputStream(source);
                OutputStream outputStream = new FileOutputStream(dest);) {
            byte[] buffer = new byte[1024];
            int length;
            while ((length = inputStream.read(buffer)) > 0) {
                outputStream.write(buffer,0,length);
            }
                }
    }

    public static void copyFileByChannel(File dest,File source) throws IOException {
        try (FileChannel sourceChannel = new FileInputStream(source).getChannel();
                FileChannel targetChannel = new FileOutputStream(dest).getChannel();) {
            for (long count = sourceChannel.size();count > 0;) {
                long transferred = sourceChannel.transferTo(sourceChannel.position(),count,targetChannel);
                count -= transferred;
            }
                }
    }
}
