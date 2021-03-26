import java.util.Scanner;
import java.util.Arrays;

public class input {

    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        String premise;
        Premise[] argument = new Premise[100];
        int line = 0;

        while(sc.hasNextLine()){
            premise = sc.nextLine();
            argument[line] = new Premise(premise, false); 
            line++;
        }
    }

}
