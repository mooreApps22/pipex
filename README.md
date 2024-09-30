# Pipex
## This is an exercise using system calls to recreate the bash's redirection pipe operator
### This project is about handling pipes

Pipex is a C program that was written on a GNU/Linux OS. Pipex takes four arguments exactly.

Program Usage: ```./pipex <infile> <cmd1> <cmd2> <outfile>```

Used to recreate the bash command: ```< <infile> <cmd1> | <cmd2> > <outfile>```

1. The contents of the infile is input into the cmd1.
2. The output of cmd1 is input into cmd2.
3. The output of cmd2 is input to the outfile. 
