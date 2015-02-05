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
#include "test_datastream.hpp"
#include <algorithm>

char test_datastream::read()
{
    if (data_to_read_.empty())
    {
        throw blocking_error();
    }
    
    char value = data_to_read_[0];
    
    data_to_read_.erase(0, 1);
    
    return value;
}

void test_datastream::write(const char *data, yggdrasil::u32 length)
{
    std::copy(
        data, data + length, std::back_inserter(data_written_));
}

std::string test_datastream::read_data_written()
{
    std::string result;
    result.swap(data_written_);
    return result;
}

void test_datastream::write_data_to_read(const std::string &text)
{
    data_to_read_ += text;
}
