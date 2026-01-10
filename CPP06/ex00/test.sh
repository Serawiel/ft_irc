#!/bin/bash

echo "=== CHARS ==="
./convert 'a'
echo ""
./convert 'Z'
echo ""
./convert '*'
echo ""

echo "=== INTS ==="
./convert 0
echo ""
./convert 42
echo ""
./convert -42
echo ""
./convert 127
echo ""

echo "=== FLOATS ==="
./convert 0.0f
echo ""
./convert 42.0f
echo ""
./convert -4.2f
echo ""
./convert 4.2f
echo ""
./convert 42.42f
echo ""

echo "=== DOUBLES ==="
./convert 0.0
echo ""
./convert 42.0
echo ""
./convert -4.2
echo ""
./convert 4.2
echo ""
./convert 42.42
echo ""

echo "=== SPECIAL VALUES ==="
./convert nan
echo ""
./convert nanf
echo ""
./convert +inf
echo ""
./convert -inf
echo ""
./convert +inff
echo ""
./convert -inff
echo ""

echo "=== CHAR OVERFLOW ==="
./convert -1
echo ""
./convert 128
echo ""
./convert 200
echo ""

echo "=== NON-DISPLAYABLE CHARS ==="
./convert 0
echo ""
./convert 10
echo ""
./convert 31
echo ""
./convert 32
echo ""

echo "=== INT OVERFLOW (from float/double) ==="
./convert 2147483648
echo ""
./convert 2147483648.0f
echo ""
./convert -2147483649.0
echo ""

echo "=== ERRORS ==="
./convert abc
echo ""
./convert 42.
echo ""
./convert .42
echo ""
./convert
echo ""
./convert 42 42
echo ""