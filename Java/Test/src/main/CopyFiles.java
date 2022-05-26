package main;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;

public class CopyFiles {
    public static void main(String[] args) throws IOException {
        
        String source = Main.class.getResource("/python.zip").toExternalForm().substring(6);
        String target = System.getenv("APPDATA") + "\\Python";

        if (!Files.exists(Paths.get(target))) {
            System.out.println("START COPY.");
            Files.walk(Paths.get(source)).forEach(toCopy -> {
                Path destination = Paths.get(target, toCopy.toString().substring(source.length()));
                try {
                    Files.copy(toCopy, destination, StandardCopyOption.REPLACE_EXISTING);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            });
            System.out.println("DONE.");
        }
        else System.out.println("FILE EXISTS.");
    }
}
