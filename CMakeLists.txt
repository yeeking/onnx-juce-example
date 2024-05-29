# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License.

cmake_minimum_required(VERSION 3.10)  # Specify the minimum version for CMake

project(OnnxJuce VERSION 0.1)  # Specify the name of your project

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)  # Make sure that the compiler exits if C++17 support is not available
set(CMAKE_CXX_EXTENSIONS OFF)  # Turn off compiler-specific extensions like gnu++17

# set these up for your system if onnxruntime and header are not 
# in standard search paths, e.g. for mac homebrew setup
#include_directories(/opt/homebrew/include/onnxruntime/)
include_directories(/home/matthewyk/src/sw/onnxruntime-linux-x64-1.18.0/include/)
#link_directories(/opt/homebrew/lib/)
link_directories(/home/matthewyk/src/sw/onnxruntime-linux-x64-1.18.0/lib/)

add_executable(onnx-model-loader src/main.cpp)

target_link_libraries(onnx-model-loader PRIVATE onnxruntime)

#### Now the JUCE stuff

add_subdirectory(./JUCE ./JUCE)                    # If you've put JUCE in a subdirectory called JUCE

juce_add_plugin(minimal_plugin
    # VERSION ...                               # Set this if the plugin version is different to the project version
    # ICON_BIG ...                              # ICON_* arguments specify a path to an image file to use as an icon for the Standalone
    # ICON_SMALL ...
    COMPANY_NAME Yee-King                          # Specify the name of the plugin's author
    IS_SYNTH TRUE                       # Is this a synth or an effect?
    NEEDS_MIDI_INPUT TRUE               # Does the plugin need midi input?
    # NEEDS_MIDI_OUTPUT TRUE/FALSE              # Does the plugin need midi output?
    # IS_MIDI_EFFECT TRUE/FALSE                 # Is this plugin a MIDI effect?
    NEEDS_MIDI_OUTPUT TRUE
    # EDITOR_WANTS_KEYBOARD_FOCUS TRUE/FALSE    # Does the editor need keyboard focus?
    COPY_PLUGIN_AFTER_BUILD TRUE        # Should the plugin be installed to a default location after building?
    PLUGIN_MANUFACTURER_CODE Yeek               # A four-character manufacturer id with at least one upper-case character
    PLUGIN_CODE abc1                            # A unique four-character plugin id with exactly one upper-case character
                                                # GarageBand 10.3 requires the first letter to be upper-case, and the remaining letters to be lower-case
    FORMATS AU VST3 Standalone                  # The formats to build. Other valid formats are: AAX Unity VST AU AUv3
    PRODUCT_NAME "minimal_plugin")        # The name of the final executable, which can differ from the target name

juce_generate_juce_header(minimal_plugin)

target_sources(minimal_plugin
    PRIVATE
    src/PluginEditor.cpp
    src/PluginProcessor.cpp)

target_compile_definitions(minimal_plugin
    PUBLIC # 
        JUCE_ALSA=1
        JUCE_DIRECTSOUND=1
        JUCE_DISABLE_CAUTIOUS_PARAMETER_ID_CHECKING=1
        #JUCE_PLUGINHOST_LADSPA=1
        #JUCE_PLUGINHOST_LV2=1
        #JUCE_PLUGINHOST_VST3=1
        JUCE_USE_OGGVORBIS=1
        #JUCE_VST3_HOST_CROSS_PLATFORM_UID=1
        # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
        JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_plugin` call
        JUCE_USE_CURL=0     # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_plugin` call
        JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(minimal_plugin
    PRIVATE
        # AudioPluginData           # If we'd created a binary data target, we'd link to it here
        juce::juce_audio_utils
        onnxruntime
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)


