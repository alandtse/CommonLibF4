#pragma once

#include "F4SE/F4SE.h"
#include "RE/Fallout.h"

#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <fstream>
#include <functional>
#include <memory>
#include <span>
#include <tuple>
#include <unordered_set>
#include <utility>
#include <vector>

#include <srell.hpp>

#ifdef NDEBUG
#	include <spdlog/sinks/basic_file_sink.h>
#else
#	include <spdlog/sinks/msvc_sink.h>
#endif

#define DLLEXPORT __declspec(dllexport)

namespace logger = F4SE::log;
namespace stl = F4SE::stl;
namespace WinAPI = F4SE::WinAPI;
using namespace std::literals;
