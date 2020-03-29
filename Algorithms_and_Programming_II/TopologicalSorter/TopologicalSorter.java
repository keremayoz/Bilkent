/*
 * Author: Kerem Ayöz
 * 18/12/2016
 * Lab 7
 * Topological Sorting algorithm
 * 
 */
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;


public class TopologicalSorter {
	public static Queue[] out;
	public static int[] in;
	public static Queue q;
	
	/*
	 * @param fileName: file name thats taken
	 * @param n: element count
	 * @return output: output String
	 * Method calculates the topological order
	 * 
	 */
	public static String topologicalSort(String fileName, int n) throws FileNotFoundException {
		String output = "";
		out = new Queue[n+1];
		in = new int[n+1];
		q = new Queue();
		int i,j;
		
		//Filling out[] array
		//First adding binary relations of numbers
		Scanner reader = new Scanner(new File(fileName));
		while (reader.hasNextLine()) {
        i = reader.nextInt();
        j = reader.nextInt();
        out[i] = new Queue();
        out[i].enqueue(j);
        in[j]++;
        }
		reader.close();
		
		
		//Traverse the in array and add the 0 indegree elements to the String output
		for (int k = 0; k < in.length; k++) {
			if (in[k] == 0) {
				in[k]--;
				q.enqueue(k);
				output += k + " ";
				while (out[k] != null && !out[k].isEmpty()) {
					in[out[k].peek()]--;
					out[k].dequeue();
				}
				k = 0;
			}
			
		}
		return output;
	}
}
