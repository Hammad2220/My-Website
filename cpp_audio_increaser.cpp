#include <iostream>
#include <string>
#include <cstdlib> // For system()

// Function to increase the volume of the video using FFmpeg
void increase_video_audio(const std::string& input_video, const std::string& output_video, double volume_multiplier) {
    // Construct the FFmpeg command
    std::string ffmpeg_command = "ffmpeg -i " + input_video + " -filter:a \"volume=" + std::to_string(volume_multiplier) + "\" -c:v copy -c:a aac " + output_video;
    
    // Run the command
    std::cout << "Executing command: " << ffmpeg_command << std::endl;
    int result = std::system(ffmpeg_command.c_str());
    
    if(result == 0) {
        std::cout << "Audio increased successfully. Output video saved as " << output_video << std::endl;
    } else {
        std::cout << "Error occurred while processing the video." << std::endl;
    }
}

int main() {
    std::string input_video = "input_video.mp4"; // Replace with your input video file
    std::string output_video = "output_video_louder.mp4"; // Output file name
    double volume_multiplier = 2.0; // Adjust this value to increase volume (e.g., 2.0 for double volume)
    
    // Increase the audio volume of the video
    increase_video_audio(input_video, output_video, volume_multiplier);
    
    return 0;
}
