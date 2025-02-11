#import "SentryDefines.h"

@class SentryANRTracker;
@class SentryAppStateManager;
@class SentryBinaryImageCache;
@class SentryCrashWrapper;
@class SentryCurrentDateProvider;
@class SentryDebugImageProvider;
@class SentryDispatchFactory;
@class SentryDispatchQueueWrapper;
@class SentryFileManager;
@class SentryNSNotificationCenterWrapper;
@class SentryNSProcessInfoWrapper;
@class SentryNSTimerFactory;
@class SentrySwizzleWrapper;
@class SentrySystemWrapper;
@class SentryThreadWrapper;
@protocol SentryRandom;

#if SENTRY_HAS_METRIC_KIT
@class SentryMXManager;
#endif // SENTRY_HAS_METRIC_KIT

#if SENTRY_HAS_UIKIT
@class SentryFramesTracker;
@class SentryScreenshot;
@class SentryUIApplication;
@class SentryViewHierarchy;
#endif

NS_ASSUME_NONNULL_BEGIN

@interface SentryDependencyContainer : NSObject
SENTRY_NO_INIT

+ (instancetype)sharedInstance;

/**
 * Set all dependencies to nil for testing purposes.
 */
+ (void)reset;

@property (nonatomic, strong) SentryFileManager *fileManager;
@property (nonatomic, strong) SentryAppStateManager *appStateManager;
@property (nonatomic, strong) SentryCrashWrapper *crashWrapper;
@property (nonatomic, strong) SentryThreadWrapper *threadWrapper;
@property (nonatomic, strong) id<SentryRandom> random;
@property (nonatomic, strong) SentrySwizzleWrapper *swizzleWrapper;
@property (nonatomic, strong) SentryDispatchQueueWrapper *dispatchQueueWrapper;
@property (nonatomic, strong) SentryNSNotificationCenterWrapper *notificationCenterWrapper;
@property (nonatomic, strong) SentryDebugImageProvider *debugImageProvider;
@property (nonatomic, strong) SentryANRTracker *anrTracker;
@property (nonatomic, strong) SentryNSProcessInfoWrapper *processInfoWrapper;
@property (nonatomic, strong) SentrySystemWrapper *systemWrapper;
@property (nonatomic, strong) SentryDispatchFactory *dispatchFactory;
@property (nonatomic, strong) SentryNSTimerFactory *timerFactory;
@property (nonatomic, strong) SentryCurrentDateProvider *dateProvider;
@property (nonatomic, strong) SentryBinaryImageCache *binaryImageCache;

#if SENTRY_HAS_UIKIT
@property (nonatomic, strong) SentryFramesTracker *framesTracker;
@property (nonatomic, strong) SentryScreenshot *screenshot;
@property (nonatomic, strong) SentryViewHierarchy *viewHierarchy;
@property (nonatomic, strong) SentryUIApplication *application;
#endif

- (SentryANRTracker *)getANRTracker:(NSTimeInterval)timeout;

#if SENTRY_HAS_METRIC_KIT
@property (nonatomic, strong) SentryMXManager *metricKitManager API_AVAILABLE(
    ios(15.0), macos(12.0), macCatalyst(15.0)) API_UNAVAILABLE(tvos, watchos);
#endif

@end

NS_ASSUME_NONNULL_END
