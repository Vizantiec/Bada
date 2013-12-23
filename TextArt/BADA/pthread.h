/* 
 * Copyright (c) 2011 Samsung Electronics Co., Ltd.
 * All rights reserved.
 * This software contains confidential and proprietary information  
 * of Samsung Electronics Co., Ltd. 
 * The user of this software agrees not to disclose, disseminate or copy such  
 * Confidential Information and shall use the software only in accordance with  
 * the terms of the license agreement the user entered into with Samsung.
 */

/**
 * @file pthread.h
 * @brief This is the header file for pthread.h, 
 *        which contains the declarations & description of pthread by IEEE Std 1003.1
 *
 */

#ifndef __PTHREAD_H__
#define __PTHREAD_H__

#if __STDC_VERSION__ >= 199901L
#else //__STDC_VERSION__
#define restrict 
#endif // __STDC_VERSION__

#include <unistd.h>
#include <sched.h>
#include <sys/errno.h>
#include <time.h>


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

    /**
     * @ingroup Newlib
     * @defgroup NewlibPthread pthread
     * @brief This contains the declarations & description of pthread by IEEE Std 1003.1
     * @details You can find more detailed information at http://www.unix.org/version3/ieee_std.html
     * @since		2.0
     * @remarks	
     *			@b Header @b %file: @b \#include @b <pthread.h> @n
     *			@b Library : @b pthread @n	    
     * @{ */ 

    // anonymous enumeration
    enum {
        PTHREAD_FALSE = 0, /** Constant enumeration for PTHREAD_FALSE */
        PTHREAD_TRUE = (!PTHREAD_FALSE), /** Constant enumeration for PTHREAD_TRUE */
        PTHREAD_CREATE_JOINABLE = 0, /** Constant enumeration for PTHREAD_CREATE_JOINABLE */
        PTHREAD_CREATE_DETACHED, /** Constant enumeration for PTHREAD_CREATE_DETACHED */
        PTHREAD_MUTEX_NORMAL = 0, /** Constant enumeration for PTHREAD_MUTEX_NORMAL */
        PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL, /** Constant enumeration for PTHREAD_MUTEX_DEFAULT */
        PTHREAD_MUTEX_ERRORCHECK, /** Constant enumeration for PTHREAD_MUTEX_ERRORCHECK */
        PTHREAD_MUTEX_RECURSIVE, /** Constant enumeration for PTHREAD_MUTEX_RECURSIVE */
        PTHREAD_PROCESS_SHARED = 0, /** Constant enumeration for PTHREAD_PROCESS_SHARED */
        PTHREAD_PROCESS_PRIVATE, /** Constant enumeration for PTHREAD_PROCESS_PRIVATE */
    };

    /** 
     * @def 	PTHREAD_MAX
     * Maximum count of threads that bada can make.
     *
     * @since 2.0
     */
#define PTHREAD_MAX 16

    /** 
     * @def 	PTHREAD_STACKSIZE_MAX
     * Maximum stacksize that thread can have.
     *
     * @since 2.0
     */
#define PTHREAD_STACKSIZE_MAX 128 * 1024

    /** 
     * @def 	PTHREAD_STACKSIZE_MIN
     * Minimum stacksize that thread requires.
     *
     * @since 2.0
     */
#define PTHREAD_STACKSIZE_MIN 32 * 1024

    /** 
     * @def 	PTHREAD_ONCE_INIT
     * Static linitializer for pthread_once
     *
     * @since 2.0
     */
#define PTHREAD_ONCE_INIT PTHREAD_FALSE
    /** 
     * @def 	PTHREAD_MUTEX_INITIALIZER
     * Static linitializer for pthread_mutex with a default attribute type
     *
     * @since 2.0
     */
#define PTHREAD_MUTEX_INITIALIZER ((pthread_mutex_t) (-1)) 
    /** 
     * @def 	PTHREAD_RECURSIVE_MUTEX_INITIALIZER
     * Static linitializer for pthread_mutex with a recursive attribute type
     *
     * @since 2.0
     */
#define PTHREAD_RECURSIVE_MUTEX_INITIALIZER ((pthread_mutex_t) (-2))

    /** 
     * @def 	PTHREAD_RWLOCK_INITIALIZER
     * Static linitializer for pthread_rwlock with a default attribute type
     *
     * @since 2.0
     */
#define PTHREAD_RWLOCK_INITIALIZER ((pthread_rwlock_t) (-1))     


    /** 
     * @def 	PTHREAD_COND_INITIALIZER
     * Static linitializer for pthread_cont with a default attribute type
     *
     * @since 2.0
     */
