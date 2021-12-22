FROM ros:foxy

# install ros package and gazebo
RUN apt-get update && apt-get install -y \
      gazebo11 \
      ros-${ROS_DISTRO}-demo-nodes-cpp \
      ros-${ROS_DISTRO}-demo-nodes-py \
      ros-$(rosversion -d)-turtlesim && \
    rm -rf /var/lib/apt/lists/*

RUN apt-get update && apt-get install -y \
      wget software-properties-common && \
      wget -qO - https://stslaptstorage.z13.web.core.windows.net/pubkey.txt | sudo apt-key add - && \
      apt-add-repository "deb https://stslaptstorage.z13.web.core.windows.net/ focal main" && \
      apt-get update && apt install -y ros-foxy-teleop-twist-keyboard ros-foxy-stsl-desktop ros-foxy-rviz2 ros-foxy-rqt ros-foxy-rqt-common-plugins && \
    rm -rf /var/lib/apt/lists/*
# launch ros package
#CMD ["ros2", "launch", "demo_nodes_cpp", "talker_listener.launch.py"]
