/*=============================================================================
  Copyright (c) 2011-2014 Bolero MURAKAMI
  https://github.com/bolero-MURAKAMI/Sprout

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef SPROUT_BIT_ROTATE_HPP
#define SPROUT_BIT_ROTATE_HPP

#include <type_traits>
#include <sprout/config.hpp>
#include <sprout/bit/rotl.hpp>
#include <sprout/bit/rotr.hpp>

namespace sprout {
	//
	// left_rotate
	//
	template<typename Integral>
	inline SPROUT_CONSTEXPR typename std::enable_if<
		std::is_integral<Integral>::value,
		Integral
	>::type
	left_rotate(Integral x, int s) {
		return sprout::rotl(x, s);
	}

	//
	// right_rotate
	//
	template<typename Integral>
	inline SPROUT_CONSTEXPR typename std::enable_if<
		std::is_integral<Integral>::value,
		Integral
	>::type
	right_rotate(Integral x, int s) {
		return sprout::rotr(x, s);
	}
}	// namespace sprout

#endif	// #ifndef SPROUT_BIT_ROTATE_HPP