#define PTHREAD_COND_INITIALIZER ((pthread_cond_t) (-1))     

    // type definition
    /**
     * type-definition for pthread_t 
     *
     * @since 2.0
     */
    typedef struct _pthread_t* pthread_t;
    /**
     * type-definition for key_t 
     *
     * @since 2.0
     */
    typedef unsigned int pthread_key_t;
    /**
     * type-definition for attr_t 
     *
     * @since 2.0
     */
    typedef struct _pthread_attr_t* pthread_attr_t;
    /**
     * type-definition for mutex_t 
     *
     * @since 2.0
     */
    typedef struct _pthread_mutex_t* pthread_mutex_t;
    /**
     * type-definition for mutexattr_t 
     *
     * @since 2.0
     */
    typedef struct _pthread_mutextattr_t* pthread_mutexattr_t;
    /**
     * type-definition for once_t 
     *
     * @since 2.0
     */
    typedef unsigned int pthread_once_t; 
    /**
     * type-definition for a function pointer for cleanup-callback 
     *
     * @since 2.0
     */
    typedef void (*cleanup_callback_t)(void*);
    
    struct _pthread_cleanup_t {
        cleanup_callback_t callback;
        void* arg; 
        struct _pthread_cleanup_t* prev;
    };

    /**
     * type-definition for pthread_cleanup_t
     *
     * @since 2.0
     */
    typedef struct _pthread_cleanup_t pthread_cleanup_t;

    /**
     * type-definition for pthread_rwlock_t 
     *
     * @since 2.0
     */
    typedef struct _pthread_rwlock_t* pthread_rwlock_t;

    /**
     * type-definition for pthread_rwlockattr_t 
     *
     * @since 2.0
     */
    typedef struct _pthread_rwlockattr_t* pthread_rwlockattr_t;


    /**
     * type-definition for pthread_cont_t 
     *
     * @since 2.0
     */
    typedef struct _pthread_cond_t* pthread_cond_t;

    /**
     * type-definition for pthread_contattr_t;
     *
     * @since 2.0
     */
    typedef struct _pthread_condattr_t* pthread_condattr_t;
    
    /** 
     * 
     * @brief thread creation
     * @details The pthread_create() function shall create a new thread,
     * with attributes specified by attr, within a process.
     * If attr is NULL, the default attributes shall be used.
     * If the attributes specified by attr are modified later, the thread's attributes shall not be affected.
     * Upon successful completion, pthread_create() shall store the ID of the created thread
     * in the location referenced by thread. The thread is created executing start_routine with arg
     * as its sole argument.If the start_routine returns,
     * the effect shall be as if there was an implicit call to pthread_exit()
     * using the return value of start_routine as the exit status.
     * Note that the thread in which main() was originally invoked differs from this.
     * When it returns from main(),
     * the effect shall be as if there was an implicit call to exit() using the return value of main()
     * as the exit status.
     *
     * @since 2.0
     *
     * @param tid Output for id of the newly created thread
     * @param attr Attributes for a thread being created 
     * @param start_rtn  A start routine which the thread starts with 
     * @param arg start_rtn uses this argument when it starts.
     * 
     * @return If successful, the pthread_create() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n 
     * @n [EAGAIN] The system lacked the necessary resources to create another thread,
     * or the system-imposed limit on the total number of threads in a process
     * PTHREAD_THREADS_MAX would be exceeded. 
     * @n [EPERM] The caller does not have appropriate permission
     * to set the required scheduling parameters or scheduling policy. 
     * @n [EINVAL] The attributes specified by attr are invalid. 
     */
    int pthread_create(pthread_t* restrict  tid,
                       const pthread_attr_t* restrict attr,
                       void *(*start_rtn)(void*),
                       void* restrict arg);
    
    /**
     * @brief 	Gets the calling thread ID
     * @details The pthread_self() function shall return the thread ID of the calling thread.
     *
     * @since   2.0
     * 
     * @return  The thread ID of the calling thread
     * 
     * @remarks No errors are defined 
     */
    pthread_t pthread_self(void);

    /** 
     * @brief Terminates the thread
     * @details The pthread_exit() function shall terminate the calling thread
     * and make the value value_ptr available to any successful join with the terminating thread.
     * Any cancellation cleanup handlers that have been pushed and not yet popped shall be popped in the reverse order
     * that they were pushed and then executed.
     * After all cancellation cleanup handlers have been executed,
     * if the thread has any thread-specific data,
     * appropriate destructor functions shall be called in an unspecified order.
     * Thread termination does not release any application visible process resources,
     * including, but not limited to, mutexes and file descriptors,
     * nor does it perform any process-level cleanup actions,
     * including, but not limited to, calling any atexit() routines that may exist.
     *
     * @since  2.0
     * 
     * @param  rval The value available to any successful join with the terminating thread
     * 
     * @remarks No errors are defined 
     */
    void pthread_exit(void* rval);
    
    /** 
     * @brief Waits for thread termination
     * @details The pthread_join() function shall suspend execution of the calling thread
     * until the target thread terminates, unless the target thread has already terminated.
     * On return from a successful pthread_join() call with a non-NULL value_ptr argument,
     * the value passed to pthread_exit() by the terminating thread shall be made available
     * in the location referenced by value_ptr.
     * When a pthread_join() returns successfully, the target thread has been terminated.
     * The results of multiple simultaneous calls to pthread_join() specifying the same target thread are undefined.
     * If the thread calling pthread_join() is canceled, then the target thread shall not be detached.
     * 
     * @since 2.0
     * 
     * @param thread Thread id to be joined 
     * @param rval Return value when the joined thread terminates
     * 
     * @return If successful, the pthread_join() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [ESRCH] No thread could be found corresponding to that specified by the given thread ID. 
     * @n [EDEADLK] A deadlock was detected or the value of thread specifies the calling thread.
     * @n [EINVAL] The value specified by thread does not refer to a joinable thread. 
     */
    int pthread_join(pthread_t thread, void** rval);

    /** 
     * @brief 	Compares thread IDs
     * @details This function shall compare the thread IDs t1 and t2.
     *
     * @since 2.0
     * 
     * @param tid1 Thread ID 
     * @param tid2 Thread ID
     * 
     * @return The pthread_equal() function shall return a non-zero value if t1 and t2 are equal;
     * otherwise, zero shall be returned.
     * @n If either t1 or t2 are not valid thread IDs, the behavior is undefined.
     * @remarks No errors are defined 
     */
    int pthread_equal(pthread_t tid1, pthread_t tid2);

    /** 
     * @brief Initializes the thread attributes object
     * @details The pthread_attr_init() function shall initialize a thread attributes object attr
     * with the default value for all of the individual attributes used by a given implementation.
     *
     * @since  2.0
     * 
     * @param  attr Attributes object to be initialized
     * 
     * @return If successful, the pthread_attr_init() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [ENOMEM] Insufficient memory exists to initialize the thread attributes object.
     * @n [EBUSY] The implementation has detected an attempt to reinitialize the thread attribute
     * referenced by attr, a previously initialized, but not yet destroyed, thread attribute.
     */
    int pthread_attr_init(pthread_attr_t *attr);
    
    /** 
     * @brief Destroys the thread attributes object
     * @details The pthread_attr_destroy() function shall destroy a thread attributes object.
     * It causes pthread_attr_destroy() to set attr to an implementation-defined invalid value.
     * A destroyed attr attributes object can be reinitialized using pthread_attr_init();
     * the results of otherwise referencing the object after it has been destroyed are undefined.
     * 
     * @since  2.0
     * 
     * @param  attr Attributes object to be destroyed
     * 
     * @return If successful, the pthread_attr_init() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The value specified by attr does not refer to an initialized thread attribute object. 
     */
    int pthread_attr_destroy(pthread_attr_t *attr);

    /** 
     * @brief Sets the detachstate attribute
     * @details The pthread_attr_setdetachstate shall set the detachstate attribute in the attr object.
     * @n The application shall set detachstate to either PTHREAD_CREATE_DETACHED or PTHREAD_CREATE_JOINABLE
     * @n A value of PTHREAD_CREATE_DETACHED shall cause all threads created with attr to be in the detached state,
     * whereas using a value of PTHREAD_CREATE_JOINABLE shall cause all threads created with attr
     * to be in the joinable state. The default value of the detachstate attribute shall be PTHREAD_CREATE_JOINABLE.
     *
     * @since 2.0
     * 
     * @param attr Attribute object to be set 
     * @param detachstate Detach state to be set with
     * 
     * @return If successful, the pthread_attr_setdetachstate() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The value of detachstate was not valid,
     * or the value specified by attr does not refer to an initialized thread attribute object.
     */
    int pthread_attr_setdetachstate(pthread_attr_t* attr,
                                    int detachstate);
    
    /** 
     * @brief Gets the detachstate attribute
     * @details The pthread_attr_getdetachstate shall get the detachstate attribute in the attr object.
     * @n The application shall get detachstate of either PTHREAD_CREATE_DETACHED or PTHREAD_CREATE_JOINABLE
     *
     * @since 2.0
     * 
     * @param attr Attribute object to be got 
     * @param detachstate Detach state to be got
     * 
     * @return If successful, the pthread_attr_setdetachstate() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The value specified by attr does not refer to an initialized thread attribute object.
     */
    int pthread_attr_getdetachstate(const pthread_attr_t* restrict attr,
                                    int* detachstate);

    /** 
     * @brief Initializes a mutex
     * @details The pthread_mutex_init() function shall initialize the mutex
     * referenced by mutex with attributes specified by attr.
     * If attr is NULL, the default mutex attributes are used;
     * the effect shall be the same as passing the address of a default mutex attributes object.
     * Upon successful initialization, the state of the mutex becomes initialized and unlocked.
     * @n Attempting to initialize an already initialized mutex results in undefined behavior.
     *
     * @since 2.0
     * 
     * @param mutex Mutex to be initialized
     * @param attr Attribute of the mutex to be used with
     * 
     * @return If successful, the pthread_mutex_init() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EAGAIN] The system lacked the necessary resources (other than memory)
     * to initialize another mutex.
     * @n [ENOMEM] Insufficient memory exists to initialize the mutex.
     * @n [EPERM] The caller does not have the privilege to perform the operation
     * @n [EBUSY] The implementation has detected an attempt
     * to reinitialize the object referenced by mutex, a previously initialized,
     * but not yet destroyed, mutex.
     * @n [EINVAL] The value specified by attr is invalid. 
     */
    int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t* restrict attr);
    
    /** 
     * @brief Destroys the mutex
     * @details The pthread_mutex_destroy() function shall destroy the mutex object
     * referenced by mutex; the mutex object becomes, in effect, uninitialized.
     * An implementation may cause pthread_mutex_destroy() to set the object referenced
     * by mutex to an invalid value. A destroyed mutex object can be reinitialized
     * using pthread_mutex_init(); the results of otherwise referencing the object
     * after it has been destroyed are undefined.
     *
     * @since 2.0
     *
     * @param mutex Mutex to be destroyed
     * 
     * @return If successful, the pthread_mutex_destroy() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EBUSY] The implementation has detected an attempt to destroy the object referenced
     * by mutex while it is locked or referenced by another thread.
     * @n [EINVAL] The value specified by mutex is invalid. 
     */
    int pthread_mutex_destroy(pthread_mutex_t *mutex);
    
    /** 
     * @brief Locks a mutex
     * @details The mutex object referenced by mutex shall be locked by calling pthread_mutex_lock().
     * If the mutex is already locked, the calling thread shall block until the mutex becomes available.
     * This operation shall return with the mutex object referenced
     * by mutex in the locked state with the calling thread as its owner
     * @n If the mutex type is PTHREAD_MUTEX_NORMAL, deadlock detection shall not be provided.
     * Attempting to relock the mutex causes deadlock.
     * If a thread attempts to unlock a mutex that it has not locked or a mutex which is unlocked,
     * undefined behavior results.
     * @n If the mutex type is PTHREAD_MUTEX_RECURSIVE,
     * then the mutex shall maintain the concept of a lock count.
     * When a thread successfully acquires a mutex for the first time,
     * the lock count shall be set to one. Every time a thread relocks this mutex,
     * the lock count shall be incremented by one. Each time the thread unlocks the mutex,
     * the lock count shall be decremented by one. When the lock count reaches zero,
     * the mutex shall become available for other threads to acquire.
     * If a thread attempts to unlock a mutex that it has not locked or a mutex which is unlocked,
     * an error shall be returned.
     * @n If the mutex type is PTHREAD_MUTEX_DEFAULT,
     * attempting to recursively lock the mutex results in undefined behavior.
     * Attempting to unlock the mutex if it was not locked
     * by the calling thread results in undefined behavior.
     * Attempting to unlock the mutex if it is not locked results in undefined behavior.
     * 
     * @since 2.0
     * 
     * @param mutex Mutex to be locked 
     * 
     * @return If successful, the pthread_mutex_lock() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The value specified by mutex does not refer to an initialized mutex object.
     * @n [EAGAIN] The mutex could not be acquired
     * because the maximum number of recursive locks for mutex has been exceeded.  
     */
    int pthread_mutex_lock(pthread_mutex_t *mutex);

    /** 
     * @brief Locks a mutex
     * @details The pthread_mutex_trylock() function shall be equivalent to pthread_mutex_lock(),
     * except that if the mutex object referenced by mutex is currently locked
     * (by any thread, including the current thread), the call shall return immediately.
     * If the mutex type is PTHREAD_MUTEX_RECURSIVE and the mutex is currently owned
     * by the calling thread, the mutex lock count shall be incremented
     * by one and the pthread_mutex_trylock() function shall immediately return success
     *
     * @since 2.0
     * 
     * @param mutex Mutex to be locked 
     * 
     * @return If successful, the pthread_mutex_trylock() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The value specified by mutex does not refer to an initialized mutex object.
     * @n [EBUSY] The mutex could not be acquired it was already locked.
     * @n [EAGAIN] The mutex could not be acquired
     * because the maximum number of recursive locks for mutex has been exceeded.  
     */
    int pthread_mutex_trylock(pthread_mutex_t *mutex);


    /** 
     * @brief Locks a mutex with a time limit
     * @details The pthread_mutex_timedlock() function shall lock the mutex object
     * referenced by mutex. If the mutex is already locked,
     * the calling thread shall block until the mutex becomes available
     * as in the pthread_mutex_lock() function.
     * If the mutex cannot be locked
     * without waiting for another thread to unlock the mutex,
     * this wait shall be terminated when the specified timeout expires.
     * The timeout shall expire when the absolute time specified
     * by abs_timeout passes, as measured by the clock on
     * which timeouts are based (that is, when the value of that clock equals
     * or exceeds abs_timeout), or if the absolute time specified
     * by abs_timeout has already been passed at the time of the call.
     *
     * @since 2.0
     * 
     * @param p_mutex Mutex to be locked 
     * @param p_tspec Timeout
     * 
     * @return If successful, the pthread_mutex_timedlock() function
     * shall return zero; otherwise, an error number shall be returned
     * to indicate the error.
     * @n [EINVAL] The value specified by mutex
     * does not refer to an initialized mutex object.
     * @n [EAGAIN] The mutex could not be acquired
     * because the maximum number of recursive locks for mutex has been exceeded.
     * @n [ETIMEDOUT] The mutex could not be locked
     * before the specified timeout expired. 
     * @n [EDEADLK] A deadlock condition was detected
     * or the current thread already owns the mutex. 
     */
    int pthread_mutex_timedlock(pthread_mutex_t* p_mutex,
                                const struct timespec* p_tspec);

    /** 
     * @brief Unlocks a mutex
     * @details The pthread_mutex_unlock() function shall release the mutex object referenced by mutex.
     * The manner in which a mutex is released is dependent upon the mutex's type attribute.
     * If there are threads blocked on the mutex object referenced by mutex
     * when pthread_mutex_unlock() is called, resulting in the mutex becoming available,
     * the scheduling policy shall determine which thread shall acquire the mutex.
     *
     * @since 2.0
     * 
     * @param mutex Mutex to be unlocked
     * 
     * @return If successful, the pthread_mutex_unlock() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The value specified by mutex does not refer to an initialized mutex object.
     * @n [EPERM] The current thread does not own the mutex. 
     */
    int pthread_mutex_unlock(pthread_mutex_t *mutex);
    
    
    /** 
     * @brief Initializes the mutex attributes object
     * @details The pthread_mutexattr_init() function shall initialize a mutex attributes object attr
     * with the default value for all of the attributes defined by the implementation.
     * Results are undefined if pthread_mutexattr_init() is called
     * specifying an already initialized attr attributes object.
     *
     * @since 2.0 
     * 
     * @param attr Attributes object to be set 
     * 
     * @return If successful, the pthread_mutexattr_init() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [ENOMEM] Insufficient memory exists to initialize the mutex attributes object.
     */
    int pthread_mutexattr_init(pthread_mutexattr_t* attr);

    /**
     * @brief Destroys the mutex attributes object.
     * @details The pthread_mutexattr_destroy() function shall destroy
     * a mutex attributes object; the object becomes, in effect, uninitialized.
     * An implementation may cause pthread_mutexattr_destroy() to set the object
     * referenced by attr to an invalid value.
     * A destroyed attr attributes object can be reinitialized
     * using pthread_mutexattr_init();
     * the results of otherwise referencing the object
     * after it has been destroyed are undefined.
     *
     * @since 2.0
     * 
     * @param attr Attributes object to be destroyed
     * 
     * @return If successful, the pthread_mutexattr_destroy() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The value specified by attr is invalid. 
     */
    int pthread_mutexattr_destroy(pthread_mutexattr_t* attr);

    /** 
     * @brief Get the mutex type attribute
     * @details The pthread_mutexattr_gettype() shall get the mutex type attribute.
     * This attribute is set in the type parameter to these functions.
     * The default value of the type attribute is PTHREAD_MUTEX_DEFAULT.
     * @n The type of mutex is contained in the type attribute of the mutex attributes.
     * Valid mutex types include:
     * @n PTHREAD_MUTEX_NORMAL This type of mutex does not detect deadlock.
     * A thread attempting to relock this mutex without first unlocking it shall deadlock.
     * Attempting to unlock a mutex locked by a different thread results
     * in undefined behavior. Attempting to unlock an unlocked mutex results
     * in undefined behavior.
     * @n PTHREAD_MUTEX_RECURSIVE A thread attempting to relock this mutex
     * without first unlocking it shall succeed in locking the mutex.
     * The relocking deadlock which can occur
     * with mutexes of type PTHREAD_MUTEX_NORMAL cannot occur
     * with this type of mutex.
     * Multiple locks of this mutex shall require the same number of unlocks
     * to release the mutex before another thread can acquire the mutex.
     * A thread attempting to unlock a mutex
     * which another thread has locked shall return with an error.
     * A thread attempting to unlock an unlocked mutex shall return with an error.
     * @n PTHREAD_MUTEX_DEFAULT This mutex type is mapped to PTHREAD_MUTEX_NORMAL
     *
     * @since 2.0
     *
     * @param attr Attribute object to be got
     * @param type Mutex type to get
     * 
     * @return If successful, the pthread_mutexattr_gettype() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The value specified by attr is invalid. 
     */
    int pthread_mutexattr_gettype(const pthread_mutexattr_t* restrict attr,
                                  int* restrict type);
    
    /** 
     * @brief Sets the mutex type attribute
     * @details The pthread_mutexattr_settype() shall set the mutex type attribute.
     * This attribute is set in the type parameter to these functions.
     *
     * @since 2.0
     *
     * @param attr Attribute object to be got
     * @param type Mutex type to get
     * 
     * @return If successful, the pthread_mutexattr_settype() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The value type is invalid. 
     */
    int pthread_mutexattr_settype(pthread_mutexattr_t* attr, int type);
    
    /** 
     * @brief Sets a thread-specific data
     * The pthread_setspecific() function shall associate a thread-specific value
     * with a key obtained via a previous call to pthread_key_create().
     * Different threads may bind different values to the same key.
     * These values are typically pointers to blocks of dynamically allocated memory
     * that have been reserved for use by the calling thread.
     * @n The effect of calling pthread_getspecific() or pthread_setspecific()
     * with a key value not obtained from pthread_key_create()
     * or after key has been deleted with pthread_key_delete() is undefined
     *
     * @since 2.0
     *
     * @param key Key to a thread specific data 
     * @param value Value with the key 
     * 
     * @return If successful, the pthread_setspecific() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     */
    int pthread_setspecific(pthread_key_t key, const void* value);
        
    /** 
     * @brief Gets a thread-specific data 
     * @details The pthread_getspecific() function shall return the value
     * currently bound to the specified key on behalf of the calling thread.
     * @n The effect of calling pthread_getspecific() or pthread_setspecific()
     * with a key value not obtained from pthread_key_create()
     * or after key has been deleted with pthread_key_delete() is undefined
     *
     * @since 2.0
     *
     * @param key Key to a thread specific data
     * 
     * @return The pthread_getspecific() function shall return the thread-specific data value
     * associated with the given key. If no thread-specific data value is associated with key,
     * then the value NULL shall be returned.
     */
    void* pthread_getspecific(pthread_key_t key);

    /** 
     * @brief Creates a thread-specific data key
     * @details The pthread_key_create() function shall create a thread-specific data key
     * visible to all threads in the process. Key values provided by pthread_key_create()
     * are opaque objects used to locate thread-specific data.
     * Although the same key value may be used by different threads,
     * the values bound to the key by pthread_setspecific() are maintained on a per-thread basis
     * and persist for the life of the calling thread.
     * @n Upon key creation, the value NULL shall be associated
     * with the new key in all active threads.
     * Upon thread creation, the value NULL shall be associated
     * with all defined keys in the new thread.
     * @n An optional destructor function may be associated with each key value.
     * At thread exit, if a key value has a non-NULL destructor pointer,
     * and the thread has a non-NULL value associated with that key,
     * the value of the key is set to NULL,
     * and then the function pointed to is called with the previously associated value
     * as its sole argument. The order of destructor calls is unspecified
     * if more than one destructor exists for a thread when it exits.
     * @n If, after all the destructors have been called
     * for all non-NULL values with associated destructors,
     * there are still some non-NULL values with associated destructors,
     * then the process is repeated. 
     *
     * @since 2.0
     * 
     * @param key Key to a thread-specific data
     * @param destructor Callback function for deleting key
     * 
     * @return If successful, the pthread_key_create() function shall store the newly created key value at *key
     * and shall return zero. Otherwise, an error number shall be returned to indicate the error.
     * @n [EAGAIN] The system lacked the necessary resources to create another thread-specific data key,
     * or the system-imposed limit on the total number of keys per process
     * {PTHREAD_KEYS_MAX} has been exceeded.
     * @n [ENOMEM] Insufficient memory exists to create the key. 
     */
    int pthread_key_create(pthread_key_t* key,
                           void (*destructor)(void *));

    /** 
     * @brief Deletes a thread specific data key
     * @details The pthread_key_delete() function shall delete a thread-specific data key
     * previously returned by pthread_key_create(). The thread-specific data values associated
     * with key need not be NULL at the time pthread_key_delete() is called.
     * It is the responsibility of the application to free any application storage
     * or perform any cleanup actions for data structures
     * related to the deleted key or associated thread-specific data in any threads;
     * this cleanup can be done either before or after pthread_key_delete() is called.
     * Any attempt to use key following the call to pthread_key_delete()
     * results in undefined behavior.
     *
     * @since 2.0
     *
     * @param key Key to a specific data 
     * 
     * @return If successful, the pthread_key_delete() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The key value is invalid. 
     */
    int pthread_key_delete(pthread_key_t key);

    /** 
     * @brief Calls a routine once at most 
     * @details The first call to pthread_once() by any thread in a process,
     * with a given once_control, shall call the init_routine with no arguments.
     * Subsequent calls of pthread_once() with the same once_control
     * shall not call the init_routine. On return from pthread_once(),
     * init_routine shall have completed. The once_control parameter
     * shall determine whether the associated initialization routine has been called.
     *
     * @since 2.0
     *
     * @param initflag Flag for indicating whether it is used
     * @param initfn Routine to be called 
     * 
     * @return If successful, the pthread_once() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] If either once_control or init_routine is invalid. 
     */
    int pthread_once(pthread_once_t* initflag, void (*initfn)(void));

    /** 
     * @brief Worker for pthread_cleanup_push()
     * @details The pthread_cleanup_push() function shall push the specified cancellation cleanup handler
     * routine onto the calling thread's cancellation cleanup stack.
     * The cancellation cleanup handler shall be popped
     * from the cancellation cleanup stack and invoked with the argument arg when:
     * @n The thread exits (that is, calls pthread_exit()).
     * @n The thread acts upon a cancellation request.
     * @n The thread calls pthread_cleanup_pop() with a non-zero execute argument.
     *
     * @since 2.0
     * 
     * @param cleanup Cleanup handler structure to be handled internally 
     * @param callback Handler to be called 
     * @param arg Argument to the handler 
     * 
     * @return No return
     * @remarks Do not call _pthread_cleanup_push directly. Use pthread_cleanup_push
     */
    extern void _pthread_cleanup_push(pthread_cleanup_t* cleanup, cleanup_callback_t callback, void* arg);

    
    /** 
     * @brief Worker for _pthread_cleanup_pop()
     * @details The pthread_cleanup_pop() function shall remove the routine
     * at the top of the calling thread's cancellation cleanup stack
     * and optionally invoke it (if execute is non-zero).
     * 
     * @since 2.0
     * 
     * @param execute If non-zero, the handler will be called 
     * 
     * @return No return
     * @remarks Do not call _pthread_cleanup_pop() directly. Use pthread_cleanup_pop()
     */

    extern void _pthread_cleanup_pop(int execute);

    /** 
     * @brief Wrapper for _pthread_cleanup_push()
     * 
     * @since 2.0
     * 
     * @param rtn Handler to be called 
     * @param arg Argument to the handler 
     * 
     * @return No return
     * @remarks See _pthread_cleanup_push()
     * @n pthread_cleanup_push() should be followed by pthread_cleanup_pop()
	 * @hideinitializer
     */
