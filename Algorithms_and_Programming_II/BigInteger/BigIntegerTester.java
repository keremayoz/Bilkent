/***********************************************\
 * @(#)BigIntegerTester.java		       *
 *					       *
 * @author Kerem Ay�z 			       *
 * @version 1.00 2016/11/21		       *
\***********************************************/

import java.util.ArrayList;
import java.util.Scanner;
import java.io.*;

public class BigIntegerTester {
   
   /*******************************************************************************\
    * Method that reads BigInteger files and fills the empty ArrayList of Strings *
    * @param fileName: starting index                                             *  
    * @return ArrayList<String>                                                   *
   \*******************************************************************************/
   public static ArrayList<String> readBigIntegerFile(String fileName) throws FileNotFoundException {
       Scanner reader = new Scanner(new File(fileName));
    	String bi;
    	ArrayList<String> bigList = new ArrayList();
    	while (reader.hasNext()) {
    		bi = reader.next();
    		bigList.add(bi);
    	}
        return bigList;
   }
   
   /********************************************************************************\
    * Method that reads ArrayList of Strings and returns new BigIntegerList object *
    * @param s: ArrayList for BigIntegerList                                       *  
    * @return BigIntegerList                                                       *
   \********************************************************************************/
   public static BigIntegerList getBigIntegersFromFile(String fileName) throws FileNotFoundException {
       return new BigIntegerList(readBigIntegerFile(fileName));
    }

    
    public static void main(String[] args) throws FileNotFoundException {
    	
       	Scanner keyboard = new Scanner(System.in);
 		
 	int i = 0;
        while (i < 3) {
        	System.out.print("Please enter the filename: ");
	       	String fileName = keyboard.next();
	       	System.out.println("Output:\n");
	       	
	       	BigIntegerList bbb = getBigIntegersFromFile(fileName);
	       	
	       	System.out.println("start index: 0");
	       	System.out.println("middle index: " + (bbb.getSize()-1)/2);
	       	System.out.println("end index: " + (bbb.getSize()-1));
	       	
	       	System.out.println("\nMinimum of the all elements: \n" + bbb.min(0,(bbb.getSize()-1)));
	       	System.out.println("\nMinimum of the first half: \n" + bbb.min(0,(bbb.getSize()-1)/2));
	       	System.out.println("\nMinimum of the second half: \n" + bbb.min(((bbb.getSize()-1)/2)+1,(bbb.getSize()-1)));
	       	
	       	i++;
                
        }
       	
       	
       	
    }
}
