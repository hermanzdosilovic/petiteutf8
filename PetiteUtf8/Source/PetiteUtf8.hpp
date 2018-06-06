/**
 *
 * MIT License
 *
 * Copyright (c) 2018 Herman Zvonimir Došilović
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#pragma once

#include <string>
#include <cstdint>

namespace petiteutf8::utf8
{

template< typename CharType = char16_t >
std::string encode( std::basic_string< CharType > const & s )
{
    std::size_t capacity{ 0 };
    for ( CharType const & c : s )
    {
        if ( c < 0x80 )
        {
            capacity += 1;
        }
        else if ( c < 0x800 )
        {
            capacity += 2;
        }
        else if ( c < 0x10000 )
        {
            capacity += 3;
        }
        else
        {
            capacity += 4;
        }
    }

    std::string utf8;
    utf8.reserve( capacity );

    for ( CharType const & c : s )
    {
        if ( c < 0x80 )
        {
            utf8 += static_cast< char >( c );
        }
        else if ( c < 0x800 )
        {
            utf8 += static_cast< char >( 0xC0 | ( ( c >> 6 ) & 0x1F ) );
            utf8 += static_cast< char >( 0x80 | ( c & 0x3F ) );
        }
        else if ( c < 0x10000 )
        {
            utf8 += static_cast< char >( 0xE0 | ( ( c >> 12 ) & 0xF  ) );
            utf8 += static_cast< char >( 0x80 | ( ( c >> 6  ) & 0x3F ) );
            utf8 += static_cast< char >( 0x80 | ( c & 0x3F ) );
        }
        else
        {
            utf8 += static_cast< char >( 0xF0 | ( ( c >> 18 ) & 0x7  ) );
            utf8 += static_cast< char >( 0x80 | ( ( c >> 12 ) & 0x3F ) );
            utf8 += static_cast< char >( 0x80 | ( ( c >> 6  ) & 0x3F ) );
            utf8 += static_cast< char >( 0x80 | ( c & 0x3F ) );
        }
    }

    return utf8;
}

template< typename CharType >
std::basic_string< CharType > decode( std::string const & s )
{
    std::size_t capacity{ 0 };
    for ( std::size_t i{ 0 }; i < s.length(); ++capacity )
    {
        auto c{ static_cast< CharType >( s[ i ] ) };
        if ( (c & 0x80 ) == 0x0 )
        {
            i += 1;
        }
        else if ( ( c & 0xE0 ) == 0xC0 )
        {
            i += 2;
        }
        else if ( ( c & 0xF0 ) == 0xE0 )
        {
            i += 3;
        }
        else
        {
            i += 4;
        }
    }

    std::basic_string< CharType > decoded;
    decoded.reserve( capacity );

    for ( std::size_t i{ 0 }; i < s.length(); )
    {
        auto c{ static_cast< CharType >( s[ i ] ) };
        if ( ( c & 0x80 ) == 0x0 )
        {
            decoded += c;
            i += 1;
        }
        else if ( ( c & 0xE0 ) == 0xC0 )
        {
            decoded += ( ( c & 0x1F ) << 6 ) |
                       ( static_cast< CharType >( s[ i + 1 ] ) & 0x3F );
            i += 2;
        }
        else if ( ( c & 0xF0 ) == 0xE0 )
        {
            decoded += ( ( c & 0xF ) << 12 ) |
                       ( ( static_cast< CharType >( s[ i + 1 ] ) & 0x3F ) << 6 ) |
                       ( ( static_cast< CharType >( s[ i + 2 ] ) & 0x3F )      );
            i += 3;
        }
        else
        {
            decoded += ( ( c & 0x7 ) << 18 ) |
                       ( ( static_cast< CharType >( s[ i + 1 ] ) & 0x3F ) << 12 ) |
                       ( ( static_cast< CharType >( s[ i + 2 ] ) & 0x3F ) << 6  ) |
                       ( ( static_cast< CharType >( s[ i + 3 ] ) & 0x3F )       );
            i += 4;
        }
    }

    return decoded;
}

}
