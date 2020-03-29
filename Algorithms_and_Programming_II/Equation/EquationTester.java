/*************************************************************************************************
 * @(#)EquationTester.java
 *
 * @author Kerem Ayöz
 *
 * EquationTester class
 *
 * To use methods of Equation class
 *
 * Remarks:
 * Works with integer numbers
 * add() substract() methods tested in program
 *
 * @version 1.00 2016/10/5
 *************************************************************************************************/
import java.util.Scanner;

public class EquationTester {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.print("Enter the value of a, b and c for first equation: ");
        int a1 = in.nextInt();
        int b1 = in.nextInt();
        int c1 = in.nextInt();
        Equation eq1 = new Equation(a1, b1, c1);

        System.out.print("Enter the value of a, b and c for second equation: ");
        int a2 = in.nextInt();
        int b2 = in.nextInt();
        int c2 = in.nextInt();
        Equation eq2 = new Equation(a2, b2, c2);

        System.out.println("Sum of the equations: " + eq1.add(eq2));

        System.out.print("Enter the value of a, b and c for first equation: ");
        int a3 = in.nextInt();
        int b3 = in.nextInt();
        int c3 = in.nextInt();
        Equation eq3 = new Equation(a3, b3, c3);

        System.out.print("Enter the value of a, b and c for second equation: ");
        int a4 = in.nextInt();
        int b4 = in.nextInt();
        int c4 = in.nextInt();
        Equation eq4 = new Equation(a4, b4, c4);

        System.out.print("Substraction of the equations: " + eq3.substract(eq4));
    }
}
