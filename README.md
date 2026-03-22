# Brainfuck Interpreter

A minimal Brainfuck interpreter in C++. Reads a `.bf` file and executes it.

## Build & Run

```bash
g++ -std=c++11 -o bf interpreter.cpp
./bf
```

Source file path is hardcoded in `file_name`. Default: `../data/numbers.bf`

## Commands

`+` `-` `>` `<` `.` `,` `[` `]` : standard Brainfuck. Everything else is a comment.