#define pthread_cleanup_push(rtn, arg)          \
    {                                           \
    pthread_cleanup_t cleanup;                  \
    _pthread_cleanup_push(&cleanup, rtn, arg);

    /** 
     * @brief Wrapper for _pthread_cleanup_pop()
     * 
     * @since 2.0
     * 
     * @param execute If non-zero, the handler will be called 
     * 
     * @return No return
     * @remarks See _pthread_cleanup_pop()
     * @n pthread_cleanup_pop() should follow pthread_cleanup_push()
	 * @hideinitializer
     */
#define pthread_cleanup_pop(execute)            \
    _pthread_cleanup_pop(execute);              \
    }

    /** 
     * @brief Initializes a pthread read-write lock
     * @details The pthread_rwlock_init() function shall allocate any resources
     * required to use the read-write lock referenced by rwlock
     * and initializes the lock to an unlocked state with attributes referenced by attr.
     * If attr is NULL, the default read-write lock attributes shall be used;
     * the effect is the same as passing the address of
     * a default read-write lock attributes object. Once initialized,
     * the lock can be used any number of times without being reinitialized.
     * Results are undefined if pthread_rwlock_init() is called specifying
     * an already initialized read-write lock. Results are undefined
     * if a read-write lock is used without first being initialized.
     *
     * @since 2.0
     * 
     * @param rwlock pthread_rwlock to be initialized
     * @param attr pthread_rwlockattr to be initialized with
     * 
     * @return If successful, the pthread_rwlock_init() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EBUSY] The implementation has detected an attempt
     * to reinitialize the object referenced by rwlock,
     * a previously initialized but not yet destroyed read-write lock. 
     * @n [EINVAL] The value specified by attr is invalid. 
     * @n [EAGAIN] The system lacked the necessary resources
     * (other than memory) to initialize another read-write lock. 
     * @n [ENOMEM] Insufficient memory exists to initialize the read-write lock. 
     * @n [EPERM] The caller does not have the privilege to perform the operation.
     */
    int pthread_rwlock_init(pthread_rwlock_t* restrict rwlock,
                            const pthread_rwlockattr_t* restrict attr);
    
    /** 
     * @brief Destroys a pthread read-write lock
     * @details The pthread_rwlock_destroy() function shall destroy
     * the read-write lock object referenced by rwlock
     * and release any resources used by the lock.
     * The effect of subsequent use of the lock is undefined
     * until the lock is reinitialized by another call to pthread_rwlock_init().
     * An implementation may cause pthread_rwlock_destroy()
     * to set the object referenced by rwlock to an invalid value.
     * Results are undefined if pthread_rwlock_destroy() is called
     * when any thread holds rwlock. Attempting to destroy an uninitialized read-write lock
     * results in undefined behavior.
     *
     * @since 2.0
     * 
     * @param rwlock pthread_rwlock to be destroyed
     * 
     * @return If successful, the pthread_rwlock_destroy() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EBUSY] The implementation has detected an attempt
     * to destroy the object referenced by rwlock while it is locked. 
     * @n [EINVAL] The value specified by rwlock is invalid. 
     */
    int pthread_rwlock_destroy(pthread_rwlock_t *rwlock);

    /** 
     * @brief Locks a read-write lock
     * @details The pthread_rwlock_rdlock() function shall apply a read lock
     * to the read-write lock referenced by rwlock.
     * The calling thread acquires the read lock
     * if a writer does not hold the lock and there are no writers blocked on the lock.
     *
     * @since 2.0 
     *     
     * @param rwlock pthread_rwlock to be locked 
     * 
     * @return If successful, the pthread_rwlock_rdlock() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error
     * @n [EINVAL] The value specified by rwlock does not refer
     * to an initialized read-write lock object.
     * @n [EAGAIN] The read lock could not be acquired
     * because the maximum number of read locks for rwlock has been exceeded.
     * @n [EDEADLK] A deadlock condition was detected
     * or the current thread already owns the read-write lock for writing. 
     */
    int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock);
    
    /** 
     * @brief Trys to lock a read-write lock
     * @details The pthread_rwlock_tryrdlock() function shall apply a read lock
     * as in the pthread_rwlock_rdlock() function,
     * with the exception that the function shall fail
     * if the equivalent pthread_rwlock_rdlock() call would have blocked the calling thread.
     * In no case shall the pthread_rwlock_tryrdlock() function ever block;
     * it always either acquires the lock or fails and returns immediately.
     *
     * @since 2.0
     * 
     * @param rwlock pthread_rwlock to be locked
     * 
     * @return If successful, the pthread_rwlock_tryrdlock() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error
     * @n [EBUSY] The read-write lock could not be acquired for reading
     * because a writer holds the lock or a writer
     * with the appropriate priority was blocked on it.
     * @n [EINVAL] The value specified by rwlock does not refer
     * to an initialized read-write lock object.
     * @n [EAGAIN] The read lock could not be acquired
     * because the maximum number of read locks for rwlock has been exceeded.
     */
    int pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock);
    
    /**
     * @brief Locks a read-write lock for the purpose of writing 
     * @details The pthread_rwlock_wrlock() function shall apply a write lock
     * to the read-write lock referenced by rwlock.
     * The calling thread acquires the write lock
     * if no other thread (reader or writer) holds the read-write lock rwlock.
     * Otherwise, the thread shall block until it can acquire the lock.
     * The calling thread may deadlock
     * if at the time the call is made it holds the read-write lock
     * (whether a read or write lock).
     *
     * @since 2.0
     * 
     * @param rwlock Read-write lock to be locked 
     * 
     * @return If successful, the pthread_rwlock_wrlock() function
     * shall return zero; otherwise, an error number
     * shall be returned to indicate the error.
     * @n [EDEADLK] A deadlock condition was detected
     * or the current thread already owns the read-write lock
     * for writing or reading. 
     */
    int pthread_rwlock_wrlock(pthread_rwlock_t *rwlock);    

    /** 
     * @brief Trys to lock a read-write lock for the purpose of writing
     * @details The pthread_rwlock_trywrlock() function
     * shall apply a write lock like the pthread_rwlock_wrlock() function,
     * with the exception that the function shall fail
     * if any thread currently holds rwlock
     *
     * @since 2.0
     * 
     * @param rwlock Read-write lock to be locked 
     * 
     * @return The pthread_rwlock_trywrlock() function shall return zero
     * if the lock for writing on the read-write lock object referenced
     * by rwlock is acquired. Otherwise, an error number shall be returned
     * to indicate the error.
     * @n [EBUSY] The read-write lock could not be acquired
     * for writing because it was already locked for reading or writing.
     * @n [EINVAL] The value specified by rwlock does not refer
     * to an initialized read-write lock object. 
     */
    int pthread_rwlock_trywrlock(pthread_rwlock_t *rwlock);
    
    /** 
     * @brief Unlocks a read-write lock object
     * @details If this function is called to release a read lock
     * from the read-write lock object
     * and there are other read locks currently held on this read-write lock object,
     * the read-write lock object remains in the read locked state.
     * If this function releases the last read lock for this read-write lock object,
     * the read-write lock object shall be put in the unlocked state with no owners.
     *
     * @since 2.0
     * 
     * @param rwlock pthread_rwlock to be unlocked 
     * 
     * @return If successful, the pthread_rwlock_unlock() function shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The value specified by rwlock does not refer to
     * an initialized read-write lock object.
     * @n [EPERM] The current thread does not hold a lock on the read-write lock. 
     */
    int pthread_rwlock_unlock(pthread_rwlock_t *rwlock);

    /** 
     * @brief Destroys a condition variable
     * @details The pthread_cond_destroy() function shall destroy
     * the given condition variable specified by cond; the object becomes,
     * in effect, uninitialized. An implementation may cause pthread_cond_destroy()
     * to set the object referenced by cond to an invalid value.
     * A destroyed condition variable object can be reinitialized using pthread_cond_init();
     * the results of otherwise referencing the object after it has been destroyed are undefined.
     * @n It shall be safe to destroy an initialized condition variable upon
     * which no threads are currently blocked.
     * Attempting to destroy a condition variable upon
     * which other threads are currently blocked results in undefined behavior.
     * 
     * @since 2.0
     * 
     * @param cond Condition variable to be destroyed
     * 
     * @return If successful, the pthread_cond_destroy() shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EBUSY] The implementation has detected an attempt to destroy the object referenced
     * by cond while it is referenced (for example, while being used in a pthread_cond_wait()
     * or pthread_cond_timedwait()) by another thread.
     * @n [EINVAL] The value specified by cond is invalid. 
     */
    int pthread_cond_destroy(pthread_cond_t *cond);
    
    /** 
     * @brief Initializes a condition variable 
     * @details The pthread_cond_init() function shall initialize
     * the condition variable referenced by cond with attributes referenced by attr.
     * If attr is NULL, the default condition variable attributes shall be used;
     * the effect is the same as passing the address
     * of a default condition variable attributes object.
     * Upon successful initialization,
     * the state of the condition variable shall become initialized.
     *
     * @since 2.0
     * 
     * @param cond Condition variable to be initialized
     * @param attr Attribute to be used when initializina a condition variable
     * 
     * @return If successful, the pthread_cond_init() shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EAGAIN] The system lacked the necessary resources
     * (other than memory) to initialize another condition variable.
     * @n [ENOMEM] Insufficient memory exists to initialize the condition variable.
     * @n [EBUSY] The implementation has detected an attempt
     * to reinitialize the object referenced by cond,
     * a previously initialized, but not yet destroyed, condition variable.
     * [EINVAL] The value specified by attr is invalid. 
     */    
    int pthread_cond_init(pthread_cond_t *restrict cond, const pthread_condattr_t *restrict attr);

    /** 
     * @brief Waits a condition
     * @details The pthread_cond_wait() shall block on a condition variable.
     * This shall be called with mutex locked by the calling thread or undefined behavior results.
     * This function atomically releases mutex and causes the calling thread
     * to block on the condition variable cond; atomically here means
     * "atomically with respect to access by another thread
     * to the mutex and then the condition variable".
     * That is, if another thread is able to acquire the mutex
     * after the about-to-block thread has released it, then a subsequent call to pthread_cond_broadcast()
     * or pthread_cond_signal() in that thread shall behave
     * as if it were issued after the about-to-block thread has blocked.
     *
     * @since 2.0
     * 
     * @param cond Condition variable to wait for 
     * @param mutex A mutex to guarantee an atomic operation
     * 
     * @return Upon successful completion, a value of zero shall be returned;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The value specified by cond or mutex is invalid.
     * @n [EPERM] The mutex was not owned by the current thread at the time of the call. 
     */
    int pthread_cond_wait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex);
    
    /** 
     * @brief Waits a condition with a time limit 
     * @details The pthread_cond_timedwait() shall block on a condition variable and is equivalent to pthread_cond_wait(), except that an error is returned if the absolute time specified by abstime passes.
     * This shall be called with mutex locked by the calling thread or undefined behavior results.
     * This function atomically releases mutex and causes the calling thread
     * to block on the condition variable cond; atomically here means
     * "atomically with respect to access by another thread
     * to the mutex and then the condition variable".
     * That is, if another thread is able to acquire the mutex
     * after the about-to-block thread has released it, then a subsequent call to pthread_cond_broadcast()
     * or pthread_cond_signal() in that thread shall behave
     * as if it were issued after the about-to-block thread has blocked.
     *
     * @since 2.0
     * 
     * @param cond Condition variable to wait for 
     * @param mutex A mutex to guarantee an atomic operation
     * @param abstime An absolute time to be specified
     * 
     * @return Upon successful completion, a value of zero shall be returned;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The value specified by cond or mutex is invalid.
     * @n [EPERM] The mutex was not owned by the current thread at the time of the call.
     * @n  [ETIMEDOUT] The time specified by abstime
     * to pthread_cond_timedwait() has passed.
     * @n [EINVAL] The value specified by abstime is invalid.
     */
    int pthread_cond_timedwait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex, const struct timespec *restrict abstime);

    /** 
     * @brief Signals a condition
     * @details The pthread_cond_signal() function shall unblock
     * at least one of the threads that are blocked
     * on the specified condition variable cond (if any threads are blocked on cond).
     *
     * @since 2.0
     * 
     * @param cond Condition variable to be signaled 
     * 
     * @return If successful, the pthread_cond_signal() shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The value cond does not refer to an initialized condition variable. 
     */
    int pthread_cond_signal(pthread_cond_t *cond);
    
    /** 
     * @brief Broadcasts a condition.
     * @details The pthread_cond_broadcast() function shall unblock all threads
     * currently blocked on the specified condition variable cond.
     *
     * @since 2.0
     * 
     * @param cond Condition variable to be signaled 
     * 
     * @return If successful, the pthread_cond_broadcast() shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The value cond does not refer to an initialized condition variable. 
     */
    int pthread_cond_broadcast(pthread_cond_t *cond);
    
    /** 
     * @brief Gets the stacksize attributes
     * @details The pthread_attr_getstacksize() shall get the thread creation stacksize
     * attribute in the attr object.
     *
     * @since 2.0
     * 
     * @param attr Attribute to get 
     * @param stacksize A pointer to a size variable to be set 
     * 
     * @return Upon successful completion, pthread_attr_getstacksize() shall return a value of 0;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The value specified by attr does not refer to
     * an initialized thread attribute object. 
     */
    int pthread_attr_getstacksize(const pthread_attr_t *restrict attr, size_t *restrict stacksize);
    
    /** 
     * @brief Sets the stacksize attributes
     * @details The pthread_attr_setstacksize() shall set the thread creation stacksize
     * attribute in the attr object.
     *
     * @since 2.0
     * 
     * @param attr Attribute to be set 
     * @param stacksize Stack size to set with 
     * 
     * @return Upon successful completion, pthread_attr_setstacksize() shall return a value of 0;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The value specified by attr does not refer to
     * an initialized thread attribute object. 
     */
    int pthread_attr_setstacksize(pthread_attr_t *attr, size_t stacksize);
    
    /** 
     * @brief Destroys a read-write lock attribute
     * @details The pthread_rwlockattr_destroy() function shall destroy
     * a read-write lock attributes object. A destroyed attr attributes object
     * can be reinitialized using pthread_rwlockattr_init();
     * the results of otherwise referencing the object
     * after it has been destroyed are undefined.
     * An implementation may cause pthread_rwlockattr_destroy() to set the object
     * referenced by attr to an invalid value
     *
     * @since 2.0
     * 
     * @param attr Attribute to be destroyed
     * 
     * @return If successful, the pthread_rwlockattr_destroy() shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The value specified by attr is invalid. 
     */
    int pthread_rwlockattr_destroy(pthread_rwlockattr_t *attr);

    /** 
     * @brief Initializes a read-write lock attribute
     * @details The pthread_rwlockattr_init() function shall initialize
     * a read-write lock attributes object attr with the default value
     * for all of the attributes defined by the implementation.
     *
     * @since 2.0
     * 
     * @param attr Attribute to be initialized
     * 
     * @return If successful, the pthread_rwlockattr_init() shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [ENOMEM] Insufficient memory exists to initialize the read-write lock attribute.
     */
    int pthread_rwlockattr_init(pthread_rwlockattr_t *attr);
    
    /** 
     * @brief Gets the process-shared attribute of the read-write lock attributes object
     * @details The pthread_rwlockattr_getpshared() function shall obtain
     * the value of the process-shared attribute
     * from the initialized attributes object referenced by attr.
     *
     * @since 2.0
     * 
     * @param attr Attribute to get 
     * @param pshared A pointer to a int variable to be set 
     * 
     * @return Upon successful, the pthread_rwlockattr_getpshared() function
     * shall return zero and store the value of the process-shared attribute
     * of attr into the object referenced by the pshared parameter.
     * Otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The value specified by attr is invalid. 
     */
    int pthread_rwlockattr_getpshared(const pthread_rwlockattr_t *restrict attr, int *restrict pshared);
    
    /**
     * @brief Sets the process-shared attribute of the read-write lock attributes object
     * @details The pthread_rwlockattr_setpshared() function shall set the process-shared
     * attribute in an initialized attributes object referenced by attr.
     *
     * @since 2.0
     * 
     * @param attr Attribute to be set 
     * @param pshared A shared option to set with
     * 
     * @return If successful, the pthread_rwlockattr_setpshared() function
     * shall return zero; otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The new value specified for the attribute is outside the range of legal values for that attribute.
     * @remarks PTHREAD_PROCESS_SHARED is not supported 
     */
    int pthread_rwlockattr_setpshared(pthread_rwlockattr_t *attr, int pshared);

    /** 
     * @brief Destroys a condition variable attribute
     * @details The pthread_condattr_destroy() function shall destroy
     * a condition variable attributes object. A destroyed attr attributes object
     * can be reinitialized using pthread_condattr_init();
     * the results of otherwise referencing the object
     * after it has been destroyed are undefined.
     * An implementation may cause pthread_condattr_destroy() to set the object
     * referenced by attr to an invalid value
     *
     * @since 2.0
     * 
     * @param attr Attribute to be destroyed
     * 
     * @return If successful, the pthread_condattr_destroy() shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The value specified by attr is invalid. 
     */
    int pthread_condattr_destroy(pthread_condattr_t *attr);
    
    /** 
     * @brief Initializes a condition variable attribute
     * @details The pthread_condattr_init() function shall initialize
     * a condition variable attributes object attr with the default value
     * for all of the attributes defined by the implementation.
     *
     * @since 2.0
     * 
     * @param attr Attribute to be initialized
     * 
     * @return If successful, the pthread_condattr_init() shall return zero;
     * otherwise, an error number shall be returned to indicate the error.
     * @n [ENOMEM] Insufficient memory exists to initialize the read-write lock attribute.
     */
    int pthread_condattr_init(pthread_condattr_t *attr);
    
    /** 
     * @brief Gets the process-shared attribute of the condition variable attributes object
     * @details The pthread_condattr_getpshared() function shall obtain
     * the value of the process-shared attribute
     * from the initialized attributes object referenced by attr.
     *
     * @since 2.0
     * 
     * @param attr Attribute to get 
     * @param pshared A pointer to a int variable to be set 
     * 
     * @return Upon successful, the pthread_condattr_getpshared() function
     * shall return zero and store the value of the process-shared attribute
     * of attr into the object referenced by the pshared parameter.
     * Otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The value specified by attr is invalid. 
     */
    int pthread_condattr_getpshared(const pthread_condattr_t *restrict attr, int *restrict pshared);
    
    /**
     * @brief Sets the process-shared attribute of the condition variable attributes object
     * @details The pthread_condattr_setpshared() function shall set the process-shared
     * attribute in an initialized attributes object referenced by attr.
     *
     * @since 2.0
     * 
     * @param attr Attribute to be set 
     * @param pshared A shared option to set with
     * 
     * @return If successful, the pthread_condattr_setpshared() function
     * shall return zero; otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The new value specified for the attribute is outside the range of legal values for that attribute.
     * @remarks PTHREAD_PROCESS_SHARED is not supported 
     */
    int pthread_condattr_setpshared(pthread_condattr_t *attr, int pshared);

    /** 
     * @brief Gets the process-shared attribute of the mutex attributes object
     * @details The pthread_mutexattr_getpshared() function shall obtain
     * the value of the process-shared attribute
     * from the initialized attributes object referenced by attr.
     *
     * @since 2.0
     * 
     * @param attr Attribute to get 
     * @param pshared A pointer to a int variable to be set 
     * 
     * @return Upon successful, the pthread_mutexattr_getpshared() function
     * shall return zero and store the value of the process-shared attribute
     * of attr into the object referenced by the pshared parameter.
     * Otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The value specified by attr is invalid. 
     */
    int pthread_mutexattr_getpshared(const pthread_mutexattr_t *restrict attr, int *restrict pshared);
    
    /**
     * @brief Sets the process-shared attribute of the mutex attributes object
     * @details The pthread_mutexattr_setpshared() function shall set the process-shared
     * attribute in an initialized attributes object referenced by attr.
     *
     * @since 2.0
     * 
     * @param attr Attribute to be set 
     * @param pshared A shared option to set with
     * 
     * @return If successful, the pthread_mutexattr_setpshared() function
     * shall return zero; otherwise, an error number shall be returned to indicate the error.
     * @n [EINVAL] The new value specified for the attribute is outside the range of legal values for that attribute.
     * @remarks PTHREAD_PROCESS_SHARED is not supported 
     */
    int pthread_mutexattr_setpshared(pthread_mutexattr_t *attr, int pshared);

    /** 
     * @brief Locks a read-write lock for reading
     * @details  The pthread_rwlock_timedrdlock() function shall apply a read lock
     * to the read-write lock referenced by rwlock as in the pthread_rwlock_rdlock() function.
     * However, if the lock cannot be acquired without waiting for other threads
     * to unlock the lock, this wait shall be terminated when the specified timeout expires.
     * The timeout shall expire when the absolute time specified by abs_timeout passes,
     * as measured by the clock on which timeouts are based
     * (that is, when the value of that clock equals or exceeds abs_timeout),
     * or if the absolute time specified by abs_timeout has already been passed at the time of the call.
     *
     * @since 2.0
     *
     * @param rwlock Read-write lock to be locked 
     * @param abs_timeout Time limit 
     * 
     * @return The pthread_rwlock_timedrdlock() function shall return zero
     * if the lock for reading on the read-write lock object referenced
     * by rwlock is acquired. Otherwise, an error number shall be returned
     * to indicate the error.
     * @n [ETIMEDOUT] The lock could not be acquired before the specified timeout expired.
     * @n [EAGAIN] The read lock could not be acquired
     * because the maximum number of read locks for lock would be exceeded.
     * @n [EDEADLK] A deadlock condition was detected
     * or the calling thread already holds a write lock on rwlock.
     * @n [EINVAL] The value specified by rwlock does not refer
     * to an initialized read-write lock object,
     * or the abs_timeout nanosecond value is less than zero or greater than or equal to 1000 million. 
     */
    int pthread_rwlock_timedrdlock(pthread_rwlock_t *restrict rwlock, const struct timespec *restrict abs_timeout);
    
    /** 
     * @brief Locks a read-write lock for writing
     * @details The pthread_rwlock_timedwrlock() function shall
     * apply a write lock to the read-write lock referenced
     * by rwlock as in the pthread_rwlock_wrlock() function.
     * However, if the lock cannot be acquired without waiting for other threads
     * to unlock the lock, this wait shall be terminated
     * when the specified timeout expires. The timeout shall expire
     * when the absolute time specified by abs_timeout passes,
     * as measured by the clock on which timeouts are based
     * (that is, when the value of that clock equals or exceeds abs_timeout),
     * or if the absolute time specified by abs_timeout has already been passed
     * at the time of the call.
     *
     * @since 2.0
     * 
     * @param rwlock Read-write lock to be locked 
     * @param abs_timeout Time limit 
     * 
     * @return The pthread_rwlock_timedwrlock() function shall return zero
     * if the lock for writing on the read-write lock object referenced
     * by rwlock is acquired.
     * Otherwise, an error number shall be returned to indicate the error.
     * @n [ETIMEDOUT] The lock could not be acquired
     * before the specified timeout expired. 
     * @n [EDEADLK] A deadlock condition was detected
     * or the calling thread already holds the rwlock.
     * @n [EINVAL] The value specified by rwlock does not refer
     * to an initialized read-write lock object,
     * or the abs_timeout nanosecond value is less than zero or greater
     * than or equal to 1000 million. 
     */
    int pthread_rwlock_timedwrlock(pthread_rwlock_t *restrict rwlock, const struct timespec *restrict abs_timeout);

    

    /** 
     * @brief Cancels execution of a thread
     *
     * @since 2.0
     * 
     * @return ENOSYS
     * @remarks Not supported
     */
    int pthread_cancel(pthread_t thread);
    
    /** 
     * @brief  Sets cancelability state
     *
     * @since 2.0
     * 
     * @return ENOSYS
     * @remarks Not supported
     */
    int pthread_setcancelstate(int state, int *oldstate);
    
    /** 
     * @brief Sets cancelability type
     *
     * @since 2.0
     * 
     * @return ENOSYS
     * @remarks Not supported
     */
    int pthread_setcanceltype(int type, int *oldtype);
    
    /** 
     * @brief Creates a cancellation point in the calling thread
     *
     * @since 2.0
     * 
     * @remarks Not supported
     */
    void pthread_testcancel(void);
    
    /** 
     * @brief Sends a signal to a thread
     *
     * @since 2.0
     * 
     * @return ENOSYS
     * @remarks Not supported
     */
    int pthread_kill(pthread_t thread, int sig);

	/**
	* @}
	*/
#ifdef __cplusplus
}
#endif // __cplusplus
#endif // __PTHREAD_H__
