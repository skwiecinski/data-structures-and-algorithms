# Stack Implementation (C++)

A minimalist, template-based Stack implementation using a dynamic array.

## Features
- **Templates**: Supports any data type (int, std::string, custom objects).
- **Dynamic Resizing**: Automatically increases array capacity when full.
- **Exception Handling**: Throws `std::out_of_range` for operations on an empty stack.
- **Operator Overloading**: Overloaded `operator<<` for easy inspection of the stack state.

## Complexity
- **Push**: O(1)
- **Pop**: O(1)
- **Peek**: O(1)
- **Empty**: O(1)

## Unit Testing (GoogleTest)
The project includes a comprehensive test suite covering:
1. Basic `Push` and `Pop` operations.
2. Top element inspection (`Peek`).
3. Memory relocation integrity during heavy data load.
4. Exception handling for empty stack access.
5. Verification of `std::string` template instantiation.

## How to Run
1. Open the `.sln` file in Visual Studio.
2. Build the solution (**Build** -> **Build Solution**).
3. Open the **Test Explorer** window (Test > Test Explorer).
4. Click **Run All** to execute the test suite.
