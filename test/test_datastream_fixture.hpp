#include "CppSpec/CppSpec.h"
#include "test_datastream.hpp"
#include "yggdrasil/io/datastream.hpp"

class EmptyTestDatastreamSpec 
  : public CppSpec::Specification<yggdrasil::io::datastream, EmptyTestDatastreamSpec>
{
public :
    EmptyTestDatastreamSpec()
    {
        REGISTER_BEHAVIOUR(EmptyTestDatastreamSpec, read_should_throw);
    }
    
    yggdrasil::io::datastream *createContext()
    {
        yggdrasil::io::datastream *datastream = 
            new yggdrasil::io::datastream(test_datastream());
            
        return datastream;
    }
    
    void read_should_throw()
    {
        specify(
            invoking(&yggdrasil::io::datastream::read)
            .should.raise.exception<blocking_error>());
    }
    
} emptyDatastreamSpec;