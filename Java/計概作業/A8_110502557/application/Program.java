package A8_110502557.application;

final public class Program {

    final public class Information {
        final public static String FILENAME = "110502557.txt";
    }

    final public class Status {
        final public static String CLEARED = "已清空";
        final public static String ENCODED = "已編碼";
        final public static String COPY_FAILED = "複製失敗";
        final public static String COPIED = "已複製";
        final public static String CREATE_FAILED = "新建失敗";
        final public static String CREATED = "已新建";
        final public static String SAVE_FAILED = "存檔失敗";
        final public static String SAVED = "已存檔";
    }

    public static String encode(String text) {
        final int LENGTH = text.length();
        String code = new String();
        for (int i = 0; i < LENGTH; i ++) {
            code += String.valueOf((int)text.charAt(i));
        }
        return code;
    }
}
