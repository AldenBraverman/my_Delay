/*
  ==============================================================================

    Parameters.h
    Created: 9 Mar 2025 4:39:32pm
    Author:  Alden

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>


//const juce::ParameterID gainParamID{ "gain", 1 };
const juce::ParameterID tempoSyncParamID { "tempoSync", 1};
const juce::ParameterID delayNoteParamID { "delayNote", 1};

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
    
    int delayNote = 0;
    bool tempoSync = false;
    
    static constexpr float minDelayTime = 5.0f;
    static constexpr float maxDelayTime = 5000.0f;
    
private:
    juce::AudioParameterFloat* gainParam;
    juce::LinearSmoothedValue<float> gainSmoother;
    juce::AudioParameterBool* tempoSyncParam;
    juce::AudioParameterChoice* delayNoteParam;
    
    
};
