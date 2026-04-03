# Stack Implementation (C++)

A template-based Stack implementation using a dynamic array with **RAII** and **Move Semantics**.

## Key Features
- **RAII & Memory Safety**: Uses `std::unique_ptr<T[]>` for automatic memory management, eliminating manual `delete[]` and memory leaks.
- **Rule of Five**: Fully implemented Copy/Move Constructors and Assignment Operators (Copy-and-Swap idiom).
- **Modern Optimizations**:
    - `push(T&&)`: Move version to efficiently handle temporary objects.
    - `emplace(Args&&...)`: Construct elements directly in stack memory.
- **STL Compatibility**: Follows standard library conventions (separate `pop()` and `peek()`).
- **Robust Indexing**: Uses `std::ptrdiff_t` for index safety and `size_t` for capacity management.

## Complexity
- **Push / Emplace**: $O(1)$ (amortized)
- **Pop**: $O(1)$
- **Peek**: $O(1)$
- **Size / Empty**: $O(1)$

## Unit Testing (GoogleTest)
The test suite validates:
1. **LIFO Integrity**: Correct order of elements.
2. **Deep Copying**: Memory isolation between copied stacks.
3. **Move Semantics**: Resource theft and state reset of moved objects.
4. **Exception Safety**: Bounds checking on empty stack access.

## How to Run
1. Open the `.sln` file in Visual Studio.
2. Build the solution (**Build** -> **Build Solution**).
3. Open the **Test Explorer** window (Test > Test Explorer).
4. Click **Run All** to execute the test suite.
