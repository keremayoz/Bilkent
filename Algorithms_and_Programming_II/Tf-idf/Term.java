/* Author: Kerem Ayöz
 * Number: 21501569
 * Section: 1
 *
 *	Term Class
 *	Class for term objects that stores words and its counts
 **/

public class Term {
	/*Variables word and count
	 **/
	public String word;
	public double count;

	/*@param word: String
	 *@param count: int
	 *
	 *Term() constructor that takes word and count and also
	 */
	public Term(String word, double count) {
		this.word = word;
		this.count = count;
	}

	/*
	 *Increment of variable count
	 **/
	public void incrementCount() {
		count++;
	}

	/*@return count
	 *
	 *Getting count
	 **/
	public double getCount() {
		return count;
	}
	/*@param count
	 *
	 *Setting count
	 **/
	public void setCount(double newCount) {
		count = newCount;
	}
	/*@return word
	 *
	 *Getting word
	 **/
	public String getWord() {
		return word;
	}
	/*@param newWord: String
	 *
	 *Setting word
	 **/
	public void setWord(String newWord) {
		word = newWord;
	}
}
