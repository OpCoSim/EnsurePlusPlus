# Ensure++

![version](https://img.shields.io/badge/Version-0.1-blue)
![license](https://img.shields.io/badge/License-MIT-blue)
![c++](https://img.shields.io/badge/C++-20-blue)

Ensure++ is a configurable, header only C++20 assertion library.

## Getting Started

To use Ensure++, simply include the single header `EnsurePlusPlus.hpp` from the `include` directory.

### Assertion Error Configuration

By default, Ensure++ will throw an `EnsureException` if an assertion is not true.
To configure this behaviour, refer to the table of macros and their effects below.

| Macro | Description |
| ===== | =========== |
| `ENSURE_PLUS_PLUS_ON_ERROR_ABORT` | Calls `abort()` when an assertion fails. |
| `ENSURE_PLUS_PLUS_ON_ERROR_TERMINATE` | Calls `std::terminate()` when an assertion fails. |
| `ENSURE_PLUS_PLUS_ON_ERROR_CUSTOM` | Calls the value of this macro when an assertion fails. Use the `message` variable to access the error message. |
