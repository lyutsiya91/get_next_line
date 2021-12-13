# get_next_line
The function that allows to read the text available on the file descriptor one line at a time until the end of it.

If the reading is successful and there is something else to read the function returns 1. 
If there is nothing else to read it returns 0, if an error has occurred it returns -1.

The argument "**line" points at the line that has just been read.

The program must compile with the flag -D BUFFER_SIZE=xx which will be used as the buffer size for the read calls in the get_next_line.
This value can be modified.

Bonus files: the function is able to manage multiple file descriptors.
