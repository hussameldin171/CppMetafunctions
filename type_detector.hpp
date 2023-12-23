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

    /******************************************************************************
	 * Metafunction: is_pointer
	 *-----------------------------------------------------------------------------
	 * Description:
	 *   -This metafunction returns true if a given type is a pointer.
     * 
	 * Template Parameters:
	 *   -T : The type to check whether it's a pointer type or not.
	 *
	 *****************************************************************************/
    
    template<typename T>
    struct is_pointer_helper : false_type{};
    
    template<typename T>
    struct is_pointer_helper<T *> : true_type{};

    template<typename T>
    struct is_pointer : is_pointer_helper<remove_cv_t<T>>{};

    template<typename T>
    static constexpr bool is_pointer_v = is_pointer<T>::value;

    /******************************************************************************
	 * Metafunction: is_integral
	 *-----------------------------------------------------------------------------
	 * Description:
	 *   -This metafunction returns true if a given type is integral.
     * 
	 * Template Parameters:
	 *   -T : The type to check whether it's integral or not.
	 *
	 *****************************************************************************/
    template<typename T>
    struct is_integral: is_in_pack<remove_cv_t<T>,
                                bool,
                                char,
                                char16_t,
                                char32_t,
                                wchar_t,
                                unsigned char,
                                short,
                                unsigned short,
                                int,
                                unsigned int,
                                long,
                                unsigned long,
                                long long,
                                unsigned long long>{};



    template<typename T>
    static constexpr bool is_integral_v = is_integral<T>::value;

    /******************************************************************************
	 * Metafunction: is_floating_point
	 *-----------------------------------------------------------------------------
	 * Description:
	 *   -This metafunction returns true if a given type is float or double.
     * 
	 * Template Parameters:
	 *   -T : The type to check whether it's floating point or not.
	 *
	 *****************************************************************************/
    template<typename T>
    struct is_floating_point : is_in_pack< remove_cv_t<T>,
                                           float,
                                           double,
                                           long double
                                           >{};
    
    template<typename T>
    static constexpr bool is_floating_point_v = is_floating_point<T>::value;

}

#endif // __TYPE_DETECTOR_H__