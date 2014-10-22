RShell
======
licensing
---------
Read `LICENSE` for more information.

purpose
-------
'RShell' is a basic command shell that displays a command prompt and reads in user-entered commands
in one line.
This program is currently a work in progress, and is a project for the class, CS100: Software Construction, taught by Mike Izbicki at the University of California, Riverside.

bugs
----
* In its current standing, RShell only works with single commands and any associated flags. It cannot accept the connecters:
`(;, &&, and ||)`.
* The `cd` function is currently non-functional. This feature will be added later on.
* The `echo` command cannot recognize quotes, and will still print words as if they are separate tokens.
* **[ FIXED 10/21/2014: Comments are now recognized in the command prompt. ] ** ~~`Comments in the command prompt (using '#') are not recognized.`~~
### Note:
1. While comments in the middle of a user entry will be recognized, such as in `echo hello #world`, a user entry that begins with `#`, as in `#echo hello world`, will result in a stated, "logic error."
* **[ FIXED 10/20/2014: The exit command is now functional without having to make multiple entries. ]** ~~`There is now an exit command in effect, but one caveat is that it may take multiple entries of exit to actually exit the program, due to the way child and parent processes are currently handled.`~~
* **[ FIXED 10/20/2014: echo can now display an entire string. ]** ~~`The "echo" command can only display one word. For example: "echo hello" will output "hello" to the console, but "echo hello world" will result in an error.`~~
