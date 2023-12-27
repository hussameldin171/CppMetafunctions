/***************************************************************************************************************
 *
 *Project:        CppTraits
 *File:           class_properties.hpp
 *Author:         Hussam Wael
 *Date:           26-12-2023
 *Description:    This file contains the definition of metafunctions that detect properties that a class might have.
 *
 **************************************************************************************************************/

#ifndef __CLASS_PROPERTIES_H__
#define __CLASS_PROPERTIES_H__

#include "basic.hpp"
#include "logic.hpp"
namespace traits
{
    /******************************************************************************
	 * Metafunction: is_default_constructible
	 *-----------------------------------------------------------------------------
	 * Description:
	 *   -This metafunction checks if a type is default constructible.
	 * Template Parameters:
	 *   -T : The type to check whether it is default constructible or not.
	 *
	 *****************************************************************************/
    template<typename T, typename = void>
    struct is_default_constructible : false_type{};

    template<typename T>
    using default_constructor_property = decltype(T{});   

    template<typename T>
    struct is_default_constructible<T, void_t<default_constructor_property<T>>> : true_type{};//is_same<default_constructor_property<T> , T>{};

    template<typename T , typename Void = void>
    static constexpr bool is_default_constructible_v = is_default_constructible<T,Void>::value;

    /******************************************************************************
	 * Metafunction: is_constructible
	 *-----------------------------------------------------------------------------
	 * Description:
	 *   -This metafunction checks if a type is generally constructible.
	 * Template Parameters:
	 *   -T : The type to check whether it is constructible or not.
	 *
	 *****************************************************************************/
    template<typename , typename = void , typename ...>
    struct is_constructible : false_type{};

    template<typename T , typename ...Args>
    using is_constructible_property = decltype(T{std::declval<Args>()...});

    template<typename T , typename ...Args>
    struct is_constructible<T , void_t< is_constructible_property<T,Args...>>, Args...> : true_type{};

    template<typename T , typename Void = void , typename ...Args>
    static constexpr bool is_constructible_v = is_constructible<T,Void,Args...>::value;


}



#endif // __CLASS_PROPERTIES_H__