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
#include "Unicode.hpp"

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iterator>
#include <limits>
#include <random>
#include <sstream>
#include <string>
#include <utility>

namespace petiteutf8
{

template< typename CharType = char16_t >
std::pair< std::basic_string< CharType >, std::string > randomStringPair( std::size_t const len )
{
    static std::random_device randomDevice;
    static std::mt19937       generator{ randomDevice() };

    auto const maxValue{ static_cast< std::uint32_t >( std::numeric_limits< CharType >::max() ) };
    auto const & last
    {
        std::upper_bound
        (
            std::begin( unicode::code_points ),
            std::end  ( unicode::code_points ),
            maxValue
        )
    };

    assert( last != std::begin( unicode::code_points ) );

    auto const & distance
    {
        static_cast< unsigned int >
        (
            std::distance
            (
                std::begin( unicode::code_points ),
                std::prev ( last )
            )
        )
    };

    std::uniform_int_distribution< unsigned int > distribution( 0, distance );

    std::basic_string< CharType > fixed;
    std::string                   utf8;

    for ( std::size_t i{ 0 }; i < len; ++i )
    {
        auto const index{ distribution( generator ) };
        char32_t const code_point{ unicode::code_points[ index ] };

        assert( code_point <= maxValue );

        fixed += static_cast< CharType >( code_point );
        utf8  += unicode::utf8_table.find( code_point )->second;
    }

    return { fixed, utf8 };
}

}
