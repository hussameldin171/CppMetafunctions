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
	 * Metafunction: is_constructible
	 *-----------------------------------------------------------------------------
	 * Description:
	 *   -This metafunction checks if a type is generally constructible.
	 * Template Parameters:
	 *   -T : The type to check whether it is constructible or not.
   *   -Args : The arguments to pass to the constructor.
	 *
	 *****************************************************************************/
    template<typename , typename = void , typename ...>
    struct is_constructible_helper : false_type{};

    template<typename T , typename ...Args>
    using is_constructible_property = decltype(T{std::declval<Args>()...});

    template<typename T , typename ...Args>
    struct is_constructible_helper<T , void_t< is_constructible_property<T,Args...>>, Args...> : true_type{};

    template<typename T , typename ...Args>
    struct is_constructible : is_constructible_helper<T,void,Args...>{};
    
    template<typename T , typename ...Args>
    static constexpr bool is_constructible_v = is_constructible<T,Args...>::value;

  /******************************************************************************
	 * Metafunction: is_default_constructible
	 *-----------------------------------------------------------------------------
	 * Description:
	 *   -This metafunction checks if a type is default constructible.
	 * Template Parameters:
	 *   -T : The type to check whether it is default constructible or not.
	 *
	 *****************************************************************************/
    template<typename T>
    struct is_default_constructible : is_constructible<T>{};

    template<typename T>
    static constexpr bool is_default_constructible_v = is_default_constructible<T>::value;

   /******************************************************************************
	 * Metafunction: is_copy_constructible
	 *-----------------------------------------------------------------------------
	 * Description:
	 *   -This metafunction checks if a type is copy constructible.
	 * Template Parameters:
	 *   -T : The type to check whether it is copy constructible or not.
	 *
	 *****************************************************************************/
    template<typename T>
    struct is_copy_constructible : is_constructible<T , const T&>{};

    template<typename T>
    static constexpr bool is_copy_constructible_v = is_copy_constructible<T>::value;

   /******************************************************************************
	 * Metafunction: is_move_constructible
	 *-----------------------------------------------------------------------------
	 * Description:
	 *   -This metafunction checks if a type is move constructible.
	 * Template Parameters:
	 *   -T : The type to check whether it is move constructible or not.
	 *
	 *****************************************************************************/
    template<typename T>
    struct is_move_constructible : is_constructible<T , T&&>{};

    template<typename T>
    static constexpr bool is_move_constructible_v = is_move_constructible<T>::value;



}



#endif // __CLASS_PROPERTIES_H__