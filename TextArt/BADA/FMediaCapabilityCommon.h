/* $Change: 576488 $ */
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
 * @file			FMediaCapabilityCommon.h
 * @brief			This is the header file for the common data of the %MediaCapability class.
 *
 * This header file contains the declarations of common data of the %MediaCapability class.
 */

#ifndef _FMEDIA_CAPABILITY_COMMON_H_
#define _FMEDIA_CAPABILITY_COMMON_H_

#include <FBase.h>
#include "FMediaConfig.h"

namespace Osp{ namespace Media {

#define AUDIOIN_SAMPLE_RATE			L"AudioIn.SampleRate"
#define AUDIOIN_SAMPLE_TYPE			L"AudioIn.SampleType"

#define	AUDIOOUT_COUNT_MAX			L"AudioOut.CountMax"
#define AUDIOOUT_SAMPLE_RATE		L"AudioOut.SampleRate"
#define AUDIOOUT_SAMPLE_TYPE		L"AudioOut.SampleType"

#define AUDIORECORDER_FORMAT		L"AudioRecorder.Format"

#define CAMERA_COUNT						L"Camera.Count"
#define CAMERA_PRIMARY_CAPTURE_FORMAT		L"Camera.Primary.CaptureFormat"
#define CAMERA_PRIMARY_CAPTURE_RESOLUTION	L"Camera.Primary.CaptureResolution"
#define CAMERA_PRIMARY_DIRECTION			L"Camera.Primary.Direction"
#define CAMERA_PRIMARY_EFFECT				L"Camera.Primary.Effect"
#define CAMERA_PRIMARY_ISO_LEVEL			L"Camera.Primary.IsoLevel"
#define CAMERA_PRIMARY_PREVIEW_FORMAT		L"Camera.Primary.PreviewFormat"
#define CAMERA_PRIMARY_PREVIEW_FRAMERATE	L"Camera.Primary.PreviewFrameRate"
#define CAMERA_PRIMARY_PREVIEW_RESOLUTION	L"Camera.Primary.PreviewResolution"
#define CAMERA_PRIMARY_RECORDING_RESOLUTION	L"Camera.Primary.RecordingResolution"
#define CAMERA_PRIMARY_ROTATION				L"Camera.Primary.Rotation"
#define CAMERA_PRIMARY_SUPPORT_BRIGHTNESS	L"Camera.Primary.SupportBrightness"
#define CAMERA_PRIMARY_SUPPORT_CAPTURE		L"Camera.Primary.SupportCapture"
#define CAMERA_PRIMARY_SUPPORT_CONTRAST     L"Camera.Primary.SupportContrast"
#define CAMERA_PRIMARY_SUPPORT_EXPOSURE		L"Camera.Primary.SupportExposure"
#define CAMERA_PRIMARY_SUPPORT_FLASH		L"Camera.Primary.SupportFlash"
#define CAMERA_PRIMARY_SUPPORT_FOCUS		L"Camera.Primary.SupportFocus"
#define CAMERA_PRIMARY_SUPPORT_PREVIEW		L"Camera.Primary.SupportPreview"
#define CAMERA_PRIMARY_SUPPORT_RECORDING	L"Camera.Primary.SupportRecording"
#define CAMERA_PRIMARY_SUPPORT_ZOOM			L"Camera.Primary.SupportZoom"
#define CAMERA_PRIMARY_WHITE_BALANCE		L"Camera.Primary.WhiteBalance"
#define CAMERA_PRIMARY_ZOOM_TYPE			L"Camera.Primary.ZoomType"
#define CAMERA_PRIMARY_FLIP					L"Camera.Primary.Flip"

#define CAMERA_SECONDARY_CAPTURE_FORMAT		L"Camera.Secondary.CaptureFormat"
#define CAMERA_SECONDARY_CAPTURE_RESOLUTION	L"Camera.Secondary.CaptureResolution"
#define CAMERA_SECONDARY_DIRECTION			L"Camera.Secondary.Direction"
#define CAMERA_SECONDARY_EFFECT				L"Camera.Secondary.Effect"
#define CAMERA_SECONDARY_ISO_LEVEL			L"Camera.Secondary.IsoLevel"
#define CAMERA_SECONDARY_PREVIEW_FORMAT		L"Camera.Secondary.PreviewFormat"
#define CAMERA_SECONDARY_PREVIEW_FRAMERATE	L"Camera.Secondary.PreviewFrameRate"
#define CAMERA_SECONDARY_PREVIEW_RESOLUTION	L"Camera.Secondary.PreviewResolution"
#define CAMERA_SECONDARY_RECORDING_RESOLUTION	L"Camera.Secondary.RecordingResolution"
#define CAMERA_SECONDARY_ROTATION			L"Camera.Secondary.Rotation"
#define CAMERA_SECONDARY_SUPPORT_BRIGHTNESS	L"Camera.Secondary.SupportBrightness"
#define CAMERA_SECONDARY_SUPPORT_CAPTURE	L"Camera.Secondary.SupportCapture"
#define CAMERA_SECONDARY_SUPPORT_CONTRAST       L"Camera.Secondary.SupportContrast"
#define CAMERA_SECONDARY_SUPPORT_EXPOSURE	L"Camera.Secondary.SupportExposure"
#define CAMERA_SECONDARY_SUPPORT_FLASH		L"Camera.Secondary.SupportFlash"
#define CAMERA_SECONDARY_SUPPORT_FOCUS		L"Camera.Secondary.SupportFocus"
#define CAMERA_SECONDARY_SUPPORT_PREVIEW	L"Camera.Secondary.SupportPreview"
#define CAMERA_SECONDARY_SUPPORT_RECORDING	L"Camera.Secondary.SupportRecording"
#define CAMERA_SECONDARY_SUPPORT_ZOOM		L"Camera.Secondary.SupportZoom"
#define CAMERA_SECONDARY_WHITE_BALANCE		L"Camera.Secondary.WhiteBalance"
#define CAMERA_SECONDARY_ZOOM_TYPE			L"Camera.Secondary.ZoomType"
#define CAMERA_SECONDARY_FLIP					L"Camera.Secondary.Flip"

#define PLAYER_AUDIO_CODEC			L"Player.AudioCodec"
#define PLAYER_COUNT_MAX			L"Player.CountMax"
#define PLAYER_PROTOCOL				L"Player.Protocol"
#define	PLAYER_VIDEO_CODEC			L"Player.VideoCodec"
#define PLAYER_VIDEO_HEIGHT			L"Player.VideoHeight"
#define PLAYER_VIDEO_WIDTH			L"Player.VideoWidth"

#define VIDEORECORDER_AUDIO_CODEC	L"VideoRecorder.AudioCodec"
#define VIDEORECORDER_FORMAT		L"VideoRecorder.Format"
#define VIDEORECORDER_VIDEO_CODEC	L"VideoRecorder.VideoCodec"

};};// Osp::Media

#endif

