Get_Next_Line is a project which was an introduction to open/read/close functions, file descriptors and static variables.

Get_Next_Line function reads from the specified file descriptor and stores the read text in the specified string variable, one line per call.

A static string variable is used to store the remaining characters read after the first encountered new line between the calls of the function.

The function returns 1 if a line has been read, -1 in case of an error and 0 if the end of file has been reached.
It is capable of reading from multiple file descriptors simultaneously and storing the remainer on the heap for each one of those.

The subject can be found in [en.subject.pdf](./en.subject.pdf)
