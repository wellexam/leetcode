import glob
import os


def files(curr_dir='.', ext='*.exe'):
    """当前目录下的文件"""
    for i in glob.glob(os.path.join(curr_dir, ext)):
        yield i


def remove_files(rootdir, ext, show=False):
    """删除rootdir目录下的符合的文件"""
    for i in files(rootdir, ext):
        if show:
            print(i)
        os.remove(i)


remove_files("./", "*.exe", True)
