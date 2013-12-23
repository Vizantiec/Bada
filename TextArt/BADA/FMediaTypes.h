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
* @file			FMediaTypes.h
* @brief		This is the header file for the media types.
*
* This header file contains the declarations of the media types.
*/
#ifndef _FMEDIA_MEDIA_TYPES_H_
#define _FMEDIA_MEDIA_TYPES_H_

namespace Osp{ namespace Media{

/**
 * Defines a macro that is added to declare the four-character code.
 *
 * @since					1.0
 * @param[in]     ch1					The first character
 * @param[in]     ch2					The second character
 * @param[in]     ch3					The third character
 * @param[in]     ch4					The fourth character
*/
#define FourCharCode(ch1,ch2,ch3,ch4)	((unsigned int)(unsigned char)(ch1)) | \
((unsigned int)(unsigned char)(ch2)<<8) | \
((unsigned int)(unsigned char)(ch3)<<16) | \
((unsigned int)(unsigned char)(ch4)<<24)



/** 
 * @enum 	CodecType
 * Defines the types of codec. 
 *
 * @since 	2.0
 * @see 		FourCharCode(ch1,ch2,ch3,ch4)
 */ 
typedef enum
{
	CODEC_NONE=0x00000000,						/**< No codec */
	/*Audio codecs*/
	CODEC_LPCM=FourCharCode('L','P','C','M'),			/**< The Linear PCM codec */
	CODEC_ALAW=FourCharCode('A','L','A','W'),		/**< The G.711 A-Law codec */
	CODEC_ULAW=FourCharCode('u','L','A','W'),			/**< The G.711 u-Law codec */
	CODEC_IMA_ADPCM=FourCharCode('I','M','A','D'),	/**< The IMA ADPCM codec */
	CODEC_MS_ADPCM=FourCharCode('M','S','A','D'),	/**< The MS ADPCM codec */
	CODEC_AMR_NB=FourCharCode('A','M','R',' '),		/**< The AMR-NB codec */
	CODEC_FLAC=FourCharCode('F','L','A','C'),			/**< The FLAC codec */
	CODEC_MP3=FourCharCode('M','P','3',' '),			/**< The MP3 codec */
	CODEC_AAC=FourCharCode('A','A','C',' '),			/**< The AAC codec */
	CODEC_HEAAC=FourCharCode('A','A','C','H'),		/**< The Enhanced AAC codec */
	CODEC_HEAAC_V2=FourCharCode('A','A','C','P'),	/**< The Enhanced AAC V2 codec */
	CODEC_AC3=FourCharCode('A','C','-','3'),			/**< The AC-3 codec */
	CODEC_VORBIS=FourCharCode('V','O','R','B'),		/**< The VORBIS codec */
	CODEC_WMA=FourCharCode('W','M','A',' '),			/**< The WMA codec */
	CODEC_MIDI=FourCharCode('M','I','D','I'),			/**< The MIDI codec */
	/*Video codecs*/
	CODEC_H263=FourCharCode('H','2','6','3'),			/**< The H.263 codec */
	CODEC_MPEG4=FourCharCode('M','P','G','4'),		/**< The MPEG4 codec */
	CODEC_H264=FourCharCode('H','2','6','4'),			/**< The H.264 codec */
	CODEC_THEORA=FourCharCode('T','H','R','A'),		/**< The THEORA codec */
	CODEC_WMV=FourCharCode('W','M','V',' '),			/**< The WMV codec */
	/*Image codecs*/
	CODEC_JPEG=FourCharCode('J','P','E','G'),			/**< The JPEG codec */
	CODEC_PNG=FourCharCode('P','N','G',' '),			/**< The PNG codec */	
	CODEC_GIF=FourCharCode('G','I','F',' '),				/**< The GIF codec */		

	CODEC_UNKNOWN=0xFFFFFFFE,				/**< The unknown codec */
	CODEC_MAX=0xFFFFFFFF						/*< Max */
} CodecType; 

/** 
 * @enum 	MediaContainerType
 * Defines the various container types of the media.
 *
 * @since 	2.0
 * @see 		FourCharCode(ch1,ch2,ch3,ch4)
 */ 
typedef enum 
{
	MEDIA_CONTAINER_NONE=0x00000000,					/**< No container */
	MEDIA_CONTAINER_WAV=FourCharCode('W','A','V',' '),		/**< The WAVE container */
	MEDIA_CONTAINER_AMR=FourCharCode('A','M','R',' '),		/**< The AMR container */
	MEDIA_CONTAINER_AAC=FourCharCode('A','A','C',' '),			/**< The AAC container */
	MEDIA_CONTAINER_MP3=FourCharCode('M','P','3',' '),			/**< The MP3 container */
	MEDIA_CONTAINER_FLAC=FourCharCode('F','L','A','C'),		/**< The FLAC container */
	MEDIA_CONTAINER_3GP=FourCharCode('3','G','P',' '),			/**< The 3GP container */
	MEDIA_CONTAINER_MP4=FourCharCode('M','P','4',' '),			/**< The MP4 container */
	MEDIA_CONTAINER_AVI=FourCharCode('A','V','I',' '),			/**< The AVI container */
	MEDIA_CONTAINER_ASF=FourCharCode('A','S','F',' '),			/**< The ASF container */
	MEDIA_CONTAINER_MKV=FourCharCode('M','K','V',' '),		/**< The MKV container */
	MEDIA_CONTAINER_MOV=FourCharCode('M','O','V',' '),		/**< The MOV container */
	MEDIA_CONTAINER_OGG=FourCharCode('O','G','G',' '),		/**< The OGG container */
	MEDIA_CONTAINER_UNKNOWN=0xFFFFFFFE,				/**< The unknown container */
	MEDIA_CONTAINER_MAX=0xFFFFFFFF					/*< Max */
} MediaContainerType;

/**
 *	@enum	MediaPropertyType
 *	Defines the various property types of the media.
 *
 *	@since	2.0
 */
typedef enum {
	MEDIA_PROPERTY_VIDEO_WIDTH = 0x0001,			/**< The video width (int) */
	MEDIA_PROPERTY_VIDEO_HEIGHT,					/**< The video height (int) */
	MEDIA_PROPERTY_VIDEO_FRAME_RATE,				/**< The video frame rate (float or int) */
	MEDIA_PROPERTY_VIDEO_PIXEL_FORMAT,				/**< The video pixel format (::MediaPixelFormat) */
	MEDIA_PROPERTY_VIDEO_BIT_RATE,					/**< The video bit rate (int) */

	MEDIA_PROPERTY_VIDEO_QUANTIZATION_PARAMETER=0x0100,	/**< The video quantization level (int) */
	MEDIA_PROPERTY_VIDEO_QUANTIZATION_MIN,			/**< The minimum quantization level (int) */
	MEDIA_PROPERTY_VIDEO_QUANTIZATION_MAX,			/**< The maximum quantization level (int) */
	MEDIA_PROPERTY_VIDEO_GOP_SIZE,					/**< The video Group of Picture (GOP) size (int) */
	MEDIA_PROPERTY_VIDEO_PROFILE,					/**< The video profile (int) */
	MEDIA_PROPERTY_VIDEO_GOB_SIZE,					/**< The video Group of Block (GOB) size (int) */
	MEDIA_PROPERTY_VIDEO_PACKET_SIZE,				/**< The video packet size in byte (int) */
	MEDIA_PROPERTY_VIDEO_SLICE_SIZE_MODE,			/**< The slice mode (::VideoSliceMode) */
	MEDIA_PROPERTY_VIDEO_SLICE_SIZE_IN_BYTE,		/**< The size of a video slice in bytes (int) */
	MEDIA_PROPERTY_VIDEO_SLICE_SIZE_IN_MACROBLOCK,	/**< The number of macroblocks in a slice (int) */
	MEDIA_PROPERTY_VIDEO_REFERENCE_PICTURE_COUNT,	/**< The count of reference picture (int) */

	MEDIA_PROPERTY_VIDEO_USE_FRAME_SKIP = 0x0200,	/**< The media property type that uses the frame skip algorithm (int) */
	MEDIA_PROPERTY_VIDEO_USE_DEBLOCKING_FILTER,		/**< The media property type that uses the deblocking filter (int) @n
	                                                     It enables or disables the deblocking filter. */
	MEDIA_PROPERTY_VIDEO_USE_AC_PREDICTION,			/**< The media property type that uses the AC prediction mode (int) */
	MEDIA_PROPERTY_VIDEO_USE_HEADER_EXTENSION_CODE,	/**< The media property type that uses the header extension code mode (int) */

	MEDIA_PROPERTY_VIDEO_FORCE_SKIP_FRAME = 0x0300,	/**< The media property type that skips the encoding or decoding of the current frame (int) by force */
	MEDIA_PROPERTY_VIDEO_FORCE_INTRA_CODING,		/**< The media property type that uses the intra coding for the current frame (int) by force  */

	MEDIA_PROPERTY_VIDEO_H264_USE_ANNEX_B=0x0400,	/**< The media property type that uses H.264 Annex B for output bitstream format (int) */


	MEDIA_PROPERTY_AUDIO_SAMPLE_RATE = 0x1000,		/**< The audio sample rate (int) */
	MEDIA_PROPERTY_AUDIO_BIT_RATE,					/**< The audio bit rate (int) */
	MEDIA_PROPERTY_AUDIO_CHANNEL_TYPE,				/**< The audio channel type (::AudioChannelType) */
	MEDIA_PROPERTY_AUDIO_SAMPLE_TYPE,				/**< The audio sample type (::AudioSampleType) */

} MediaPropertyType;

/**
 *	@enum	MediaPixelFormat
 *	Defines the pixel formats of the media data.
 *
 *	@since	2.0
 */
typedef enum {
	MEDIA_PIXEL_FORMAT_NONE = 0x0000,		/*< The undefined pixel format */
	MEDIA_PIXEL_FORMAT_RGB565LE  = 0x0001,		/**< The RGB565 little-endian format */
	MEDIA_PIXEL_FORMAT_RGB565BE,			/**< The RGB565 big-endian format */
	MEDIA_PIXEL_FORMAT_RGB888 = 0x0100,		/**< The RGB888 format */
	MEDIA_PIXEL_FORMAT_BGR888,			/**< The BGR888 format */
	MEDIA_PIXEL_FORMAT_RGBA8888,			/**< The RGBA8888 format */
	MEDIA_PIXEL_FORMAT_BGRA8888,			/**< The BGRA8888 format */
	MEDIA_PIXEL_FORMAT_YUV420P = 0x0200,		/**< The YUV420 Planar format */
	MEDIA_PIXEL_FORMAT_NV12,			/**< The NV12 format */
	MEDIA_PIXEL_FORMAT_NV12_TILE,			/**< The NV12 tiled format */
} MediaPixelFormat;


/**
 * 	@enum VideoSliceMode
 * 	Defines the slice mode of the video data.
 * 	@since	2.0
 */
typedef enum {
	VIDEO_SLICE_MODE_NONE = 0x00,			/**< The no slicing mode */
	VIDEO_SLICE_MODE_FIXED_MACROBLOCK,		/**< The slicing of a video by a fixed number of macroblocks */
	VIDEO_SLICE_MODE_FIXED_BYTE,			/**< The slicing of a video by a fixed number of bytes */
} VideoSliceMode;

/**
 * 	@enum H263ProfileType
 * 	Defines the profile types of the H.263 video codec.
 * 	@since	2.0
 */
typedef enum {
	H263_PROFILE_BASELINE = 0x00,			/**< The baseline profile */
	H263_PROFILE_VERSION_2 = 0x03,			/**< The version 2 interactive and streaming wireless profile */
} H263ProfileType;


};}; // Osp::Media


#endif

