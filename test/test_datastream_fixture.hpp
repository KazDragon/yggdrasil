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
        REGISTER_BEHAVIOUR(EmptyTestDatastreamSpec, write_should_store_data);
    }
    
    yggdrasil::io::datastream *createContext()
    {
        return new yggdrasil::io::datastream(stream_);
    }
    
    void read_should_throw()
    {
        specify(
            invoking(&yggdrasil::io::datastream::read)
            .should.raise.exception<blocking_error>());
    }
    
    void write_should_store_data()
    {
        auto data = std::vector<char>{'a', 'b', 'c'};
        context().write(data);
        
        specify(stream_.read_data_written(), should.equal(data));
        specify(stream_.read_data_written(), should.equal(std::vector<char>{}));
    }
    
private :
    test_datastream stream_;
} emptyDatastreamSpec;

class TestDatastreamWithDataToReadSpec
  : public CppSpec::Specification<yggdrasil::io::datastream, TestDatastreamWithDataToReadSpec>
{
public :
    TestDatastreamWithDataToReadSpec()
    {
        REGISTER_BEHAVIOUR(TestDatastreamWithDataToReadSpec, read_reads_data);
    }
    
    yggdrasil::io::datastream *createContext()
    {
        stream_.write_data_to_read({'a', 'b', 'c'});
        return new yggdrasil::io::datastream(stream_);
    }
    
    void read_reads_data()
    {
        specify(*context().read(), should.equal('a'));
        specify(*context().read(), should.equal('b'));
        specify(*context().read(), should.equal('c'));
        specify(
            invoking(&yggdrasil::io::datastream::read)
            .should.raise.exception<blocking_error>());
    }
    
private :
    test_datastream stream_;
} testDatastreamWithDataSpec;