/*******************************************************************************
* Copyright 2017-2018 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#pragma once

#include "ngraph/runtime/tensor_view.hpp"
#include "ngraph/type/element_type.hpp"

namespace ngraph
{
    namespace runtime
    {
        static size_t alignment = 64;

        namespace he
        {
            class HEBackend;

            class HETensorView : public ngraph::runtime::TensorView
            {
            public:
                HETensorView(const std::shared_ptr<ngraph::descriptor::TensorView>& descriptor)
                    : TensorView(descriptor)
                {
                }

                virtual ~HETensorView();

                /// @brief Write bytes directly into the tensor
                /// @param p Pointer to source of data
                /// @param tensor_offset Offset into tensor storage to begin writing. Must be element-aligned.
                /// @param n Number of bytes to write, must be integral number of elements.
                virtual void write(const void* p, size_t tensor_offset, size_t n) override;

                /// @brief Read bytes directly from the tensor
                /// @param p Pointer to destination for data
                /// @param tensor_offset Offset into tensor storage to begin reading. Must be element-aligned.
                /// @param n Number of bytes to read, must be integral number of elements.
                virtual void read(void* p, size_t tensor_offset, size_t n) const override;

            private:
                std::shared_ptr<HEBackend> m_he_backend;
            };
        }
    }
}