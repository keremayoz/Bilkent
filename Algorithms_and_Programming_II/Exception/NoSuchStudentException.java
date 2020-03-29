/**
 * @(#)NoSuchStudentException.java
 *
 *
 * @author 
 * @version 1.00 2016/12/5
 */

public class NoSuchStudentException extends java.lang.Exception {
        
    /**
     * Creates a new instance of <code>NoSuchStudentException</code>.
     */
    public NoSuchStudentException() {
    }
    
    /**
     * Constructs an instance of <code>NoSuchStudentException</code> with the specified 
     * detail message.
     *
     * @param message.
     */
    public NoSuchStudentException(String message) {
        super(message);
    }
}