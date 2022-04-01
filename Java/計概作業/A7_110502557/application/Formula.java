package A7_110502557.application;

import java.util.LinkedList;

public class Formula extends LinkedList<Operand> {

    @Override
    public void addLast(Operand operand) {
        if (super.isEmpty()) {
            if (operand.getType() != Operand.Type.OPERATOR) {
                if (operand.getType() == Operand.Type.POINT)
                    super.addLast(new Operand(Operand.Type.NUMBER, "0"));
                super.addLast(operand);
            }
            return;
        }

        switch (operand.getType()) {
            case Operand.Type.NUMBER:
                if (super.getLast().getType() == Operand.Type.NUMBER) {
                    super.getLast().setValue(super.getLast().getValue() + operand.getValue());
                    return;
                }
                break;
            case Operand.Type.OPERATOR:
                if (super.getLast().getType() == Operand.Type.NEGTIVE)
                    return;
                if (super.getLast().getType() == Operand.Type.POINT)
                    super.removeLast();
                if (super.getLast().getType() == Operand.Type.OPERATOR)
                    super.removeLast();
                break;
            case Operand.Type.NEGTIVE:
                if (super.getLast().getType() == Operand.Type.NEGTIVE) {
                    super.removeLast();
                    return;
                }
                if (super.getLast().getType() == Operand.Type.POINT)
                    super.removeLast();
                if (super.getLast().getType() == Operand.Type.NUMBER)
                    operand.setType(Operand.Type.OPERATOR);
                break;
            case Operand.Type.POINT:
                if (super.getLast().getType() == Operand.Type.POINT)
                    return;
                if (super.getLast().getType() != Operand.Type.NUMBER)
                    super.addLast(new Operand(Operand.Type.NUMBER, "0"));
                break;
            default: break;
        }
        super.addLast(operand);
    }

    @Override
    public Operand removeLast() {
        if (super.isEmpty())
            return null;
        
        Operand operand = super.getLast();
        if (operand.getType() == Operand.Type.NUMBER) {
            operand.setValue(operand.getValue().substring(0, operand.getValue().length() - 1));
            if (operand.getValue().length() == 0)
                super.removeLast();
        }
        else super.removeLast();

        if (super.isEmpty())
            return null;
        return super.getLast();
    }

    public void count() {
        int priority = 1;
        while (super.size() > 1) {
            for (int i = 0; i < super.size(); ) {
                if (super.get(i).getOperator() / 10 == priority) {
                    switch (super.get(i).getOperator()) {
                        case Operand.Operator.POINT:
                            super.get(i - 1).appendValue(
                                super.get(i).getValue() + super.get(i + 1).getValue()
                            );
                            super.remove(i);
                            super.remove(i);
                            break;
                        case Operand.Operator.NEGTIVE:
                            super.get(i).appendValue(super.get(i + 1).getValue());
                            super.remove(i + 1);
                            break;
                        case Operand.Operator.POWER:
                            super.get(i - 1).setValue(String.valueOf(Math.pow(
                                Double.parseDouble(super.get(i - 1).getValue()),
                                Double.parseDouble(super.get(i + 1).getValue())
                            )));
                            super.remove(i);
                            super.remove(i);
                            break;
                        case Operand.Operator.MULTIPLY:
                            super.get(i - 1).setValue(String.valueOf(
                                Double.parseDouble(super.get(i - 1).getValue()) *
                                Double.parseDouble(super.get(i + 1).getValue())
                            ));
                            super.remove(i);
                            super.remove(i);
                            break;
                        case Operand.Operator.DIVIDE:
                            super.get(i - 1).setValue(String.valueOf(
                                Double.parseDouble(super.get(i - 1).getValue()) /
                                Double.parseDouble(super.get(i + 1).getValue())
                            ));
                            super.remove(i);
                            super.remove(i);
                            break;
                        case Operand.Operator.MOD:
                            super.get(i - 1).setValue(String.valueOf(
                                Double.parseDouble(super.get(i - 1).getValue()) %
                                Double.parseDouble(super.get(i + 1).getValue())
                            ));
                            super.remove(i);
                            super.remove(i);
                            break;
                        case Operand.Operator.PLUS:
                        super.get(i - 1).setValue(String.valueOf(
                                Double.parseDouble(super.get(i - 1).getValue()) +
                                Double.parseDouble(super.get(i + 1).getValue())
                            ));
                            super.remove(i);
                            super.remove(i);
                            break;
                        case Operand.Operator.MINUS:
                            super.get(i - 1).setValue(String.valueOf(
                                Double.parseDouble(super.get(i - 1).getValue()) -
                                Double.parseDouble(super.get(i + 1).getValue())
                            ));
                            super.remove(i);
                            super.remove(i);
                            break;
                        default: break;
                    }
                }
                else i ++;
            }
            priority ++;
        }

        String[] valArr = super.getFirst().getValue().split("\\.");
        String valInt = valArr[0];
        String valDec = valArr[1];
        super.clear();
        super.addLast(new Operand(Operand.Type.NUMBER, valInt));
        if (!valDec.equals("0")) {
            super.addLast(new Operand(Operand.Type.POINT, "."));
            super.addLast(new Operand(Operand.Type.NUMBER, valDec));
        }
    }

    public String toString() {
        String str = new String();
        for (Operand operand : this) {
            str += operand.getValue();
        }
        return str;
    }
}
