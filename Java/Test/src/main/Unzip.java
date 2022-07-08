package main;

import java.io.FileInputStream;
import java.io.IOException;
import java.net.URISyntaxException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

public class Unzip {
    public static void main(String[] args) throws IOException, URISyntaxException {

        Path source = Paths.get(Main.class.getResource("/resources/Python39.zip").toURI());
        Path target = Paths.get(System.getenv("APPDATA") + "\\Python");
        
        if (Files.notExists(target)) {
            Files.createDirectories(target);
            unzip(source, target);
        }
        else System.out.println("FILE EXISTS.");

    }

    public static void unzip(Path source, Path target) {

        try (ZipInputStream zipFile = new ZipInputStream(new FileInputStream(source.toFile()))) {

            ZipEntry zipEntry = zipFile.getNextEntry();
            while (zipEntry != null) {
                boolean isDirectory = zipEntry.toString().endsWith("/");
                Path newPath = Paths.get(target.toString(), zipEntry.toString());
                if (isDirectory)
                    Files.createDirectories(newPath);
                else {
                    if (newPath.getParent() != null)
                        if (Files.notExists(newPath.getParent()))
                            Files.createDirectories(newPath.getParent());
                    Files.copy(zipFile, newPath, StandardCopyOption.REPLACE_EXISTING);
                }
                zipEntry = zipFile.getNextEntry();
            }
            zipFile.closeEntry();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
