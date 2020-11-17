# README
By default, the make file will compile the program to bin/lineWriter.
You may need to make modifications to the Makefile for your OS (I'm working on Manjaro Linux).

I created this program to create a decently efficient way to modify a single line of a file.
It's easier than doing it manually in bash everytime.
I hope this can be useful to you in some way!
See the *LICENSE* file for details.

You can move the generated *lineWriter* file to wherever you need it.
Then, run *./lineWriter fileName line "String"*.
This will then write the String to that line of the file.

## How I'm Making It Work
It's far from perfect.
I'm reading the file and modifying the line.
Then I rewrite the entire file.

If you write to a line that doesn't exist, it will write newlines up to that line as needed.
If you write to a file that doesn't exist, it will create it.
It will add a newline to the end of the file automatically.

## Future Plans
- Adding the option to append the line, rather the overwrite it.
- Making it so I don't have to rewrite the entire file.
- Adding the ability to write multiple lines at once.
