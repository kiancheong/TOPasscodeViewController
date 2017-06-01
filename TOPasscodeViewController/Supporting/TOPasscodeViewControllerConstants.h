//
//  TOPasscodeViewControllerConstants.h
//  TOPasscodeViewControllerExample
//
//  Created by Tim Oliver on 5/15/17.
//  Copyright © 2017 Timothy Oliver. All rights reserved.
//

/* The visual style of the PIN view controller */
typedef NS_ENUM(NSInteger, TOPasscodeViewStyle) {
    TOPasscodeViewStyleTranslucentDark,
    TOPasscodeViewStyleTranslucentLight,
    TOPasscodeViewStyleOpaqueDark,
    TOPasscodeViewStyleOpaqueLight
};

/* Depending on the amount of horizontal space, the sizing of the elements */
typedef NS_ENUM(NSInteger, TOPasscodeViewContentSize) {
    TOPasscodeViewContentSizeDefault = 414, // Default, 414 points and above (6 Plus, all remaining iPad sizes)
    TOPasscodeViewContentSizeMedium = 375, // Greater or equal to 375 points: iPhone 6 / iPad Pro 1/4 split mode
    TOPasscodeViewContentSizeSmall  = 320  // Greater or equal to 320 points: iPhone SE / iPad 1/4 split mode
};

static inline BOOL TOPasscodeViewStyleIsTranslucent(TOPasscodeViewStyle style) {
    return style <= TOPasscodeViewStyleTranslucentLight;
}

static inline BOOL TOPasscodeViewStyleIsDark(TOPasscodeViewStyle style) {
    return style < TOPasscodeViewStyleTranslucentLight || style == TOPasscodeViewStyleOpaqueDark;
}
