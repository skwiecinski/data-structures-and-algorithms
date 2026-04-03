# Circular Queue Implementation (C++)

A template-based Circular Queue implementation focusing on modern C++ standards, memory safety, and STL compatibility.

## Key Features
- **Circular Buffer Logic**: Optimized $O(1)$ time complexity for both `push` and `pop` operations by eliminating memory shifts.
- **RAII Memory Management**: Utilizes `std::unique_ptr<T[]>` to ensure exception safety and prevent memory leaks.
- **Rule of Five**: Fully implemented Copy/Move constructors and assignment operators for seamless resource management.
- **STL-Compliant Interface**: Follows standard library conventions (e.g., `pop()` returns `void`, `front()` provides access).
- **Advanced Optimizations**:
    - `emplace()`: In-place object construction using Variadic Templates and Perfect Forwarding.
    - `noexcept` guarantees: Move operations and `swap` are marked `noexcept` for better integration with STL containers like `std::vector`.
    - **ADL-ready `swap`**: Custom global `swap` function to support Argument Dependent Lookup.

## Technical Specifications
- **Type Safety**: Fully templated class.
- **Exception Safety**: Provides strong exception guarantees using the "Copy-and-Swap" idiom.
- **Modern C++**: Uses `explicit` constructors, `size_t` for indexing, and `std::move` semantics.

## Complexity
- **Push / Emplace**: $O(1)$
- **Pop**: $O(1)$
- **Front / Back**: $O(1)$
- **Size / Empty**: $O(1)$

## Unit Testing (GoogleTest)
Comprehensive test suite covering:
1. **Basic FIFO Flow**: Verifying correct order of elements.
2. **Circular Wrapping**: Testing index wrap-around logic when `rear < front`.
3. **Dynamic Resizing**: Ensuring data integrity during capacity expansion.
4. **Deep Copy vs Move**: Validating independent states after copy and resource theft after move.
5. **Edge Cases**: Operations on empty/full queues and custom object handling via `emplace`.

## How to Run
1. Open the `.sln` file in Visual Studio.
2. Build the solution (**Build** -> **Build Solution**).
3. Open the **Test Explorer** window (Test > Test Explorer).
4. Click **Run All** to execute the test suite.
