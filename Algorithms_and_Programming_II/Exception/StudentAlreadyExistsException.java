/**
 * @(#)StudentAlreadyExistsException.java
 *
 *
 * @author 
 * @version 1.00 2016/12/5
 */

public class StudentAlreadyExistsException extends java.lang.Exception {
        
    /**
     * Creates a new instance of <code>StudentAlreadyExistsException</code>.
     */
    public StudentAlreadyExistsException() {
    }
    
    /**
     * Constructs an instance of <code>StudentAlreadyExistsException</code> with the specified 
     * detail message.
     *
     * @param message.
     */
    public StudentAlreadyExistsException(String message) {
        super(message);
    }
}