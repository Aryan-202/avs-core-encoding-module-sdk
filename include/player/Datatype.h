#pragma once

#include <chrono>
#include <functional>

namespace DataType {

    enum class FrameType {
        Video,
        Audio,
        Unknown
    };

    struct MediaFrame {
        FrameType type = FrameType::Unknown;

        // --- Common Data ---
        double pts = 0.0; 

        // --- Video Specific Data ---
        int width = 0;
        int height = 0;
        
        uint8_t* data[8] = { nullptr }; 
        
        int linesize[8] = { 0 }; 

        // --- Audio Specific Data ---
        int sampleRate = 0;
        int channels = 0;
        int numSamples = 0;

        bool ownsMemory = false; 
    };

} // namespace DataType

namespace Player {
    enum class Error {
        None = 0,
        File_Not_Found,
        Unknown
    };

    using TimeChangeCallBack = std::function<void(double, double)>;
    using TogglePlayCallBack = std::function<void(bool)>;
    using VoidCallBack       = std::function<void()>;

    using Frame = DataType::MediaFrame;
    using Time  = std::chrono::high_resolution_clock;
}