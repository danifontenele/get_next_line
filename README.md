# get_next_line

In this project I had to implement a function that read an opened file and return the next line always when the function is called.
A big detail of this function is in the fact it has to consider using different sizes of buffer to analyse the text in blocks, it's important to improve the program efficiency.

## The static variable
The most importatnt concept of C I had to learn to this project was the concept of the static variables.
In resume, the static variable keeps the state of the variable as soon as the program is still running, so when the funcion is evetually called again, this variable can be used in the same state it was let in the last call.

Some other important things about static variables:
- They does't stay in stack or heap memory, but in another part called static memory.
- As they are not allocated, there's no memory leaks, because at the end of the program they are freed.
- When a static memory is declared or limited by a '\0' terminator, the non initialized memory is automatically 0.

## The idea: 
<img width="1065" height="2400" alt="gnl_diagram" src="https://github.com/user-attachments/assets/eee1af84-f830-4c01-bc39-4a05d775045f" />

### 1) The fuction receives fd as argument
- The fd and the BUFFER_SIZE are checked(see in get_next_line.c).
- The line is initialized for the first occurence of get_next_line() in the program.

### 2) The main loop(inifity one)
In this infinity loop there are all the necessary conditions to stop and return something, so don't worry.

### 3) line_joint()
This funciton receive the buffer(blocks of the file's text) and join it to the last block building the line block to block(while the main loop is happening). The funcion stops building the line when it finds a '\n'.
One important thing of this function is: just build the line for the output, never changes something in the buffer. This is a task for the next function.

### 4) set_buffer()
As the infinity loop is happening, the buffer is changing, so to the buffer to keep reading and being replaced to the next block of the file's text I have to set the first index of this buffer to '\0' always when the this buffer is already joinned to the old line.
The only case the buffer is not emptied is when in the buffer there is a new line. First of all it says to me that I reached the end of a line.
But the buffer can be big as it also get a part of the next line. To solve this, in this canse, the function moves the characters after the '\n' to the beggining of the buffer and set the end of this rest to '\0', returning a new valid buffer to be joinned and start the next line.

### 5) in the first condition of the main loop
When the number of bytes read is 0, the function returns the line, the last one.

### 6) the last condition of the main loop
When the line has a '\n'(so it's a completed valid line) it returns this valid line.

