import java.math.BigInteger;
import java.util.Scanner;
import java.lang.Math;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            int t = scanner.nextInt();
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            System.out.printf("(%d^%d-1)/(%d^%d-1) ", t, a, t, b);

            if (t == 1 || a % b != 0 || (a - b) * Math.log10(t) > 99) {
                System.out.println("is not an integer with less than 100 digits.");
                continue;
            }
            if (a == b) {
                System.out.println("1");
                continue;
            }
            BigInteger tPowA_1 = BigInteger.valueOf(t).pow(a).subtract(BigInteger.ONE);
            BigInteger tPowB_1 = BigInteger.valueOf(t).pow(b).subtract(BigInteger.ONE);
            if (tPowB_1.equals(BigInteger.ZERO)) {
                System.out.println("is not an integer with less than 100 digits.");
                continue;
            }
            BigInteger result = tPowA_1.divide(tPowB_1);
            System.out.println(result.toString());
        }
        scanner.close();
    }
}