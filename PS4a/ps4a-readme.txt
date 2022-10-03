/**********************************************************************
 *  readme.txt template                                                   
 *  Synthesizing a Plucked String Sound:
 *  CircularBuffer implementation with unit tests and exceptions 
 **********************************************************************/

Name: Thomas Freeman


Hours to complete assignment: 5 

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The goal for the first half of assignment for was to create our 
circular buffer implementation, and make sure it passes a number of 
given tests and throws the correct exceptions. The Karplus Strong algorithm works
with the array int16_t to store samples of vibration. We then test these
using the boost library commands in test.



/**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
Well this revolves around the use of an array as a queue. The data in int16_t
is modified by two functions, enqueue and dequeue. Enqueue adds data to the end
of the stack, dequeue pops a value from the top of the stack. If we just want to
look at the first value in the queue, we use the peek function to see that.




/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
CircularBuffer dynamically allocates all values into array int16_t. the data
is consistently being moved, copied or destructed. For example enqueue takes a parameter
and attaches it to the buffers end, at an index equal to the buffers size then increments.
dequeue behaves in the opposite way, holding an element at the beginning of buffer and decrementing
the entire buffer, returning the item as a result.




/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes all boost tests either pass or purposely throw an exception.





 *  Does your CircularBuffer implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
When all the tests finish no errors will be indicated since some tests 
are purposed to throw exceptions.




/**********************************************************************
 *  Explain the time and space performance of your RingBuffer
 *	implementation
 **********************************************************************/
 The size of the buffer can be represented as N, we only need a single loop 
to allocate or deallocate items to the buffer, so our time complexity is 0(N)





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
