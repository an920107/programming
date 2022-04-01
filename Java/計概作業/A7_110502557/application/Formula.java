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
        int priority = 0;
        while (super.size() > 1) {
            for (Operand operand : this) {
                if (operand.getPriority() == priority) {
                    
                }
            }
            priority ++;
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
