import os
import cv2

# Define the resizing factor (50% of the original size)
resize_value = 0.5

image_path = os.path.join("..", "media", "bubbles.jpg")

# Load the image from the specified path
img = cv2.imread(image_path)

# Get the original image dimensions (height, width, and color channels)
height, width, color_channels = img.shape

# Print the original image dimensions
print(f"Height: {height}\nWidth: {width}\nColorscheme: {color_channels}")

# Display the original image in a window named "img"
cv2.imshow("img", img)

# Scale the height and width based on the resize factor
height = int(height * resize_value)
width = int(width * resize_value)

# Resize the image using OpenCV's `resize` function
# Note: OpenCV's resize function expects (width, height) as arguments, opposite of img.shape (height, width)
resized_img = cv2.resize(img, (width, height))

# Get the resized image dimensions
height, width, color_channels = resized_img.shape

# Print the resized image dimensions
print(f"Height: {height}\nWidth: {width}\nColorscheme: {color_channels}")

# Display the resized image in a window named "resized img"
cv2.imshow("resized img", resized_img)

# Wait indefinitely until a key is pressed
cv2.waitKey(0)

# Close all OpenCV windows
cv2.destroyAllWindows()

