/***********************************************************************************************************************************
 *
 *Project:        CppTraits
 *File:           type_detector.hpp
 *Author:         Hussam Wael
 *Date:           22-12-2023
 *Description:    This file contains the definition of metafunctions that check for types (Ex: is_integral, is_floating_point,...).
 *
 ***********************************************************************************************************************************/

#ifndef __TYPE_DETECTOR_H__
#define __TYPE_DETECTOR_H__

#include "logic.hpp"

namespace traits
{       
    /******************************************************************************
	 * Metafunction: is_signed
	 *-----------------------------------------------------------------------------
	 * Description:
	 *   -This metafunction returns true if a given type is signed.
     *   -If the type is does not have a sign, it will return false using SFINAE.
     * 
	 * Template Parameters:
	 *   -T : The type to check whether it's signed or not.
	 *
	 *****************************************************************************/
    template<typename T , typename = void>
    struct is_signed : false_type{};

    template<typename T>
    using sign_type = decltype(T{-1} < T{0});

    template<typename T>
    static constexpr bool sign_type_v = (T{-1} < T{0});

    template<typename T>
    struct is_signed<T , void_t<sign_type<T>>> : bool_constant<sign_type_v<T>>{};

    template<typename T , typename Void = void>
    static constexpr bool is_signed_v = is_signed<T,Void>::value;

}

#endif // __TYPE_DETECTOR_H__