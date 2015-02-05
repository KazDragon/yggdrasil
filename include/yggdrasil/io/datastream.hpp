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
#ifndef YGGDRASIL_IO_DATASTREAM_HPP_
#define YGGDRASIL_IO_DATASTREAM_HPP_

#include "yggdrasil/types.hpp"
#include "yggdrasil/util/make_unique.hpp"
#include <boost/optional.hpp>
#include <memory>
#include <utility>

namespace yggdrasil { namespace io {
    
class datastream
{
public :
    //* =====================================================================
    /// \brief Constructor
    //* =====================================================================
    template <class Datastream>
    datastream(Datastream &&mdl)
      : self_(yggdrasil::util::make_unique<impl<Datastream>>(
            std::forward<Datastream>(mdl)))
    {
    }

    //* =====================================================================
    /// \brief Returns the next byte in the datastream, or no value if the 
    /// datastream was terminated.
    //* =====================================================================
    boost::optional<char> read()
    {
        return self_->read_();
    }
    
    //* =====================================================================
    /// \brief Writes a sequence of data into the datastream.
    //* =====================================================================
    void write(char const *data, u32 length)
    {
        self_->write_(data, length);
    }
private :
    //* =====================================================================
    /// \brief The concept that the datastream will implement.
    //* =====================================================================
    struct concept
    {
        //* =================================================================
        /// \brief Destructor
        //* =================================================================
        virtual ~concept(){}
    
        //* =================================================================
        /// \brief Returns the next byte in the datastream, or no value if
        /// the datastream was terminated.
        //* =================================================================
        virtual boost::optional<char> read_() = 0;

        //* =================================================================
        /// \brief Writes a sequence of data into the datastream.
        //* =================================================================
        virtual void write_(char const *data, u32 length) = 0;
    };
    
    //* =====================================================================
    /// \brief The wrapper of the datastream concept, templated around a 
    /// class that will actually provide the implementation.
    //* =====================================================================
    template <class Datastream>
    struct impl : concept
    {
        //* =================================================================
        /// \brief Constructor
        //* =================================================================
        impl(Datastream &&mdl)
          : model_(std::forward<Datastream>(mdl))
        {
        }
        
        //* =================================================================
        /// \brief Returns the next byte in the datastream, or no value if
        /// the datastream was terminated.
        //* =================================================================
        virtual boost::optional<char> read_() override
        {
            return model_.read();
        }
        
        //* =================================================================
        /// \brief Writes a sequence of data into the datastream.
        //* =================================================================
        virtual void write_(char const *data, u32 length) override
        {
            model_.write(data, length);
        }
        
        Datastream model_;
    };    
    
    std::unique_ptr<concept> self_;
};

}}


#endif
