// The MIT License (MIT)
//
// Copyright (c) 2015 Alexander Grebenyuk (github.com/kean).
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class DFCollectionViewPreheatingController;


@protocol DFCollectionViewPreheatingControllerDelegate <NSObject>

/*! Tells the delegate that the preheat window changed significantly.
 @param addedIndexPaths Index paths for items added to the preheat window. Index paths are sorted so that the items closest to the previous preheat window are in the beginning of the array; no matter whether user is scrolling forward of backward.
 @param removedIndexPaths Index paths for items there were removed from the preheat window.
 */
- (void)collectionViewPreheatingController:(DFCollectionViewPreheatingController *)controller didUpdatePreheatRectWithAddedIndexPaths:(NSArray *)addedIndexPaths removedIndexPaths:(NSArray *)removedIndexPaths;

@end


/*! Detects changes in collection view content offset and updates preheat window. The preheat window is a rect inside the collection view content which is bigger than the viewport of the collection view. Provides delegate with index paths for added and removed cells when the preheat window changes significantly.
 @note Supports UICollectionViewFlowLayout and it's subclasses with either vertical or horizontal scroll direction.
 */
@interface DFCollectionViewPreheatingController : NSObject

@property (nonatomic, readonly) UICollectionView *collectionView;

@property (nonatomic, weak) id<DFCollectionViewPreheatingControllerDelegate> delegate;

/*! The proportion of the collection view bounds (either width or height depending on the scroll direction) that is used as a preheat window. Default value is 2.0.
 */
@property (nonatomic) CGFloat preheatRectRatio;

/*! How far the user need to scroll from the current preheat rect to revalidate it. Default value is 0.33.
 */
@property (nonatomic) CGFloat preheatRectRevalidationRatio;

@property (nonatomic, readonly) CGRect preheatRect;
@property (nonatomic, readonly) NSSet *preheatIndexPaths;

/*! Initializes preheating controller with a collection view.
 Collection view must not be nil.
 */
- (instancetype)initWithCollectionView:(UICollectionView *)collectionView NS_DESIGNATED_INITIALIZER;

/*! Resets preheat rect and calls delegate with removed index paths.
 */
- (void)resetPreheatRect;

/*! Updates current preheat rect and all items contained in it.
 */
- (void)updatePreheatRect;

@end
