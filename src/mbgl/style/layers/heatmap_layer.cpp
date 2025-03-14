// This file is generated. Edit scripts/generate-style-code.js, then run `make style-code`.

#include <mbgl/style/layers/heatmap_layer.hpp>
#include <mbgl/style/layers/heatmap_layer_impl.hpp>
#include <mbgl/style/layer_observer.hpp>
#include <mbgl/style/conversion/color_ramp_property_value.hpp>
#include <mbgl/style/conversion/constant.hpp>
#include <mbgl/style/conversion/property_value.hpp>
#include <mbgl/style/conversion/transition_options.hpp>
#include <mbgl/style/conversion/json.hpp>
#include <mbgl/style/conversion_impl.hpp>
#include <mbgl/util/traits.hpp>

#include <mapbox/eternal.hpp>

namespace mbgl {
namespace style {


// static
const LayerTypeInfo* HeatmapLayer::Impl::staticTypeInfo() noexcept {
    const static LayerTypeInfo typeInfo
        {"heatmap",
          LayerTypeInfo::Source::Required,
          LayerTypeInfo::Pass3D::Required,
          LayerTypeInfo::Layout::NotRequired,
          LayerTypeInfo::FadingTiles::NotRequired,
          LayerTypeInfo::CrossTileIndex::NotRequired
        };
    return &typeInfo;
}


HeatmapLayer::HeatmapLayer(const std::string& layerID, const std::string& sourceID)
    : Layer(makeMutable<Impl>(layerID, sourceID)) {
}

HeatmapLayer::HeatmapLayer(Immutable<Impl> impl_)
    : Layer(std::move(impl_)) {
}

HeatmapLayer::~HeatmapLayer() = default;

const HeatmapLayer::Impl& HeatmapLayer::impl() const {
    return static_cast<const Impl&>(*baseImpl);
}

Mutable<HeatmapLayer::Impl> HeatmapLayer::mutableImpl() const {
    return makeMutable<Impl>(impl());
}

std::unique_ptr<Layer> HeatmapLayer::cloneRef(const std::string& id_) const {
    auto impl_ = mutableImpl();
    impl_->id = id_;
    impl_->paint = HeatmapPaintProperties::Transitionable();
    return std::make_unique<HeatmapLayer>(std::move(impl_));
}

void HeatmapLayer::Impl::stringifyLayout(rapidjson::Writer<rapidjson::StringBuffer>&) const {
}

// Layout properties


// Paint properties

ColorRampPropertyValue HeatmapLayer::getDefaultHeatmapColor() {
    conversion::Error error;
    std::string rawValue = R"JSON(["interpolate",["linear"],["heatmap-density"],0,"rgba(0, 0, 255, 0)",0.1,"royalblue",0.3,"cyan",0.5,"lime",0.7,"yellow",1,"red"])JSON";
    return *conversion::convertJSON<ColorRampPropertyValue>(rawValue, error);
}

const ColorRampPropertyValue& HeatmapLayer::getHeatmapColor() const {
    return impl().paint.template get<HeatmapColor>().value;
}

void HeatmapLayer::setHeatmapColor(const ColorRampPropertyValue& value) {
    if (value == getHeatmapColor())
        return;
    auto impl_ = mutableImpl();
    impl_->paint.template get<HeatmapColor>().value = value;
    baseImpl = std::move(impl_);
    observer->onLayerChanged(*this);
}

void HeatmapLayer::setHeatmapColorTransition(const TransitionOptions& options) {
    auto impl_ = mutableImpl();
    impl_->paint.template get<HeatmapColor>().options = options;
    baseImpl = std::move(impl_);
}

TransitionOptions HeatmapLayer::getHeatmapColorTransition() const {
    return impl().paint.template get<HeatmapColor>().options;
}

PropertyValue<float> HeatmapLayer::getDefaultHeatmapIntensity() {
    return { 1 };
}

const PropertyValue<float>& HeatmapLayer::getHeatmapIntensity() const {
    return impl().paint.template get<HeatmapIntensity>().value;
}

void HeatmapLayer::setHeatmapIntensity(const PropertyValue<float>& value) {
    if (value == getHeatmapIntensity())
        return;
    auto impl_ = mutableImpl();
    impl_->paint.template get<HeatmapIntensity>().value = value;
    baseImpl = std::move(impl_);
    observer->onLayerChanged(*this);
}

void HeatmapLayer::setHeatmapIntensityTransition(const TransitionOptions& options) {
    auto impl_ = mutableImpl();
    impl_->paint.template get<HeatmapIntensity>().options = options;
    baseImpl = std::move(impl_);
}

TransitionOptions HeatmapLayer::getHeatmapIntensityTransition() const {
    return impl().paint.template get<HeatmapIntensity>().options;
}

PropertyValue<float> HeatmapLayer::getDefaultHeatmapOpacity() {
    return { 1 };
}

const PropertyValue<float>& HeatmapLayer::getHeatmapOpacity() const {
    return impl().paint.template get<HeatmapOpacity>().value;
}

void HeatmapLayer::setHeatmapOpacity(const PropertyValue<float>& value) {
    if (value == getHeatmapOpacity())
        return;
    auto impl_ = mutableImpl();
    impl_->paint.template get<HeatmapOpacity>().value = value;
    baseImpl = std::move(impl_);
    observer->onLayerChanged(*this);
}

void HeatmapLayer::setHeatmapOpacityTransition(const TransitionOptions& options) {
    auto impl_ = mutableImpl();
    impl_->paint.template get<HeatmapOpacity>().options = options;
    baseImpl = std::move(impl_);
}

TransitionOptions HeatmapLayer::getHeatmapOpacityTransition() const {
    return impl().paint.template get<HeatmapOpacity>().options;
}

PropertyValue<float> HeatmapLayer::getDefaultHeatmapRadius() {
    return { 30 };
}

const PropertyValue<float>& HeatmapLayer::getHeatmapRadius() const {
    return impl().paint.template get<HeatmapRadius>().value;
}

void HeatmapLayer::setHeatmapRadius(const PropertyValue<float>& value) {
    if (value == getHeatmapRadius())
        return;
    auto impl_ = mutableImpl();
    impl_->paint.template get<HeatmapRadius>().value = value;
    baseImpl = std::move(impl_);
    observer->onLayerChanged(*this);
}

void HeatmapLayer::setHeatmapRadiusTransition(const TransitionOptions& options) {
    auto impl_ = mutableImpl();
    impl_->paint.template get<HeatmapRadius>().options = options;
    baseImpl = std::move(impl_);
}

TransitionOptions HeatmapLayer::getHeatmapRadiusTransition() const {
    return impl().paint.template get<HeatmapRadius>().options;
}

PropertyValue<float> HeatmapLayer::getDefaultHeatmapWeight() {
    return { 1 };
}

const PropertyValue<float>& HeatmapLayer::getHeatmapWeight() const {
    return impl().paint.template get<HeatmapWeight>().value;
}

void HeatmapLayer::setHeatmapWeight(const PropertyValue<float>& value) {
    if (value == getHeatmapWeight())
        return;
    auto impl_ = mutableImpl();
    impl_->paint.template get<HeatmapWeight>().value = value;
    baseImpl = std::move(impl_);
    observer->onLayerChanged(*this);
}

void HeatmapLayer::setHeatmapWeightTransition(const TransitionOptions& options) {
    auto impl_ = mutableImpl();
    impl_->paint.template get<HeatmapWeight>().options = options;
    baseImpl = std::move(impl_);
}

TransitionOptions HeatmapLayer::getHeatmapWeightTransition() const {
    return impl().paint.template get<HeatmapWeight>().options;
}

using namespace conversion;

optional<Error> HeatmapLayer::setPaintProperty(const std::string& name, const Convertible& value) {
    enum class Property {
        HeatmapColor,
        HeatmapIntensity,
        HeatmapOpacity,
        HeatmapRadius,
        HeatmapWeight,
        HeatmapColorTransition,
        HeatmapIntensityTransition,
        HeatmapOpacityTransition,
        HeatmapRadiusTransition,
        HeatmapWeightTransition,
    };

    MAPBOX_ETERNAL_CONSTEXPR const auto properties = mapbox::eternal::hash_map<mapbox::eternal::string, uint8_t>({
        { "heatmap-color", mbgl::underlying_type(Property::HeatmapColor) },
        { "heatmap-intensity", mbgl::underlying_type(Property::HeatmapIntensity) },
        { "heatmap-opacity", mbgl::underlying_type(Property::HeatmapOpacity) },
        { "heatmap-radius", mbgl::underlying_type(Property::HeatmapRadius) },
        { "heatmap-weight", mbgl::underlying_type(Property::HeatmapWeight) },
        { "heatmap-color-transition", mbgl::underlying_type(Property::HeatmapColorTransition) },
        { "heatmap-intensity-transition", mbgl::underlying_type(Property::HeatmapIntensityTransition) },
        { "heatmap-opacity-transition", mbgl::underlying_type(Property::HeatmapOpacityTransition) },
        { "heatmap-radius-transition", mbgl::underlying_type(Property::HeatmapRadiusTransition) },
        { "heatmap-weight-transition", mbgl::underlying_type(Property::HeatmapWeightTransition) }
    });

    const auto it = properties.find(name.c_str());
    if (it == properties.end()) {
        return Error { "layer doesn't support this property" };
    }

    auto property = static_cast<Property>(it->second);

        
    if (property == Property::HeatmapColor) {
        Error error;
        optional<ColorRampPropertyValue> typedValue = convert<ColorRampPropertyValue>(value, error, false, false);
        if (!typedValue) {
            return error;
        }
        
        setHeatmapColor(*typedValue);
        return nullopt;
        
    }
    
    if (property == Property::HeatmapIntensity || property == Property::HeatmapOpacity) {
        Error error;
        optional<PropertyValue<float>> typedValue = convert<PropertyValue<float>>(value, error, false, false);
        if (!typedValue) {
            return error;
        }
        
        if (property == Property::HeatmapIntensity) {
            setHeatmapIntensity(*typedValue);
            return nullopt;
        }
        
        if (property == Property::HeatmapOpacity) {
            setHeatmapOpacity(*typedValue);
            return nullopt;
        }
        
    }
    
    if (property == Property::HeatmapRadius || property == Property::HeatmapWeight) {
        Error error;
        optional<PropertyValue<float>> typedValue = convert<PropertyValue<float>>(value, error, true, false);
        if (!typedValue) {
            return error;
        }
        
        if (property == Property::HeatmapRadius) {
            setHeatmapRadius(*typedValue);
            return nullopt;
        }
        
        if (property == Property::HeatmapWeight) {
            setHeatmapWeight(*typedValue);
            return nullopt;
        }
        
    }
    

    Error error;
    optional<TransitionOptions> transition = convert<TransitionOptions>(value, error);
    if (!transition) {
        return error;
    }
    
    if (property == Property::HeatmapColorTransition) {
        setHeatmapColorTransition(*transition);
        return nullopt;
    }
    
    if (property == Property::HeatmapIntensityTransition) {
        setHeatmapIntensityTransition(*transition);
        return nullopt;
    }
    
    if (property == Property::HeatmapOpacityTransition) {
        setHeatmapOpacityTransition(*transition);
        return nullopt;
    }
    
    if (property == Property::HeatmapRadiusTransition) {
        setHeatmapRadiusTransition(*transition);
        return nullopt;
    }
    
    if (property == Property::HeatmapWeightTransition) {
        setHeatmapWeightTransition(*transition);
        return nullopt;
    }
    

    return Error { "layer doesn't support this property" };
}

optional<Error> HeatmapLayer::setLayoutProperty(const std::string& name, const Convertible& value) {
    if (name == "visibility") {
        return Layer::setVisibility(value);
    }

    return Error { "layer doesn't support this property" };
}

Mutable<Layer::Impl> HeatmapLayer::mutableBaseImpl() const {
    return staticMutableCast<Layer::Impl>(mutableImpl());
}

} // namespace style
} // namespace mbgl
