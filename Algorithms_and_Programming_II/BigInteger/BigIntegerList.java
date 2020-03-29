/***********************************************\
 * @(#)BigIntegerList.java		       *
 *					       *
 * @author Kerem Ay�z 			       *
 * @version 1.00 2016/11/17		       *
\***********************************************/

import java.util.ArrayList;

public class BigIntegerList {
	ArrayList<BigInteger> numbers = new ArrayList();
	
/******************************************************************************\
 * The constructor takes an ArrayList of Strings that represents BigInteger   *
 *  ,and one by one adds them to the numbers list as BigIntegers. 	      *
 * @param numbers: ArrayList<String> to be added to the ArrayList<BigInteger> *								    *
\******************************************************************************/
    public BigIntegerList(ArrayList<String> n) {
    	for (int i = 0; i < n.size(); i++) {
    		numbers.add(new BigInteger(n.get(i)));
    	}
    }
    
    /**************************************************\
     * Returns the size of the BigInteger ArrayList<> *
     * @return numbers.size(): size of the list	      *
    \**************************************************/
    public int getSize() {
    	return numbers.size();
    }
    
    /*******************************************************\
     * Returns the BigInteger at given index	           *
     * @param index: given index for the BigInteger search *
     * @return numbers.size(): size of the list            *
    \*******************************************************/
    public BigInteger getBigIntegerAt(int index) {
    	return numbers.get(index);
    }
    
    /************************************************************\
     * Method that sets the bigInt to object at the given index *
     * @param index: index for setting 				*
     * @param bigInt: BigInteger object to set		        *
    \************************************************************/
    public void setBigIntegerAt(int index, BigInteger bigInt) {
 		numbers.set(index, bigInt);
    }
    
    /***********************************************************\
     * Method that adds the number to the BigInteger ArrayList *
     * @param number: number to be added		       *
    \***********************************************************/
    public void addBigInteger(String number) {
    	numbers.add(new BigInteger(number));
    }
    
    /**************************************************\
     * Method that removes the element at given index *
     * @param index: index of number to be removed    *
    \**************************************************/
    public void removeBigInteger(int index) {
    	numbers.remove(index);
    }
    
    /*****************************************************************************************\
     * Overloaded version of the removeBigInteger that takes BigInteger object to be removed *
     * @param bigInt								             *
    \*****************************************************************************************/
    public void removeBigInteger(BigInteger bigInt) {
    	for (int i = 0; i < numbers.size(); i++) {
    		if (numbers.get(i).equals(bigInt))
    			numbers.remove(i);
    	}
    }
    
    /*******************************************************************************\
     * Recursive method for finding minimum of the String typed BigInteger objects *
     * @param start: starting index                                                *
     * @param end: end index                                                       *
     * @return BigInteger                                                          *
    \*******************************************************************************/
    public BigInteger min(int start, int end) {
           if (start == end)
               return numbers.get(start);
           else {
               BigInteger bs = min(start+1,end);
               if (numbers.get(start).compareTo(bs) == 1)
                   return bs;
               else
                   return numbers.get(start);
           }   
    }
    
   
    
    
    
    
    
}