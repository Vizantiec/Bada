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
 * @file			FUixFaceCommon.h
 * @brief			This is the header file for the Osp::Uix namespace.
 *
 * This header file contains the declarations of the Osp::Uix namespace.
 */
 
#ifndef _FUIX_FACE_COMMON_H_
#define _FUIX_FACE_COMMON_H_


//Include
#include "FUixConfig.h"

namespace Osp{ namespace Uix{ 

/**
 * @enum  FaceDetectorConfigProperty
 * Defines the configuration properties of a FaceDetector.
 *
 * @since 		1.0 
 * @see	  FaceDetector::GetRange(), FaceDetector::GetProperty(), FaceDetector::SetProperty()
 */
typedef enum
{
	/**
	* The maximum number of faces to detect from a video stream @n
	* This will be used when FaceDetector::DetectFacesFromVideoStreamN() is called.
 	*
	*/	
	FACEDETECTOR_MAXNUMBER_VIDEO,   

	/**
	* The maximum number of faces to detect from a still image @n
	* This will be used when FaceDetector::DetectFacesFromStillImageN() is called.
 	*		
	*/		
	FACEDETECTOR_MAXNUMBER_IMAGE,	
	
	/**
	* The minimum ratio of detectable faces is relative to the size of a video stream @n
	* The range is from values @c 1 to @c 3, where the value @c 1 has the longest execution time and @c 3 
	* has the shortest execution time. The value @c 1 detects small faces.
	* Therefore, for an application using a camera or a video file, the value @c 3 is an appropriate option.
	* The value @c 3 is used when DetectFacesFromVideoStreamN() is called unless it has been changed earlier 
	* using the SetProperty() method. @n
	*
	* This will be used when FaceDetector::DetectFacesFromVideoStreamN() is called.
 	*	
	*/			
	FACEDETECTOR_SCALE_VIDEO, 

	/**
	* The minimum ratio of detectable faces is relative to the size of a still image @n 
	* The range is from values @c 1 to @c 3, where the value @c 1 has the longest execution time and @c 3 has 
	* the shortest execution time. The value @c 1 detects small faces.
	* Therefore, for an application handling images, the value @c 1 is an appropriate option.
	* The value @c 1 is used when DetectFacesFromStillImageN() is called unless it has been changed 
    * earlier using the SetProperty() method. @n
	*
	* This will be used when FaceDetector::DetectFacesFromStillImageN() is called.
 	*	
	*/	
	FACEDETECTOR_SCALE_IMAGE,

	/** 
	* The maximum number of faces to detect @n 
	* The value @c 1 is used when DetectFacesN() is called unless it has been changed earlier 
	* using the SetProperty() method. @n		
	* This will be used when FaceDetector::DetectFacesN() is called @b since: @b 2.0.	
	*/	
	FACEDETECTOR_MAXNUMBER_FACES, 

	/**
	* The minimum ratio of detectable faces relative to the input data @n 
	* The range is from values @c 1 to @c 3, where the value @c 1 has the longest execution time and @c 3 
	* has the shortest execution time. The value @c 1 detects small faces.
	* The value @c 3 is used when DetectFacesN() is called unless it has been changed earlier using 
	* the SetProperty() method. @n
	*
	* This will be used when FaceDetector::DetectFacesN() is called @b since: @b 2.0.
	*/	
	FACEDETECTOR_SCALE_FACTOR,		
}FaceDetectorConfigProperty;



/**
 * @enum  FaceRecognizerConfigProperty
 * Defines the configuration properties of a FaceRecognizer.
 *
 * @since 		1.0 
 * @see	  FaceRecognizer::GetRange(), FaceRecognizer::GetProperty(), FaceRecognizer::SetProperty()
 */
typedef enum
{
	/** 
 	* The maximum number of faces to extract face information from a video stream @n
 	* This will be used when FaceRecognizer::ExtractFaceInfoFromVideoStreamN() is called.
 	*	
	*/
	FACERECOGNIZER_MAXNUMBER_VIDEO, 

	/** 
	* The maximum number of faces to extract face information from a still image @n
 	* This will be used when FaceRecognizer::ExtractFaceInfoFromStillImageN() is called.
 	*			
	*/	
	FACERECOGNIZER_MAXNUMBER_IMAGE,	

	/**
	* The minimum ratio of the detectable faces relative to the size of a video stream @n
	* The range is from values @c 1 to @c 3, where the value @c 1 has the longest execution time and @c 3 has 
	* the shortest execution time. The value @c 1 detects small faces.
   	* Therefore, for an application using a camera or a video file, the value @c 3 is an appropriate option.
	* The value @c 3 is used when ExtractFaceInfoFromVideoStreamN() is called unless it has been changed
	* earlier using the SetProperty() method. @n
	*
	* This will be used when FaceRecognizer::ExtractFaceInfoFromVideoStreamN() is called.
 	*	
	*/	
	FACERECOGNIZER_SCALE_VIDEO, 

	/**
	* The minimum ratio of the detectable faces relative to the size of a still image @n
	* The range is from values @c 1 to @c 3, where the value @c 1 has the longest execution time and @c 3 has 
	* the shortest execution time.
    * The value @c 1 detects small faces.
	* Therefore, for an application handling images, the value @c 1 is an appropriate option.
	* The value @c 1 is used when ExtractFaceInfoFromStillImageN() is called unless it has been changed 
	* earlier using the SetProperty() method. @n
	*
	* This will be used when FaceRecognizer::ExtractFaceInfoFromStillImageN() is called.
 	*
	*/	
	FACERECOGNIZER_SCALE_IMAGE, 
	}FaceRecognizerConfigProperty;	



/**
 * @enum  FaceDetectionOption
 * Defines the face detection options.
 *
 * @since 		2.0  
 * @see	  FaceDetector::DetectFacesN()
 */
typedef enum
{
	FACE_DETECTION_OPTION_FAST, 		/**< The option to detect faces as fast as possible even if the accuracy is low */	
	FACE_DETECTION_OPTION_ROBUST,	/**< The option to detect faces as accurate as possible even if it takes more time */
}FaceDetectionOption;



/**
 * @enum  EyeState
 * Defines the eye state.
 *
 * @since 		2.0   
 * @see	  FaceRecognizer::GetEyeState()
 */
typedef enum
{
	EYE_STATE_NONE,			/**< The no eye state, when the eye detect fails */
	EYE_STATE_BOTH_OPEN, 		/**< The state when both eyes are open */	
	EYE_STATE_BOTH_CLOSED,	/**< The state when both eyes are closed */	
}EyeState;



/**
 * @enum  FacialExpression
 * Defines the facial expressions.
 *
 * @since 		2.0    
 * @see	  FaceRecognizer::RecognizeExpression()
 */
typedef enum
{
	FACIAL_EXPRESSION_NONE,		/**<  The no face expression, when the face recognition fails */
	FACIAL_EXPRESSION_NEUTRAL,	/**<  The neutral face expression  */
	FACIAL_EXPRESSION_ANGRY,		/**<  The angry face expression */
	FACIAL_EXPRESSION_HAPPY,		/**<  The happy face expression */
	FACIAL_EXPRESSION_SURPRISED,	/**<  The surprised face expression  */
}FacialExpression;


};};






#endif





