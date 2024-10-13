//
//  PPBluetoothBorreDataAnalysis.h
//  PPBluetoothKit
//
//  Created by 彭思远 on 2023/4/10.
//

#import <Foundation/Foundation.h>
#import "PPBluetoothAdvDeviceModel.h"
#import "PPBluetoothScaleBaseModel.h"
#import "PPAnalysisResultModel.h"
#import "PPBatteryInfoModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface PPBluetoothBorreDataAnalysis : NSObject

+ (PPAnalysisResultModel *)analysisData:(NSData *)receiveDate;

+ (NSArray <PPBluetoothScaleBaseModel *>*)torreHistoryWithData:(NSData *)data;

+ (PPBatteryInfoModel *)analysisStrengthWithData:(NSData *)receiveData;

@end

NS_ASSUME_NONNULL_END
