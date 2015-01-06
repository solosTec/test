//  (C) Copyright Gennadiy Rozental 2011-2014.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.

//[example_code
#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>
#include <sstream>

namespace bdata = boost::unit_test::data;

// Generates a Fibonacci sequence
std::vector<float> fibonacci() {
  std::vector<float> ret(8);
  ret[0] = 0;
  ret[1] = 1;
  
  for(std::size_t s(2); s < ret.size(); s++)
  {
    ret[s] = ret[s-1] + ret[s-2];
  }
  return ret;
}

BOOST_DATA_TEST_CASE( 
  test_case_snippet_1, 
  bdata::make(fibonacci()),
  array_element)
{
  std::cout << "test 1: " 
    << array_element 
    << std::endl;
  BOOST_CHECK(array_element <= 13);
}

typedef std::pair<const std::string, float> pair_map_t;
BOOST_TEST_DONT_PRINT_LOG_VALUE( pair_map_t );

// Generates a map from a vector
std::map<std::string, float> vect_2_str(std::vector<float> v) 
{
  std::map<std::string, float> out;
  for(std::size_t s(0); s < v.size(); s++)
  {
    std::ostringstream o;
    o << v[s];
    out[o.str()] = v[s];
  }
  return out;
}

BOOST_DATA_TEST_CASE( 
  test_case_snippet_2, 
  bdata::make(vect_2_str(fibonacci())),
  array_element)
{
  std::cout << "test 2: \"" 
    << array_element.first << "\", "
    << array_element.second
    << std::endl;
  BOOST_CHECK(array_element.second <= 13);
}
//]