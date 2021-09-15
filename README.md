# pipex
### pipex 42 cursus

- Status : finished
- Result : 125%

This is a project to reproduce the shell behavior of redirecting STDIN and STDOUT to files and emulating pipes.

To execute the mandatory part, execute command **make** and type the command listed below. 
The arguments will be processed as same as < infile cmd1 | cmd2 > outfile on the shell.

> ./pipex infile cmd1 cmd2 outfile

To execute the bonus part, execute command **make bonus** and type the command listed below.
The arguments will be processed as same as < infile cmd1 | cmd2 | cmd3 | ... cmdn > outfile on the shell.

> ./pipex infile cmd1 cmd2 cmd3 ... cmdn outfile

The bonus part supports not only overwriting the output file, but also adding to it. 
For this, the first argument must be set here_doc, as in the example below.

> ./pipex here_doc STOP cmd1 cmd2 cmd3 ... cmdn outfile

This will work similarly to a sequence of commands executed in the shell, for example:

> cmd << STOP | cmd1 | cmd2 | cmd3 | ... cmdn >> outfile  

[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/powered-by-coffee.svg)](https://forthebadge.com)
