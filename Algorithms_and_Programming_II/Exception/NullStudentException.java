/**
 * @(#)NullStudentException.java
 *
 *
 * @author 
 * @version 1.00 2016/12/5
 */

public class NullStudentException extends java.lang.Exception {
        
    /**
     * Creates a new instance of <code>NullStudentException</code>.
     */
    public NullStudentException() {
    }
    
    /**
     * Constructs an instance of <code>NullStudentException</code> with the specified 
     * detail message.
     *
     * @param message.
     */
    public NullStudentException(String message) {
        super(message);
    }
}