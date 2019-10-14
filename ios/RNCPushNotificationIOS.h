/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <React/RCTEventEmitter.h>
#import <UserNotifications/UserNotifications.h>

extern NSString *const RNCRemoteNotificationReceived;

@interface RNCPushNotificationIOS : RCTEventEmitter <UNUserNotificationCenterDelegate>

typedef void (^RNCRemoteNotificationCallback)(UIBackgroundFetchResult result);
API_AVAILABLE(ios(10.0))
typedef void (^RNCNotificationWillPresentCallback)(UNNotificationPresentationOptions options);

#if !TARGET_OS_TV
+ (void)didRegisterUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings;
+ (void)didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;
+ (void)didReceiveRemoteNotification:(NSDictionary *)notification;
+ (void)didReceiveRemoteNotification:(NSDictionary *)notification fetchCompletionHandler:(RNCRemoteNotificationCallback)completionHandler;
+ (void)didReceiveLocalNotification:(UILocalNotification *)notification;
+ (void)didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;
#endif

@end
