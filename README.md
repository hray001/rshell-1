RShell
======
licensing
---------
Read `LICENSE` for more information.

purpose
-------
'RShell' is a basic command shell that displays a command prompt and reads in user-entered commands
in one line.
This program is currently a work in progress.

bugs
----
* In its current standing, RShell only works with single commands and cannot accept the connecters:
`(;, &&, and ||)`.
* **FIXED 10/20/2014** There is currently no exit command in effect.
* RShell can only be executed one time. Once a command is successful, the program will exit.
* The `echo` command can only display one word. For example: `echo hello` will output `hello` to the
console, but `echo hello world` will result in an error.
* The `cd` function is currently non-functional. This feature will be added later on.
