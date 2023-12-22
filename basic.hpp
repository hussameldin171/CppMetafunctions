/***************************************************************************************************************
 *
 *Project:        CppTraits
 *File:           basic.hpp
 *Author:         Hussam Wael
 *Date:           22-12-2023
 *Description:    This file contains the definition of the core types used in implementing other metafunctions.
 *
 **************************************************************************************************************/

#ifndef __BASIC_H__
#define __BASIC_H__

namespace traits
{
	/******************************************************************************
	 * Metafunction: integral_constant
	 *-----------------------------------------------------------------------------
	 * Description:
	 *   -This metafunction serves as a wrapper for an integral constant.
	 *   -It serves as a base class for value returning metafunctions.  
	 *
	 * Template Parameters:
	 *   -T : The integral type used.
	 *   -v : The value of the integral constant.
	 *
	 *****************************************************************************/

	template <typename T, T v>
		struct integral_constant
		{       
			static constexpr T value = v;

			using value_type = T;

			/* Description: 
             * This operator allows casting of integral constant to the type being held.
             */
			constexpr operator value_type() const noexcept
			{
				return value;
			}
            

			/* Description: 
             * A function-call operator that returns the value being held by the integral constant
             */
			constexpr value_type operator()() const noexcept
			{
				return value;
			}
		};

	/******************************************************************************
	 * Metafunction: bool_constant
	 *-----------------------------------------------------------------------------
	 * Description:
	 *   -This metafunction serves as a wrapper for an bool constant.
	 *   -It serves as a base class for true/false returning metafunctions.
	 *    (is_same ,is_class, etc...).
	 *        
	 *
	 * Template Parameters:
	 *  -value : The boolean value used.
	 *
	 *****************************************************************************/
	template <bool value>
	using bool_constant = integral_constant<bool, value> ;

    /******************************************************************************
	 * Metafunction: true_type
	 *-----------------------------------------------------------------------------
	 * Description:
	 *   -This metafunction serves as a wrapper for the value of true.
	 *   -It serves as a base class for true returning metafunctions.
	 *****************************************************************************/
	using true_type = bool_constant<true> ;

    /******************************************************************************
	 * Metafunction: false_type
	 *-----------------------------------------------------------------------------
	 * Description:
	 *   -This metafunction serves as a wrapper for the value of false.
	 *   -It serves as a base class for false returning metafunctions.
	 *****************************************************************************/
	using false_type = bool_constant<false> ;

	/******************************************************************************
	 * Metafunction: type_is
	 *-----------------------------------------------------------------------------
	 * Description:
	 *   -This metafunction serves as a wrapper for a given type.
	 *   -It serves as a base class for type returning metafunctions.
	 *    (remove_const, decay, etc...).
	 *        
	 *
	 * Template Parameters:
	 *  -T : The type to wrap.
	 *
	 *****************************************************************************/
	template <typename T>
		struct type_is
		{
			using type = T;
		};

	/******************************************************************************
	 * Metafunction: void_t
	 *-----------------------------------------------------------------------------
	 * Description:
	 *   -This metafunction maps any sequence of types to void.
     *   -It is used alongside SFINAE to create more sophisticated metafunctions.
     *   (is_copy_constructible, is_incrementable, etc...)  
	 *
	 *****************************************************************************/
	template <typename...>
		using void_t = void;

}


#endif	// __BASIC_H__