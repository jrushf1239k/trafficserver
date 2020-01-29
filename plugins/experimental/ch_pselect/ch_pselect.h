/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#pragma once

#include "tscore/ConsistentHash.h"

#define PLUGIN_NAME "ch_pselect"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdarg.h>

#ifndef _CH_PSELECT_UNIT_TESTS
#define CH_Debug(fmt, ...) TSDebug(PLUGIN_NAME, "[%s:%d]: " fmt, __FILE__, __LINE__, ##__VA_ARGS__)
#define CH_Error(fmt, ...) TSError("(%s) [%s:%d]: " fmt, PLUGIN_NAME, __FILE__, __LINE__, ##__VA_ARGS__)
#else
void PrintToStdErr(const char *fmt, ...);

#define CH_Debug(fmt, ...) PrintToStdErr("%s [%s:%d]: " fmt, PLUGIN_NAME, __FILE__, __LINE__, ##__VA_ARGS__)
#define CH_Error(fmt, ...) PrintToStdErr("%s [%s:%d]: " fmt, PLUGIN_NAME, __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */
