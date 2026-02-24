#!/bin/bash
mkdir -p build && cd build
cmake .. && make

echo -e "\n--- Tests ---\n"

for i in {1..4}
do
    echo -n "Test $i: "
    ./TrieTree < ../tests/$i.in > my_output.txt

    if diff -q my_output.txt ../tests/$i.out; then
        echo "Test PASSED!"
    else
        echo "Test FAILED! Check differences:"
        diff --side-by-side --suppress-common-lines my_output.txt ../tests/$i.out | head -n 20
    fi
done

echo -e "\n--- Tests finished ---\n"
