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

    /******************************************************************************
	 * Metafunction: And
	 *-----------------------------------------------------------------------------
	 * Description:
	 *   -This variadic metafunction returns true if all of its arguments are true.
     *   -It must be used with at least one argument.
	 * Template Parameters:
     *   - cond         : The first boolean argument.
	 *   -...conditions : The rest of the boolean arguments.
	 *****************************************************************************/

    template<bool cond , bool... conditions>
    struct And;

    template<bool condition>
    struct And<condition> : bool_constant<condition>{};

    template<bool cond1 , bool cond2 , bool ...conditions>
    struct And<cond1 , cond2, conditions...> : And< cond1&&cond2 , conditions...>{};

    template<bool cond , bool... conditions>
    static constexpr bool And_v = And<cond,conditions...>::value;

    /******************************************************************************
	 * Metafunction: Or
	 *-----------------------------------------------------------------------------
	 * Description:
	 *   -This metafunction returns true if at least one of its arguments is true.
     *   -It must be used with at least one argument.
	 * Template Parameters:
     *   - cond         : The first boolean argument.
	 *   -...conditions : The rest of the boolean arguments.
	 *****************************************************************************/

    template<bool cond , bool... conditions>
    struct Or;

    template<bool condition>
    struct Or<condition> : bool_constant<condition>{};

    template<bool cond1 , bool cond2 , bool ...conditions>
    struct Or<cond1 , cond2, conditions...> : Or< cond1||cond2 , conditions...>{};

    template<bool cond , bool... conditions>
    static constexpr bool Or_v = Or<cond,conditions...>::value;

    /******************************************************************************
	 * Metafunction: Not
	 *-----------------------------------------------------------------------------
	 * Description:
	 *   -This metafunction returns the logical invert of a boolean value.
	 *
	 * Template Parameters:
	 *   -condition : The boolean value to invert.
     * 
	 *****************************************************************************/
    template<bool condition>
    struct Not : bool_constant<!condition>{};

    template<bool condition>
    static constexpr bool Not_v = Not<condition>::value;

    
}  
#endif // __LOGIC _H__