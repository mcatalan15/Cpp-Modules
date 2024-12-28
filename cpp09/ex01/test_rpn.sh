#!/bin/bash

# Path to your RPN executable
RPN_EXEC="./RPN"

# Build the executable
echo "Rebuilding the project..."
make re
if [ $? -ne 0 ]; then
    echo -e "\033[31mBuild failed. Exiting.\033[0m"
    exit 1
fi
echo -e "\033[32mBuild successful.\033[0m"

# Test cases
declare -a TESTS=(
    "5"                     # Single number
    "9 8 - 7 - 6 - 5 -"     # Chain of subtractions
    "1 2 * 3 * 4 * 5 *"     # Chain of multiplications
    "1 2 + 3 4 + * 5 - 6 7 + *"  # Mixed operators
    "8 1 /"                 # Divide by 1
    "8 4 / 2 /"             # Divide to zero (proper division)

    ""                      # Empty input
    "5 +"                   # Unmatched operand count
    "5 1 2 +"               # Excess operands
    "1 a +"                 # Non-numeric tokens
    "1 2 ^"                 # Unsupported tokens
    "8 0 /"                 # Division by zero
    "1 2 + 3"               # Unbalanced expression

    "1 2 + 3 4 + * 5 6 + * 7 8 + * 9 0 + *"  # Long expression
    "9 8 - 7 + 6 * 5 /"       # All operators at once
    "9 3 / 3 / 3 /"           # Chain of divisions resulting in zero
)

# Expected outputs
declare -a EXPECTED=(
    "5"
    "-17"
    "120"
    "208"
    "8"
    "1"

    "Error"
    "Error"
    "Error"
    "Error"
    "Error"
    "inf"
    "Error"

    "31185"
    "9.6"
    "0.333333"
)

# ANSI color codes
GREEN="\033[32m"
RED="\033[31m"
YELLOW="\033[33m"
RESET="\033[0m"

# Run tests
echo "Running tests..."
for i in "${!TESTS[@]}"; do
    TEST_INPUT="${TESTS[i]}"
    EXPECTED_OUTPUT="${EXPECTED[i]}"

    # Run the RPN program with the test input
    OUTPUT=$($RPN_EXEC "$TEST_INPUT" 2>&1)

    # Check the result
    if [ "$OUTPUT" == "$EXPECTED_OUTPUT" ]; then
        echo -e "${GREEN}Test $((i + 1)): Passed${RESET}"
    elif [ "$EXPECTED_OUTPUT" == "Computed result of the expression" ]; then
        echo -e "${YELLOW}Test $((i + 1)): Potential conflict${RESET}"
        echo "  Input: \"$TEST_INPUT\""
        echo "  Expected: $EXPECTED_OUTPUT"
        echo "  Got: $OUTPUT"
    else
        echo -e "${RED}Test $((i + 1)): Failed${RESET}"
        echo "  Input: \"$TEST_INPUT\""
        echo "  Expected: $EXPECTED_OUTPUT"
        echo "  Got: $OUTPUT"
    fi
done
