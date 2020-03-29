/* Author: Kerem Ayöz
 * Number: 21501569
 * Section: 1
 *
 *	Document Class
 *	Document class process documents to fill the array of the document. Also it contains methds to calculate frequency and find most frequent one
 **/
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Document {

	private String fileName;
	public Term[] ta;
	private int totalWords = 0;

	/*@param fileName: name of the document
	 *
	 *Constructor of the Document class
	 **/
	public Document(String fileName) {
		this.fileName = fileName;
		ta = new Term[200];
	}

	/*
	 *Method that reads the text file and fills the array with the words of text file
	 **/
	public void processDocument() throws FileNotFoundException {
		Scanner reader = new Scanner(new File(fileName));
		Scanner in;
		String s,h;
		while(reader.hasNext()) {
			s = reader.nextLine();
			in = new Scanner(s);

			while (in.hasNext()) {
				h = in.next();
				h = editWord(h);
				for (int i = 0; i < ta.length; i++) {
					if (ta[i] == null) {
						ta[i] = new Term(h, 1);
						break;
					}
					else if (ta[i].getWord().equals(h)) {
						ta[i].incrementCount();
						break;
					}
				}
				totalWords++;
			}//Inner-While
		}//Outer-While
	}

	/*@param word: given word to calculate its count
	 *@return remp: number of the word's count in Term array
	 *
	 *Method that shows the appearence of word in document
	 **/
	public int getCount(String word) {
		double temp = 0;
		for (int i = 0; i < ta.length && ta[i] != null; i++) {
			if (word.equals(ta[i].getWord())) {
				temp = ta[i].getCount();
				break;
			}
		}
		return (int)temp;
	}

	/*@param word: given word to calculate frequency
	 *@return getCount(word) / (totalWords * 1.0): count of the word divided by the count total word in document
	 *
	 *Method shows the frequency of word
	 **/
	public double getFrequency(String word) {

		return getCount(word) / (totalWords * 1.0);
	}

	/*@return ta[temp]: the most frequent Term object
	 *
	 *Finding the most frequent term with the greatest frequency
	 **/
	public Term getMostFrequentTerm() {
		double largest = getFrequency(ta[0].getWord());
		int temp = 0;
		for (int i = 1; i < ta.length; i++) {
			if (ta[i] != null && getFrequency(ta[i].getWord()) > largest) {
				largest = getFrequency(ta[i].getWord());
				temp = i;
			}
		}
		return ta[temp];
	}
	/*@param s: given string which will be returned
	 *@return s: edited parameter
	 *
	 *Method that removes punctation and makes every character lower-case
	 **/
	public static String editWord(String s) {

		s = s.replace(",", "");
		s = s.replace(".", "");
		s = s.replace("\"", "");
		s = s.replace(":", "");
		s = s.replace(";", "");
		s = s.replace("!", "");
		s = s.toLowerCase();
		return s;
	}

	/*@return ta
	 *
	 *Getting ta array
	 **/
	public Term[] getTa() {
		return ta;
	}
	/*@return totalWords
	 *
	 *Getting totalWords
	 **/
	public int getTotal() {
		return totalWords;
	}
	/*@param ta
	 *
	 *Setting ta array
	 **/
	public void setTa(Term[] ta) {
		this.ta = ta;
	}
}
