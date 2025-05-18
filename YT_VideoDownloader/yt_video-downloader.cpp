#include <iostream>
#include <string>
#include <cstdlib>
#include <curl/curl.h> // for system()

int main() {
    std::string url;
    std::string outputDir;
    std::string formatChoice;

    std::cout << "Enter YouTube video URL: ";
    std::getline(std::cin, url);

    std::cout << "Enter the full path of the directory to save the file: ";
    std::getline(std::cin, outputDir);

    std::cout << "Do you want to download as MP4 (video) or MP3 (audio)? Enter 'mp4' or 'mp3': ";
    std::getline(std::cin, formatChoice);

    std::string command;

    if (formatChoice == "mp4") {
        // Download the best video and audio and merge them into one MP4 file, at 480p if possible
        command = "yt-dlp -f \"bestvideo[height<=480]+bestaudio/best[height<=480]\" --merge-output-format mp4 "
                  "-o \"" + outputDir + "/%(title)s.%(ext)s\" \"" + url + "\"";
    } else if (formatChoice == "mp3") {
        // Download audio only and convert it to mp3
        command = "yt-dlp -x --audio-format mp3 "
                  "-o \"" + outputDir + "/%(title)s.%(ext)s\" \"" + url + "\"";
    } else {
        std::cout << "Invalid format choice. Please enter 'mp4' or 'mp3'.\n";
        return 1;
    }

    std::cout << "\nDownloading in ." << formatChoice << " format...\n";
    int result = system(command.c_str());

    if (result == 0) {
        std::cout << "Download completed successfully.\n";
    } else {
        std::cout << "An error occurred during download. Make sure yt-dlp (and ffmpeg if needed) is installed.\n";
    }

    return 0;
}
