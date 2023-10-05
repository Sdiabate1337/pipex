# Pipex

This project will let you discover in detail a UNIX mechanism that you already know
by using it in your program.

```  
* Handle multiple pipes
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2

Should behave like:
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
````
```
* Support « and » when the first parameter is "here_doc".
$> ./pipex here_doc LIMITER cmd cmd1 file

Should behave like:
cmd << LIMITER | cmd1 >> file
```
