#import "MGLRasterTileSource.h"

#include <memory>

namespace mbgl {
    namespace style {
        class RasterSource;
    }
}

NS_ASSUME_NONNULL_BEGIN

@interface MGLRasterTileSource (Private)

@property (nonatomic, readonly, nullable) mbgl::style::RasterSource *rawSource;

- (std::unique_ptr<mbgl::style::RasterSource>)pendingSourceWithIdentifier:(NSString *)identifier configurationURL:(NSURL *)configurationURL tileSize:(CGFloat)tileSize;

@end

NS_ASSUME_NONNULL_END
