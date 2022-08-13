# PipeTest Error codes:
-> **904**: An error has occurred when trying to open the pipe, check if the **fifo file** is being **generated** in the **current run**  
-> **905**: An error has occurred when trying to close the pipe, check if the pipe is still being used while tying to close it  
-> **148**: An error has occurred when trying to **create** the **fifo** file, check if a **file** with the **same name** is already **present** in the folder where the executable is  
-> **405**: An error has occurred when trying to remove(delete) the fifo file, check if the **fifo** file is being **generated correctly** 
-> **980**: An error has occurred when trying to write into the pipe:   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - check if the **pipe** has been **opened**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - check if the permissions of the **fifo** are set to **READ** and **WRITE** for the current user  ( 0**6**66, the first 6 is for the current user, means READ and WRITE permissions )  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - check if the **buffer** that is trying to be **written** into the pipe isn't **corrupted** or is **too big**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - check if the **pipe** is **open** in  **O_WRITE**  or **O_RDWR**  
-> **981**: An error has occurred when trying to read from the file:  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - check if the **permissions** of the fifo are set to **READ** and **WRITE** for the current user  ( 0**6**66, the first 6 is for the current user, means READ and WRITE permissions )  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - check if the pipe is open in **O_READ** or **O_RDWR**  

-> If the program freezes after entering the message and no error code pops up, then the read() call blocks the program: it tries to read more information than it is currently in the pipe ( wrong buffer size transmitted, starving effect occurs )