import glob
import os
from PIL import Image

from resizeimage import resizeimage


print("Convert");
x = int(input("x number of pixels:\n"))
y = int(input("y number of pixels:\n"))

if not os.path.exists('to'):
    os.mkdir("to")

for imageName in glob.glob("./from/*"):
    print(imageName)
    with open(imageName, 'r+b') as f:
        with Image.open(imageName) as image:
            newImage = image.resize([x, y], Image.ANTIALIAS)
            newImage.save("./to/" + imageName[len("./from/"):], image.format)

path = os.getcwd()
print("In " + path)
for imageName in glob.glob("./to/*"): 
    print("converted: " + imageName)