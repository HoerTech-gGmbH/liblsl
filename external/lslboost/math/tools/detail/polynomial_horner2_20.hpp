//  (C) Copyright John Maddock 2007.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.lslboost.org/LICENSE_1_0.txt)
//
//  This file is machine generated, do not edit by hand

// Polynomial evaluation using second order Horners rule
#ifndef BOOST_MATH_TOOLS_POLY_EVAL_20_HPP
#define BOOST_MATH_TOOLS_POLY_EVAL_20_HPP

namespace lslboost{ namespace math{ namespace tools{ namespace detail{

template <class T, class V>
inline V evaluate_polynomial_c_imp(const T*, const V&, const mpl::int_<0>*)
{
   return static_cast<V>(0);
}

template <class T, class V>
inline V evaluate_polynomial_c_imp(const T* a, const V&, const mpl::int_<1>*)
{
   return static_cast<V>(a[0]);
}

template <class T, class V>
inline V evaluate_polynomial_c_imp(const T* a, const V& x, const mpl::int_<2>*)
{
   return static_cast<V>(a[1] * x + a[0]);
}

template <class T, class V>
inline V evaluate_polynomial_c_imp(const T* a, const V& x, const mpl::int_<3>*)
{
   return static_cast<V>((a[2] * x + a[1]) * x + a[0]);
}

template <class T, class V>
inline V evaluate_polynomial_c_imp(const T* a, const V& x, const mpl::int_<4>*)
{
   return static_cast<V>(((a[3] * x + a[2]) * x + a[1]) * x + a[0]);
}

template <class T, class V>
inline V evaluate_polynomial_c_imp(const T* a, const V& x, const mpl::int_<5>*)
{
   V x2 = x * x;
   return static_cast<V>((a[4] * x2 + a[2]) * x2 + a[0] + (a[3] * x2 + a[1]) * x);
}

template <class T, class V>
inline V evaluate_polynomial_c_imp(const T* a, const V& x, const mpl::int_<6>*)
{
   V x2 = x * x;
   return static_cast<V>(((a[5] * x2 + a[3]) * x2 + a[1]) * x + (a[4] * x2 + a[2]) * x2 + a[0]);
}

template <class T, class V>
inline V evaluate_polynomial_c_imp(const T* a, const V& x, const mpl::int_<7>*)
{
   V x2 = x * x;
   return static_cast<V>(((a[6] * x2 + a[4]) * x2 + a[2]) * x2 + a[0] + ((a[5] * x2 + a[3]) * x2 + a[1]) * x);
}

template <class T, class V>
inline V evaluate_polynomial_c_imp(const T* a, const V& x, const mpl::int_<8>*)
{
   V x2 = x * x;
   return static_cast<V>((((a[7] * x2 + a[5]) * x2 + a[3]) * x2 + a[1]) * x + ((a[6] * x2 + a[4]) * x2 + a[2]) * x2 + a[0]);
}

template <class T, class V>
inline V evaluate_polynomial_c_imp(const T* a, const V& x, const mpl::int_<9>*)
{
   V x2 = x * x;
   return static_cast<V>((((a[8] * x2 + a[6]) * x2 + a[4]) * x2 + a[2]) * x2 + a[0] + (((a[7] * x2 + a[5]) * x2 + a[3]) * x2 + a[1]) * x);
}

template <class T, class V>
inline V evaluate_polynomial_c_imp(const T* a, const V& x, const mpl::int_<10>*)
{
   V x2 = x * x;
   return static_cast<V>(((((a[9] * x2 + a[7]) * x2 + a[5]) * x2 + a[3]) * x2 + a[1]) * x + (((a[8] * x2 + a[6]) * x2 + a[4]) * x2 + a[2]) * x2 + a[0]);
}

template <class T, class V>
inline V evaluate_polynomial_c_imp(const T* a, const V& x, const mpl::int_<11>*)
{
   V x2 = x * x;
   return static_cast<V>(((((a[10] * x2 + a[8]) * x2 + a[6]) * x2 + a[4]) * x2 + a[2]) * x2 + a[0] + ((((a[9] * x2 + a[7]) * x2 + a[5]) * x2 + a[3]) * x2 + a[1]) * x);
}

template <class T, class V>
inline V evaluate_polynomial_c_imp(const T* a, const V& x, const mpl::int_<12>*)
{
   V x2 = x * x;
   return static_cast<V>((((((a[11] * x2 + a[9]) * x2 + a[7]) * x2 + a[5]) * x2 + a[3]) * x2 + a[1]) * x + ((((a[10] * x2 + a[8]) * x2 + a[6]) * x2 + a[4]) * x2 + a[2]) * x2 + a[0]);
}

template <class T, class V>
inline V evaluate_polynomial_c_imp(const T* a, const V& x, const mpl::int_<13>*)
{
   V x2 = x * x;
   return static_cast<V>((((((a[12] * x2 + a[10]) * x2 + a[8]) * x2 + a[6]) * x2 + a[4]) * x2 + a[2]) * x2 + a[0] + (((((a[11] * x2 + a[9]) * x2 + a[7]) * x2 + a[5]) * x2 + a[3]) * x2 + a[1]) * x);
}

template <class T, class V>
inline V evaluate_polynomial_c_imp(const T* a, const V& x, const mpl::int_<14>*)
{
   V x2 = x * x;
   return static_cast<V>(((((((a[13] * x2 + a[11]) * x2 + a[9]) * x2 + a[7]) * x2 + a[5]) * x2 + a[3]) * x2 + a[1]) * x + (((((a[12] * x2 + a[10]) * x2 + a[8]) * x2 + a[6]) * x2 + a[4]) * x2 + a[2]) * x2 + a[0]);
}

template <class T, class V>
inline V evaluate_polynomial_c_imp(const T* a, const V& x, const mpl::int_<15>*)
{
   V x2 = x * x;
   return static_cast<V>(((((((a[14] * x2 + a[12]) * x2 + a[10]) * x2 + a[8]) * x2 + a[6]) * x2 + a[4]) * x2 + a[2]) * x2 + a[0] + ((((((a[13] * x2 + a[11]) * x2 + a[9]) * x2 + a[7]) * x2 + a[5]) * x2 + a[3]) * x2 + a[1]) * x);
}

template <class T, class V>
inline V evaluate_polynomial_c_imp(const T* a, const V& x, const mpl::int_<16>*)
{
   V x2 = x * x;
   return static_cast<V>((((((((a[15] * x2 + a[13]) * x2 + a[11]) * x2 + a[9]) * x2 + a[7]) * x2 + a[5]) * x2 + a[3]) * x2 + a[1]) * x + ((((((a[14] * x2 + a[12]) * x2 + a[10]) * x2 + a[8]) * x2 + a[6]) * x2 + a[4]) * x2 + a[2]) * x2 + a[0]);
}

template <class T, class V>
inline V evaluate_polynomial_c_imp(const T* a, const V& x, const mpl::int_<17>*)
{
   V x2 = x * x;
   return static_cast<V>((((((((a[16] * x2 + a[14]) * x2 + a[12]) * x2 + a[10]) * x2 + a[8]) * x2 + a[6]) * x2 + a[4]) * x2 + a[2]) * x2 + a[0] + (((((((a[15] * x2 + a[13]) * x2 + a[11]) * x2 + a[9]) * x2 + a[7]) * x2 + a[5]) * x2 + a[3]) * x2 + a[1]) * x);
}

template <class T, class V>
inline V evaluate_polynomial_c_imp(const T* a, const V& x, const mpl::int_<18>*)
{
   V x2 = x * x;
   return static_cast<V>(((((((((a[17] * x2 + a[15]) * x2 + a[13]) * x2 + a[11]) * x2 + a[9]) * x2 + a[7]) * x2 + a[5]) * x2 + a[3]) * x2 + a[1]) * x + (((((((a[16] * x2 + a[14]) * x2 + a[12]) * x2 + a[10]) * x2 + a[8]) * x2 + a[6]) * x2 + a[4]) * x2 + a[2]) * x2 + a[0]);
}

template <class T, class V>
inline V evaluate_polynomial_c_imp(const T* a, const V& x, const mpl::int_<19>*)
{
   V x2 = x * x;
   return static_cast<V>(((((((((a[18] * x2 + a[16]) * x2 + a[14]) * x2 + a[12]) * x2 + a[10]) * x2 + a[8]) * x2 + a[6]) * x2 + a[4]) * x2 + a[2]) * x2 + a[0] + ((((((((a[17] * x2 + a[15]) * x2 + a[13]) * x2 + a[11]) * x2 + a[9]) * x2 + a[7]) * x2 + a[5]) * x2 + a[3]) * x2 + a[1]) * x);
}

template <class T, class V>
inline V evaluate_polynomial_c_imp(const T* a, const V& x, const mpl::int_<20>*)
{
   V x2 = x * x;
   return static_cast<V>((((((((((a[19] * x2 + a[17]) * x2 + a[15]) * x2 + a[13]) * x2 + a[11]) * x2 + a[9]) * x2 + a[7]) * x2 + a[5]) * x2 + a[3]) * x2 + a[1]) * x + ((((((((a[18] * x2 + a[16]) * x2 + a[14]) * x2 + a[12]) * x2 + a[10]) * x2 + a[8]) * x2 + a[6]) * x2 + a[4]) * x2 + a[2]) * x2 + a[0]);
}


}}}} // namespaces

#endif // include guard

