//
//  TCISCrash+Crash.h
//  ToastCrash
//
//  Created by Hyup on 2017. 10. 19..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <ToastLogger/ToastLogger.h>
#import <ToastCommon/ToastCommon.h>
#import <ToastCore/ToastCore.h>

@protocol TCISCrashDelegate <NSObject>
@optional
- (void)crashLoggerInstance:(TCISInstanceLogger *)instanceLogger
        didSendSuccessedCrashLog:(TCISLog *)crashLog;

- (void)crashLoggerInstance:(TCISInstanceLogger *)instanceLogger
           didSendFailedCrashLog:(TCISLog *)crashLog
                      error:(NSError *)error;

- (void)crashLoggerInstance:(TCISInstanceLogger *)instanceLogger
           didSavedCrashLog:(TCISLog *)crashLog;

- (void)crashLoggerInstance:(TCISInstanceLogger *)instanceLogger
             didFilteredCrashLog:(TCISLog *)crashLog
                  logFilter:(TCISLogFilter *)logFilter;
@end


@interface TCISCrash : NSObject

+ (void)setConfigurationLogger:(TCISInstanceLogger *)logger;

+ (void)enableCrashDelegate:(id<TCISCrashDelegate>)crashDelegate;

+ (void)setUserFieldWithValue:(NSString *)value forKey:(NSString *)key;
+ (void)setUserField:(NSDictionary<NSString*, NSString*> *)addUserLogField;
+ (void)setUserFieldIntoTCISCrashBlock:(void (^)(void))block;

#pragma mark - Version
+ (NSString *)version;

#pragma mark - private
+ (void)handledWithLog:(TCISLog *)log ;

@end
