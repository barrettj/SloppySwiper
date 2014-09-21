//
//  SloppySwiper.h
//
//  Created by Arkadiusz Holko http://holko.pl on 29-05-14.
//

#import <Foundation/Foundation.h>

typedef BOOL (^SloppySwiperNoViewControllersToPopToBlock)(void);
typedef void (^SloppySwiperNoViewControllersUpdateBlock)(CGFloat update);
typedef void (^SloppySwiperNoViewControllersEndedBlock)();


/**
 *  `SloppySwiper` is a class conforming to `UINavigationControllerDelegate` protocol that allows pan back gesture to be started from anywhere on the screen (not only from the left edge).
 */
@interface SloppySwiper : NSObject <UINavigationControllerDelegate>

/// Gesture recognizer used to recognize swiping to the right.
@property (weak, readonly, nonatomic) UIPanGestureRecognizer *panRecognizer;

/// Called when there's no view controllers to pop to in the navigation controller
@property (strong, nonatomic) SloppySwiperNoViewControllersToPopToBlock noViewControllersBlock;

/// Update the no view controllers transition
@property (strong, nonatomic) SloppySwiperNoViewControllersUpdateBlock noViewControllersTransitionUpdate;

/// Cancel the no view controllers transition
@property (strong, nonatomic) SloppySwiperNoViewControllersEndedBlock noViewControllersTransitionCancelled;

/// Finish (successfully) the no view controllers transition
@property (strong, nonatomic) SloppySwiperNoViewControllersEndedBlock noViewControllersTransitionFinished;

/// Designated initializer if the class isn't used from the Interface Builder.
- (instancetype)initWithNavigationController:(UINavigationController *)navigationController;

@end
