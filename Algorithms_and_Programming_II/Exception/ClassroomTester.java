
public class ClassroomTester {
	public static void main (String [] agrs) throws Exception
	{
		// Fill this main method so that all exceptions you added
		// can be seen when we run the code. Note that you should
		// write the code segment based and each segment should
		// corresponds to a specific exception. You cannot run the
		// code and it shows all exception.
		
		Classroom c1 = new Classroom(3, "A class");
		Student s1 = new Student(0001, "Kerem", "Ayöz", "CS");
		Student s2 = new Student(0002, "Wesley", "Sneijder", "FU");
		Student s3 = new Student(0003, "Alan", "Turing", "CS");
		Student s4 = new Student(0004, "Albert", "Einstein", "PHYS");
		Student s5 = new Student(0005, "Nelson", "Mandela", "POLS");
		Student s6 = null;
		c1.addStudent(s1);
		c1.addStudent(s2);
		c1.addStudent(s3);
		/*
		//ADDING MORE THAN CAPACITY
			c1.addStudent(s4);
		
		//ADDING SAME STUDENT
			Classroom c2 = new Classroom(10, "B class");
			c2.addStudent(s1);
			c2.addStudent(s1);
	
		//REMOVE
			c1.removeStudent(s5);
	
		//INDEXOF
			System.out.println(c1.indexOf(s6));
		
		//PRINT INTO FILE
			c1.printIntoFile("Document1");
		
		//APPEND TO FILE
			c1.appendToFile("Document2");
	
		//GET STUDENT AT
			System.out.println(c1.getStudentAt(5));
		
		//NEGATIVE CAPACITY
			Classroom c3 = new Classroom(-8, "C class");
		
		
		//ADDING NULL STUDENT
			Student s6 = null;
			Classroom c3 = new Classroom(10,"D class");
			c3.addStudent(s6);
		*/
	}

}
