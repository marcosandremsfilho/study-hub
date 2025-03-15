import os

import cv2

# Define the path to the input image
image_path = os.path.join("..", "media", "bubbles.jpg")

# Read the image from the specified path and store it in the 'img' variable
img = cv2.imread(image_path)

# Define the path for saving the new image
new_image_path = os.path.join("..", "media", "bubbles_out.jpg")

# Save the image with a different filename in the same directory
cv2.imwrite(new_image_path, img)

# Display the image in a window named 'image'
cv2.imshow("image", img)

# Keep the image window open until a key is pressed
# The argument '0' means the program will wait indefinitely until a key is pressed
cv2.waitKey(0)

# Close all OpenCV windows to free up resources. This is important to release the memory used by OpenCV.
cv2.destroyAllWindows()
