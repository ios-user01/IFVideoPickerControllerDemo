//
//  IFVideoPicker.h
//  IFVideoPickerControllerDemo
//
//  Created by Min Kim on 3/25/13.
//  Copyright (c) 2013 iFactory Lab Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "AVFoundation/AVCaptureSession.h"
#import "AVFoundation/AVCaptureOutput.h"
#import "AVFoundation/AVCaptureDevice.h"
#import "AVFoundation/AVCaptureInput.h"
#import "AVFoundation/AVCaptureVideoPreviewLayer.h"
#import "AVFoundation/AVMediaFormat.h"

typedef enum {
  kBufferUnknown = 0,
  kBufferVideo,
  kBufferAudio
} IFCapturedBufferType;

typedef void (^captureHandler)(CMSampleBufferRef sampleBuffer,
                               IFCapturedBufferType type);
typedef void (^encodedCaptureHandler)(void);

@class IFVideoEncoder;
@class IFAudioEncoder;

@interface IFVideoPicker : NSObject {
  
}

@property (nonatomic, retain) AVCaptureDeviceInput *videoInput;
@property (nonatomic, retain) AVCaptureDeviceInput *audioInput;
@property (nonatomic, retain) AVCaptureVideoDataOutput *videoBufferOutput;
@property (nonatomic, retain) AVCaptureAudioDataOutput *audioBufferOutput;
@property (nonatomic, retain) AVCaptureVideoPreviewLayer *captureVideoPreviewLayer;
@property (nonatomic, retain) AVCaptureSession *session;
@property (nonatomic, retain) UIView *videoPreviewView;
@property (nonatomic, retain) IFVideoEncoder *videoEncoder;
@property (nonatomic, retain) IFAudioEncoder *audioEncoder;
@property (nonatomic, assign) BOOL isCapturing;

- (BOOL)startup;

- (void)shutdown;

/**
 @abstract
  start preview of camera input
 
 @param captureOutput

 */
- (void)startPreview:(UIView *)view;

- (void)startPreview:(UIView *)view withFrame:(CGRect)frame;

/**
 @abstract
  start capture YUV format video and audio stream from camera device. It returns
  captured raw buffer as form of CMSampleBufferRef through captureBlock.
 */
- (void)startCaptureWithBlock:(captureHandler)captureBlock;

/**
 @abstract
  start capture YUV format video and audio stream from camera device. It returns
  encoded format of video and audio output through captureBlock.
 */
- (void)startCaptureWithEncoder:(IFVideoEncoder *)video
                          audio:(IFAudioEncoder *)audio
                   captureBlock:(encodedCaptureHandler)captureBlock;


/**
 */
- (void)stopCapture;

/**
 */
- (void)stopPreview;


@end
