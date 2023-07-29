# Minishell :shell: - A Simple Shell Implementation
## As beautiful as a shell
### This project is about creating a simple shell. Yes, your own little bash
**Minishell is a simple shell implementation written in C, allowing users to interact with their operating system using command-line commands. It supports various features like executing executables, managing environment variables, implementing redirections, pipes, and handling signals. This project is part of the 42 School curriculum.**
## Table of Contents

1. [Introduction](#introduction)
2. [Installation](#installation)
3. [Usage](#usage)
4. [Features](#features)
5. [Built-in Commands](#built-in-commands)
6. [Contributing](#contributing)

## Introduction

Minishell aims to provide a basic shell experience for users, allowing them to execute commands, navigate the file system, and manage environment variables. It is designed to be user-friendly and provide the essential functionalities of a shell.

## Installation

To compile Minishell, make sure you have the `gcc` compiler and the `GNU Make` utility installed on your system. Then, follow these steps:

1. Clone this repository to your local machine:

```bash
git clone https://github.com/AfafTarchoun/minishell.git
cd minishell
```

2. Run the provided Makefile to build the executable:

```bash
make
```
The minishell executable should now be generated in the project directory.

## Usage
Run the minishell executable to start the shell:

```bash
./Minishell
```
You will see the Minishell prompt, where you can type in your commands.

To exit Minishell, use the exit command:

```bash
minishell$ exit
```
## Features
Minishell provides the following features:

- Displaying a prompt to interact with the user.
- Maintaining a command history for easy navigation.
- Searching and executing the right executable using the PATH variable or absolute/relative paths.
- Handling single and double quotes to prevent interpretation of metacharacters.
- Implementing redirections for input (<) and output (>), as well as append mode (>>).
- Supporting pipes (|) to chain commands together.
- Expanding environment variables ($VAR) to their values.
- Expanding $? to the exit status of the most recently executed foreground pipeline.
- Handling signals ctrl-C, ctrl-D, and ctrl-\ as expected in a shell.
- Implementing various built-in commands (see Built-in Commands).

## Built-in Commands
Minishell supports the following built-in commands:

- **echo** : Display arguments to the standard output, with the option -n to omit the trailing newline.
- **cd** : Change the current directory using a relative or absolute path.
- **pwd** : Display the absolute pathname of the current working directory.
- **export** : Set an environment variable with the format key=value.
- **unset** : Unset/delete an environment variable.
- **env** : Display the current environment variables.
- **exit** : Exit the shell.

## Contributing
Contributions to Minishell are welcome! If you find any issues or have improvements to suggest, please feel free to open an issue or submit a pull request.
