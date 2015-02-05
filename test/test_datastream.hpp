// ==========================================================================
// Test Datastream
//
// Copyright (C) <Year> <Author>, All Rights Reserved.
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
#ifndef TEST_DATASTREAM_HPP_
#define TEST_DATASTREAM_HPP_

#include "yggdrasil/types.hpp"
#include <stdexcept>
#include <string>
#include <vector>

//* =========================================================================
/// \brief A fake datastream should not block during testing, otherwise the
/// testing blocks.  Therefore, if we detect a blocking situation, we throw a
/// blocking error instead.
//* =========================================================================
class blocking_error
    : public std::runtime_error
{
public :
    blocking_error()
        : std::runtime_error("Blocked!")
    {
    }
};

class test_datastream
{
public :
    char read();
    void write(char const *data, yggdrasil::u32 length);
    
    void write_data_to_read(std::string const &text);
    std::string read_data_written();
    
private :
    std::string data_to_read_;
    std::string data_written_;
};

#endif
