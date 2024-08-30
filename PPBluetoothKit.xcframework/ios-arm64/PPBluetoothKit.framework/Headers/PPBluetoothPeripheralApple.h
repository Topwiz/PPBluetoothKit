//
//  PPBluetoothPeripheralApple.h
//  PPBluetoothKit
//
//  Created by 彭思远 on 2023/3/31.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "PPBluetoothAdvDeviceModel.h"
#import "PPBluetooth180ADeviceModel.h"
#import "PPBluetoothInterface.h"
//#import "PPBluetoothDeviceSettingModel.h"
#import "PPWifiInfoModel.h"
#import <PPBaseKit/PPBaseKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, PPBluetoothAppleWifiConfigState) {
    PPBluetoothAppleWifiConfigStateSuccess = 0, // 配网成功 Successful distribution network
    PPBluetoothAppleWifiConfigStateLowBatteryLevel = 1, // 电量过低 Low battery level
    PPBluetoothAppleWifiConfigStateRegistFail = 3, // 注册失败 login has failed
    PPBluetoothAppleWifiConfigStateUnableToFindRouter = 5, // 找不到路由 Unable to find route
    PPBluetoothAppleWifiConfigStatePasswordError = 6, //密码错误 Password error
    PPBluetoothAppleWifiConfigStateOtherFail, // 其它错误（app可以不用关注） Other errors (app can be ignored)
};

@interface PPBluetoothPeripheralApple : NSObject

@property (nonatomic, weak) id<PPBluetoothServiceDelegate> serviceDelegate;

@property (nonatomic, weak) id<PPBluetoothCMDDataDelegate> cmdDelegate;

@property (nonatomic, weak) id<PPBluetoothScaleDataDelegate> scaleDataDelegate;

@property (nonatomic, strong) CBPeripheral *peripheral;

@property (nonatomic, strong) PPBatteryInfoModel *batteryInfo;


- (instancetype)initWithPeripheral:(CBPeripheral *)peripheral  andDevice:(PPBluetoothAdvDeviceModel *)device;

- (void)discoverDeviceInfoService:(void(^)(PPBluetooth180ADeviceModel *deviceModel))deviceInfoResponseHandler;

- (void)discoverFFF0Service;

- (void)fetchDeviceHistoryData;

/// 删除历史数据
///  - status 0 : 成功，1 : 失败
- (void)deleteDeviceHistoryDataWithHandler:(void(^)(NSInteger status))handler;

/// 同步时间
///  - status 0 : 成功，1 : 失败
- (void)syncDeviceTimeWithHandler:(void(^)(NSInteger status))handler;

- (void)fetchDeviceBatteryInfo;

- (void)syncDeviceSetting:(PPBluetoothDeviceSettingModel *)settingModel;


/// 恢复出厂状态
/// - Parameter handler:
- (void)restoreFactoryWithHandler:(void(^)(void))handler;

/// 配网
/// - Parameters:
///   - model: name 和 pwd
///   - handler:
- (void)configNetWorkWithSSID:(NSString *)ssid password:(NSString *)password handler:(void(^)(NSString *sn, PPBluetoothAppleWifiConfigState configState))handler;

/// 配网
/// 此方法即将过期，使用 - (void)configNetWorkWithSSID:(NSString *)ssid password:(NSString *)password handler:(void(^)(NSString *sn, PPBluetoothAppleWifiConfigState configState))handler 代替
/// - Parameters:
///   - model: name 和 pwd
///   - handler:
- (void)configNetWorkWithSSID:(NSString *)ssid password:(NSString *)password withHandler:(void(^)(NSString *sn))handler API_DEPRECATED("Use - (void)configNetWorkWithSSID:(NSString *)ssid password:(NSString *)password handler:(void(^)(NSString *sn, PPBluetoothAppleWifiConfigState configState))handler instead", ios(1.0, API_TO_BE_DEPRECATED), visionos(1.0, API_TO_BE_DEPRECATED));

/// 设置DNS，即服务器域名
/// - Parameters:
///   - dns: 域名
///   - handler:
- (void)changeDNS:(NSString *)dns withHandler:(void(^)(NSInteger statu))handler;

/// 查询wifi参数
/// - Parameter handler:
- (void)queryWifiConfigWithHandler:(void (^)(PPWifiInfoModel * _Nullable))handler;

/// 断开设备蓝牙连接
- (void)disconnectDevice;

/// 查询设备时间
- (void)queryDeviceTime:(void(^)(NSString* deviceTime))handler;

/// 删除Wi-Fi参数
///  status 0：成功，1：失败
- (void)deleteWIFI:(void(^)(NSInteger status))handler;

@end

NS_ASSUME_NONNULL_END
