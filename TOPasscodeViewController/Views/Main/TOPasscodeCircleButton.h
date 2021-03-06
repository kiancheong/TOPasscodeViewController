//
//  TOPasscodeCircleButton.h
//  TOPasscodeViewControllerExample
//
//  Created by Tim Oliver on 5/15/17.
//  Copyright © 2017 Timothy Oliver. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TOPasscodeCircleView;
@class TOPasscodeButtonLabel;

NS_ASSUME_NONNULL_BEGIN

@interface TOPasscodeCircleButton : UIControl

// Alpha value that properly controls the necessary subviews
@property (nonatomic, assign) CGFloat contentAlpha;

// Required to be set before this view can be properly rendered
@property (nonatomic, strong) UIImage *backgroundImage;
@property (nonatomic, strong) UIImage *hightlightedBackgroundImage;
@property (nonatomic, strong) UIVibrancyEffect *vibrancyEffect;

// Properties with default values
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong, nullable) UIColor *highlightedTextColor;
@property (nonatomic, strong) UIFont *numberFont;
@property (nonatomic, strong) UIFont *letteringFont;
@property (nonatomic, assign) CGFloat letteringCharacterSpacing;
@property (nonatomic, assign) CGFloat letteringVerticalSpacing;

@property (nonatomic, readonly) NSString *numberString;
@property (nonatomic, readonly) NSString *letteringString;

// The internal views
@property (nonatomic, readonly) TOPasscodeButtonLabel *buttonLabel;
@property (nonatomic, readonly) TOPasscodeCircleView *circleView;
@property (nonatomic, readonly) UIVisualEffectView *vibrancyView;

// Callback handler
@property (nonatomic, copy) void (^buttonTappedHandler)();

- (instancetype)initWithNumberString:(NSString *)numberString letteringString:(NSString *)letteringString;

// Automatically called when tapped
- (void)setHighlighted:(BOOL)highlighted animated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
