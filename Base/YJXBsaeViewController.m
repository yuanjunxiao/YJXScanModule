//
//  YJXBsaeViewController.m
//  YJXScanMoudle
//
//  Created by peter on 2019/11/28.
//

#import "YJXBsaeViewController.h"
#import
#define ITGViewControllerImage(fileName)\
({ \
NSBundle *currentBundle = [NSBundle bundleForClass:NSClassFromString(@"YJXBsaeViewController")]; \
NSString *resourceBundlePath = [currentBundle pathForResource:@"Base" ofType:@"bundle"]; \
NSBundle *resourceBundle = [NSBundle bundleWithPath:resourceBundlePath]; \
UIImage *image = [UIImage imageNamed:fileName inBundle:resourceBundle compatibleWithTraitCollection:nil]; \
image; \
})
@interface YJXBsaeViewController ()
@property (nonatomic, assign) BOOL hideNavigationBar;
@property (nonatomic, strong) UIColor * navigationBarColor;

@end

@implementation YJXBsaeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
