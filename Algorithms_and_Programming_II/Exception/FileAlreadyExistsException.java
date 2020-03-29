/**
 * @(#)FileAlreadyExistsException.java
 *
 *
 * @author 
 * @version 1.00 2016/12/5
 */

public class FileAlreadyExistsException extends java.lang.Exception {
        
    /**
     * Creates a new instance of <code>FileAlreadyExistsException</code>.
     */
    public FileAlreadyExistsException() {
    }
    
    /**
     * Constructs an instance of <code>FileAlreadyExistsException</code> with the specified 
     * detail message.
     *
     * @param message.
     */
    public FileAlreadyExistsException(String message) {
        super(message);
    }
}