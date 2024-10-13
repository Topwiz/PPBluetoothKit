//
//  PPBluetoothCMDApple.h
//  PPBluetoothKit
//
//  Created by 彭思远 on 2023/4/3.
//

#import <Foundation/Foundation.h>
//#import "PPBluetoothDeviceSettingModel.h"
#import "PPBluetooth180ADeviceModel.h"
#import "PPBluetoothAdvDeviceModel.h"
#import <PPBaseKit/PPBaseKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PPBluetoothCMDApple : NSObject

+ (NSString *)syncTimeCMDWithDevice180AModel:(PPBluetooth180ADeviceModel *)device180A;

+ (NSString *)syncInfoCmdWithSettingModel:(PPBluetoothDeviceSettingModel *)settingModel device180AModel:(PPBluetooth180ADeviceModel *)device180A andAdvDeviceModel:(PPBluetoothAdvDeviceModel *)deviceModel;

+ (NSArray *)configWifiCMDBySSID:(NSString *)ssid andPassword:(NSString *)password;

+ (NSArray *)changeDNS:(NSString *)dns;
@end

NS_ASSUME_NONNULL_END
