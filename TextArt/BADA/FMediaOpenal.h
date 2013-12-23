// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.
 
// This software contains confidential and proprietary information 
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such 
// Confidential Information and shall use the software only in accordance with 
// the terms of the license agreement the user entered into with Samsung.
//
/** 
 * @file		FMediaOpenal.h 
 * @brief		This is the header file for the %Openal namespace.
 *
 * This header file contains the declarations of the %Openal namespace.
 *
 */
#ifndef _FMEDIA_OPENAL_H_
#define _FMEDIA_OPENAL_H_

/**
 * @namespace	Osp::Media::Openal
 * @brief		This namespace contains interfaces for %OpenAL.
 *
 * - <a href ="group__libopenal.html"> libopenal</a>
 * - <a href ="group__libfreealut.html"> libfreealut</a>
 * @since				2.0
 *
 * @remarks	    @b Header @b %file: @b \#include @b <FMediaOpenal.h> or @b \#include @b <AL/al.h>, @b <AL/alc.h>, @b <AL/alex.h> and @b <AL/alut.h> @n
 *              @b Library: @b openal, @b freealut and @b FOsp
 *
 *
 * The %Openal namespace provides %OpenAL (Version 1.1) methods and utilities.
 * %OpenAL is a cross platform three-dimensional audio method. It can also be referred as a software interface to audio hardware.
 * The primary purpose of %OpenAL is to allow an application to position audio sources in three dimensional spaces around a listener, producing reasonable spatialization of the sources for the audio system.
 * %OpenAL is appropriate for many audio applications, but is specifically designed for gaming audio.
 * The %Openal namespace provides %OpenAL Utility Toolkit (ALUT) features. 
 *
 * For more information on the %Openal namespace features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/openal.htm">OpenAL Guide</a>.
 */
namespace Osp { namespace Media {
namespace Openal
{
#include "AL/al.h"
#include "AL/alc.h"
#include "AL/alext.h"
#include "AL/alut.h"
}; // Openal
}; }; // Osp::Media
#endif // _FMEDIA_OPENAL_H_


