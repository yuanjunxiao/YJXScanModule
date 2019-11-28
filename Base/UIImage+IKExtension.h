//
//  UIImage+IKExtension.h
//  YJXScanMoudle
//
//  Created by peter on 2019/11/28.
//



#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (IKExtension)

+ (UIImage * _Nullable)imageWithColor:(UIColor * _Nullable)color;

+ (UIImage * _Nullable)originalImageNamed:(NSString *)name;

+ (UIImage *)placeholderImageWithSize:(CGSize)size image:(UIImage *)image;

@end

NS_ASSUME_NONNULL_END
