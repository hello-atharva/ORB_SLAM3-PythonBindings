# ORB_SLAM2-PythonBindings
A python wrapper for ORB_SLAM2, which can be found at [https://github.com/raulmur/ORB_SLAM2](https://github.com/raulmur/ORB_SLAM2).
This is designed to work with the base version of ORB_SLAM2, with a couple of minimal API changes to access the system output.
It has been tested on ubuntu 14.04 and 16.04 and built against Python3, although it does not rely on any python3 features.

## Installation

### Prerequesities

- ORBSLAM2 source code
- ORBSLAM2 compiliation dependencies (Pangolin, Eigen, OpenCV)
- Boost, specifically its python component (python-35)
- Numpy development headers (to represent images in python, automatically converted to cv::Mat)

### Setup

#### Compilation
Return to the ORBSLAM-Python source, build and install it by running
```
mkdir build
cd build
cmake ..
make
make install
```
This will install the .so file to /usr/local/lib/python3.10/dist-packages, such that it should 
If you have changed the install location of ORBSLAM3, you need to indicate where it is installed using ``-DORB_SLAM3_DIR=/your/desired/location``,
which should be the same as the install prefix above (and contain 'include' and 'lib' folders).

Verify your installation by typing
```
python3
>>> import orbslam3
```
And there should be no errors.

#### Examples

ORBSLAM3's examples have been re-implemented in python in the examples folder.
Run them with the same parameters as the ORBSLAM examples, i.e.:

```
python3 examples/orbslam_mono_tum.py [PATH_TO_ORBSLAM]/Vocabulary/ORBvoc.txt [PATH_TO_ORBSLAM]/Examples_old/Monocular/TUM2.yaml [PATH_TO_TUM]/rgbd_dataset_freiburg2_pioneer_slam/
```

```
python3 orbslam_mono_kitti.py [PATH_TO_ORBSLAM]/Vocabulary/ORBvoc.txt [PATH_TO_ORBSLAM]/Examples/Monocular/KITTI00-02.yaml [PATH_TO_KITTI]/sequences/00/
```

#### Alternative Python Versions

At the moment, CMakeLists is hard-coded to use python 3.5. If you wish to use a different version, simply change the boost component used (python-35) to the desired version (say, python-27), on line 38 of CMakeLists.txt.
You will also need to change the install location on line 73 of CMakeLists.txt to your desired dist/site packages directory.

## License
This code is licensed under the BSD Simplified license, although it requires and links to ORB_SLAM2, which is available under the GPLv3 license

It uses pyboostcvconverter (https://github.com/Algomorph/pyboostcvconverter) by Gregory Kramida under the MIT licence (see pyboostcvconverter-LICENSE).

