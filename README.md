# petiteutf8
Small, simple and header only C++17 UTF-8 library.

## Usage
Download [`PetiteUtf8.hpp`](https://github.com/hermanzdosilovic/petiteutf8/blob/master/PetiteUtf8/Source/PetiteUtf8.hpp), place
it in your project and you are ready to go:

```cpp
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
    assert( greeting != petiteutf8::utf8::encode< char >( narrowGreeting ) ); // consequence of data loss

    return 0;
}
```

## Running tests
```
$ git clone https://github.com/hermanzdosilovic/petiteutf8.git
$ cd petiteutf8
$ git submodule init
$ git submodule update
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./PetiteUtf8Test
```

## Test dependencies
- [Catch2](https://github.com/catchorg/Catch2/blob/master/LICENSE.txt)

## Tested with
- GCC 8.1.0
