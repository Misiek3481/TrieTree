# Dynamic sparse table (Trie Tree Implementation)

## Project Overview
This project implements a space-optimized **Trie** data structure in C++. It was designed to decrease pessimistic access time estimate with a focus on manual memory management and algorithmic efficiency.

### Input
The first line contains the number **n**, specifying the number of test cases (commands **I**, **L**, **D**, and **P** – insert, lookup, delete, and print), each on a new line. The next line contains two numbers: **minimum** and **maximum**, defining the possible range of input values. The following line contains two more numbers: **n** and **k**, the parameters of our trie. Then, after a blank line, there are **n** test cases as mentioned earlier. Command:
* **I x** – inserts key **x** into the trie. If it already exists, it prints **x exist**; otherwise, it prints nothing.
* **L x** – prints **x exist** if the key is found, otherwise **x not exist**.
* **D x** – deletes key **x** from the trie. If deletion fails (key not found), it prints **x not exist**. If deletion is successful, it prints nothing. The deleted node is either the **leftmost external child** of the node containing **x**, or the node itself if it has no children.
* **P** – prints the contents of the tree in **preorder** order. If during deletion (**D x**) the leftmost external node is not chosen, the tree structure will differ, affecting preorder traversal and final output.

### Output
Each line contains the result of the commands (**I**, **L**, **D**, **P**), or no line in case no output is expected (e.g., successful insertion or deletion x).

## Key Features
* **Custom Memory Management:** Manual allocation and deallocation of nodes to ensure zero memory leaks.
* **Algorithmic Complexity:** 
    * Insertion: $O(L)$
    * Search: $O(L)$
    * *where L is the length of the key.*
* **Recursive Logic:** Implementation utilizes recursive tree traversal for deletion and printing operations.

## Build Instructions
This project uses **CMake** for cross-platform support.
1. `mkdir build`
2. `cd build`
3. `cmake ..`
4. `cmake --build . --config Release`

## Testing
The implementation has been verified using an automated test suite. The project includes large-scale test cases (up to 40,000+ operations) to ensure algorithmic stability and correct memory management.

### Running Automated Tests (Linux)
A Bash script is provided to automate the build and verification process:
1. Ensure you have `cmake` installed.
2. Run the test script:
   ```bash
   chmod +x run_tests.sh
   ./run_tests.sh

## Technical Constraints
This project was developed under strict architectural constraints to demonstrate low-level memory management skills:
* **No STL (Standard Template Library):** All data structures and memory management are implemented from scratch.
* **No `std::string`:** Character and string processing is handled via standard C-style buffers and pointers.
* **Manual Memory Management:** Demonstrated through raw pointers and custom destructor logic to ensure no memory leaks.