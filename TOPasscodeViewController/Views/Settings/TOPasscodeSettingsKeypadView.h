//
//  TOPasscodeSettingsKeypadView.h
//  TOPasscodeViewControllerExample
//
//  Created by Tim Oliver on 6/18/17.
//  Copyright © 2017 Timothy Oliver. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TOPasscodeViewControllerConstants.h"

NS_ASSUME_NONNULL_BEGIN

@interface TOPasscodeSettingsKeypadView : UIView

/* Whether the control is allowing input */
@property (nonatomic, assign) BOOL enabled;

/* Whether the view is currently light mode or dark. */
@property (nonatomic, assign) TOPasscodeSettingsViewStyle style;

/* The color of the separator line */
@property (nonatomic, strong) UIColor *separatorLineColor;

/* Labels in the buttons are laid out horizontally */
@property (nonatomic, assign) BOOL buttonLabelHorizontalLayout;

/* If overridden, the foreground color of the buttons */
@property (nonatomic, assign) CGFloat keypadButtonBorderThickness;

/* Untapped background images */
@property (nonatomic, strong, null_resettable) UIColor *keypadButtonForegroundColor;
@property (nonatomic, strong, null_resettable) UIColor *keypadButtonBorderColor;

/* Tapped background images */
@property (nonatomic, strong, null_resettable) UIColor *keypadButtonTappedForegroundColor;
@property (nonatomic, strong, nullable) UIColor *keypadButtonTappedBorderColor;

/* Button label styling */
@property (nonatomic, strong) UIFont *keypadButtonNumberFont;
@property (nonatomic, strong) UIFont *keypadButtonLetteringFont;
@property (nonatomic, strong) UIColor *keypadButtonLabelTextColor;
@property (nonatomic, assign) CGFloat keypadButtonVerticalSpacing;
@property (nonatomic, assign) CGFloat keypadButtonHorizontalSpacing;
@property (nonatomic, assign) CGFloat keypadButtonLetteringSpacing;

/* Callback handlers */
@property (nonatomic, copy) void (^numberButtonTappedHandler)(NSInteger number);
@property (nonatomic, copy) void (^deleteButtonTappedHandler)();

/* In really small sizes, set the keypad labels to horizontal */
- (void)setButtonLabelHorizontalLayout:(BOOL)horizontal animated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
