/***********************************************\
 * @(#)BigInteger.java			       *
 *				               *
 * @author Kerem Ay�z 			       *
 * @version 1.00 2016/11/17		       *
\***********************************************/
public class BigInteger implements Comparable {
	private String number;
	private int[] numberArray;
	
    /**************************************************************************************************************\
     * Constructor takes the number as a String and adds each digit character by character into the integer array *
     * @param n: String of the BigInteger number                                                                  *
    \**************************************************************************************************************/
    public BigInteger(String n) {
    	boolean done = false;
    	for (int i = 0;!done;) { 
            if (i != n.length()-1 && n.charAt(i) == '0')
    		i++;
            else {
    		done = true;
    		number = n.substring(i);
            }
    	}	
    	numberArray = new int[number.length()];
    	for (int i = 0; i < number.length(); i++) {
    		numberArray[i] = number.charAt(i);
    	}
    }
    
    /***************************************************\
     * Returns the number of digits in the BigInteger. *
     * @return number.length() : length of the String  *
    \***************************************************/
    public int numberOfDigits() {
    	return number.length();
    }
    
    /*************************************************************************************************\
	 * Returns the most important digit. The most important digit is the left most digit in a number *
	 * @return getDigit(0): first digit 						                                 	 *
	\*************************************************************************************************/
    public int MID() {
    	return getDigit(0);
    }
    
    /****************************************************************************************************\
     * Returns the least important digit. The least important digit is the right most digit in a number *
     * @return getDigit(numberOfDigits()-1): last digit		                                        *
    \****************************************************************************************************/
    public int LID() {
    	return getDigit(numberOfDigits()-1);
    }
    
    /***************************************************************************\
     * Returns the digit at the given index.                                   *
     * @param index: index of the digit is given        		       *
     * @return Character.getNumericValue(number.charAt(index)): digit at index *
    \***************************************************************************/
    public int getDigit(int index) {
    	return Character.getNumericValue(number.charAt(index));
    }
    
    /****************************************************************\
     * Checks the equality of the given object between class object *
     * @param o: Object to be checked whether equal or not          *	
     * @return truth: boolean for the equality	            	    *
    \****************************************************************/
    public boolean equals(Object o) {
    	boolean truth = true;
    	for (int i = 0; i < number.length() && truth; i++) {
    		if (number.charAt(i) != ((String)o).charAt(i))
    			truth = false;
    	}
    	return truth;
    }
    
    /***************************************************************************\
     * Compares two Objects of BigInteger                                      *
     * Firstly it looks the size of the strings                                *
     * If they are equal, index i is increased until the digits become unequal *
     * After that it returns the -1 for smalller, 0 for equality, 1 for bigger *
     * @param o: Object to be checked whether equal or not                     *	
     * @return int                                                             *
    \***************************************************************************/
    public int compareTo(Object o) {
    	int i = 0;
    	if (number.length() > ((BigInteger)o).numberOfDigits())
    		return 1;
    	else if (number.length() < ((BigInteger)o).numberOfDigits()) 
    		return -1;
    	else {
    		while (number.charAt(i) == ((BigInteger)o).getDigit(i))
    				i++;
    		if (Character.getNumericValue(number.charAt(i)) > ((BigInteger)o).getDigit(i))
    			return 1;
    		else if (Character.getNumericValue(number.charAt(i)) < ((BigInteger)o).getDigit(i))
    			return -1;
    		else 
    			return 0; 
    	}
    }
    
    /********************************************\
     * Returns the number format of the String  *	
     * @return String                           *
    \********************************************/
    public String toString() {
        return number;
    }
}