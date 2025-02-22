// Copyright 2014 Wouter van Oortmerssen. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#ifdef _MSC_VER
    #define _CRT_SECURE_NO_WARNINGS
    #define _SCL_SECURE_NO_WARNINGS
    #define _CRTDBG_MAP_ALLOC
    #include <stdlib.h>
    #include <crtdbg.h>
    #ifndef NDEBUG
        #define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
        #define new DEBUG_NEW
    #endif
    #include "StackWalker\StackWalkerHelpers.h"
    #include <intrin.h>
#endif

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <float.h>
#include <limits.h>
#include <csetjmp>

#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <iterator>
#include <functional>
#include <array>
#include <type_traits>
#include <memory>
#include <optional>
#include <charconv>

#if defined(__has_include) && __has_include(<string_view>)
    #include <string_view>
#else
    #include <experimental/string_view>
#endif

#include <thread>
#include <future>

#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

#include "gsl/gsl-lite.hpp"

#include "flatbuffers/flatbuffers.h"
#include "flatbuffers/flexbuffers.h"

// Our universally used headers.
#include "wentropy.h"
#include "tools.h"
#include "platform.h"
#include "slaballoc.h"
#include "geom.h"
#include "unicode.h"

using namespace geom;

#ifndef VM_JIT_MODE
    #if defined(BUILD_CONTEXT_compiled_lobster) || \
        defined(__IOS__) || \
        defined(__ANDROID__) || \
        defined(__EMSCRIPTEN__)
        #define VM_JIT_MODE 0
    #else
        #define VM_JIT_MODE 1
    #endif
#endif

#ifndef LOBSTER_ENGINE
    // By default, build Lobster assuming it comes with the default engine.
    // Build systems can override this for a console-only build.
    #define LOBSTER_ENGINE 1
#endif
