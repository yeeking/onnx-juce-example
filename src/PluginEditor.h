/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <onnxruntime_cxx_api.h>

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class TestPluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    TestPluginAudioProcessorEditor (TestPluginAudioProcessor&);
    ~TestPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    /** load an onnx model  */
    void loadONNXModel(const std::string& modelFile);
    std::string print_shape(const std::vector<std::int64_t>& v);

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    TestPluginAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TestPluginAudioProcessorEditor)
};
