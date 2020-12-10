//
// Created by desig on 2020-08-15.
//

#ifndef EUPHONY_WAVEGENERATOR_H
#define EUPHONY_WAVEGENERATOR_H


#include <TappableAudioSource.h>
#include "Oscillator.h"

namespace Euphony {
    class WaveGenerator : public TappableAudioSource {
        static constexpr size_t kSharedBufferSize = 2048;
    public:
        WaveGenerator(int32_t sampleRate, int32_t channelCount);

        ~WaveGenerator() = default;

        WaveGenerator(WaveGenerator &&other) = default;

        WaveGenerator &operator=(WaveGenerator &&other) = default;

        void tap(bool isDown) override;

        void renderAudio(float *audioData, int32_t numFrames) override;

        void setFrequency(double frequency);

    private:
        std::unique_ptr<Oscillator[]> mOscillators;
        std::unique_ptr<float[]> mBuffer = std::make_unique<float[]>(kSharedBufferSize);

    };
}


#endif //EUPHONY_WAVEGENERATOR_H