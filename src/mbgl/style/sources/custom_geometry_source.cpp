#include <mbgl/style/sources/custom_geometry_source.hpp>
#include <mbgl/style/custom_tile_loader.hpp>
#include <mbgl/style/sources/custom_geometry_source_impl.hpp>
#include <mbgl/style/source_observer.hpp>
#include <mbgl/actor/actor.hpp>
#include <mbgl/actor/scheduler.hpp>
#include <mbgl/tile/tile_id.hpp>
#include <tuple>
#include <map>

namespace mbgl {
namespace style {

CustomGeometrySource::CustomGeometrySource(std::string id,
                                       const CustomGeometrySource::Options options)
    : Source(makeMutable<CustomGeometrySource::Impl>(std::move(id), options)),
    loader(std::make_unique<Actor<CustomTileLoader>>(Scheduler::GetBackground(), options.fetchTileFunction, options.cancelTileFunction)) {
}

CustomGeometrySource::~CustomGeometrySource() = default;

const CustomGeometrySource::Impl& CustomGeometrySource::impl() const {
    return static_cast<const CustomGeometrySource::Impl&>(*baseImpl);
}

void CustomGeometrySource::loadDescription(FileSource&) {
    baseImpl = makeMutable<CustomGeometrySource::Impl>(impl(), loader->self());
    loaded = true;
    observer->onSourceLoaded(*this);
}

void CustomGeometrySource::setTileData(const CanonicalTileID& tileID,
                                     const GeoJSON& data) {
    loader->self().invoke(&CustomTileLoader::setTileData, tileID, data);
}

void CustomGeometrySource::invalidateTile(const CanonicalTileID& tileID) {
    loader->self().invoke(&CustomTileLoader::invalidateTile, tileID);
}

void CustomGeometrySource::invalidateRegion(const LatLngBounds& bounds) {
    loader->self().invoke(&CustomTileLoader::invalidateRegion, bounds, impl().getZoomRange());
}

} // namespace style
} // namespace mbgl
