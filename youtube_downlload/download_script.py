from pytube import YouTube

# Function to download a YouTube video
def download_youtube_video(url, save_path='.'):
    try:
        # Create YouTube object
        yt = YouTube(url)
        
        # Get the highest resolution stream
        ys = yt.streams.get_highest_resolution()
        
        # Print video title and resolution
        print(f'Downloading: {yt.title}')
        print(f'Resolution: {ys.resolution}')
        
        # Download the video
        ys.download(save_path)
        
        print('Download completed!')
    except Exception as e:
        print(f'Error: {e}')

# Example usage
if __name__ == '__main__':
    video_url = input('Enter the URL of the YouTube video: ')
    save_path = input('Enter the directory where the video will be saved (leave blank for current directory): ')
    
    # Set default save path if none provided
    if not save_path:
        save_path = '.'
    
    download_youtube_video(video_url, save_path)
