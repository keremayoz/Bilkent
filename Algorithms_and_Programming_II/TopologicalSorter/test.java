import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class test {

	public static void main(String[] args) throws FileNotFoundException {
		System.out.println(TopologicalSorter.topologicalSort("input.txt", 7));
		System.out.println(TopologicalSorter.topologicalSort("input2.txt", 8));
		
	}

}
