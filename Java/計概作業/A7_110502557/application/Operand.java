package A7_110502557.application;

public class Operand {

    public static class Type {
        final public static int NUMBER = 0;
        final public static int OPERATOR = 1;
        final public static int NEGTIVE = 2;
        final public static int POINT = 3;
    }

    public static class Operator {
        final public static int POWER = 0;
        final public static int MULTIPLY = 1;
        final public static int DIVIDE = 2;
        final public static int MOD = 3;
        final public static int PLUS = 4;
        final public static int MINUS = 5;
    }

    private int type;
    private String value;
    private boolean negtive;
    private int priority;
    private int operator;

    public Operand(int type, String value) {
        this.type = type;
        this.value = value;
        negtive = false;

        // priority: point -> negtive -> power -> multiply/divide/mod -> plus/minus
        if (type == Type.POINT) priority = 0;
        else if (type == Type.NEGTIVE) priority = 1;
        else if (type == Type.OPERATOR) {
            if (value.equals("^")) {
                priority = 2;
                operator = Operator.POWER;
            }
            else if (value.equals("×")) {
                priority = 3;
                operator = Operator.MULTIPLY;
            }
            else if (value.equals("÷")) {
                priority = 3;
                operator = Operator.DIVIDE;
            }
            else if (value.equals("%")) {
                priority = 3;
                operator = Operator.MOD;
            }
            else if (value.equals("+")) {
                priority = 4;
                operator = Operator.PLUS;
            }
            else if (value.equals("-")) {
                priority = 4;
                operator = Operator.MINUS;
            }
        }
        else {
            priority = -1;
            operator = -1;
        }
    }

    public void setType(int type) { this.type = type; }
    public void setValue(String value) { this.value = value; }

    public int getType() { return type; }
    public String getValue() { return value; }
    public boolean isNegtive() { return negtive; }
    public int getPriority() { return priority; }
    public int getOperator() {return operator; }
}
