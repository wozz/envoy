#pragma once

#include <memory>

#include "envoy/api/v2/rds.pb.h"
#include "envoy/router/router.h"

namespace Envoy {
namespace Router {

/**
 * A provider for constant route configurations.
 */
class RouteConfigProvider {
public:
  struct ConfigInfo {
    const envoy::api::v2::RouteConfiguration& config_;
    std::string version_;
  };

  virtual ~RouteConfigProvider() {}

  /**
   * @return Router::ConfigConstSharedPtr a route configuration for use during a single request. The
   * returned config may be different on a subsequent call, so a new config should be acquired for
   * each request flow.
   */
  virtual Router::ConfigConstSharedPtr config() PURE;

  /**
   * @return fixfix
   */
  virtual absl::optional<ConfigInfo> configInfo() const PURE;
};

typedef std::shared_ptr<RouteConfigProvider> RouteConfigProviderSharedPtr;

} // namespace Router
} // namespace Envoy
