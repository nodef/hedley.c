#!/usr/bin/env bash
# Fetch the latest version of the library
fetch() {
if [ -f "hedley.h" ]; then return; fi
URL="https://github.com/nemequ/hedley/raw/refs/heads/master/hedley.h"
FILE="hedley.h"

# Download the release
if [ ! -f "$FILE" ]; then
  echo "Downloading $FILE from $URL ..."
  curl -L "$URL" -o "$FILE"
  echo ""
fi
}


# Test the project
test() {
echo "Running 01-basic-features.c ..."
clang -I. -o 01.exe examples/01-basic-features.c         && ./01 && echo -e "\n"
echo "Running 02-likely-unlikely-static.c ..."
clang -I. -o 02.exe examples/02-likely-unlikely-static.c && ./02 && echo -e "\n"
echo "Running 03-deprecated-static.c ..."
clang -I. -o 03.exe examples/03-deprecated-static.c      && ./03 && echo -e "\n"
echo "Running 04-static-assert-version.c ..."
clang -I. -o 04.exe examples/04-static-assert-version.c  && ./04 && echo -e "\n"
}


# Main script
if [[ "$1" == "test" ]]; then test
elif [[ "$1" == "fetch" ]]; then fetch
else echo "Usage: $0 {fetch|test}"; fi

# 01-basic-features.c
# 02-likely-unlikely-static.c
# 03-deprecated-static.c
# 04-static-assert-version.c
