import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.*;
import java.lang.*;
import java.nio.file.NoSuchFileException;


public class Classroom {
	private Student [] students;
	private int MAX_CAPACITY;
	private String name;
	private int size;
	/*
	 * default constructor
	 */
	public Classroom(int capacity, String name) throws InvalidCapacityException
	{
		if (capacity < 0)
			throw new InvalidCapacityException();
		MAX_CAPACITY = capacity;
		this.name = name;
		students = new Student [MAX_CAPACITY];
		size = 0;
	}
	/*
	 * get and set methods
	 */
	public Student getStudentAt(int index) throws IndexOutOfBoundsException
	{
		if (index < 0 || index > size)
			throw new IndexOutOfBoundsException();
		return students[index];		
	}
	
	public int getSize()
	{
		return size;
	}
	
	public int getMaxCapacity()
	{
		return MAX_CAPACITY;
	}
	/*
	 * add student in order of the student ID
	 * check not to overflow the max capacity
	 */
	public void addStudent(Student newStudent) throws StudentAlreadyExistsException, ArrayIndexOutOfBoundsException, NullStudentException
	{
		int index;
		
		if (newStudent == null)
			throw new NullStudentException();
			
		if (size == 0)
		{
			students[size] = newStudent;
			size++;
			return;
		}
		for (int i = 0; i < size; i++) {
			if (newStudent.equals(students[i]))
				throw new StudentAlreadyExistsException();
		}
		index = bestIndex(0, size-1, newStudent.getStdID());
		
		for (int i = size; i > index; i--)
		{
			students[i] = students[i-1];
		}
		// insert the student and increase the size
		students[index] = newStudent;
		size++;		
	}
	/*
	 * removes a student if exists
	 * throws an exception otherwise
	 */
	public void removeStudent(Student std) throws NoSuchStudentException
	{
		// search for the student
		int index = indexOf(std);
		if(index == -1)
			throw new NoSuchStudentException();
		//otherwise shift all students back
		for (int i = index; i < size-1; i++)
		{
			students[i] = students[i+1];
		}
		// update size
		size--;
	}
	/*
	 * Recursively search for the closest id to the new stdID
	 *  -- for use in other methods
	 *  each time splits the array in half and checks the middle
	 *  accordingly it will check the middle, if its a match terminates.
	 *  If the middle student is greater than stdID checks the first half.
	 *  If the middle student is less than stdID check the second half
	 *  check if end < start will terminate, this case happens if the stdID does not exist
	 *  but start will always be the closes position to the desired ID
	 *  NOTE: start might become the last one (size) -> check for this
	 */
	private int bestIndex(int start, int end, int stdID)
	{
		if (end < start)
		{
			// terminate -- not found
			return start;
		}
		int middle = (start + end) / 2;
		if (students[middle].getStdID() == stdID)
		{
			// terminate -- found
			return middle;
		}
		
		if (students[middle].getStdID()  > stdID)
		{
			// search the first half
			return bestIndex(start, middle-1, stdID);
		}
		// search the second half
		return bestIndex(middle + 1, end, stdID);
	}
	/*
	 * search for the student -- for user
	 * returns the index of the student
	 * -1 if student does not exist
	 * not required in the assignment
	 */
	public int indexOf(Student student)
	{
		int index;
		// given the fact that the student IDs are unique
		// first find this id
		index = bestIndex(0, size-1, student.getStdID());
		// then check if they are equal
		return (index < size && students[index].equals(student) ? index : -1);
	}
	/*
	 * search for a student by using the recursive bestIndex
	 * returns the student if found, null otherwise
	 */
	public Student searchStudent(int stdID) throws NoSuchStudentException
	{
		int index;
		// first find this id
		index = bestIndex(0, size-1, stdID);
		// then check if they are equal
		if(index == -1)
			throw new NoSuchStudentException();
		return (index < size && students[index].getStdID() == stdID ? students[index] : null);
	}
	
	/*
	 * print out the information about the class into the given file
	 * if that file does not exist. If it does, it should give exception
	 */
	public void printIntoFile(String fileName) throws FileAlreadyExistsException, FileNotFoundException {
		
		PrintWriter pw = null;
		try {
			File f = new File(fileName);
			if (f.exists())
				throw new FileAlreadyExistsException();
			pw = new PrintWriter(f);
			pw.printf("%s\n", toString());
		}
		finally {
			if (pw != null)
				pw.close();
		}
	}
	
	/*
	 * append the information about the class to the given file
	 * if that file exists. If it does not, it should give exception
	 */
	public void appendToFile( String fileName) throws NoSuchFileException, IOException {
		
		PrintWriter pw = null;
		try {
			File f = new File(fileName);
			if (!f.exists())
				throw new NoSuchFileException(fileName);
			pw = new PrintWriter(new FileWriter(f, true));
			pw.printf("%s\n", toString());
		}
		finally {
			if(pw != null)		
				pw.close();
		}
	}
	
	/*
	 * Override toString
	 * (non-Javadoc)
	 * @see java.lang.Object#toString()
	 */
	public String toString()
	{
		String str;
		// classroom info
		str = "************   " + name + "   **************\n";
		str += "MAX CAPACITY : " + getMaxCapacity() + "\n";
		str += "No. of students : " + getSize() + "\n";
		// print each student info
		for (int i = 0; i < size; i++)
		{
			str += (i+1) + ")\t" + students[i] + "\n";
		}
		str += "\n*************************************\n";
		return str;
	}
}
