//
//  YJXBsaeViewController.h
//  YJXScanMoudle
//
//  Created by peter on 2019/11/28.
//

#import <UIKit/UIKit.h>

@interface YJXBsaeViewController : UIViewController

/*
*  @brief 是否需要隐藏导航栏
*  默认为NO
*  如需使用, 须Override
*/
- (void)hideNavigationBar;

/*
*  @brief 导航栏颜色
*  默认为 ITG_MAIN_THEME_COLOR
*  如需使用, 须Override
*/
- (UIColor *)navigationBarColor;

/*
*  @brief 支持侧滑
*  默认为 YES
*  如需使用, 须Override
*/
- (BOOL)enableScreenEdgepanGesture;

/*
*  @brief 是否为Presented控制器
*  如该控制器是Presented, 须将该值设为YES
*  默认为NO
*/
@property (nonatomic, assign, readwrite) BOOL presented;
/*
*  @brief 导航栏关闭按钮执行的事件
*  默认事件为关闭此控制器
*/
@property (nonatomic, copy, readwrite) void (^navigationBackAction)(void);
@end


