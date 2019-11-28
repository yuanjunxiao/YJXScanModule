//
//  YJXScanDefinition.h
//  YJXScanMoudle
//
//  Created by peter on 2019/11/28.
//

#ifndef YJXScanDefinition_h
#define YJXScanDefinition_h


#define ITG_SCAN_ROUTE @"tutorabc://scan"

/**
 *  扫到二维码/条形码后是否需要回到上一级页面
 *  如果设置为YES, 则扫到二维码/条形码后, 回到上一级页面; 在上一级页面中queryParams取key=ITG_SCAN_QRCODE即为结果
 *  如果设置为NO,  则扫到二维码/条形码后, 用ITGRoute打开扫到的内容
 *  默认为NO
 *  Example: [ITGRoute handleURL:[NSURL URLWithString:@"tutorabc://scan?ITG_SCAN_NEED_BACK=1"]];
 */
#define ITG_SCAN_NEED_BACK  @"ITG_SCAN_NEED_BACK"

#define ITG_SCAN_QRCODE     @"ITG_SCAN_QRCODE"


// 系统版本
#define ITG_SYSTEM_VERSION  [[[UIDevice currentDevice] systemVersion] floatValue]
#define ITG_IOS_8   (ITG_SYSTEM_VERSION >= 7.0 && ITG_SYSTEM_VERSION < 8.0)
#define ITG_IOS_9   (ITG_SYSTEM_VERSION >= 8.0 && ITG_SYSTEM_VERSION < 9.0)
#define ITG_IOS_10  (ITG_SYSTEM_VERSION >= 10.0 && ITG_SYSTEM_VERSION < 11.0)
#define ITG_IOS_11  (ITG_SYSTEM_VERSION >= 11.0 && ITG_SYSTEM_VERSION < 12.0)
#define ITG_IOS_12  (ITG_SYSTEM_VERSION >= 12.0 && ITG_SYSTEM_VERSION < 13.0)

#define ITG_IOS_AT_LEAST_8  (ITG_SYSTEM_VERSION >= 8.0)
#define ITG_IOS_AT_LEAST_9  (ITG_SYSTEM_VERSION >= 9.0)
#define ITG_IOS_AT_LEAST_10 (ITG_SYSTEM_VERSION >= 10.0)
#define ITG_IOS_AT_LEAST_11 (ITG_SYSTEM_VERSION >= 11.0)
#define ITG_IOS_AT_LEAST_12 (ITG_SYSTEM_VERSION >= 12.0)

// 型号
#define ITG_DEVICE_IPAD         (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define ITG_DEVICE_IPHONE       (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)

// 特殊手机型号, 刘海屏: iPhoneX, iPhone XS, iPhone XR...
#define ITGSafeAreaInsets() \
({ \
UIEdgeInsets insets; \
if (@available(iOS 11.0, *)) { \
insets = UIApplication.sharedApplication.keyWindow.safeAreaInsets; \
} else { \
insets = UIEdgeInsetsZero; \
} \
(insets); \
}) \

#define ITG_DEVICE_IPHONE_X \
({  \
CGFloat bottomSafeInset = ITGSafeAreaInsets().bottom;  \
BOOL isDeviceX = bottomSafeInset == 34.0f || bottomSafeInset == 21.0f;  \
BOOL isIPhoneX = isDeviceX && ITG_DEVICE_IPHONE;\
(isIPhoneX);    \
})  \

// 特殊手机型号, 小手机: iPhone4S, iPhone5S... (屏幕为3.5英寸或者4英寸)
#define ITG_DEVICE_IPHONE_SMALL (ITG_DEVICE_IPHONE && (ITG_DEFALUT_SCREEN_WIDTH == 320 || ITG_DEFALUT_SCREEN_HEIGHT == 320))

// 屏幕方向
#define ITG_DEVICE_STATUS_BAR_ORIENTATION   [[UIApplication sharedApplication] statusBarOrientation]
#define ITG_DEVICE_PORTRAIT \
(ITG_DEVICE_STATUS_BAR_ORIENTATION == UIInterfaceOrientationPortrait || ITG_DEVICE_STATUS_BAR_ORIENTATION == UIDeviceOrientationPortraitUpsideDown)
#define ITG_DEVICE_LANDSCAPE \
(ITG_DEVICE_STATUS_BAR_ORIENTATION == UIDeviceOrientationLandscapeRight || ITG_DEVICE_STATUS_BAR_ORIENTATION == UIDeviceOrientationLandscapeLeft)

// 像素
#define ITG_DEFALUT_SCREEN_WIDTH     [[UIScreen mainScreen] bounds].size.width
#define ITG_DEFALUT_SCREEN_HEIGHT    [[UIScreen mainScreen] bounds].size.height
#define ITG_DEFALUT_STATUSBAR_HEIGHT [[UIApplication sharedApplication] statusBarFrame].size.height
#define ITG_ORIENTATION_SCREEN_WIDTH   MIN([UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height)
#define ITG_ORIENTATION_SCREEN_HEIGHT  MAX([UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height)

// 默认设计稿像素
#define ITG_DEFALUT_PHONE_SCALE_PX 375.0
#define ITG_DEFALUT_PAD_SCALE_PX   1024.0
// 比例像素
#define ITG_PHONE_SCALE_PX(value)  ceil((value / (ITG_DEFALUT_PHONE_SCALE_PX / [UIScreen mainScreen].bounds.size.width)))
#define ITG_PAD_SCALE_PX(value)    ceil((value / (ITG_DEFALUT_PAD_SCALE_PX / [UIScreen mainScreen].bounds.size.width)))
#define ITG_ORIENTATION_PHONE_SCALE_PX(value)  ceil((value / (ITG_DEFALUT_PHONE_SCALE_PX / ITG_ORIENTATION_SCREEN_WIDTH)))


// 字体
#define ITG_DEFALUT_FONT(size)      [UIFont systemFontOfSize:size]
#define ITG_DEFALUT_BOLD_FONT(size) [UIFont boldSystemFontOfSize:size]
#define ITG_PF_REGULAR_FONT(_size_) [UIFont fontWithName:@"PingFangSC-Regular" size:_size_]
#define ITG_PF_MEDIUM_FONT(_size_)  [UIFont fontWithName:@"PingFangSC-Medium" size:_size_]

// 颜色
// RGBA
#define ITG_COLOR_RGBA(r, g, b ,a) \
[UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:a]
#define ITG_COLOR_RGB(r, g, b)  ITG_COLOR_RGBA(r, g, b, 1.0)

// 16进制
#define ITG_COLOR_HEXA(hex, a) \
[UIColor colorWithRed:((float)((hex & 0xFF0000) >> 16))/255.0 green:((float)((hex & 0xFF00) >> 8))/255.0 blue:((float)(hex & 0xFF))/255.0 alpha:a]
#define ITG_COLOR_HEX(hex)  ITG_COLOR_HEXA(hex, 1.0)

// 主题色
#define ITG_MAIN_THEME_COLOR    ITG_COLOR_HEX(0xF74C4C) // 247,76,76
#define ITG_MAIN_TEXT_COLOR     ITG_COLOR_HEX(0x333333) // 51,51,51

// ----- ITGKit 内部本地化使用 -----
#define ITGKitLocalizedString(Key) \
ITGLocalizedString(Key, @"Base", @"ITGKitTable")

#endif /* YJXScanDefinition_h */
