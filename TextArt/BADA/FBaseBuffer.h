/* $Change: 1142016 $ */
//
// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.
 
// This software contains confidential and proprietary information 
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such 
// Confidential Information and shall use the software only in accordance with 
// the terms of the license agreement the user entered into with Samsung.
//
/** 
 * @file		FBaseBuffer.h 
 * @brief		This is the header file for the %Buffer class.
 *
 * This header file contains declarations of the %Buffer<Type> classes.
 */

#ifndef _FBASE_BUFFER_H_
#define _FBASE_BUFFER_H_

// Includes
#include "FBaseBufferBase.h"
#include "FBaseResult.h"

#include "string.h"

namespace Osp { namespace Base {

// Forward declaration
class ByteBuffer;

/**
 * @class	Buffer
 * @brief	This class represents a linear finite sequence of elements of the same type.
 * @since	1.0
 *
 * The %Buffer class represents a linear finite sequence of elements of the same type.
 * It is a means of defining an aggregation of the same type of objects, similar to an array.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/buffer.htm">Buffer</a>.
 *
  * @see		Osp::Base::BufferBase
 *
 * The following example demonstrates how to create and initialize a %Buffer instance. 
 *
 * @code
 *	
 *	#include <FBase.h>
 *
 *	using namespace Osp::Base;
 *	
 *	void
 *	MyClass::BufferSample(void)
 *	{
 *		// Set the buffer capacity to 1024
 *		const int BUFFER_SIZE_MAX = 1024;
 *
 *		// Initialize intBuf with capacity
 *		IntBuffer intBuf;
 *		intBuf.Construct(BUFFER_SIZE_MAX);
 *
 *
 *		int intArray[] = {0,1,2,3,4,5,6,7,8,9};
 *	
 *		// Copy all values from intArray to intBuffer instance
 *		// position = 10 (num of element copied)
 *		intBuf.SetArray(intArray, 0, (sizeof(intArray)/sizeof(int))); 
 *	
 *
 *		// Flip the buffer: The limit is set to the current position and
 *		// then the position is set to zero
 *		intBuf.Flip(); // position = 0, limit = 10
 *	
 *
 *		// Get the number of elements between the current position and the limit
 *		int remaining = intBuf.GetRemaining();
 *	
 *		// Initialize doubleBuf with capacity(10) using Construct() method
 *		DoubleBuffer doubleBuf;
 *		doubleBuf.Construct(remaining);
 *	
 *	
 *		// Read and write elements from intBuf to doubleBuf
 *		for (int i = 0; i < remaining; i++)
 *		{
 *			int value;
 *
 *			// Demonstrates relative reading and writing
 *	
 *			// Reads the value at the current position, and then increments the position
 *			intBuf.Get(value);
 *	
 *			// Write the value * 12.34 at the current position of doubleBuf 
 *			// and then increment the position
 *			doubleBuf.Set(value * 12.34);
 *	
 *			// Now, positions of intBuf and doubleBuf have been incremented by one.
 *		}
 *	
 *	
 *		// Flip doubleBuf
 *		doubleBuf.Flip();
 *		// Now, doubleBuf's position = 0 and limit = 10
 *	
 *	
 *		// Get the remaining elements of doubleBuf
 *		remaining = doubleBuf.GetRemaining();
 *	
 *	
 *		// Get the second double value with index
 *		double doubleValue;
 *		doubleBuf.Get(1, doubleValue);			// 12.34
 *	
 *	}
 *	
 * @endcode
 */
template <class Type>
class _EXPORT_BASE_ Buffer:
	public BufferBase
{

public:

// Lifecycle

	/**
	 * This is the default constructor for this class.
	 *
	 * @since			1.0
	 * @remarks		After creating an instance of the %Buffer class, one of the Construct() methods must be called explicitly to initialize this instance.
	 * @see				Construct()
	 */
	Buffer(void)
	{

	}


	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~Buffer(void)
	{
	
	}


	/**
	 * Initializes this instance of %Buffer which is a view of the specified buffer. @n
	 * This is similar to a copy constructor.
	 *
	 * @since			1.0
	 * @param[in]	buffer          The other %Buffer instance
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid, or
	 *								the source buffer is not constructed.
	 * @see			Buffer()
	 */
	result Construct(const Buffer<Type>& buffer)
	{
		TryReturn(null != buffer.__pData, E_INVALID_ARG, ("[E_INVALID_ARG] The source buffer is not constructed."));

		__capacity = buffer.__capacity;
		__position = buffer.__position;
		__limit = buffer.__limit;
		__mark = buffer.__mark;
		__pData = buffer.__pData;
		
		AddRef();
		__pArrayStart = buffer.__pArrayStart;

		return E_SUCCESS;
	}


	/**
	 * Initializes this instance of %Buffer with the specified capacity.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	capacity	The number of elements
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c capacity is negative.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @see			Buffer()
	 */
	result Construct(int capacity)
	{
		return BufferBase::Construct(capacity);
	}



// Operator

	/**
	 * This subscript operator returns the reference to the element indicated by the given index.
	 *
	 * @since			1.0
	 * @return		A reference to the indexed element
	 * @param[in]	index	The index of the element @n
	 *						It must be less than the limit.
	 */
	Type& operator [](int index) const
	{
		AppAssertf(index < __limit, "index out of range.\n");
		AppAssertf(index >= 0, "index out of range.\n");

		return ((Type*)__pArrayStart)[index];
	}


	/**
	 * Overloaded equality operator to compare two %Buffer instances.
	 *
	 * @since			1.0
	 * @return		@c true if the buffers being compared are equal, @n
	 *							else @c false
	 * @param[in]	buffer The buffer to compare with the current instance of %Buffer
	 * @remarks		This method returns @c true only if the two buffers have the same number of remaining elements 
	 *						and the two sequences of remaining elements are equal (considered independently of their starting positions).
	 * @see				Equals()
	 */
	bool operator ==(const Buffer<Type>& buffer) const
	{
		bool r = true;
		if (this == (void*)(&buffer))
		{
			r = true;
		}
		else if (GetRemaining() != buffer.GetRemaining())
		{
			r = false;
		}
		else
		{
			void* p1 = &(((Type*)__pArrayStart)[__position]);
			void* p2 = &(((Type*)buffer.__pArrayStart)[buffer.__position]);
			if ((p1 != p2) && (memcmp(p1, p2, sizeof(Type) * GetRemaining()) != 0))
			{
				r = false;
			}
		}

		return r;
	}


	/**
	 * Overloaded inequality operator to compare two %Buffer instances.
	 *
	 * @since			1.0
	 * @return		@c true if the buffers are not equal, @n
	 *							else @c false
	 * @param[in]	buffer The buffer to compare with the current instance of %Buffer
	 * @remarks		This method returns @c false only if the two buffers being compared have the same 
	 *						number of remaining elements and the two sequences of remaining elements are equal
	 *						(considered independently of their starting positions).
	 * @see				Equals()
	 */
	bool operator !=(const Buffer<Type>& buffer) const
	{
		return !(*this == buffer);
	}


// Operation

	/**
	 * Copies the remaining elements of the input %Buffer instance into the current
	 * %Buffer instance. It returns E_OVERFLOW if the remaining part of the current instance is smaller
	 * than the remaining part of the input instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	buffer	The source buffer from which bytes are to be read @n
	 *						It must not be the current instance of %Buffer.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid, or
	 *								the source buffer is same as destination buffer, 
	 *								that is, the current instance of %Buffer.
	 * @exception	E_OVERFLOW		The operation (arithmetic/casting/conversion) has caused an overflow. @n
	 *								The number of remaining bytes of the current buffer is less than
	 *								the number of remaining bytes of the given buffer.
	 * @remarks		After the copy operation, the current (destination) buffer's position and the given 
	 *				(source) buffer's position are incremented by the number of elements copied (the number
	 *				of remaining elements of the given buffer). @n
	 *				If the remaining part of the current instance is not less than the remaining part of the input instance,
	 *				the effect of this method and the ReadFrom() method is the same. But when the remaining part of the
	 *				current instance is less, ReadFrom() method copies the number of remaining elements of the current
	 *				instance while this method returns E_OVERFLOW and does not transfer.
	 * @see			ReadFrom()
	 *
	 * The following example shows how to operate this method:
	 *
	 * @code
	 *
	 *	// Create instances of IntBuffer to act as source and destination buffers
	 *	IntBuffer srcBuf;
	 *	IntBuffer destBuf;
	 *
	 *	// Declare an array of integers
	 *	int pArray[] = {0,1,2,3,4,5,6,7,8,9};
	 *
	 *	// Initialize the source buffer with 10 elements.
	 *	srcBuf.Construct(10);
	 *
	 *	// Copy the 10 values from pArray starting at position 0 to srcBuf
	 *	// Now srcBuf's position = 10
	 *	srcBuf.SetArray(pArray, 0, 10); 
	 *
	 *	// Flip the buffer: The limit is set to the current position
	 *	// and then the position is set to zero
	 *	srcBuf.Flip();		// srcBuf's position = 0 and limit = 10
	 *
	 *
	 *	destBuf.Construct(20);
	 *
	 *	// Copy from srcBuf to destBuf
	 *	// Now srcBuf's position = 10, destBuf's position = 10
	 *	destBuf.CopyFrom(srcBuf); 
	 *
	 * @endcode
	 *
	 * The following example has exactly the same effect as the above CopyFrom() method:
	 * 
	 * @code
	 *
	 *	int copyNum = srcBuf.GetRemaining();
	 *	for (int i = 0; i < copyNum; i++)
	 *	{
	 *		int value;
	 *
	 *		// Read from the source buffer
	 *		srcBuf.Get(value);			// srcBuf position is incremented by one.
	 *
	 *		// Write to the destination buffer
	 *		destBuf.Set(value);			// destBuf position is incremented by one.
	 *
	 *	}
	 * @endcode
	 */
	result CopyFrom(Buffer<Type>& buffer)
	{
		TryReturn(this != static_cast<void*>(&buffer), E_INVALID_ARG, "[E_INVALID_ARG] The source and target buffers are identical.");
		int copyLength = buffer.GetRemaining();
		TryReturn(GetRemaining() >= copyLength, E_OVERFLOW, "[E_OVERFLOW]");

		memcpy(__pArrayStart + __position * sizeof(Type), buffer.__pArrayStart + buffer.__position * sizeof(Type), copyLength * sizeof(Type));

		__position += copyLength;
		buffer.__position += copyLength;

		return E_SUCCESS;
	}


	/**
	 * Reads the value from the current position in the buffer, and then increments the position. @n
	 * Provides a way for relative indexing and reading.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[out]	value               The value at the current position
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_UNDERFLOW		The operation (arithmetic/casting/conversion) has caused an underflow. @n
	 *								The current position is greater than the limit.
	 * @see					Set()
	 */
	result Get(Type& value)
	{
		TryReturn(__position < __limit, E_UNDERFLOW, "[E_UNDERFLOW]");

		value = ((Type*)__pArrayStart)[__position++];
		return E_SUCCESS;
	}


	/**
	 * Reads the value at the given index. @n
	 * Provides a way for absolute indexing and reading.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		index The index into the buffer from where the value is to be read
	 * @param[out]	value The value at the given index
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_OUT_OF_RANGE		The specified @c index is outside the bounds of the data structure. @n
	 *									The @c index is greater than the limit or less than @c 0.
	 * @see					Set()
	 */
	result Get(int index, Type& value) const
	{
		TryReturn(index < __limit && index >= 0, E_OUT_OF_RANGE, "[E_OUT_OF_RANGE] The index(%d) MUST be greater than or equal to 0, and less then the current limit(%d).", index, __limit);

		value = ((Type*)__pArrayStart)[index];
		return E_SUCCESS;
	}


	/**
	 * Copies the specified range of values from the calling buffer to the specified destination array as per the given index of the array.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[out]	pArray	A pointer to the array into which values are to be written
	 * @param[in]	index	The starting index in the array of the first value to be written
	 * @param[in]	length	The number of values from the buffer to be written to the array
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid. @n
	 *									The @c pArray is @c null.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure. @n
	 *									The @c index or length is less than @c 0.
	 * @exception	E_UNDERFLOW			The operation (arithmetic/casting/conversion) has caused an underflow. @n
	 *									The remaining elements of this buffer are smaller than @c length.
	 * @remarks		After the copy operation, the position is incremented by @c length.
	 * @see			SetArray()
	 */
	result GetArray(Type* pArray, int index, int length)
	{
		TryReturn(0 != pArray, E_INVALID_ARG, "[E_INVALID_ARG] The pArray is null.");
		TryReturn(index >= 0 && length >= 0, E_OUT_OF_RANGE, "[E_OUT_OF_RANGE] Both of index(%d) and length(%d) MUST be greater than or equal to 0.", index, length);
		TryReturn(GetRemaining() >= length, E_UNDERFLOW, "[E_UNDERFLOW]");

		memcpy(pArray + index * sizeof(Type), __pArrayStart + __position * sizeof(Type), length * sizeof(Type));
		__position += length;

		return E_SUCCESS;
	}


	/**
	 * Transfers bytes from the input buffer into the calling buffer. @n
	 * If the empty space in the calling buffer is larger than the remaining values from the input buffer,
	 * all the remaining elements from the input are copied to the destination. @n
	 * Otherwise, the number of bytes copied equals the number of elements remaining in the calling buffer.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	buffer	The source buffer from which bytes are to be read @n
	 *						It must not be this buffer.
 	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid. @n
	 *								The given buffer is same as the current buffer instance.
	 * @remarks		After the copy operation, the current (destination) buffer's position and the given 
	 *				(source) buffer's position are	incremented by the number of elements copied (the smaller value 
	 *				between the number of elements remaining in the calling buffer and the source buffer). @n
	 *				If there are more elements remaining in the calling buffer than elements remaining in the input instance,
	 *				this method is equivalent to CopyFrom() method. If there are less remaining elements in the 
	 *				calling buffer, the CopyFrom() method returns E_OVERFLOW and does not transfer
	 *				while this method copies the number of remaining elements of the current instance.
	 * @see			CopyFrom()
	 *
	 * The following example shows how to use this method.
	 *
	 * @code
	 *
	 *	// Create instances of IntBuffer to act as the source and destination buffers
	 *	IntBuffer srcBuf;
	 *	IntBuffer destBuf;
	 *
	 *	// Declare an array of integers
	 *	int pArray[] = {0,1,2,3,4,5,6,7,8,9};
	 *
	 *	// Initialize the source buffer with a capacity of 10 elements.
	 *	srcBuf.Construct(10);
	 *
	 *	// Copy the 10 values from pArray starting at position 0 to srcBuf
	 *	// Now srcBuf's position = 10
	 *	srcBuf.SetArray(pArray, 0, 10); 
	 *
	 *	// Flip the buffer: The limit is set to the current position
	 *	// and then the position is set to zero
	 *	srcBuf.Flip();	// srcBuf's position = 0 and limit = 10
	 *
	 *
	 *	// Initialize the destination buffer with a capacity of 10 elements.
	 *	destBuf.Construct(10);
	 *
	 *	// Set the limit of destBuf to 5
	 *	destBuf.SetLimit(5);
	 *
	 *	// Read from srcBuf to destBuf
	 *	// destBuf's remaining is 5, smaller than the srcBuf's (10).
	 *	// Therefore, five elements are transferred.
	 *	// srcBuf's position = 5, destBuf's position = 5
	 *	destBuf.ReadFrom(srcBuf); 
	 *
	 *
	 * @endcode
	 *
	 * The following example has exactly the same effect as the above ReadFrom() method.
	 * 
	 * @code
	 *
	 *	int copyNum = (destBuf.GetRemaining() < srcBuf.GetRemaing())? destBuf.GetRemaining() : srcBuf.GetRemaining();
	 *	for (int i = 0; i < copyNum; i++)
	 *	{
	 *		int value;
	 *
	 *		// Read from source buffer
	 *		srcBuf.Get(value);			// srcBuf position is incremented by one.
	 *
	 *		// Write to destination buffer
	 *		destBuf.Set(value);			// destBuf position is incremented by one.
	 *
	 *	}
	 * @endcode
	 */
	result ReadFrom(Buffer<Type>& buffer)
	{
		TryReturn(this != static_cast<void*>(&buffer), E_INVALID_ARG, "[E_INVALID_ARG] The source and target buffers are identical.");

		int copyLength = (GetRemaining() < buffer.GetRemaining()) ? GetRemaining() : buffer.GetRemaining();

		memcpy(__pArrayStart + __position * sizeof(Type), buffer.__pArrayStart + buffer.__position * sizeof(Type), copyLength * sizeof(Type));

		__position += copyLength;
		buffer.__position += copyLength;

		return E_SUCCESS;
	}


	/**
	 * Writes the specified value into the current buffer instance at the current position,
	 * and then increments the position. @n
	 * Provides a way for relative indexing and writing.
	 *
	 * @since			1.0	
	 * @return		An error code
	 * @param[in]	value           The value to be written to the calling %Buffer
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OVERFLOW		The operation (arithmetic/casting/conversion) has caused an overflow. @n
	 *								The current position is not smaller than the limit.
	 * @see			Get()
	 */
	result Set(Type value)
	{
		TryReturn(__position < __limit, E_OVERFLOW, "[E_OVERFLOW]");

		((Type*)__pArrayStart)[__position++] = value;
		return E_SUCCESS;
	}


	/**
	 * Writes the specified value into the current instance of buffer at the given index. @n
	 * Provides a way for absolute indexing and writing.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	index	The index at which the value is written
	 * @param[in]	value	The value to be written
	 * @exception	E_SUCCESS  			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure. @n
	 *									The @c index is not smaller than the limit or less than @c 0.
	 * @see			Get()
	 */
	result Set(int index, Type value)
	{
		TryReturn(index < __limit && index >= 0, E_OUT_OF_RANGE, "[E_OUT_OF_RANGE] The index(%d) MUST be greater than or equal to 0, and less then the current limit(%d).", index, __limit);

		((Type*)__pArrayStart)[index] = value;
		return E_SUCCESS;
	}


	/**
	 * Copies values from the input source array into the calling buffer.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	pArray		A pointer to the array from which values are to be read
	 * @param[in]	index		The starting index of the array
	 * @param[in]	length		The number of values to be read from the given array
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid. @n
	 *									The @c pArray is @c null.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure. @n
	 *									The @c index or length is less than @c 0.
	 * @exception	E_OVERFLOW			The operation (arithmetic/casting/conversion) has caused an overflow. @n
	 *									The remainder of this buffer is smaller than @c length.
	 * @remarks		This method copies @c length number of values from the source array, 
	 *				starting from the given index in the array,  into the calling 
	 *				buffer, starting at the current position.
	 *				After the copy operation, the position is incremented by @c length.
	 * @see			GetArray()
	 */
	result SetArray(const Type* pArray, int index, int length)
	{
		TryReturn(null != pArray, E_INVALID_ARG, "[E_INVALID_ARG] The pArray is null.");
		TryReturn(index >= 0 && length >= 0, E_OUT_OF_RANGE, "[E_OUT_OF_RANGE] Both of index(%d) and length(%d) MUST be greater than or equal to 0.", index, length);
		TryReturn(GetRemaining() >= length, E_OVERFLOW, "[E_OVERFLOW]");

		memcpy(__pArrayStart + __position * sizeof(Type), pArray + index * sizeof(Type), length * sizeof(Type));
		__position += length;

		return E_SUCCESS;
	}


	/**
	 * Creates a new %Buffer instance. Its content is a shared portion of 
	 * the calling %Buffer instance that starts from the current position of calling %Buffer instance.
	 *
	 * @since			1.0
	 * @return		A pointer to the new buffer
	 * @remarks		The content of the new buffer starts at the current position of this instance of %Buffer. 
	 *				The new buffer's position is @c 0, its capacity and limit is
	 *				the number of bytes remaining in the current instance of %Buffer,
	 *				and it is marked as undefined. 	
	 */
	Buffer<Type>* SliceN(void) const
	{
		Buffer<Type>* pBuffer = new Buffer<Type>();
		pBuffer->__pData = __pData;
		AddRef();
		pBuffer->__capacity = GetRemaining();
		pBuffer->__limit = pBuffer->__capacity;
		if (pBuffer->__capacity > 0)
			pBuffer->__pArrayStart = (byte*)&((Type*)__pArrayStart)[__position];

		return pBuffer;
	}


// Access

	/**
	 * Returns a raw array pointer to calling buffer.
	 *
	 * @since			1.0
	 * @return		A raw array pointer to the buffer, @n
	 *				else @c null if the capacity is @c 0
	 */
	const Type* GetPointer(void) const
	{
		return (Type*)__pArrayStart;
	}



// Inquery

	/** 
	 * Compares the Object instance with the calling %Buffer instance for equivalence.
	 *
	 * @since			1.0
	 * @return		@c true if the input equals the calling %Buffer instance, @n
	 *				else @c false
	 * @param[in]	obj	The object to compare with the calling Buffer
	 * @remarks		This method returns @c true if and only if the specified object is also an instance of Buffer class,
	 *				the two buffers have the same number of remaining elements, and the two sequences of 
	 *				remaining elements are equal (considered independently of their starting positions).
	 * @see			Osp::Base::BufferBase::GetHashCode()
	 */
	virtual bool Equals(const Osp::Base::Object& obj) const
	{
		bool out = false;
		const Buffer<Type>* other = static_cast<const Buffer<Type>*>(&obj);
		if ((other == this) || (*other == *this))
		{
			out = true;
		}

		return out;
	}


private:

// Lifecycle

	/**
	 * This is the copy constructor for this class.
	 */
	Buffer(const Buffer<Type>& buffer)
	{
		Construct(buffer);
	}

// Operator

	/**
	 * This is the assignment operator.
	 */
	Buffer<Type>& operator=(const Buffer<Type>& buffer);


// Access

	/**
	 * Returns the size of the type of this buffer.
	 *
	 * @return		The size of the buffer
	 */
	virtual int GetTypeSize(void) const
	{
		return sizeof(Type);
	}


// Friend class declaration

	friend class ByteBuffer;


}; // Buffer


/**
 * @brief The double buffer type.
 * @since	1.0
 */
typedef Buffer<double> DoubleBuffer;

/**
* @brief 	The float buffer type.
* @since	1.0
*/
typedef Buffer<float> FloatBuffer;

/**
* @brief 	The int buffer type.
* @since	1.0
*/
typedef Buffer<int> IntBuffer;

/**
* @brief 	The long buffer type.
* @since	1.0
*/
typedef Buffer<long> LongBuffer;

/**
* @brief 	The long long buffer type.
* @since	1.0
*/
typedef Buffer<long long> LongLongBuffer;

/**
* @brief 	The mchar buffer type.
* @since	1.0
*/
typedef Buffer<mchar> McharBuffer;

/**
* @brief 	The short buffer type.
* @since	1.0
*/
typedef Buffer<short> ShortBuffer;


#ifdef _MSC_VER
template class _EXPORT_BASE_ Buffer<double>;
template class _EXPORT_BASE_ Buffer<float>;
template class _EXPORT_BASE_ Buffer<int>;
template class _EXPORT_BASE_ Buffer<long>;
template class _EXPORT_BASE_ Buffer<long long>;
template class _EXPORT_BASE_ Buffer<mchar>;
template class _EXPORT_BASE_ Buffer<short>;
#endif

}; }; // Osp::Base
#endif // _FBASE_BUFFER_H_

