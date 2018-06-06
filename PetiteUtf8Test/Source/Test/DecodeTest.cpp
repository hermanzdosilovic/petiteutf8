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
#include "RandomString.hpp"

#include <PetiteUtf8.hpp>

#include <catch.hpp>

#include <cstddef>

namespace petiteutf8
{

constexpr std::size_t kNumberOfAssertions{ 10000 };
constexpr std::size_t kStringLength{ 20 };

TEST_CASE( "random decode char32_t", "decode" )
{
    for ( std::size_t i{ 0 }; i < kNumberOfAssertions; ++i )
    {
        auto const & stringPair{ randomStringPair< char32_t >( kStringLength ) };
        REQUIRE( utf8::decode< char32_t >( stringPair.second ) == stringPair.first );
    }
}

TEST_CASE( "random decode encoded char32_t", "decode" )
{
    for ( std::size_t i{ 0 }; i < kNumberOfAssertions; ++i )
    {
        auto const & stringPair{ randomStringPair< char32_t >( kStringLength ) };
        REQUIRE( utf8::decode< char32_t >( utf8::encode< char32_t >( stringPair.first ) ) == stringPair.first );
    }
}

TEST_CASE( "random decode char16_t", "decode" )
{
    for ( std::size_t i{ 0 }; i < kNumberOfAssertions; ++i )
    {
        auto const & stringPair{ randomStringPair< char16_t >( kStringLength ) };
        REQUIRE( utf8::decode< char16_t >( stringPair.second ) == stringPair.first );
    }
}

TEST_CASE( "random decode encoded char16_t", "decode" )
{
    for ( std::size_t i{ 0 }; i < kNumberOfAssertions; ++i )
    {
        auto const & stringPair{ randomStringPair< char16_t >( kStringLength ) };
        REQUIRE( utf8::decode< char16_t >( utf8::encode< char16_t >( stringPair.first ) ) == stringPair.first );
    }
}

TEST_CASE( "random decode char", "decode" )
{
    for ( std::size_t i{ 0 }; i < kNumberOfAssertions; ++i )
    {
        auto const & stringPair{ randomStringPair< char >( kStringLength ) };
        REQUIRE( utf8::decode< char >( stringPair.second ) == stringPair.first );
    }
}

TEST_CASE( "random decode encoded char", "decode" )
{
    for ( std::size_t i{ 0 }; i < kNumberOfAssertions; ++i )
    {
        auto const & stringPair{ randomStringPair< char >( kStringLength ) };
        REQUIRE( utf8::decode< char >( utf8::encode< char >( stringPair.first ) ) == stringPair.first );
    }
}

TEST_CASE( "random decode signed char", "decode" )
{
    for ( std::size_t i{ 0 }; i < kNumberOfAssertions; ++i )
    {
        auto const & stringPair{ randomStringPair< signed char >( kStringLength ) };
        REQUIRE( utf8::decode< signed char >( stringPair.second ) == stringPair.first );
    }
}

TEST_CASE( "random decode encoded signed char", "decode" )
{
    for ( std::size_t i{ 0 }; i < kNumberOfAssertions; ++i )
    {
        auto const & stringPair{ randomStringPair< signed char >( kStringLength ) };
        REQUIRE( utf8::decode< signed char >( utf8::encode< signed char >( stringPair.first ) ) == stringPair.first );
    }
}

TEST_CASE( "random decode unsigned char", "decode" )
{
    for ( std::size_t i{ 0 }; i < kNumberOfAssertions; ++i )
    {
        auto const & stringPair{ randomStringPair< unsigned char >( kStringLength ) };
        REQUIRE( utf8::decode< unsigned char >( stringPair.second ) == stringPair.first );
    }
}

TEST_CASE( "random decode encoded unsigned char", "decode" )
{
    for ( std::size_t i{ 0 }; i < kNumberOfAssertions; ++i )
    {
        auto const & stringPair{ randomStringPair< unsigned char >( kStringLength ) };
        REQUIRE( utf8::decode< unsigned char >( utf8::encode< unsigned char >( stringPair.first ) ) == stringPair.first );
    }
}

TEST_CASE( "random decode encoded wchar_t", "decode" )
{
    for ( std::size_t i{ 0 }; i < kNumberOfAssertions; ++i )
    {
        auto const & stringPair{ randomStringPair< wchar_t >( kStringLength ) };
        REQUIRE( utf8::decode< wchar_t >( utf8::encode< wchar_t >( stringPair.first ) ) == stringPair.first );
    }
}

TEST_CASE( "random decode signed wchar_t", "decode" )
{
    for ( std::size_t i{ 0 }; i < kNumberOfAssertions; ++i )
    {
        auto const & stringPair{ randomStringPair< wchar_t >( kStringLength ) };
        REQUIRE( utf8::decode< wchar_t >( stringPair.second ) == stringPair.first );
    }
}

}