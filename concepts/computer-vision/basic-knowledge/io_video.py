import os

import cv2

# Set the desired video frame rate (frames per second)
video_frame_rate_hz = 40

# Convert the frame rate from Hz (FPS) to milliseconds per frame
video_frame_rate_ms = int((1 / video_frame_rate_hz) * 1000)

# Define the path to the video file
video_path = os.path.join("..", "media", "bubbles.mp4")

# Open the video file for reading
video = cv2.VideoCapture(video_path)

# Flag to check if a new frame is successfully read
is_new_frame = True

# Loop through the video frames
while is_new_frame:
    # Read the next frame from the video
    is_new_frame, frame = video.read()

    if is_new_frame:
        # Display the frame in a window
        cv2.imshow("video", frame)

        # Wait for the specified duration to control playback speed
        cv2.waitKey(video_frame_rate_ms)
    else:
        # Break the loop if there are no more frames
        break

# Release the video capture object and close all OpenCV windows. This is important to release the memory used by OpenCV.
video.release()
cv2.destroyAllWindows()
