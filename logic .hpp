/***************************************************************************************************************
 *
 *Project:        CppTraits
 *File:           logic.hpp
 *Author:         Hussam Wael
 *Date:           22-12-2023
 *Description:    This file contains the definition of logical metafunctions.
 *
 **************************************************************************************************************/

#ifndef __LOGIC_H__
#define __LOGIC_H__

#include "basic.hpp"

namespace traits
{
    /******************************************************************************
	 * Metafunction: is_same
	 *-----------------------------------------------------------------------------
	 * Description:
	 *   -This metafunction checks if two types are the same.
	 *
	 * Template Parameters:
	 *   -T : The first type.
     *   -U : The second type.
	 *
	 *****************************************************************************/
    template<typename T , typename U>
    struct is_same : false_type{};

    template<typename T>
    struct is_same<T,T> : true_type{};

    template<typename T , typename U>
    static constexpr bool is_same_v = is_same<T,U>::value;

    /******************************************************************************
	 * Metafunction: if_type
	 *-----------------------------------------------------------------------------
	 * Description:
	 *   -This metafunction returns one of two types based on a boolean condition.
	 *
	 * Template Parameters:
	 *   -B : The boolean condition.
     *   -T : The type to return if B is true.
     *   -U : The type to return if B is false.
	 *
	 *****************************************************************************/
    template<bool B , typename T , typename U>
    struct if_type : type_is<U>{};

    template<typename T, typename U>
    struct if_type<true,T,U> : type_is<T>{};

    template<bool B , typename T , typename U>
    using if_type_t = typename if_type<B,T,U>::type;


}

#endif // __LOGIC _H__