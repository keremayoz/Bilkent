/* Author: Kerem Ayöz
 * Number: 21501569
 * Section: 1
 *
 *	DocumentAnalyzer Class
 *	Class for analyzing document to calculate frequency and tf-idf ratio
 **/
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class DocumentAnalyzer {

	/*calculateTfidf() method calculates tf-idf ratio for the given word and given documents.
	 *@param word: given word
	 *@param doc: given document
	 *@param docs: given document array
	 *
	 *@return tf-idf of given word
	 **/
	public static double calculateTfidf(String word, Document doc, Document[] docs) {
		/*Counts the number of total documents
		 */
		double documentTotal = 0;
		for (int i = 0; i < docs.length; i++) {
			if (docs[i] != null)
				documentTotal++;
		}

		/*Counts the number of documents including word in docs
		 */
		double wordTotalInDocuments = 0;
		for (int i = 0; i < docs.length; i++) {
			if (docs[i] != null && docs[i].getCount(word) > 0)
				wordTotalInDocuments++;
		}
		/*tf-idf = tf * idf
		 */
		return (doc.getFrequency(word)) * (Math.log(documentTotal / wordTotalInDocuments));
	}


	public static Term[] returnBiggest(Document doc) {
		Document[] aa = new Document[1];
		aa[1] = doc;
		Term[] most = new Term[doc.ta.length];
		for (int i = 0; i < doc.ta.length; i++) {
			most[i].count = calculateTfidf(doc.ta.word,doc,aa);
			most[i].word = doc.ta.word;
		}
		return most;
	}

public void bubbleSort(Term arr[]) {
int n = arr.length;
for (int i = 0; i < n-1; i++) {
for (int j = 0; j < n-i-1; j++) {
if (arr[j].count > arr[j+1].count) {
Term temp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = temp;
}
}
}
}
	 public static void main(String[] args) throws FileNotFoundException  {
		 /*Scanner for user input*/
		 Scanner kb = new Scanner(System.in);
		 /*Document array da*/
		 Document[] da = new Document[100];
		 /*Document doc to take documents*/
		 Document doc;

		  System.out.print("Enter the number of documents: ");
		  int input1 = kb.nextInt();

		  /*Input for document taking*/
		  for (int i = 1; i <= input1; i++) {
			  System.out.print("Enter the name of the document " + i + ": ");
			  String str = kb.next();
			  doc = new Document(str);
			  doc.processDocument();
			  da[i-1] = doc;
		  }
		  /*Options for program's menu*/
		  int menuOption;

		  do {
			  System.out.print("Enter an option(enter 4 to quit): ");
			  menuOption = kb.nextInt();

			  /*Asking for word to show its frequency*/
			  if (menuOption == 1) {
				  System.out.print("Enter the word which you want to find the frequency: ");
				  String wf = kb.next();
				  for (int i = 1; i <= input1; i++) {
					  System.out.println("Document " + i);
					  System.out.println("word: " + wf);
					  System.out.println("term frequency: " + da[i-1].getFrequency(wf));
				  }
			  }

			  /*Showing the most frequent terms in documents*/
			  else if (menuOption == 2) {
				  for (int i = 1; i <= input1; i++) {
					  System.out.println("Document " + i);
					  System.out.println("word: " + da[i-1].getMostFrequentTerm().getWord());
					  System.out.println("number of appearance: " + da[i-1].getMostFrequentTerm().getCount());
				  }
			  }

			  /*Showing tf-idf for given word */
			  else if (menuOption == 3) {
				  System.out.print("Enter the word which you want to calculate tf-idf: ");
				  String str = kb.next();
				  for (int i = 1; i <= input1; i++) {
					  System.out.println("Document " + i);
					  System.out.println("word: " + str);
					  System.out.println("tf-idf: " + calculateTfidf(str, da[i-1], da));
				  }
			  }
			  /*Exiting from program*/
			  else if (menuOption == 4) {
				  System.out.println("Done");
			  }

			  else if (menuOption == 5) {
			  	System.out.println(da[0].getFrequency("kerem"));
			  	System.out.println(da[0].getCount("kerem"));
			  	System.out.println(da[0].getTotal());
			  }
		  }
		  while (menuOption != 4);
		  kb.close();
	 }

}

