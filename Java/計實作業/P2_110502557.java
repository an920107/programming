/**
 * Practice 02
 * Student Number: 110502557
 * Course: 2022-CE1004-A
 */

public class P2_110502557 {
    public static void main(String[] args) throws Exception {
        final boolean isWindows = System.getProperty("os.name").toLowerCase().indexOf("win") >= 0;
        final String command = (isWindows ? "copy" : "cp") + " test.txt 110502557.txt";
        Process process = Runtime.getRuntime().exec(command);
        process.waitFor();
    }
}
