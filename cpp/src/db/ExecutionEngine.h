#pragma once

#include <vector>
#include <memory>

#include "Status.h"

namespace zilliz {
namespace vecwise {
namespace engine {

class ExecutionEngine;

class ExecutionEngine {
public:

    Status AddWithIds(const std::vector<float>& vectors,
                              const std::vector<long>& vector_ids);

    virtual Status AddWithIds(long n, const float *xdata, const long *xids) = 0;

    virtual size_t Count() const = 0;

    virtual size_t Size() const = 0;

    virtual size_t PhysicalSize() const = 0;

    virtual Status Serialize() = 0;

    virtual Status Load() = 0;

    virtual Status Merge(const std::string& location) = 0;

    virtual Status Search(long n,
                          const float *data,
                          long k,
                          float *distances,
                          long *labels) const = 0;

    virtual std::shared_ptr<ExecutionEngine> BuildIndex(const std::string&) = 0;

    virtual Status Cache() = 0;

    virtual ~ExecutionEngine() {}
};

template <typename Derived>
class ExecutionEngineBase {
public:

    Status AddWithIds(const std::vector<float>& vectors,
                              const std::vector<long>& vector_ids);

    Status AddWithIds(long n, const float *xdata, const long *xids);

    size_t Count() const;

    size_t Size() const;

    size_t PhysicalSize() const;

    Status Serialize();

    Status Load();

    Status Merge(const std::string& location);

    Status Search(long n,
                  const float *data,
                  long k,
                  float *distances,
                  long *labels) const;

    std::shared_ptr<Derived> BuildIndex(const std::string&);

    Status Cache();
};


} // namespace engine
} // namespace vecwise
} // namespace zilliz
