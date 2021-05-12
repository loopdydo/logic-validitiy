import java.util.Scanner;

public class Premise {
    public String premise;
    public enum Connective {
        CONJUCT,
        DISJUNCT,        
        CONDITIONAL,
        BICONDITIONAL
    } 
    Connective connective;
    public Premise RHS;
    public Premise LHS; 
    public Boolean isConclusion;  
    
    public Premise (String premise, Boolean isConclusion) {
        this.premise = premise;
        this.isConclusion = isConclusion;

        Scanner sc = new Scanner(premise);
        int openBracket = 0;
        int pos = 0;

        while (sc.next().equals("(")) {
            openBracket++;
            pos++;
        }

        while (sc.hasNext() && openBracket > 0) {
            if (sc.next().equals(")")) {
                openBracket--;
            } 
            pos++;
        }

        if (sc.hasNext()) {
            switch (sc.next()) {
                case "^":
                    this.connective = Connective.CONJUCT;
                    pos++;
                    break;
                case "v":
                    this.connective = Connective.DISJUNCT;
                    pos++;
                    break;
                case "->":
                    this.connective = Connective.CONDITIONAL;
                    pos++;
                    break;
                case "<->":
                    this.connective = Connective.BICONDITIONAL;
                    pos++;
                    break;
                default:
                    this.connective = null;
            } 
        } else {
            this.connective = null;
        }
        
        System.out.println(connective);

        if (this.connective != null) {
            if (premise.charAt(0) == '(') {
                LHS = new Premise(premise.substring(1, pos - 1), this.isConclusion);
            } else {
                LHS = new Premise(premise.substring(0, pos), this.isConclusion);
            }
            if (premise.charAt(premise.length()-1) == ')') {
                RHS = new Premise(premise.substring(pos + 2, premise.length()-1), this.isConclusion);
            } else {
                RHS = new Premise(premise.substring(pos + 1), this.isConclusion);
            }
        }
    }
}
