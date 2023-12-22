/***************************************************************************************************************
 *
 *Project:        CppTraits
 *File:           qualifier.hpp
 *Author:         Hussam Wael
 *Date:           22-12-2023
 *Description:    This file contains the definition of metafunctions that deal with qualifiers.
 *
 **************************************************************************************************************/

#ifndef __QUALIFIER_H__
#define __QUALIFIER_H__

#include "basic.hpp"

namespace traits
{
    /******************************************************************************
     * Metafunction: remove_const
     *-----------------------------------------------------------------------------
     * Description:
     *   -This metafunction removes the const qualifier from a type.
     *
     * Template Parameters:
     *   -T : The type to remove the const qualifier from.
     *
     *****************************************************************************/
    template<typename T>
    struct remove_const : type_is<T>{};

    template<typename T>
    struct remove_const<const T> : type_is<T>{};

    template<typename T>
    using remove_const_t = typename remove_const<T>::type;

    /******************************************************************************
     * Metafunction: remove_volatile
     *-----------------------------------------------------------------------------
     * Description:
     *   -This metafunction removes the volatile qualifier from a type.
     *
     * Template Parameters:
     *   -T : The type to remove the volatile qualifier from.
     *
     *****************************************************************************/
    template<typename T>
    struct remove_volatile : type_is<T>{};

    template<typename T>
    struct remove_volatile<volatile T> : type_is<T>{};

    template<typename T>
    using remove_volatile_t = typename remove_volatile<T>::type;

    /******************************************************************************
     * Metafunction: remove_cv
     *-----------------------------------------------------------------------------
     * Description:
     *   -This metafunction removes the const and volatile qualifiers from a type.
     *
     * Template Parameters:
     *   -T : The type to remove the const and volatile qualifiers from.
     *
     *****************************************************************************/
    template<typename T>
    struct remove_cv : type_is<remove_const_t<remove_volatile_t<T>>>{};

    template<typename T>
    using remove_cv_t = typename remove_cv<T>::type; 

    /******************************************************************************
     * Metafunction: add_const
     *-----------------------------------------------------------------------------
     * Description:
     *   -This metafunction adds the const qualifier to a type.
     *
     * Template Parameters:
     *   -T : The type to add the const qualifier to.
     *
     *****************************************************************************/
    template<typename T>
    struct add_const : type_is<const T>{};

    template<typename T>
    using add_const_t = typename add_const<T>::type;

    /******************************************************************************
     * Metafunction: add_volatile
     *-----------------------------------------------------------------------------
     * Description:
     *   -This metafunction adds the volatile qualifier to a type.
     *
     * Template Parameters:
     *   -T : The type to add the volatile qualifier to.
     *
     *****************************************************************************/
    template<typename T>
    struct add_volatile : type_is<volatile T>{};

    template<typename T>
    using add_volatile_t = typename add_volatile<T>::type;

    /******************************************************************************
     * Metafunction: add_cv
     *-----------------------------------------------------------------------------
     * Description:
     *   -This metafunction adds both const and volatile qualifiers to a type.
     *
     * Template Parameters:
     *   -T : The type to add the const volatile to.
     *
     *****************************************************************************/
    template<typename T>
    struct add_cv : type_is<const volatile T>{};
    
    template<typename T>
    using add_cv_t = typename add_cv<T>::type;

}

#endif // __QUALIFIER_H__
