#!/bin/bash
if [[ -n "$1" && "$1" == "p" ]]; then
    pbpaste > ./in.txt
fi

if [[ -n "$1" && "$1" == "c" ]]; then
    cat test.cpp | pbcopy
fi

if [[ -n "$2" && "$2" == "c" ]]; then
    cat test.cpp | pbcopy
fi

/opt/homebrew/bin/g++-12 test.cpp && ./a.out < in.txt
