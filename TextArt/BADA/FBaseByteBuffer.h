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
 * @file		FBaseByteBuffer.h 
 * @brief		This is the header file for the %ByteBuffer class.
 *
 * This header file contains the declarations of the %ByteBuffer class.
 */

#ifndef _FBASE_BYTE_BUFFER_H_
#define _FBASE_BYTE_BUFFER_H_

// Includes
#include "FBaseBufferBase.h"
#include "FBaseBuffer.h"

namespace Osp { namespace Base {

///////////////////////////////////////////////////////////////////////////////////////////
/// ByteBuffer class declaration
	
/**
 * @class	ByteBuffer
 * @brief	This class provides a contiguous sequence of the @c byte ( @c unsigned @c char) built-in type.
 * @since	1.0
 * 
 * The %ByteBuffer class provides a means of encapsulating a sequence of bytes in memory. It defines
 * methods to read and write all primitive built-in types (except @c bool), to and from a sequence of 
 * bytes. These methods read the size of primitive type bytes from a @c byte sequence and 
 * convert it to the actual primitive type. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/buffer.htm">Buffer</a>.
 *
 * @see		Osp::Base::BufferBase
 *
 * The following example demonstrates how to use the %ByteBuffer class.
 *
 * @code
 *
 *	#include <FBase.h>
 *
 *	using namespace Osp::Base;
 *
 *	void
 *	MyClass::ByteBufferSample(void)                                                                
 *	{                                                                                                
 *		// Define the maximum buffer size: capacity                                                  
 *		const int BUFFER_SIZE_MAX = 1024;       
 *
 *		// Initialize buf using the Construct method to the capacity                                      
 *		ByteBuffer buf;		                                                                         
 *		buf.Construct(BUFFER_SIZE_MAX);                                                           
 *	                                                                                                 
 *	                                                                                                 
 *		// Copy five values into buf                                                                     
 *		for (int i = 0; i < 5; i++)                                                                   
 *		{                                                                                             
 *			byte b = 'A' + i;                                                                          
 *	                                                                                                 
 *			// Write byte b to the current position of buf                                             
 *			buf.SetByte(b); // position is incremented by one.                                     
 *		}                                                                                             
 *		// position is moved to 5                                                                     
 *	                                                                                                 
 *	                                                                                                 
 *		// Flip buf                                                                                   
 *		buf.Flip();                                                                                   
 *		// Now, position = 0 and limit = 5                                                              
 *	                                                                                                 
 *	                                                                                                 
 *		// Read bytes from buf using "relative access method"                                         
 *		while(buf.HasRemaining())                                                                     
 *		{                                                                                             
 *			byte b;                                                                                    
 *	                                                                                                 
 *			// Read byte b from the current position of buf                                            
 *			buf.GetByte(b); // position is incremented by one.                                     
 *		}                                                                                             
 *                                                                  
 *	                                                                                                 
 *		// Clear buf                                                                                  
 *		buf.Clear();                                                                                  
 *		// buf's position = 0 and limit = capacity                                                      
 *	                                                                                                 
 *	                                                                                                 
 *		// Write int values to buf                                                                    
 *		for (int i = 0; i < 5; i++)                                                                   
 *		{                                                                                             
 *			// Write int value at the current position                                                 
 *			buf.SetInt(i); // position is incremented by sizeof(int)                               
 *		}                                                                                             
 *	                                                                                                 
 *		// Flip buf                                                                                   
 *		buf.Flip();                                                                                   
 *		// Now, position = 0 and limit = sizeof(int) * 5                                                
 *	                                                                                                 
 *	                                                                                                 
 *		// Create a new view, IntBuffer. 
 *		// Capacity of intBuf = 5
 *		// The content of intBuf is from buf's position to buf's limit
 *		IntBuffer* pIntBuf = buf.AsIntBufferN();
 *	                                                                                                 
 *	                                                                                                 
 *		// Test whether the change in view buffer(IntBuffer) is visible in original buffer(ByteBuffer)
 *		pIntBuf->Set(4, 9);
 *	                                                                                                 
 *	                                                                                                 
 *		// Read int values from buf using "absolute access method"                                    
 *		for (int i = 0; i < 5; i++)                                                                  
 *		{                                                                                             
 *			int out;                                                                                   
 *	                                                                                                 
 *			// Read int value from buf with the specified index.                                           
 *			buf.GetInt((i * sizeof(int)), out);		// 0, 1, 2, 3, 9 
 *													//  position is not changed. 
 *		}                                                                                             
 *
 *		delete pIntBuf;
 *	                                                                                                 
 *	}                                                                                                	
 *		
 * @endcode
 */
class _EXPORT_BASE_ ByteBuffer :
	public BufferBase
{

public:

// Lifecycle

	/**
	 * This is the default constructor for this class.
	 *
	 * @since			1.0
	 * @remarks		After creating an instance of the %ByteBuffer class, one of the Construct() methods must be called explicitly to initialize this instance.
	 * @see				Construct()
	 */
	ByteBuffer(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~ByteBuffer(void);


	/**
	 * Initializes this instance of %ByteBuffer which is a view of the specified buffer. @n
	 * This is the copy constructor for the %ByteBuffer class.
	 *
	 * @since			1.0
	 * @param[in]	buffer          The %ByteBuffer instance used to initialize new object
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the source buffer is not constructed.
	 * @see				ByteBuffer()
	 */
	result Construct(const ByteBuffer& buffer);


	/**
	 * Initializes this instance of %ByteBuffer with the specified @c capacity.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	capacity		The number of elements
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *				                the specified @c capacity is negative.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @see				ByteBuffer()
	 */
	result Construct(int capacity);


	
// Operator

	/**
	 * Gets the reference to the byte value at the specified index.
	 *
	 * @since			1.0
	 * @return		Reference to the @c byte value
	 * @param[in]	index	The index of the @c byte value in the calling %ByteBuffer instance @n
	 *						It must be less than the limit.
	 */
	byte& operator [](int index) const;


	/**
	 * Compares the two %ByteBuffer instances.
	 *
	 * @since			1.0
	 * @return		@c true if the input buffer is equal to the calling %ByteBuffer instance, @n
	 *				else @c false
	 * @param[in]	buffer	The %ByteBuffer instance to compare with the current instance
	 * @remarks		This method returns @c true only if the two buffers have the same number of 
	 *						remaining elements, and the two sequences of remaining elements are equal
	 *						(considered independently, irrespective of their starting positions).
	 * @see				Equals()
	 */
	bool operator ==(const ByteBuffer& buffer) const;


	/**
	 * Compares the calling %ByteBuffer instance with the specified instance.
	 *
	 * @since			1.0
	 * @return		@c true if the two objects are not the same, @n
	 *				else @c false.
	 * @param[in]	buffer	The buffer to compare with the current instance
	 * @remarks		This method returns @c false only if the two buffers being compared have the same 
	 *						number of remaining elements, and the two sequences of remaining elements are equal
	 *						(considered independently, irrespective of their starting positions).
	 * @see				Equals()
	 */
	bool operator !=(const ByteBuffer& buffer) const;


// Operation

	/**
	 * Creates a new double buffer view for the content of the byte buffer
	 *	
	 * @since			1.0
	 * @return		DoubleBuffer  A pointer to the current position of the calling object
	 * @remarks		The content of the view buffer starts at the current position of the calling buffer.
	 *				The new buffer's position is zero, the mark is undefined, and the capacity and limit 
	 *				are equal to the remaining part of this buffer divided by the size of @c double.
	 *				Any change to the byte buffer content is visible in the double buffer view, and vice versa.
	 */
	DoubleBuffer* AsDoubleBufferN(void) const;


	/**
	 * Creates a new float buffer view for the content of the byte buffer.
	 *
	 * @since			1.0	
	 * @return		FloatBuffer A pointer to the current position of the calling buffer
	 * @remarks		The content of the view buffer starts at the current position of the calling buffer.
	 *				The new buffer's position is zero, the mark is undefined, and the capacity and limit 
	 *				are equal to the remaining part of the calling buffer divided by the size of @c float.
	 *				Any change to the byte buffer content is visible in the float buffer view, and vice versa.  
	 */
	FloatBuffer* AsFloatBufferN(void) const;


	/**
	 * Creates a new Int buffer view for the content of the byte buffer
	 *
	 * @since			1.0	
	 * @return		IntBuffer A pointer to the current position of the calling buffer
	 * @remarks		The content of the view buffer starts at the current position of the calling buffer.
	 *				The new buffer's position is zero, the mark is undefined, and the capacity and limit 
	 *				are equal to the remaining part of calling buffer divided by the size of @c int.
	 *				Any change to the byte buffer content is visible in the Int buffer view, and vice versa.  
	 */
	IntBuffer* AsIntBufferN(void) const;


	/**
	 * Creates a new long buffer view for the content of the byte buffer
	 *
	 * @since			1.0	
	 * @return		LongBuffer A pointer to the current position of the calling buffer
	 * @remarks		The content of the view buffer starts at the current position of this buffer. 
	 *				The new buffer's position is zero, the mark is undefined, and the capacity and limit 
	 *				are equal to the remaining part of calling buffer divided by the size of @c long.
	 *				Any change to the byte buffer content is visible in the long buffer view, and vice versa.  
	 */
	LongBuffer* AsLongBufferN(void) const;


	/**
	 * Creates a new long long buffer view for the content of the byte buffer
	 *
	 * @since			1.0	
	 * @return		LongLongBuffer A pointer to the current position of the calling buffer
	 * @remarks		The content of the view buffer starts at the current position of this buffer. 
	 *				The new buffer's position is zero, the mark is undefined, and the capacity and limit 
	 *				are equal to the remaining part of calling buffer divided by the size of @c long.
	 *				Any change to the byte buffer content is visible in the long long buffer view, and vice versa. 
	 */
	LongLongBuffer* AsLongLongBufferN(void) const;


	/**
	 * Creates a new mchar buffer view for the content of the byte buffer
	 *
	 * @since			1.0	
	 * @return		McharBuffer A pointer to the current position of the calling buffer
	 * @remarks		The content of the view buffer starts at the current position of this buffer. 
	 *				The new buffer's position is zero, the mark is undefined, and the capacity and limit 
	 *				are equal to the remaining part of the calling buffer divided by the size of @c long.
	 *				Any change to the byte buffer content is visible in the mchar buffer view, and vice versa.  
	 */
	McharBuffer* AsMcharBufferN(void) const;


	/**
	 * Creates a new short buffer view for the content of the byte buffer
	 *
	 * @since			1.0	
	 * @return		ShortBuffer pointer to the current position of the calling buffer
	 * @remarks		The content of the view buffer starts at the current position of this buffer. 
	 *				The new buffer's position is zero, the mark is undefined, and the capacity and limit 
	 *				are equal to the remaining part of calling buffer divided by the size of @c long.
	 *				Any change to the byte buffer content is visible in the short buffer view, and vice versa.
	 */
	ShortBuffer* AsShortBufferN(void) const;


	/**
	 * Copies the remaining bytes of the input ByteBuffer instance into the calling ByteBuffer object. @n
	 * It returns E_OVERFLOW if the remaining bytes in the current instance are less 
	 * than the remaining bytes in the input instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	buffer		The source buffer from which bytes are to be read @n
	 *							It must not be the calling object.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid. @n
	 *								The source buffer is same as destination buffer, 
	 *								that is, the current instance of the buffer.
	 * @exception	E_OVERFLOW		The operation (arithmetic/casting/conversion) has caused an overflow. @n
	 *								The number of remaining bytes of the current buffer is smaller than 
	 *								the number of remaining bytes of the input buffer.
	 * @remarks		After the copy operation, the current (destination) buffer's position and the given
	 *				(source) buffer's positions are incremented by the number of bytes copied (the number of 
	 *				remaining bytes of the given buffer). @n
	 *				If the remaining part of the current instance is greater than or equal to the remaining part of the input instance,
	 *				the effect of this method and the ReadFrom(ByteBuffer) method is the same. But when the remaining part of the
	 *				current instance is less, the ReadFrom() method copies the number of remaining elements of the current
	 *				instance while this method returns E_OVERFLOW and does not copy.
	 * @see			ReadFrom()
	 *
	 * The following example shows how to operate this method:
	 *
	 * @code
	 *
	 *	// Creates instances of ByteBuffer to act as source and destination buffers
	 *	ByteBuffer srcBuf;
	 *	ByteBuffer destBuf;
	 *
	 *	// Declares an array of byte values
	 *	byte pArray[] = {'A','B','C','D','E','F','G','H','I','J'};
	 *
	 *	// Initializes the source array with a capacity of ten elements.
	 *	srcBuf.Construct(10);
	 *
	 *	// Copies the ten values from pArray starting at position 0 to srcBuf
	 *	// Now, srcBuf's position = 10
	 *	srcBuf.SetArray(pArray, 0, 10); 
	 *
	 *	// Flips the buffer: The limit is set to the current position and
	 *	// then the position is set to zero
	 *	srcBuf.Flip();			// srcBuf's position = 0 and limit = 10
	 *
	 *
	 *	destBuf.Construct(20);
	 *
	 *	// Copy from srcBuf to destBuf
	 *	// Now, srcBuf's position = 10, destBuf's position = 10
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
	 *		byte b;
	 *
	 *		// Reads from source buffer
	 *		srcBuf.GetByte(b);			// srcBuf position is incremented by 1.
	 *
	 *		// Writes to destination buffer
	 *		destBuf.SetByte(b);			// destBuf position is incremented by 1.
	 *
	 *	}
	 * @endcode
	 */
	result CopyFrom(ByteBuffer& buffer);


	/**
	 * Copies the specified number of bytes from the calling %ByteBuffer
	 * instance to the given destination array.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[out]	pArray		A pointer to the destination array into which the bytes are to be written
	 * @param[in]	index		The starting index in the array of the first byte to be written
	 * @param[in]	length		The number of bytes to be written to the given array
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid. @n
	 *								The @c pArray is @c null.
	 * @exception	E_OUT_OF_RANGE	A specified input parameter is invalid. @n
	 *								The @c index or @c length is less than @c 0.
	 * @exception	E_UNDERFLOW		The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *								the remaining bytes of this buffer are smaller than @c length.
	 * @remarks		This method copies @c length bytes from the current instance of %ByteBuffer to the given array,
	 *				starting at the current position and at the given index in the array.
	 *				After the copy operation, the position is incremented by @c length bytes.
	 * @see			SetArray()
	 */
	result GetArray(byte* pArray, int index, int length);


	/**
	 * Reads the @c byte value from the buffer at the current position, and then increments the position. @n
	 * Provides a way for relative indexing and reading.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[out]	value 		The @c byte value at the current position in the %ByteBuffer instance
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_UNDERFLOW		The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *								the current position is not smaller than the limit.
	 * @see			SetByte()
	 */
	result GetByte(byte& value);


	/**
	 * Reads the @c byte value at the given index. @n
	 * Provides a way for absolute indexing and reading. 
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	index		The index of the current %ByteBuffer instance, from which the byte is read
	 * @param[out]	value 		The @c byte value at the given @c index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified index is outside the bounds of the data structure, or
	 *								the @c index is not smaller than the limit or less than @c 0.
	 * @see			SetByte()
	 */
	result GetByte(int index, byte& value) const;


	/**
	 * Reads the size of @c double number of bytes from the buffer at the current position, converts 
	 * it to the corresponding @c double equivalent, and then increments the position. @n
	 * Provides a way for relative indexing and reading.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[out]	value 		The @c double value at the current position in the %ByteBuffer instance
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_UNDERFLOW		The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *								the remaining bytes of this buffer are smaller than the size of @c double.
	 * @remarks		This method reads the next size of @c double number of bytes at the current position,
	 *				composing it into a @c double value, and then increments the position by the size of @c double.
	 * @see			SetDouble()
	 */
	result GetDouble(double& value);


	/**
	 * Reads the size of @c double number of bytes at the given index and converts it to the equivalent @c double value. @n
	 * Provides a way for absolute indexing and reading.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	index		The index of the current %ByteBuffer instance, from which the bytes are read
	 * @param[out]	value		The @c double value at the given index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus size of @c double or less than @c 0.
	 * @remarks		This method reads size of @c double number of bytes at the given index,
	 *				composing them into a @c double value.
	 * @see			SetDouble()
	 */
	result GetDouble(int index, double& value) const;


	/**
	 * Reads the size of @c float number of bytes from the buffer at the current position, converts 
	 * it to the corresponding @c float equivalent, and then increments the position. @n
	 * Provides a way for relative indexing and reading.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[out]	value 		The @c float value at the current position in the %ByteBuffer instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_UNDERFLOW			The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *									the remaining bytes of this buffer are smaller than the size of @c float.
	 * @remarks		This method reads the next size of @c float number of bytes at the current position,
	 *				composing it into a @c float value, and then increments the position by the size of @c float.
	 * @see			SetFloat()
	 */
	result GetFloat(float& value);


	/**
	 * Reads the size of @c float number of bytes at the given index and converts it to equivalent @c float value. @n
	 * Provides a way for absolute indexing and reading.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	index 		The index of the current %ByteBuffer instance, from which the bytes are read
	 * @param[out]	value 		The @c float value at the given index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus size of @c float or less than @c 0.
	 * @remarks		This method reads the size of @c float number of bytes at the given index,
	 *				composing it into a @c float value.
	 * @see			SetFloat()
	 */
	result GetFloat(int index, float& value) const;


	/**
	 * Reads the size of @c int number of bytes from the buffer at the current position, converts
	 * it to the corresponding @c int equivalent, and then increments the position. @n
	 * Provides a way for relative indexing and reading.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[out]	value 		The @c int value at the current position in the %ByteBuffer instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_UNDERFLOW			The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *									the remaining bytes of this buffer are smaller than the size of @c int.
	 * @remarks		This method reads the next size of @c int number of bytes at the current position,
	 *				composing them into an @c int value, and then increments the position by the size of @c int.
	 * @see			SetInt()
	 */
	result GetInt(int& value);


	/**
	 * Reads the size of @c int number of bytes at the given index and converts it to the equivalent @c int value. @n
	 * Provides a way for absolute indexing and reading.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	index 		The index of the current %ByteBuffer instance, from which the bytes are read
	 * @param[out]	value 		The @c int value at the given index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus size of @c int or negative.
	 * @remarks		This method reads the size of @c int number of bytes at the given index,
	 *				composing it into an @c int value.
	 * @see			SetInt()
	 */
	result GetInt(int index, int& value) const;


	/**
	 * Reads the size of @c long number of bytes from the buffer at the current position, converts 
	 * it to the corresponding @c long equivalent, and then increments the position. @n
	 * Provides a way for relative indexing and reading.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[out]	value 		The @c long value at the current position in the %ByteBuffer instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_UNDERFLOW			The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *									the remaining bytes of this buffer are smaller than the size of @c long.
	 * @remarks		This method reads the next size of @c long number of bytes at the current position,
	 *				composing it into a @c long value, and then increments the position by the size of @c long.
	 * @see			SetLong()
	 */	
	result GetLong(long& value);


	/**
	 * Reads the size of @c long number of bytes at the given index and converts it to equivalent @c long value. @n
	 * Provides a way for absolute indexing and reading.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	index 		The index of the current %ByteBuffer instance, from which the bytes are read
	 * @param[out]	value 		The @c long value at the given index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus size of @c long or less than @c 0.
	 * @remarks		This method reads the size of @c long number of bytes at the given index,
	 *				composing it into a @c long value.
	 * @see			SetLong()
	 */
	result GetLong(int index, long& value) const;


	/**
	 * Reads the size of @c long @c long number of bytes from the buffer at the current position, converts 
	 * it to the corresponding @c long @c long equivalent, and then increments the position. @n
	 * Provides a way for relative indexing and reading.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[out]	value 		The @c long @c long value at the current position in the ByteBuffer instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_UNDERFLOW			The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *									the remaining bytes of this buffer are smaller than the size of @c long @c long.
	 * @remarks		This method reads the next size of @c long @c long number of bytes at the current position,
	 *				composing it into a @c long @c long value, and then increments the position by the size of @c long @c long.
	 * @see			SetLongLong()
	 */	
	result GetLongLong(long long& value);


	/**
	 * Reads the size of @c long @c long number of bytes at the given index and converts it to the equivalent @c long @c long value. @n
	 * Provides a way for absolute indexing and reading.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	index 		The index of the current %ByteBuffer instance, from which the bytes are read
	 * @param[out]	value 		The @c long @c long value at the given index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus size of @c long @c long or less than @c 0.
	 * @remarks		This method reads the size of @c long @c long number of bytes at the given index,
	 *				composing it into a @c long @c long value.
	 * @see			SetLongLong()
	 */
	result GetLongLong(int index, long long& value) const;


	/**
	 * Reads the size of @c mchar number of bytes from the buffer at the current position, converts
	 * it to the corresponding @c mchar equivalent, and then increments the position. @n
	 * Provides a way for relative indexing and reading.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[out]	value 		The @c mchar value at the current position in the ByteBuffer instance
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_UNDERFLOW		The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *								the remaining bytes of this buffer are smaller than the size of @c mchar.
	 * @remarks		This method reads the next size of @c mchar number of bytes at the current position,
	 *				composing it into a @c mchar value, and then increments the position by the size of @c mchar.
	 * @see			SetMchar()
	 */
	result GetMchar(mchar& value);


	/**
	 * Provides a way for absolute indexing and reading. @n
	 * It reads the size of @c mchar number of bytes at the given index and converts it to equivalent @c mchar value.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	index 		The index of the current %ByteBuffer instance, from which the bytes are read
	 * @param[out]	value 		The @c mchar value at the given index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus size of @c mchar or less than @c 0.
	 * @remarks		This method reads the size of @c mchar number of bytes at the given index,
	 *				composing it into a @c mchar value.
	 * @see			SetMchar()
	 */
	result GetMchar(int index, mchar& value) const;


	/**
	 * Reads the size of @c short number of bytes from the buffer at the current position, converts
	 * it to the corresponding @c short equivalent, and then increments the position. @n
	 * Provides a way for relative indexing and reading.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[out]	value 		The @c short value at the current position in the %ByteBuffer instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_UNDERFLOW			The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *									the remaining bytes of this buffer are smaller than the size of @c short.
	 * @remarks		This method reads the next size of @c short number of bytes at the current position,
	 *				composing it into a @c short value, and then increments the position by the size of @c short.
	 * @see			SetShort()
	 */
	result GetShort(short& value);


	/**
	 * Reads the size of @c short number of bytes at the given index and converts it to the equivalent @c short value. @n
	 * Provides a way for absolute indexing and reading.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	index 		The index of the current ByteBuffer instance, from which the bytes are read
	 * @param[out]	value 		The @c short value at the given index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus size of @c short or less than @c 0.
	 * @remarks		This method reads the size of @c short number of bytes at the given index, 
	 *				composing it into a @c short value.
	 * @see			SetShort()
	 */
	result GetShort(int index, short& value) const;


	/**
	 * Copies the remaining bytes of the input %ByteBuffer instance into the calling %ByteBuffer instance 
	 * if the remaining part of the current instance is greater than or equal to the remaining part of the input instance. @n
	 * Otherwise, the number of bytes copied is equal to the number of remaining elements of the current instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	buffer		The source buffer from which bytes are to be read @n
	 *							It must not be the calling %ByteBuffer instance.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 *								
	 * @remarks		After the copy operation, the current (destination) buffer's position and the given 
	 *				(source) buffer's position are	incremented by the number of elements copied (the lesser of 
	 *				the number of elements remaining in the current buffer and the given buffer). @n
	 *				If the remaining part of the current instance is greater than or equal to the remaining part of the input instance,
	 *				the effect of this method is the same as the CopyFrom() method. But when the remaining part of the
	 *				current instance is less, the CopyFrom() method returns E_OVERFLOW and does not transfer;
	 *				whereas this method copies the number of remaining elements of the current instance.
	 * @see			CopyFrom()
	 *
	 * The following example shows how to operate this method:
	 *
	 * @code
	 *
	 *	// Creates instances of %ByteBuffer to act as source and destination buffers
	 *	ByteBuffer srcBuf;
	 *	ByteBuffer destBuf;
	 *
	 *	// Declares an array of byte values
	 *	byte pArray[] = {'A','B','C','D','E','F','G','H','I','J'};
	 *
	 *	// Initializes the source array with capacity of ten elements.
	 *	srcBuf.Construct(10);
	 *
	 *	// Copies the 10 values from pArray starting at position 0 to srcBuf
	 *	// Now, srcBuf's position = 10
	 *	srcBuf.SetArray(pArray, 0, 10); 
	 *
	 *	// Flips the buffer: The limit is set to the current position and
	 *	// then the position is set to zero
	 *	srcBuf.Flip();	// srcBuf's position = 0 and limit = 10
	 *
	 *
	 *	// Initializes the destination buffer with capacity of ten elements.
	 *	destBuf.Construct(10);
	 *
	 *	// Sets the limit of destBuf to 5
	 *	destBuf.SetLimit(5);
	 *
	 *	// Reads from srcBuf to destBuf
	 *	// destBuf's remaining is 5, smaller than the srcBuf's (10).
	 *	// Therefore, five elements are transferred.
	 *	// srcBuf's position = 5, destBuf's position = 5
	 *	destBuf.ReadFrom(srcBuf); 
	 *
	 *
	 * @endcode
	 *
	 * The following example has exactly the same effect as above ReadFrom() method:
	 * 
	 * @code
	 * 
	 *	int copyNum = (destBuf.GetRemaining() < srcBuf.GetRemaing())? destBuf.GetRemaining() : srcBuf.GetRemaining();
	 *	for (int i = 0; i < copyNum; i++)
	 *	{
	 *		byte b;
	 *
	 *		// Reads from the source buffer
	 *		srcBuf.GetByte(b); // srcBuf position is incremented by 1.
	 *
	 *		// Writes to the destination buffer
	 *		destBuf.SetByte(b);	// destBuf position is incremented by 1.
	 *
	 *	}
	 *
	 * @endcode
	 */
	result ReadFrom(ByteBuffer& buffer);


	/**
	 * Copies @c byte values into the current instance of buffer from the given source array @c pArray.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	pArray		The array from which bytes are to be read
	 * @param[in]	index		The starting index of the array from where the first @c byte value is to be read
	 * @param[in]	length		The number of bytes to be read from the given array
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the @c pArray is @c null.
	 * @exception	E_OUT_OF_RANGE	The specified index is outside the bounds of the data structure,
	 *								the @c index or length is less than zero.
	 * @exception	E_OVERFLOW		The operation (arithmetic/casting/conversion) has caused an overflow, or
	 *								the remaining bytes are smaller than @c length.
	 * @remarks		This method copies the specified number (@c length) of @c byte values into 
	 *				the calling object of buffer from the source array,
	 *				starting from the current position, and at the given index in the array.
	 *				After the copy operation, the position is incremented by @c length.
	 * @see			GetArray()
	 */
	result SetArray(const byte* pArray, int index, int length);


	/**
	 * Writes the given @c byte value into the calling ByteBuffer object 
	 * at the current position, and then increments the position. @n
	 * Provides a way for relative indexing and writing.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	value		The @c byte value to be written to the current instance of %ByteBuffer
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OVERFLOW		The operation (arithmetic/casting/conversion) has caused an overflow, or
	 *								the current position is not smaller than the limit.
	 * @see			GetByte()
	 */
	result SetByte(byte value);



	/**
	 * Writes the given @c byte value into the calling ByteBuffer object at the specified index. @n
	 * Provides a way for absolute indexing and writing.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	index		The index of the current instance of %ByteBuffer at which the byte is written
	 * @param[in]	value		The @c byte value to be written
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is not smaller than the limit or less than @c 0.
	 * @see			GetByte()
	 */
	result SetByte(int index, byte value);


	/**
	 * Writes the given @c double value into the calling ByteBuffer object 
	 * at the current position, and then increments the position. @n
	 * Provides a way for relative indexing and writing.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	value		The @c double value to be written
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OVERFLOW		The operation (arithmetic/casting/conversion) has caused an overflow, or
	 *								the remaining bytes of this buffer are smaller than the size of @c double.
	 * @remarks		This method writes the size of @c double number of bytes containing the given @c double value 
	 *				into the calling buffer, at the current position, and then increments the position by the size of @c double.
	 * @see			GetDouble()
	 */
	result SetDouble(double value);


	/**
	 * Writes the given @c float value into the calling ByteBuffer object 
	 * at the current position, and then increments the position. @n
	 * Provides a way for relative indexing and writing.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	value		The @c float value to be written
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OVERFLOW		The operation (arithmetic/casting/conversion) has caused an overflow, or
	 *								the remaining bytes of this buffer are smaller than the size of @c float.
	 * @remarks		This method writes the size of @c float number of bytes containing the given @c float value 
	 *				into this buffer at the current position, and then increments the position by the size of @c float.
	 * @see			GetFloat()
	 */
	result SetFloat(float value);


	/**
	 * Writes the given @c int value into the calling %ByteBuffer instance at the current
	 * position, and then increments the position. @n
	 * Provides a way for relative indexing and writing.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	value	The @c int value to be written
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OVERFLOW		The operation (arithmetic/casting/conversion) has caused an overflow, or
	 *								the remaining bytes of this buffer are smaller than the size of @c int.
	 * @remarks		This method writes the size of @c int number of bytes containing the given @c int value 
	 *				into this buffer at the current position, and then increments the position by the size of @c int.
	 * @see			GetInt()
	 */
	result SetInt(int value);


	/**
	 * Writes the given @c long value into the calling ByteBuffer instance at the current
	 * position, and then increments the position. @n
	 * Provides a way for relative indexing and writing.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	value		The @c long value to be written
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OVERFLOW		The operation (arithmetic/casting/conversion) has caused an overflow, or
	 *								the remaining bytes of this buffer are smaller than size of @c long.
	 * @remarks		This method writes the size of @c long number of bytes containing the given @c long value
	 *				into this buffer at the current position, and then increments the position by the size of @c long.
	 * @see			GetLong()
	 */
	result SetLong(long value);


	/**
	 * Writes the given @c long @c long value into the calling ByteBuffer object at the current
	 * position, and then increments the position. @n
	 * Provides a way for relative indexing and writing.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	value		The @c long @c long value to be written
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OVERFLOW		The operation (arithmetic/casting/conversion) has caused an overflow, or
	 *								the remaining bytes of this buffer are smaller than the size of @c long @c long.
	 * @remarks		This method writes the size of @c long @c long number of bytes containing the given @c long @c long value 
	 *				into this buffer at the current position, and then increments the position by the size of @c long @c long.
	 * @see			GetLongLong()
	 */
	result SetLongLong(long long value);


	/**
	 * Writes the given @c mchar value into the calling ByteBuffer object at the current
	 * position, and then increments the position. @n
	 * Provides a way for relative indexing and writing.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	value		The @c mchar value to be written
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OVERFLOW		The operation (arithmetic/casting/conversion) has caused an overflow, or
	 *								the remaining bytes of this buffer are smaller than the size of @c mchar.
	 * @remarks		This method writes the size of @c mchar number of bytes containing the given @c mchar value
	 *				into this buffer at the current position, and then increments the position by the size of @c mchar.
	 * @see			GetMchar()
	 */
	result SetMchar(mchar value);


	/**
	 * Writes the given @c short value into the current instance of ByteBuffer at the current
	 * position, and then increments the position. @n
	 * Provides a way for relative indexing and writing.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	value		The @c short value to be written
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OVERFLOW		The operation (arithmetic/casting/conversion) has caused an overflow, or
	 *								the remaining bytes of this buffer are smaller than the size of @c short.
	 * @remarks		This method writes the size of @c short number of bytes containing the given @c short value 
	 *				into this buffer at the current position, and then increments the position by the size of @c short.
	 * @see			GetShort()
	 */
	result SetShort(short value);



	/**
	 * Writes a @c double value at the specified index of the current instance of ByteBuffer. @n
	 * Provides a way for absolute indexing and writing.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	index		The index of current instance of ByteBuffer at which the bytes are written
	 * @param[in]	value		The @c double value to be written
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus the size of @c double or less than @c 0.
	 * @remarks		This method writes the size of @c double number of bytes containing the given @c double value 
	 *				into this buffer at the given index.
	 * @see			GetDouble()
	 */
	result SetDouble(int index, double value);



	/**
	 *  Writes a @c float value at the specified index of the calling ByteBuffer object. @n
	 *  Provides a way for absolute indexing and writing.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	index		The index of current instance of ByteBuffer at which the bytes are written
	 * @param[in]	value		The @c float value to be written
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus the size of @c float or less than @c 0.
	 * @remarks		This method writes the size of @c float number of bytes containing the given @c float value 
	 *				into this buffer at the given index.
	 * @see			GetFloat()
	 */
	result SetFloat(int index, float value);



	/**
	 * Writes a @c int value at the specified index of the calling ByteBuffer object. @n 
	 * Provides a way for absolute indexing and writing.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	index		The index of current instance of ByteBuffer at which the bytes are written
	 * @param[in]	value		The @c int value to be written
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus size of @c int or less than @c 0.
	 * @remarks		This method writes the size of @c int number of bytes containing the given @c int value 
	 *				into this buffer at the given index.
	 * @see			GetInt()
	 */
	result SetInt(int index, int value);



	/**
	 * Writes a @c long value at the specified index of the calling ByteBuffer object. @n
	 * Provides a way for absolute indexing and writing 
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	index		The index at which the bytes are written
	 * @param[in]	value		The @c long value to be written
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus the size of @c long or less than @c 0.
	 * @remarks		This method writes size of @c long number of bytes containing the given @c long value 
	 *				into this buffer at the given index.
	 * @see			GetLong()
	 */
	result SetLong(int index, long value);



	/**
	 * Writes a @c long @c long value at the specified index of the calling ByteBuffer object. @n
	 * Provides a way for absolute indexing and writing.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	index		The index at which the bytes will be written
	 * @param[in]	value		The @c long @c long value to be written
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus the size of @c long @c long or less than @c 0.
	 * @remarks		This method writes the size of @c long @c long number of bytes containing the given @c long @c long value 
	 *				into this buffer at the given index.
	 * @see			GetLongLong()
	 */
	result SetLongLong(int index, long long value);



	/**
	 * Writes a @c mchar value at the specified index of the calling ByteBuffer object. @n
	 * Provides a way for absolute indexing and writing
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	index		The index at which the bytes will be written
	 * @param[in]	value		The @c mchar value to be written
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus the size of @c mchar or less than @c 0.
	 * @remarks		This method writes the size of @c mchar number of bytes containing the given @c mchar value 
	 *				into this buffer at the given index.
	 * @see			GetMchar()
	 */
	result SetMchar(int index, mchar value);



	/**
	 * Writes a @c short value at the specified index of the calling ByteBuffer object. @n
	 * Provides a way for absolute indexing and writing.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	index		The index of at which the bytes are written
	 * @param[in]	value		The @c short value to be written
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the @c index is larger than the limit minus the size of @c short or less than @c 0.
	 * @remarks		This method writes the size of @c short number of bytes containing the given @c short value 
	 *				into this buffer at the given index.
	 * @see			GetShort()
	 */
	result SetShort(int index, short value);


	/**
	 * Creates a new %ByteBuffer whose content is a shared portion of 
	 * the content of the calling ByteBuffer object.
	 *
	 * @since			1.0
	 * @return		A ByteBuffer pointer to the current position of the calling object
	 * @remarks		The content of the new buffer starts at the current position of the calling %ByteBuffer instance.
	 *				The new buffer's position is zero, its capacity and limit are 
	 *				the number of bytes remaining of the current instance of ByteBuffer, 
	 *				and its mark is undefined. 	
	 */
	ByteBuffer* SliceN(void) const;


// Access

	/**
	 * Returns the pointer to the raw array of the calling buffer. @n
	 * If the capacity is zero, it returns @c null.
	 *
	 * @since			1.0
	 * @return		A pointer to the raw array of the calling buffer
	 */
	const byte* GetPointer(void) const;


// Inquery

	/** 
	 * Compares the input Object with the calling %ByteBuffer instance.
	 *
	 * @since			1.0
	 * @return		@c true if the input object equals the calling %ByteBuffer instance, @n
					else @c false
	 * @param[in]	obj	The object instance to compare with the calling object
	 * @remarks		This method returns @c true only if the specified object is also an instance of 
	 *				the %ByteBuffer class, the two buffers have the same number of remaining elements, and the two 
	 *				sequences of remaining elements are equal (considered independent of their starting positions).
	 * @see			Osp::Base::BufferBase::GetHashCode()
	 */
	virtual bool Equals(const Osp::Base::Object& obj) const;


private:

// Lifecycle

	/**
	 * This is the copy constructor for this class. 
	 */
	ByteBuffer(const ByteBuffer& buffer)
	{
		Construct(buffer);
	}

// Operator	
	/**
	 * This is the assignment operator.
	 */
	ByteBuffer& operator =(const ByteBuffer& buffer);


// Access

	/**
	 * Returns the size of byte(1).
	 *
	 * @return		The size of byte(1)
	 */
	virtual int GetTypeSize(void) const;


private:
	friend class ByteBufferEx;
	class ByteBufferEx* __pByteBufferEx;

}; // ByteBuffer

}; }; // Osp::Base
#endif // _FBASE_BYTE_BUFFER_H_

