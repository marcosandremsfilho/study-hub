import cv2

# Set the desired video frame rate (frames per second)
video_frame_rate_hz = 60

# Index of the webcam
webcam_index = 0

# Convert the frame rate from Hz (FPS) to milliseconds per frame
video_frame_rate_ms = int((1 / video_frame_rate_hz) * 1000)

# Open the webcam for video capture
webcam = cv2.VideoCapture(webcam_index)

is_new_frame = True
while is_new_frame:
    # Capture a frame from the webcam
    is_new_frame, frame = webcam.read()

    if is_new_frame:
        # Display the captured frame in a window
        cv2.imshow("webcam", frame)

        # Exit the loop when the 'q' key is pressed
        # This prevents the program from running indefinitely
        if cv2.waitKey(video_frame_rate_ms) & 0xFF == ord('q'):
            break

# Release the video capture object and close all OpenCV windows. This is important to release the memory used by OpenCV.
webcam.release()
cv2.destroyAllWindows()
