/*
 * Copyright (c) 2021-2023 Huawei Device Co., Ltd.
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
 */

#ifndef OHOS_CAMERA_HDI_LOG_H
#define OHOS_CAMERA_HDI_LOG_H

#include <stdio.h>

#include "hilog/log.h"

#undef LOG_DOMAIN
#undef LOG_TAG
#define LOG_DOMAIN 0xD002513
#define LOG_TAG "SEQUENCEABLE"

#define FILENAME (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

#ifndef OHOS_DEBUG
#define DECORATOR_HDFLOG(op, fmt, args...)             \
    do {                                               \
        op(LOG_CORE, "%{public}s() " fmt, __FUNCTION__, ##args); \
    } while (0)
#else
#define DECORATOR_HDFLOG(op, fmt, args...)                                     \
    do {                                                                       \
        op(LOG_CORE, "{%s()-%s:%d} " fmt, __FUNCTION__, FILENAME, __LINE__, ##args); \
    } while (0)
#endif

#define HDI_CAMERA_LOGE(fmt, ...) DECORATOR_HDFLOG(HILOG_ERROR, fmt, ##__VA_ARGS__)
#define HDI_CAMERA_LOGW(fmt, ...) DECORATOR_HDFLOG(HILOG_WARN, fmt, ##__VA_ARGS__)
#define HDI_CAMERA_LOGI(fmt, ...) DECORATOR_HDFLOG(HILOG_INFO, fmt, ##__VA_ARGS__)
#define HDI_CAMERA_LOGV(fmt, ...) DECORATOR_HDFLOG(HILOG_DEBUG, fmt, ##__VA_ARGS__)
#define HDI_CAMERA_LOGD(fmt, ...) DECORATOR_HDFLOG(HILOG_DEBUG, fmt, ##__VA_ARGS__)

#endif //OHOS_CAMERA_HDI_LOG_H