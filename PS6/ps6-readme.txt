 /**********************************************************************
 *  readme.txt template                                                   
 *  Random Writer 
 **********************************************************************/

Name:Thomas Freeman

Hours to complete assignment:8

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The goal of this assignment was to implement the markov model. This model
can determine the next sequence of characters at k length which in the code is 
called k_grams. The class takes the parameters string and order k that inputs 
and maps k_gram. A new string is then written based upon the probability of 
the proceeding characters. The TextWriter class then analyzes the words in a given
text file, producing a random string of L length to recreate text.
I tested with ./TextWriter 10 10 < markov/amendments.txt




  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
The Random Writer class has a map that contains k_gram as a key and map 
of the characters. We also use a mersenne twister random number generator 
along with the kRand() function for number generation.




/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
The constructor of RandWriter creates a map that can be visualized as 
a table with outputs that hold k_gram, the following characters, and their frequency
generate() uses the kRand method to help select the next random characters
from k_gram string once it starts to build a new string. 




/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes the assignment functions correctly



/**********************************************************************
 *  Does your implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
Yes it passes the boost unit tests. 



 /**********************************************************************
 *  Describe where you used exceptions. 
 *  Provide files and lines of the code.
 ***********************************************************************/
RandWriter possesses all the exceptions needed for TextWriter to 
catch and handle.




 /**********************************************************************
 *  Describe where you used lambda expression if any
 *  Provide files and lines of the code.
 ***********************************************************************/


/**********************************************************************
 *  Did you implemented program for extra poits? If yes, describe your 
 *  If yes, describe your implementation.
 ***********************************************************************/



/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
