#### WELCOME TO THIS B-TREE

This program is designed to perform the following tasks:

1. **Generate Random Keys**: The program will ask the user for the number of elements to insert into the B-tree. It generates a sequence of random integers within the range [0, 3*N], where N is the user-input number, ensuring no duplicate values.

2. **Build B-Tree**: It constructs a 5-way B-tree using the randomly generated keys in the sequence order.

3. **Search and Return Keys**: The program searches for and returns any keys in the range [N, 2*N].

---

#### Technologies, Algorithms, and Concepts Used

This program is implemented in C++ and utilizes several key technologies, algorithms, and concepts to implement a B-tree data structure efficiently:

1. **B-tree**: The program implements a B-tree data structure for efficient storage and retrieval of large sets of data. B-trees are balanced multiway search trees, commonly used in database systems and file systems.

2. **Node Splitting**: When a node in the B-tree becomes full, the program employs node splitting, a fundamental operation in B-tree insertion. This ensures that the tree remains balanced and maintains its properties.

3. **Node Insertion**: The program handles the insertion of keys into B-tree nodes, ensuring that the tree's properties are preserved at all times. It follows the rules of B-tree insertion, such as redistributing keys between nodes when necessary.

4. **Traversal**: Traversal of the B-tree is performed to output keys in sorted order. This traversal ensures that all keys stored in the tree are visited and displayed correctly.

---

#### Running the Program

To execute the program:

1. **Compilation**: Open your terminal and navigate to the directory containing the source code.

2. **Make Run**: Type `make run` and press Enter. This will compile and run the program.

3. **Input Number of Elements**: Follow the prompts to input the number of elements (N) for the B-tree. Ensure the input is greater than or equal to 400.

4. **View Outputs**:
   - The program will display all random keys generated between 0 and 3N as they appear in the B-tree.
   - It will then show the keys found within the range [N, 2*N].

---

#### Cleanup

After running the program, you can clean up by typing `make clean` into the terminal. This will remove any generated files.

---

#### Program Requirements

- **Input**: N (Number of elements)
- **Output**: B-tree; Keys found in the range [N, 2*N]