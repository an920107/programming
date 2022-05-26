package main;

import java.io.InputStream;
import java.io.OutputStream;
import java.net.URL;
import java.net.URLConnection;
import java.nio.file.Files;
import java.nio.file.Paths;

public class DownloadFile implements AutoCloseable {

    private String url;
    private String filename;

    public DownloadFile(String url, String filename) {
        this.url = url;
        this.filename = filename;
    }

    public void start() throws Exception {
        URLConnection connection = new URL(url).openConnection();
        
        try (InputStream is = connection.getInputStream();
                OutputStream os = Files.newOutputStream(Paths.get(filename))) {
            
            byte[] buf = new byte[8192];
            int n;
            while ((n = is.read(buf)) > 0) {
                os.write(buf, 0, n);
            }
        }
    }

    @Override
    public void close() throws Exception {
        
    }
}