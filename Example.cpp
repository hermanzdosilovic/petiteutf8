#include <PetiteUtf8.hpp>

#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::string const greeting{ u8"hello, 世界" };
    assert( greeting.length() == 13 ); // wrong length

    std::u16string const & decodedGreeting{ petiteutf8::utf8::decode( greeting ) };
    assert( decodedGreeting.length() == 9 ); // correct length
    assert( greeting == petiteutf8::utf8::encode( decodedGreeting ) );

    std::u32string const & widerGreeting{ petiteutf8::utf8::decode< char32_t >( greeting ) };
    assert( widerGreeting.length() == 9 );
    assert( greeting == petiteutf8::utf8::encode< char32_t >( widerGreeting ) );

    std::string const & narrowGreeting{ petiteutf8::utf8::decode< char >( greeting ) }; // data loss for 世 and 界
    assert( narrowGreeting.length() == 9 );
    assert( greeting != petiteutf8::utf8::encode< char >( narrowGreeting ) ); // data loss consequence

    return 0;
}