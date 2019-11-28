//
//  UIImage+IKExtension.m
//  YJXScanMoudle
//
//  Created by peter on 2019/11/28.
//

#import "UIImage+IKExtension.h"
#import "YJXScanDefinition.h"



@implementation UIImage (IKExtension)

+ (UIImage *)imageWithColor:(UIColor *)color {
    CGRect rect = CGRectMake(0.0f, 0.0f, 1.0f, 1.0f);
    UIGraphicsBeginImageContext(rect.size);
    CGContextRef context = UIGraphicsGetCurrentContext();
    
    CGContextSetFillColorWithColor(context, [color CGColor]);
    CGContextFillRect(context, rect);
    
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return image;
    
}

+ (UIImage *)originalImageNamed:(NSString *)name {
    return [[self imageNamed:name] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
}

+ (UIImage *)placeholderImageWithSize:(CGSize)size image:(UIImage *)image {
    UIColor *backgroundColor = ITG_COLOR_HEX(0xF2F2F2);
    CGFloat logoWH = (size.width > size.height ? size.height : size.width) * 0.5;
    CGSize logSize = CGSizeMake(logoWH, logoWH);
    UIGraphicsBeginImageContextWithOptions(size, 0, [UIScreen mainScreen].scale);
    [backgroundColor set];
    UIRectFill(CGRectMake(0, 0, size.width, size.height));
    CGFloat imageX = (size.width / 2) - (logSize.width / 2);
    CGFloat imageY = (size.height / 2) - (logSize.width / 2);
    [image drawInRect:CGRectMake(imageX, imageY, logSize.width, logSize.height)];
    UIImage *resImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return resImage;
    
}
@end
