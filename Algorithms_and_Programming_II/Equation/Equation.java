/*************************************************************************************************
 * @(#)Equation.java
 *
 * @author Kerem Ayöz
 *
 * Equation class
 *
 * Basic class for mathematical equations like a = bx + c
 *
 * Remarks:
 * Works with integer numbers
 * Just have 3 terms
 *
 * @version 1.00 2016/10/5
 *************************************************************************************************/


public class Equation {
//Defining coefficients of equations
	private int a;
	private int b;
	private int c;
//Equation()
    public Equation(int a, int b, int c) {
    	if (b < 0) {
    		b = -b;
    		c = -c;
    		a = -a;
    	}
    	this.a = a;
    	this.b = b;
    	this.c = c;
    }

//gcd() method that finds greatest common divisor of two numbers
    public static int gcd(int k, int l) {
    	while (k !=0 && l !=0) {
    		//Making negative numbers positive because it does not change the result
    		if (l < 0)
    			l *= -1;

    		if (k < 0)
    			k *= -1;
			//After every operation we supposed to have the least element and the remainder as new elements
    			//So we change the greatest one with the remainder and take the least one directly
    		if (k >= l) {
	    		k = k % l;
    		}
    		else if (l > k) {
    			l = l % k;
    		}
    	}
    	return Math.max(k,l);
    }

//gcd3() method that calculates greatest common divosor of 3 numbers and uses gcd method.
    public static int gcd3(int k, int l, int m) {
    	return gcd(gcd(k,l),m);
    }

//reduceEquation() method divides every coefficient with gcd of them
    public void reduceEquation() {
    		int cd = gcd3(a,b,c);
    		a /= cd;
    		b /= cd;
    		c /= cd;
    }


    public Equation add(Equation eq2) {
    	a += eq2.a;
    	b += eq2.b;
    	c += eq2.c;
    	Equation eq3 = new Equation(a,b,c);
    	eq3.reduceEquation();
    	return eq3;
    }
//subtract() function substracts two equation and also reduces the result
    public Equation substract(Equation eq2) {
    	a -= eq2.a;
    	b -= eq2.b;
    	c -= eq2.c;
		Equation eq3 = new Equation(a,b,c);
		eq3.reduceEquation();
    	return eq3;
    }

//toString method shows the equation a = bx + c
    public String toString() {
    	if (b == 0)
    		return a + " = " + c;
    	else if (c == 0)
    		return a + " = " + b + "x";
    	else
    		return a + " = " + b + "x + " + c;
    }
}