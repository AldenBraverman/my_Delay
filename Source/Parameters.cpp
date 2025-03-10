/*
  ==============================================================================

    Parameters.cpp
    Created: 9 Mar 2025 4:39:32pm
    Author:  Alden

  ==============================================================================
*/

#include "Parameters.h"

template<typename T>
static void castParameter(juce::AudioProcessorValueTreeState& apvts,
    const juce::ParameterID& id, T& destination)
{
    destination = dynamic_cast<T>(apvts.getParameter(id.getParamID()));
    jassert(destination);
}

Parameters::Parameters(juce::AudioProcessorValueTreeState& apvts)
{
    // auto* param = apvts.getParameter(gainParamID.getParamID());
    // gainParam = dynamic_cast<juce::AudioParameterFloat*>(param);
    castParameter(apvts, gainParamID, gainParam);
}

void Parameters::prepareToPlay(double sampleRate) noexcept
{
    double duration = 0.02;
    gainSmoother.reset(sampleRate, duration);
}

void Parameters::reset() noexcept
{
    gain = 0.0f;

    gainSmoother.setCurrentAndTargetValue(
        juce::Decibels::decibelsToGain(gainParam->get())
    );
}

void Parameters::update() noexcept
{
    /*float gainInDecibels = juce::Decibels::decibelsToGain(gainParam->get());
    float newGain = juce::Decibels::decibelsToGain(gainInDecibels);
    gainSmoother.setTargetValue(newGain);*/

    gainSmoother.setTargetValue(juce::Decibels::decibelsToGain(gainParam->get()));
}

void Parameters::smoothen() noexcept
{
    gain = gainSmoother.getNextValue();
}