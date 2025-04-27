#include <iostream>
#include <cstdlib>  // For system() function

void download_video(const std::string& url) {
    // Correct yt-dlp command to download best video and audio and merge them into a single mp4
    std::string command = "yt-dlp -f bestvideo+bestaudio --merge-output-format mp4 " + url;

    // Execute the command
    int result = system(command.c_str());

    if (result == 0) {
        std::cout << "✅ Download complete!" << std::endl;
    } else {
        std::cout << "❌ Something went wrong while downloading the video." << std::endl;
    }
}

int main() {
    std::string url="https://youtu.be/4XO9fpwNFso?si=-NSbvDO4hwFeM9tL";
   

    // Download the video
    download_video(url);

    return 0;
}

