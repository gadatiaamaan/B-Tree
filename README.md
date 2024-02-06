#### WELCOME TO THIS B-TREE PROGRAM!

This program is designed to perform the following tasks:

1. **Generate Random Keys**: The program will ask the user for the number of elements to insert into the B-tree. It generates a sequence of random integers within the range [0, 3*N], where N is the user-input number, ensuring no duplicate values.

2. **Build B-Tree**: It constructs a 5-way B-tree using the randomly generated keys in the sequence order.

3. **Search and Return Keys**: The program searches for and returns any keys in the range [N, 2*N].

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

