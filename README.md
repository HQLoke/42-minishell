# 42-minishell
The goal of this project is to create a simple shell. Will be your own little
bash or zsh. 
![](https://github.com/HQLoke/42-minishell/blob/master/minishell.gif)
## Table of contents 📋
- [Project Structure](#overall-structure)
- [Implementations](#the-project-implements)
- [Usage 📦](#usage)
- [References 📌](#reference)

## Overall structure
1) **Lexical analysis**: Reading input
2) **Parser**: Expanding and parsing input
3) **Execution**: Execute input that is parsed

## The project implements
- Display:
  - Search and launch the right executable (based on the PATH variable, using a relative or an absolute path)
  - Show a prompt when waiting for a new commands
  - History of previous entered commands
- Builtins:
  - ```echo``` with option ’-n’
  - ```cd``` with only a relative or absolute path
  - ```pwd``` without any options
  - ```export``` without any options
  - ```unset``` without any options
  - ```env``` without any options and any arguments
  - ```exit``` without any options
- Redirections:
  - ```<``` Redirecting Input
  - ```>``` Redirecting Output
  - ```>>``` Appending Redirected Output
  - ```<<``` Here Documents
- ```Environment variables expansion```
- Pipes:
  - ```|```

- ```$?``` expands to the last exit status
- Signals:
  - ```ctrl-\``` do nothing
  - ```ctrl-C``` print a new prompt on a newline
  - ```ctrl-D```exit the shell

## Usage
```
git clone https://github.com/HQLoke/42-minishell.git
cd 42-minishell
make
./minishell
```


## Reference
- [How to create your own shell](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)
- [GNU Bash Reference Manual](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html)
- [minishell - 42 Docs](https://harm-smits.github.io/42docs/projects/minishell)
- [$? explained](https://unix.stackexchange.com/questions/7704/what-is-the-meaning-of-in-a-shell-script)
- [env builtin](https://man7.org/linux/man-pages/man1/env.1.html)
- [Signals](https://www.geeksforgeeks.org/signals-c-language/)
- [Subject](https://cdn.intra.42.fr/pdf/pdf/10992/en.subject.pdf)
- [man : bash](https://linux.die.net/man/1/bash)

---
[Back To The Top](#42-minishell)
