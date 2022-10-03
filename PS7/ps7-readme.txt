 /**********************************************************************
 *  readme.txt template                                                   
 *  PS7 Kronos 
 **********************************************************************/

Name: Thomas Freeman


Hours to complete assignment: 7

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes, All the files generated theirs respective regex's as per the 
assignment description. 


/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/

I only used one long regex to read the data and time. any other 
messages didn't require a regex at all, the expression is as follows.

^\\d{4}[-](0[1-9]|1[012])[-](0[1-9]|[12][0-9]|3[01])\\s\\d{2}[:]\\d{2}[:]\\d{2}


/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
 This program will read our given log files line by line and determine the 
 start and completion of their respective boots. If a boot start message is scanned
 then the date and time of said boot will be recorded via the regex. the date and time
 is then saved again along with the complete boot time. The info is finally saved under 
 a report file with file extension .rpt. 



/**********************************************************************
 *  Did you use lambda expression? If yes describe there.
 **********************************************************************/
I did not use lambda expression.




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
