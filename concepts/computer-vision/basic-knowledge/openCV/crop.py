import os
import cv2

image_path = os.path.join("..", "media", "bubbles.jpg")

# Load the image from the specified path
img = cv2.imread(image_path)

# Crop a region of the image. Here, we select pixels between:
# - Rows (height): 300 to 500
# - Columns (width): 400 to 600
cropped_img = img[300:500, 400:600]

# Display the original image in a window named "img"
cv2.imshow("img", img)

# Display the cropped image in a window named "cropped img"
cv2.imshow("cropped img", cropped_img)

# Wait indefinitely until a key is pressed
cv2.waitKey(0)

# Close all OpenCV windows
cv2.destroyAllWindows()
