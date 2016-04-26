#pragma once

#include "input_state_cache.hpp"

namespace stats {
  /**
   * Writes container state to disk, so that it can be recovered if the agent is restarted.
   */
  class InputStateCacheImpl : public InputStateCache {
   public:
    InputStateCacheImpl(const mesos::Parameters& parameters);

    const std::string& path() const;
    container_id_map<UDPEndpoint> get_containers();
    void add_container(const mesos::ContainerID& container_id, const UDPEndpoint& endpoint);
    void remove_container(const mesos::ContainerID& container_id);

   private:
    const std::string state_path_dir;
  };
}
