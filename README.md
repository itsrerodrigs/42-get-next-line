# 🚀 Get Next Line - 42 School

**Get Next Line** is a project from 42 School that involves creating a function that reads a line from a file or file descriptor (like `stdin`), returning a string each time it's called. The main goal is to practice memory management and buffer handling in C, as well as work with efficient file reading. 🌱

## 📋 Features

- 📄 **File reading**: The `get_next_line` function reads a line from a file, returning the entire line up to the newline character (`\n`) or the end of the file.
- 💡 **Buffer usage**: Manipulating temporary buffers to store data read from the file.
- 🧠 **Memory management**: Manual memory management to store the read lines and ensure that the program doesn't cause memory leaks.
- ✅ Fully compliant with the **42 School Norminette** (no use of `printf`, no `for` loops, etc.), and also with **Francinette**, a framework that validates code according to **Moulinette**.

## 🛠️ Installation

### Prerequisites

Before you begin, make sure you have the following installed:

- 🖥️ **Unix-like Operating System** (Linux, macOS, etc.)
- 🔧 **GCC or Clang Compiler**

### Installation Steps

1. **Clone the repository**:
    ```bash
    git clone https://github.com/itsrerodrigs/42-get-next-line.git
    cd get-next-line
    ```

2. **Compile the project**:
    To compile the code with a custom buffer size, use the following command:

    ```bash
    gcc -Wall -Wextra -Werror -D BUFFER_SIZE=<buffer_size> get_next_line.c get_next_line_utils.c
    ```

    This will generate the executable `a.out`, which you can run to test the project.

## 🚀 Usage

After compiling the project, you can use the `get_next_line` function in your own C projects! 🎯

1. **Include the library header** in your program:
    ```c
    #include "get_next_line.h"
    ```

2. **Compile your program** with the generated object files:
    ```bash
    gcc -Wall -Wextra -Werror -D BUFFER_SIZE=<buffer_size> get_next_line.c get_next_line_utils.c -o your_program
    ```

3. **Run your program**:
    ```bash
    ./your_program
    ```

## 🧹 Cleanup

- To remove all object files (`.o`):
    ```bash
    make clean
    ```

- To remove object files **and** the `get_next_line.a` file:
    ```bash
    make fclean
    ```

- To clean and recompile everything from scratch:
    ```bash
    make re
    ```

## 🛡️ Testing

You can test your project implementation using the following command, adjusting the value of `BUFFER_SIZE` as needed:

```bash
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=<buffer_size> get_next_line.c get_next_line_utils.c && ./a.out
```

Alternatively, you can use third-party testing tools to ensure your Get Next Line implementation works correctly. Here are some popular testers:

- [42 Get Next Line Tester](https://github.com/Tripouille/get_next_line_tester) por @Tripouille
