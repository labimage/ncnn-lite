// Tencent is pleased to support the open source community by making ncnn available.
//
// Copyright (C) 2017 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// https://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

#ifndef NCNN_MODELBIN_H
#define NCNN_MODELBIN_H

#include "mat.h"

struct DataReader;
struct ModelBin
{
    virtual ~ModelBin();
    // element type
    // 0 = auto
    // 1 = float32
    // 2 = float16
    // 3 = int8
    // load vec
    virtual Mat load(int w, int type) const = 0;
    // load image
    virtual Mat load(int w, int h, int type) const;
    // load dim
    virtual Mat load(int w, int h, int c, int type) const;
};

struct ModelBinFromDataReader : public ModelBin
{
    ModelBinFromDataReader(const DataReader& dr);

    virtual Mat load(int w, int type) const;

    const DataReader& dr;
};

struct ModelBinFromMatArray : public ModelBin
{
    // construct from weight blob array
    ModelBinFromMatArray(const Mat* weights);

    virtual Mat load(int w, int type) const;

    mutable const Mat* weights;
};

#endif // NCNN_MODELBIN_H
