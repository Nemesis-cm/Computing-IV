/**********************************************************************
 *                                                  
 *  PS3b: StringSound implementation and SFML audio output 
 **********************************************************************/

Name: Thomas Freeman

Hours to complete assignment : 6

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
The program works to the specifications provided in the assignments.
All keys pressed in order produce the correct sounds.


/**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)?
 *  Successfully or not?  
 **********************************************************************/
I did not implement any extra credit.

/**********************************************************************
 *  Did you implement exseptions to check your StringSound 
 *	implementation?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
yes, The constructor for frequency in string sound has an exception that 
prevents frequency from being 0, preventing any loss of sound. StringSound
handles these exceptions thrown via the circular buffer as memeory is allocated.


/**********************************************************************
 *  Did you implement lambda expression?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
yes, The lambda expressions are mainly used in stringsound in order to
continuously pass different arguments individually, involving the 
null pointers, and the steps taken in the program. These arguments
are then passed on to KSGuitarSim in order to create the correct sound
of the strings.


/**********************************************************************
 *  Did your code pass cpplint?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
yes, all files besides makefile pass cpplint. The most common edits i needed to make 
were whitespace issues and lines that contained too many characters were trimmed down.

/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/