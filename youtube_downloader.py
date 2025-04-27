import yt_dlp
import os

def download_video(url, output_path='.', merge_format='mp4'):
    options = {
        'format': 'bestvideo+bestaudio/best',
        'outtmpl': f'{output_path}/%(title)s.%(ext)s',
        'merge_output_format': merge_format,
        'quiet': False,
        'verbose': True,  # Turn on verbose mode for debugging
    }

    with yt_dlp.YoutubeDL(options) as ydl:
        print(f"\n🔽 Downloading from: {url}")
        try:
            ydl.download([url])
        except Exception as e:
            print(f"Error: {e}")
        print("\n✅ Done!")

def get_download_path():
    # Ask user where they want to save the video
    while True:
        output_path = input("Enter the folder path where you want to save the video (or press Enter to save in the current folder): ")
        # If the user doesn't enter anything, use the current directory.
        if not output_path:
            output_path = '.'

        # Check if the directory exists, if not, ask again.
        if os.path.isdir(output_path):
            return output_path
        else:
            print("Invalid path! Please enter a valid directory.")

def get_video_url():
    # Ask the user for the video URL
    while True:
        video_url = input("Enter the URL of the video you want to download: ")
        if video_url:
            return video_url
        else:
            print("URL cannot be empty. Please enter a valid URL.")

# === Example ===
if __name__ == "__main__":
    # Ask for the video URL
    video_url = get_video_url()

    # Ask for the download location
    download_path = get_download_path()

    # Download video
    download_video(video_url, download_path)
