#ifndef ORBSLAMPYTHON_H
#define ORBSLAMPYTHON_H

#include <memory>
#include <Python.h>
#include <boost/python.hpp>
#include <ORB_SLAM3/System.h>
#include <ORB_SLAM3/Tracking.h>

class ORBSlamPython
{
public:
    ORBSlamPython(std::string vocabFile, std::string settingsFile,
        ORB_SLAM3::System::eSensor sensorMode = ORB_SLAM3::System::eSensor::RGBD);
    ORBSlamPython(const char* vocabFile, const char* settingsFile,
        ORB_SLAM3::System::eSensor sensorMode = ORB_SLAM3::System::eSensor::RGBD);
    ~ORBSlamPython();
    
    bool initialize();
    bool isRunning();
    bool loadAndProcessMono(std::string imageFile, double timestamp);
    boost::python::list processMono(cv::Mat image, double timestamp);
    bool loadAndProcessStereo(std::string leftImageFile, std::string rightImageFile, double timestamp);
    bool processStereo(cv::Mat leftImage, cv::Mat rightImage, double timestamp);
    bool loadAndProcessRGBD(std::string imageFile, std::string depthImageFile, double timestamp);
    boost::python::list processRGBD(cv::Mat image, cv::Mat depthImage, boost::python::list imuMeas, double timestamp);
    void reset();
    void shutdown();
    ORB_SLAM3::Tracking::eTrackingState getTrackingState() const;
    unsigned int getNumFeatures() const;
    unsigned int getNumMatches() const;
    boost::python::list getKeyframePoints() const;
    boost::python::list getTrajectoryPoints() const;
    boost::python::list getTrackedMappoints() const;
    bool saveSettings(boost::python::dict settings) const;
    boost::python::dict loadSettings() const;
    void setMode(ORB_SLAM3::System::eSensor mode);
    void setRGBMode(bool rgb);
    void setUseViewer(bool useViewer);
    
    static bool saveSettingsFile(boost::python::dict settings, std::string settingsFilename);
    static boost::python::dict loadSettingsFile(std::string settingsFilename);

    void SaveMap(std::string filename);
    bool LoadMap(std::string filename);
    
private:
    std::string vocabluaryFile;
    std::string settingsFile;
    ORB_SLAM3::System::eSensor sensorMode;
    std::shared_ptr<ORB_SLAM3::System> system;
    bool bUseViewer;
    bool bUseRGB;
};



#endif // ORBSLAMPYTHON_H
