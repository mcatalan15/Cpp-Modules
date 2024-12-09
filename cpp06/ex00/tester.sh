#!/bin/bash

# Compile the program
make re
if [ $? -ne 0 ]; then
    echo "Compilation failed. Exiting..."
    exit 1
fi

# Inputs for testing
declare -a inputs=(
    "'A'"         # Char
    "42"          # Int
    "42.0f"       # Float
    "42.0"        # Double
    "nan"         # Double special case
    "+inff"       # Float special case
    "-inf"        # Double special case
    "' '"         # Char: Space
    "127"         # Int: Non-displayable char
    "2147483647"  # Int: Max int
    "-2147483648" # Int: Min int
    "3.40282e+38" # Float: Largest representable
    "abc"         # Invalid
    "12a34"       # Invalid
    "'AB'"        # Invalid char
    "42.42.42"    # Invalid

    # New test cases
    "0"                  # Int: Zero
    "-0"                 # Int: Negative zero
    "0.0"                # Double: Zero
    "-0.0"               # Double: Negative zero
    "1e10"               # Double: Scientific notation
    "-1e-10"             # Double: Small negative scientific notation
    "3.4028235e+38f"     # Float: Slightly larger than max float
    "1.7976931348623157e+308" # Double: Largest representable double
    "1.8e+308"           # Double: Overflow case
    "-nan"               # Double: Negative NaN
    "'\\n'"              # Char: Newline (invalid but parsable input)
    "'\\xff'"            # Char: Non-ASCII (invalid input)
    "2.2250738585072014e-308" # Double: Smallest positive normal double
    "inf"                # Double: Positive infinity (without '+')
    "+inff"              # Float: Redundant test
)

# Expected outputs for each test case (optional)
declare -a expected_outputs=(
    "char: 'A'\nint: 65\nfloat: 65.0f\ndouble: 65.0"
    "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0"
    "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0"
    "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0"
    "char: Impossible\nint: Impossible\nfloat: nanf\ndouble: nan"
    "char: Impossible\nint: Impossible\nfloat: +inff\ndouble: +inf"
    "char: Impossible\nint: Impossible\nfloat: -inff\ndouble: -inf"
    "char: ' '\nint: 32\nfloat: 32.0f\ndouble: 32.0"
    "char: Non displayable\nint: 127\nfloat: 127.0f\ndouble: 127.0"
    "char: Impossible\nint: 2147483647\nfloat: 2147483647.0f\ndouble: 2147483647.0"
    "char: Impossible\nint: -2147483648\nfloat: -2147483648.0f\ndouble: -2147483648.0"
    "char: Impossible\nint: Impossible\nfloat: 340282001837565597733306976381245063168.0f\ndouble: 340282000000000014192072600942972764160.0"
    "Invalid input"
    "Invalid input"
    "Invalid input"
    "Invalid input"

    # Expected outputs for new test cases
    "char: '0'\nint: 0\nfloat: 0.0f\ndouble: 0.0"
    "char: '0'\nint: 0\nfloat: 0.0f\ndouble: 0.0"
    "char: '0'\nint: 0\nfloat: 0.0f\ndouble: 0.0"
    "char: '0'\nint: 0\nfloat: -0.0f\ndouble: -0.0"
    "char: Impossible\nint: 10000000000\nfloat: 1.0e+10f\ndouble: 1.0e+10"
    "char: Impossible\nint: Impossible\nfloat: -1.0e-10f\ndouble: -1.0e-10"
    "Invalid input" # Overflow float
    "char: Impossible\nint: Impossible\nfloat: Impossible\ndouble: 1.7976931348623157e+308"
    "Invalid input" # Overflow double
    "char: Impossible\nint: Impossible\nfloat: nanf\ndouble: -nan"
    "Invalid input"
    "Invalid input"
    "char: Impossible\nint: Impossible\nfloat: 2.2250738585072014e-308f\ndouble: 2.2250738585072014e-308"
    "char: Impossible\nint: Impossible\nfloat: +inff\ndouble: +inf"
)

# Helper function to compare outputs
compare_outputs() {
    local expected="$1"
    local actual="$2"

    # Normalize numerical outputs for comparison
    expected=$(echo -e "$expected" | awk '/float|double/ { printf("%.6e\n", $NF); next } { print }')
    actual=$(echo -e "$actual" | awk '/float|double/ { printf("%.6e\n", $NF); next } { print }')

    # Compare normalized outputs
    if [[ "$expected" == "$actual" ]]; then
        return 0
    else
        return 1
    fi
}

# Run tests
echo "Running tests..."
for i in "${!inputs[@]}"; do
    input="${inputs[$i]}"
    echo "Test $((i + 1)): Input = $input"
    ./Conversion "$input" > output.log 2>&1
    actual_output=$(cat output.log)

    # Compare actual output with expected
    expected_output="${expected_outputs[$i]}"
    if compare_outputs "$expected_output" "$actual_output"; then
        echo "✅ Test $((i + 1)) passed."
    else
        echo "❌ Test $((i + 1)) failed."
        echo "Expected:"
        echo -e "$expected_output"
        echo "Got:"
        echo -e "$actual_output"
    fi
    echo
done

# Clean up
rm -f output.log
