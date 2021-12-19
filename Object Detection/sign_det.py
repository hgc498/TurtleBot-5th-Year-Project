# Stop sign detection
#Refrenced: https://www.geeksforgeeks.org/detect-an-object-with-opencv-python/
from picamera.array import PiRGBArray # Generates a 3D RGB array
from picamera import PiCamera # Provides a Python interface for the RPi Camera Module
import time # Provides time-related functions
import cv2 # OpenCV library
import numpy as np # Import NumPy library

# Initialize the camera
camera = PiCamera()

# Set the camera resolution
camera.resolution = (640, 480)

# Set the number of frames per second
camera.framerate = 32

# Generates a 3D RGB array and stores it in rawCapture
raw_capture = PiRGBArray(camera, size=(640, 480))

# Wait a certain number of seconds to allow the camera time to warmup
time.sleep(0.1)

kernel = np.ones((5,5),np.uint8)

# Capture frames continuously from the camera
for frame in camera.capture_continuous(raw_capture, format="bgr", use_video_port=True):

    image = frame.array

    # OpenCV opens images as BRG
    # but we want it as RGB We'll
    # also need a grayscale version
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # Close gaps using closing
    gray = cv2.morphologyEx(gray,cv2.MORPH_CLOSE,kernel)

    # Remove salt and pepper noise with a median filter
    gray = cv2.medianBlur(gray,5)

    # Use minSize because for not
    # bothering with extra-small
    # dots that would look like STOP signs
    stop_data = cv2.CascadeClassifier('stop_data.xml')

    found = stop_data.detectMultiScale(gray,
                                       minSize =(20, 20))

    # Don't do anything if there's
    # no sign
    amount_found = len(found)

    if amount_found != 0:

        # There may be more than one
        # sign in the image
        for (x, y, width, height) in found:

            # We draw a green rectangle around
            # every recognized sign
            cv2.rectangle(image, (x, y),
                          (x + height, y + width),
                          (0, 255, 0), 5)

            image = cv2.putText(image, 'Stop Sign', (x, y-10), cv2.FONT_HERSHEY_SIMPLEX, 1, (0,255,0),2)



    # Display the resulting frame
    cv2.imshow("Frame",image)

    # Wait for keyPress for 1 millisecond
    key = cv2.waitKey(1) & 0xFF

    # Clear the stream in preparation for the next frame
    raw_capture.truncate(0)

    # If "q" is pressed on the keyboard,
    # exit this loop
    if key == ord("q"):
      break

# Close down windows
cv2.destroyAllWindows()
