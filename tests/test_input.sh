#!/bin/bash

my_program=push_swap_input
# Compile the program first
make
if [ $? -ne 0 ]; then
    echo "❌ Compilation failed!"
    exit 1
fi

echo "🚀 Running test suite..."
passed=0
total=0

# Loop through all .in files dynamically
for input_file in tests/inputs/*.in; do
    # Get the base name (e.g., "tests/test1")
    base="${input_file%.in}"
    expected_stdout="$base.stdout"
    expected_stderr="$base.stderr"
    
    total=$((total + 1))
    echo -n "Running $(basename "$base")... "

    # Run program with input and save output
	./$my_program $(cat "$input_file") > "$base.actual_stdout" 2> "$base.actual_stderr"

    # Compare results
    if diff -q "$base.actual_stdout" "$expected_stdout" > /dev/null; then
        echo -n "✅ STDOUT PASSED "
        passed=$((passed + 1))
        rm "$base.actual_stdout" # Clean up temporary file
    else
        echo "❌ STDOUT FAILED"
        echo "--- Differences ---"
        diff -y "$base.actual_stdout" "$expected_stdout"
        echo "-------------------"
    fi
    total=$((total + 1))
    if diff -q "$base.actual_stderr" "$expected_stderr" > /dev/null; then
        echo  "✅ STDERR PASSED"
        passed=$((passed + 1))
        rm "$base.actual_stderr" # Clean up temporary file
    else
        echo "❌ STDERR FAILED"
        echo "--- Differences ---"
        diff -y "$base.actual_stderr" "$expected_stderr"
        echo "-------------------"
    fi
done

echo "📊 Results: $passed/$total passed."

