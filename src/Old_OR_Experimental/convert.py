import os
import time
import imageio
import rawpy

def DirPrompt():
    parent_directory = input('\nPlease input the path to the target directory: ')
    parent_directory = parent_directory.strip()

    if not parent_directory.endswith('/') or not parent_directory.endswith('\\'):
        parent_directory += '/'

    while not os.path.exists(parent_directory) or not os.path.isdir(parent_directory):
        print("\nCould not find path in filesystem or is not a directory...")
        parent_directory = input('\nPlease input the path to the target directory that contains the folder of the folders of images: ')
        parent_directory = parent_directory.strip()

        if not parent_directory.endswith('/') or not parent_directory.endswith('\\'):
            parent_directory += '/'

    return parent_directory

def GetDirs(path):
    dirs = []
    for dir in sorted(os.listdir(path)):
        if os.path.isdir(path + dir):
            if ("partial" in dir or "rename_all" in dir) and "EREBIDAE" not in dir and "HEDYLIDAE" not in dir:
                dirs.append(dir)
    return dirs


def GetSubDirs(path):
    dirs = []
    for dir in sorted(os.listdir(path)):
        if os.path.isdir(path + dir):
            #if "partial" in dir or "rename_all" in dir:
            dirs.append(dir)
    return dirs


def GetImgs(path):
    imgs = []
    for img in sorted(os.listdir(path)):
        if os.path.isfile(path + img) and img.split('.')[1] == 'CR2':
            imgs.append(img)
    return imgs


def GetJPGS(path):
    jpgs = []
    for jpg in sorted(os.listdir(path)):
        if os.path.isfile(path + jpg) and (jpg.split('.')[1] == 'JPG' or jpg.split('.')[1] == 'jpg' or jpg.split('.')[1] == 'JPEG' or jpg.split('.')[1] == 'jpeg'):
            jpgs.append(jpg)
    return jpgs


def main():
    path = r"M:\\NaturalHistory\\Lepidoptera\\Kawahara\\Digitization\\LepNet\\PINNED_COLLECTION\\IMAGES_UPLOADED\\IMAGES_CR2_editing_complete\\"
    families = GetDirs(path)
    for family in families:
        genera = GetSubDirs(path + family + '/')
        for genus in genera:
            dates = GetSubDirs(path + family + '/' + genus + '/')
            for date in dates:
                images = GetImgs(path + family + '/' + genus + '/' + date + '/')
                current_path = path + family + '/' + genus + '/' + date + '/'
                print("Current Path: " + current_path)
                #old_new_paths = []
                for image in images:
                    if "MGCL" in image:
                        continue
                    print (image)
                    #time.sleep(4)
                    with rawpy.imread(current_path + image) as raw:
                        rgb = raw.postprocess(user_wb=[1, 0.5, 1, 0])
                        name = image.split('.')[0] + '.jpg'
                        imageio.imsave(current_path + name, rgb)
                    #time.sleep(10)


if __name__ == '__main__':
    main()