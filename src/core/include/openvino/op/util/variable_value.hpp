// Copyright (C) 2018-2023 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <memory>
#include <utility>

#include "openvino/core/core_visibility.hpp"
#include "openvino/core/deprecated.hpp"
#include "openvino/runtime/tensor.hpp"

namespace ov {
namespace op {
namespace util {
/// VariableValue stores data and state (reset flag) for a Variable,
/// and provides an interface for changing them.
class OPENVINO_API VariableValue {
public:
    using Ptr = std::shared_ptr<VariableValue>;
    /// \brief Constructs an uninitialized VariableValue.
    VariableValue();

    /// \brief Sets the reset flag to a new state.
    /// \param reset The new state of the reset flag.
    void set_reset(bool reset);

    /// \brief Returns the current reset flag state.
    bool get_reset() const;

    explicit VariableValue(const ov::Tensor& value);

    /// \brief Constructor for VariableValue.
    /// \deprecated This method is deprecated and will be removed in 2024.0 release. Please use method with ov::Tensor
    /// instead
    /// \param value Data for Variable.
    /// \param reset The current state of the reset flag.
    VariableValue(const ov::Tensor& value, bool reset);

    /// \brief Returns the current stored data.
    /// \deprecated This method is deprecated and will be removed in 2024.0 release. Please use method with ov::Tensor
    /// instead
    const ov::Tensor& get_state() const;

    /// \brief Sets new values for Variable.
    /// \deprecated This method is deprecated and will be removed in 2024.0 release. Please use method with ov::Tensor
    /// instead
    /// \param value New data for Variable.
    void set_state(const ov::Tensor& value);

private:
    bool m_reset = true;
    ov::Tensor m_value;
};
}  // namespace util
}  // namespace op
}  // namespace ov
