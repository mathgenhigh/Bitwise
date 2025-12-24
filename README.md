# Bitwise

This repository provides a C library for performing and visualizing various bitwise operations and number system conversions. It is designed to be a learning tool, printing the binary representations of numbers before and after each operation.

## Features

*   **Bitwise Operations**:
    *   `NOT`
    *   `AND`
    *   `OR`
    *   `XOR`
    *   Arithmetic `Left Shift`
    *   Arithmetic `Right Shift`
*   **Number System Conversions**:
    *   Decimal to Binary
    *   Decimal to Hexadecimal
    *   Binary to Decimal
    *   Hexadecimal to Decimal

## Getting Started

### Prerequisites

*   A C compiler, such as `gcc`.
*   Permissions to write to `/usr/local/lib` and `/usr/local/include` for library installation (`sudo`).

### Installation and Building

This project can be built as a shared library and an executable that links against it.

1.  Clone the repository:
    ```bash
    git clone https://github.com/mathgenhigh/Bitwise.git
    cd Bitwise
    ```

2.  Run the `make_lib.sh` script. This script will:
    *   Compile the source files (`bitwise.c`, `conversions.c`) into object files.
    *   Create a shared library named `libbitwise_utils.so`.
    *   Install the library and its header files into system directories (`/usr/local/lib` and `/usr/local/include`).
    *   Update the dynamic linker cache.
    *   Compile `main.c` and link it against the newly installed library, creating an executable named `res`.

    ```bash
    chmod +x scripts/make_lib.sh
    ./scripts/make_lib.sh
    ```

### Running the Example

After running the installation script, you can run the example executable:

```bash
./src/res
```

This will execute the `main.c` program, which demonstrates the various bitwise functions using sample numbers.

Alternatively, the `run.sh` script can be used to re-compile and run the `main.c` file, assuming the shared library is already installed.

```bash
chmod +x scripts/run.sh
./scripts/run.sh
```