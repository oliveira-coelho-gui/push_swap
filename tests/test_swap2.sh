#!/bin/bash

my_program=test_swap2
# Compile the program first
make
if [ $? -ne 0 ]; then
    echo "❌ Compilation failed!"
    exit 1
fi

echo "🚀 Running OPERATIONS  unit tests..."
passed=0
total=0

# Loop through all .in files dynamically
for input_file in tests/operations/swap/input2/*.in; do
    # Get the base name (e.g., "operations/test1")
    base="${input_file%.in}"
    expected_stdout="$base.stdout"
    
    total=$((total + 1))
    echo -n "Running $(basename "$base")... "

    # Run program with input and save output
	./$my_program $(cat "$input_file") > "$base.actual_stdout"

    # Compare results
    if diff -q "$base.actual_stdout" "$expected_stdout" > /dev/null; then
        echo  "✅ STDOUT PASSED"
        passed=$((passed + 1))
        rm "$base.actual_stdout" # Clean up temporary file
    else
        echo "❌ STDOUT FAILED"
        echo "--- Differences ---"
        diff -y "$base.actual_stdout" "$expected_stdout"
        echo "-------------------"
    fi
done

echo "📊 Results: $passed/$total passed."
