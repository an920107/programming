package A7_110502557.application;

public class Operand {

    public static class Type {
        final public static int NUMBER = 0;
        final public static int OPERATOR = 1;
        final public static int NEGTIVE = 2;
        final public static int POINT = 3;
    }

    public static class Operator {
        // priority: point -> negtive -> power -> multiply/divide/mod -> plus/minus
        final public static int POINT = 10;
        final public static int NEGTIVE = 20;
        final public static int POWER = 30;
        final public static int MULTIPLY = 40;
        final public static int DIVIDE = 41;
        final public static int MOD = 42;
        final public static int PLUS = 50;
        final public static int MINUS = 51;
    }

    private int type;
    private String value;
    private int operator;

    public Operand(int type, String value) {
        this.type = type;
        this.value = value;

        if (type == Type.POINT) operator = Operator.POINT;
        else if (type == Type.NEGTIVE) operator = Operator.NEGTIVE;
        else if (type == Type.OPERATOR) {
            if (value.equals("^")) operator = Operator.POWER;
            else if (value.equals("×")) operator = Operator.MULTIPLY;
            else if (value.equals("÷")) operator = Operator.DIVIDE;
            else if (value.equals("%")) operator = Operator.MOD;
            else if (value.equals("+")) operator = Operator.PLUS;
            else if (value.equals("-")) operator = Operator.MINUS;
        }
        else operator = 0;
    }

    public void setType(int type) { this.type = type; }
    public void setValue(String value) { this.value = value; }

    public int getType() { return type; }
    public String getValue() { return value; }
    public int getOperator() {return operator; }

    public void appendValue(String append) {
        this.value += append;
    }
}
