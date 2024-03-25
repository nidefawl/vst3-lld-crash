cmake_minimum_required(VERSION 3.21)
project("vst3-lld-crash" LANGUAGES C CXX)

# disabling either option will prevent the crash
add_link_options(-Wl,--gc-sections)
add_compile_options(-ffunction-sections -fdata-sections)

set(SMTG_ENABLE_VST3_PLUGIN_EXAMPLES OFF)
set(SMTG_ENABLE_VST3_HOSTING_EXAMPLES OFF)
set(SMTG_ENABLE_VSTGUI_SUPPORT OFF)
set(SMTG_RENAME_ASSERT OFF)

add_subdirectory("vst3sdk" "build-vst3sdk")

add_executable(test_vst3sdk main.cpp)
target_compile_options(test_vst3sdk PRIVATE -Wall -Wextra -pedantic)
target_link_libraries(test_vst3sdk PUBLIC sdk_hosting)
