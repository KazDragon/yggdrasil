// ==========================================================================
// Yggdrasil I/O Datastream
//
// Copyright (C) 2015 Matthew Chaplain, All Rights Reserved.
//
// Permission to reproduce, distribute, perform, display, and to prepare
// derivitive works from this file under the following conditions:
//
// 1. Any copy, reproduction or derivitive work of any part of this file 
//    contains this copyright notice and licence in its entirety.
//
// 2. The rights granted to you under this license automatically terminate
//    should you attempt to assert any patent claims against the licensor 
//    or contributors, which in any way restrict the ability of any party 
//    from using this software or portions thereof in any form under the
//    terms of this license.
//
// Disclaimer: THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
//             KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE 
//             WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR 
//             PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS 
//             OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR 
//             OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
//             OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
//             SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. 
// ==========================================================================
#ifndef YGGDRASIL_UTIL_MAKE_UNIQUE_HPP_
#define YGGDRASIL_UTIL_MAKE_UNIQUE_HPP_

#include <memory>

namespace yggdrasil { namespace util {

//* =========================================================================
/// \brief A function that implements C++14's make_unique in C++11, or simply
///forwards to the C++14 version, depending on what is available.
//* =========================================================================
template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    // unique_ptr<> came into existence without make_unique(), and this was
    // corrected in C++14.
    
    /* TODO: these macros also need to look at the library version for GNU.
#if (__cplusplus == 201103L)
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
#elif (__cplusplus > 201103L)
    return std::make_unique(std::forward<Args>(args)...));
#endif
    */
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

}}

#endif
