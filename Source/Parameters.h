/*
  ==============================================================================

    Parameters.h
    Created: 9 Mar 2025 4:39:32pm
    Author:  Alden

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

const juce::ParameterID gainParamID{ "gain", 1 };

class Parameters
{
public:
    Parameters(juce::AudioProcessorValueTreeState& apvts);

    static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

    void update() noexcept;

    float gain = 0.0f;

    void prepareToPlay(double sampleRate) noexcept;
    void reset() noexcept;
    void smoothen() noexcept;
private:
    juce::AudioParameterFloat* gainParam;

    juce::LinearSmoothedValue<float> gainSmoother;
};