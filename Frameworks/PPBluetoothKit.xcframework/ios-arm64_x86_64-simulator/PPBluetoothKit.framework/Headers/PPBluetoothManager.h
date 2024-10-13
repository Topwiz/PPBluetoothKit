//
//  PPBluetoothManager.h
//  PPBluetoothKit
//
//  Created by 彭思远 on 2023/4/7.
//

#import <Foundation/Foundation.h>
#import "PPBluetoothDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface PPBluetoothManager : NSObject




+ (BOOL)hasScaleFunc:(PPDeviceFuncType)funcType;

+ (BOOL)hasHistoryFunc:(PPDeviceFuncType)funcType;

+ (BOOL)hasSafeFunc:(PPDeviceFuncType)funcType;

+ (BOOL)hasBMDJFunc:(PPDeviceFuncType)funcType;

+ (BOOL)hasBabyFunc:(PPDeviceFuncType)funcType;

+ (BOOL)hasWifiFunc:(PPDeviceFuncType)funcType;

+ (BOOL)hasHeartRateFunc:(PPDeviceFuncType)funcType;

+ (BOOL)hasBidirectionalFunc:(PPDeviceFuncType)funcType;

+ (BOOL)hasTimeFormatFunc:(PPDeviceFuncType)funcType;

+ (BOOL)hasLightFunc:(PPDeviceFuncType)funcType;

+ (void)loadDeviceWithJsonData:(NSArray *)jsonDicDataArray;

+ (void)loadDeviceWithJsonFile:(NSString *)filePath;

+ (void)loadDeviceWithAppKey:(NSString *)appKey appSecrect:(NSString *)appSecret filePath:(NSString *)path;

@end

NS_ASSUME_NONNULL_END
