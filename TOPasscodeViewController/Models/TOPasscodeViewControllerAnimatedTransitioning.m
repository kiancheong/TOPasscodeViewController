//
//  TOPasscodeViewControllerAnimatedTransitioning.m
//  TOPasscodeViewControllerExample
//
//  Created by Tim Oliver on 5/15/17.
//  Copyright © 2017 Timothy Oliver. All rights reserved.
//

#import "TOPasscodeViewControllerAnimatedTransitioning.h"
#import "TOPasscodeViewController.h"
#import "TOPasscodeView.h"

@interface TOPasscodeViewControllerAnimatedTransitioning ()
@property (nonatomic, weak) TOPasscodeViewController *passcodeViewController;
@end

@implementation TOPasscodeViewControllerAnimatedTransitioning

- (instancetype)initWithPasscodeViewController:(TOPasscodeViewController *)passcodeViewController dismissing:(BOOL)dismissing success:(BOOL)success
{
    if (self = [super init]) {
        _passcodeViewController = passcodeViewController;
        _dismissing = dismissing;
        _passcodeSuccess = success;
    }

    return self;
}

- (NSTimeInterval)transitionDuration:(nullable id <UIViewControllerContextTransitioning>)transitionContext
{
    return 0.35f;
}

- (void)animateTransition:(id <UIViewControllerContextTransitioning>)transitionContext
{
    BOOL isPhone = UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone;
    UIView *containerView = transitionContext.containerView;
    UIVisualEffectView *backgroundEffectView = self.passcodeViewController.backgroundEffectView;
    UIView *backgroundView = self.passcodeViewController.backgroundView;
    UIVisualEffect *backgroundEffect = backgroundEffectView.effect;
    TOPasscodeView *passcodeView = self.passcodeViewController.passcodeView;

    // Set the initial properties when presenting
    if (!self.dismissing) {
        backgroundEffectView.effect = nil;
        backgroundView.alpha = 0.0f;

        self.passcodeViewController.view.frame = containerView.bounds;
        [containerView addSubview:self.passcodeViewController.view];
    }
    else {
        UIViewController *baseController = [transitionContext viewControllerForKey:UITransitionContextToViewControllerKey];
        if (baseController.view.superview == nil) {
            [containerView insertSubview:baseController.view atIndex:0];
        }
    }

    CGFloat alpha = self.dismissing ? 1.0f : 0.0f;
    passcodeView.contentAlpha = alpha;

    // Animate the accessory views
    if (isPhone) {
        self.passcodeViewController.leftAccessoryButton.alpha = alpha;
        self.passcodeViewController.rightAccessoryButton.alpha = alpha;
        self.passcodeViewController.cancelButton.alpha = alpha;
        self.passcodeViewController.biometricButton.alpha  = alpha;
    }

    id animationBlock = ^{
        backgroundEffectView.effect = self.dismissing ? nil : backgroundEffect;
        backgroundView.alpha = self.dismissing ? 0.0f : 1.0f;

        CGFloat toAlpha = self.dismissing ? 0.0f : 1.0f;
        passcodeView.contentAlpha = toAlpha;
        if (isPhone) {
            self.passcodeViewController.leftAccessoryButton.alpha = toAlpha;
            self.passcodeViewController.rightAccessoryButton.alpha = toAlpha;
            self.passcodeViewController.cancelButton.alpha = toAlpha;
            self.passcodeViewController.biometricButton.alpha  = toAlpha;
        }
    };

    id completedBlock = ^(BOOL completed) {
        backgroundEffectView.effect = backgroundEffect;
        [transitionContext completeTransition:completed];
    };

    // If we're animating out from a successful password, play a zooming out animation
    // to give some more context
    if (self.passcodeSuccess && self.dismissing) {
        CABasicAnimation *animation = [CABasicAnimation animationWithKeyPath:@"transform"];
        animation.duration = [self transitionDuration:transitionContext];
        animation.toValue = [NSValue valueWithCATransform3D:CATransform3DMakeScale(0.75f, 0.75f, 1)];
        animation.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseInEaseOut];
        [passcodeView.layer addAnimation:animation forKey:@"transform"];
    }

    [UIView animateWithDuration:[self transitionDuration:transitionContext]
                          delay:0.0f
//         usingSpringWithDamping:1.0f
//          initialSpringVelocity:0.3f
                        options:UIViewAnimationOptionAllowUserInteraction
                     animations:animationBlock
                     completion:completedBlock];
}

@end
