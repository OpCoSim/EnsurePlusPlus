// MIT License
//
// Copyright (c) 2022 OpCoSim
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef ENSURE_PLUS_PLUS_HPP
#define ENSURE_PLUS_PLUS_HPP

#include <stdexcept>
#include <exception>

namespace Ensure
{
    #ifdef ENSURE_PLUS_PLUS_DISABLE_ASSERTS
    inline bool constexpr Enabled = false;
    #else
    inline bool constexpr Enabled = true;
    #endif

    /// The default exception type.
    struct EnsureException final : std::runtime_error
    {
        /// Initializes a new instance of the EnsureException type.
        /// @param message The error message.
        explicit EnsureException(char const* message)
            : std::runtime_error(message)
        {
        }
    };

    /// Throws an error based on the configured error action.
    /// @param message The message. 
    inline void Throw(char const* message)
    {
        #if defined(ENSURE_PLUS_PLUS_ON_ERROR_CUSTOM)
        ENSURE_PLUS_PLUS_ON_ERROR_CUSTOM
        #elif defined(ENSURE_PLUS_PLUS_ON_ERROR_ABORT)
        abort();
        #elif defined(ENSURE_PLUS_PLUS_ON_ERROR_TERMINATE)
        std::terminate();
        #else
        throw EnsureException(message);
        #endif
    }

    /// The root of all assertion calls. Calls the given assertion
    /// when assertions are enabled.
    /// @tparam F The type of the assertion function.
    /// @param assertion The assertion.
    template <typename F>
    inline void AssertCore(F&& assertion)
    {
        if constexpr (Enabled)
        {
            assertion();
        }
    }
}

#endif // ENSURE_PLUS_PLUS_HPP
