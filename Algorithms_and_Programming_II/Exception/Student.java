
public class Student {
	private String firstName;
	private String lastName;
	private int stdID;
	private String depID;
	
	/*
	 * Constructor
	 */
	// default
	public Student()
	{
		firstName = "";
		lastName = "";
		stdID = -1;
		depID = "";
	}
	// set all attributes
	public Student(int stdID, String firstName, String lastName, String depID)
	{
		this.stdID = stdID;
		this.lastName = lastName;
		this.firstName = firstName;
		this.depID = depID;
	}
	/*
	 * set methods
	 */
	/**!!! student ID can not be set !!!**/
	public void setLastName(String lastName)
	{
		this.lastName = lastName;
	}
	public void setFirstName(String firstName)
	{
		this.firstName = firstName;
	}
	public void setDepID(String depID)
	{
		this.depID = depID;
	}
	/*
	 * get methods
	 */
	public int getStdID()
	{
		return stdID;
	}
	public String getLastName()
	{
		return lastName;
	}
	public String getFirstName()
	{
		return firstName;
	}
	public String getDepID()
	{
		return depID;
	}
	/*
	 * equals method. The depID needs not to be the same
	 */
	@Override
	public boolean equals(Object obj)
	{
		Student s = (Student) obj;
		
		return this.stdID == s.stdID &&
				this.firstName.equals(s.firstName) &&
				this.lastName.equals(s.lastName);
	}
	/*
	 * Override toString
	 * 
	 * (non-Javadoc)
	 * @see java.lang.Object#toString()
	 */
	public String toString()
	{
		return stdID + "\t" + lastName + "\t" + firstName + "\t" + depID;
	}

}
