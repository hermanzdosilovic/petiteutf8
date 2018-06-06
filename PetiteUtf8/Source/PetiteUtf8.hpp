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
    std::string utf8;

    for ( CharType const & c1 : s )
    {
        char32_t c{ static_cast< char32_t >( c1 ) };
        if ( c < 0x80ul )
        {
            utf8 += static_cast< char >( c );
        }
        else if ( c < 0x800ul )
        {
            utf8 += static_cast< char >( 0xC0ul | ( ( c >> 6ul ) & 0x1Ful ) );
            utf8 += static_cast< char >( 0x80ul | ( c & 0x3Ful ) );
        }
        else if ( c < 0x10000ul )
        {
            utf8 += static_cast< char >( 0xE0ul | ( ( c >> 12ul ) & 0xFul  ) );
            utf8 += static_cast< char >( 0x80ul | ( ( c >> 6ul  ) & 0x3Ful ) );
            utf8 += static_cast< char >( 0x80ul | ( c & 0x3Ful ) );
        }
        else
        {
            utf8 += static_cast< char >( 0xF0ul | ( ( c >> 18ul ) & 0x7ul  ) );
            utf8 += static_cast< char >( 0x80ul | ( ( c >> 12ul ) & 0x3Ful ) );
            utf8 += static_cast< char >( 0x80ul | ( ( c >> 6ul  ) & 0x3Ful ) );
            utf8 += static_cast< char >( 0x80ul | ( c & 0x3Ful ) );
        }
    }

    return utf8;
}

template< typename CharType >
std::basic_string< CharType > decode( std::string const & s )
{
    std::basic_string< CharType > decoded;

    for ( std::size_t i{ 0 }; i < s.length(); )
    {
        char32_t c{ static_cast< unsigned char >( s[ i ] ) };
        if ( ( c & 0x80ul ) == 0x0ul )
        {
            decoded += static_cast< CharType >( c );
            i += 1;
        }
        else if ( ( c & 0xE0ul ) == 0xC0ul )
        {
            decoded += static_cast< CharType >
            (
                ( ( c & 0x1Ful ) << 6ul ) |
                ( static_cast< unsigned char >( s[ i + 1 ] ) & 0x3Ful )
            );
            i += 2;
        }
        else if ( ( c & 0xF0ul ) == 0xE0ul )
        {
            decoded += static_cast< CharType >
            (
                ( ( c & 0xFul ) << 12ul ) |
                ( ( static_cast< unsigned char >( s[ i + 1 ] ) & 0x3Ful ) << 6ul ) |
                ( ( static_cast< unsigned char >( s[ i + 2 ] ) & 0x3Ful ) )
            );
            i += 3;
        }
        else
        {
            decoded += static_cast< CharType >
            (
                ( ( c & 0x7ul ) << 18ul ) |
                ( ( static_cast< unsigned char >( s[ i + 1 ] ) & 0x3Ful ) << 12ul ) |
                ( ( static_cast< unsigned char >( s[ i + 2 ] ) & 0x3Ful ) << 6ul  ) |
                ( ( static_cast< unsigned char >( s[ i + 3 ] ) & 0x3Ful ) )
            );
            i += 4;
        }
    }

    return decoded;
}

}
