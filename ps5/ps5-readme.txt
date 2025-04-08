/**********************************************************************
 *  readme 
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Thomas Freeman

Hours to complete assignment: 6

/**********************************************************************
 * Explain which approach you decided to use when implementing
 * (either recursive with memoization, recursive without memoization,
 * dynamic programming or Hirschberg’s algorithm). Also describe why
 * you chose this approach and what its pros and cons are.
 **********************************************************************/
My approach for this assignment was to use dynamic programming to 
fill up a matrix in order to get the optimal distance length. The matrix
is filled from bottom right to top left and traced from bottom left to top 
right. This allows the matrix to store parts of the string and move to the next
section and solve the next section. This prevents any backtracking of the string
itself, making runtime alot longer. 




/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
Input:./EDistance < endgaps7.txt

Expected output:
Edit distance = 4 
a - 2
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0
- a 2
Execution time = some small time measure in seconds

What happened:
Edit distance = 4 
a - 2
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0
- a 2
Execution time = 2.6e-05 seconds



/**********************************************************************
 * Look at your computer’s specs in the settings. 
 * How much RAM does your computer have and explain what this means? 
 **********************************************************************/
 Well the VM possesses 4gb of ram by default. ram is used for data 
 allocation during a programs runtime. In the case of the DNA 
 sequence, the vectors within the matrix are what allocate data 
 and use the VM's ram.



/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 8GB (billion bytes) of memory?
 **********************************************************************/
a = 4 bytes per int derived from vector<int>
b = 2 since this is the complexity of nested for loops
largest N = sqrt(20000000) = 44721

/**********************************************************************
 * Run valgrind if you can and attach the output file to your submission. 
 * If you cannot run it, explain why, and list all errors you’re seeing. 
 * If you can run it successfully, does the memory usage nearly match that 
 * found in the question above? 
 * Explain why or why not. 
/**********************************************************************
Yes, when using say ecoli5000.txt, we get under 100mb or in my case,
93.2mb which is under what is expected. 


/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)     memory (MB)
------------------------------------------------------------------
ecoli2500.txt       118             0.063		28.43
ecoli5000.txt       160             0.148		93.20
ecoli7000.txt       194             0.419  		192.4           
ecoli10000.txt      223             0.957 		401.2            
ecoli20000.txt      3135            1.533		732.8
ecoli28284.txt      8394	     3.041		1250.2

/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730



/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 4 bytes 
b = 3.83 average of ratios of N to 2N
largest N = 2,560,000

/
**********************************************************************
 *  Did you use the lambda expression in your assignment? If yes, where 
 * (describe a method or provide a lines numbers)
 **********************************************************************/
I did not use the lambda expression



**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
