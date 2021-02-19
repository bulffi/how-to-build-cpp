# CLion remote docker environment (How to build docker container, run and stop it)
#
# Build and run:
#   docker build -t clion/remote-cpp-env:0.5 -f Dockerfile.remote-cpp-env .
#   docker run -d --cap-add sys_ptrace -p127.0.0.1:2222:22 --name clion_remote_env clion/remote-cpp-env:0.5
#   ssh-keygen -f "$HOME/.ssh/known_hosts" -R "[localhost]:2222"
#
# stop:
#   docker stop clion_remote_env
# 
# ssh credentials (test user):
#   user@password 

FROM ubuntu:18.04

# ===============
# Normal Dependency
# ===============

RUN apt-get update

RUN apt-get install -y ssh build-essential autoconf libtool
RUN apt-get install -y gcc pkg-config curl unzip git
RUN apt-get install -y g++ gdb
RUN apt-get install -y rsync tar python \
        && apt-get clean

# ===============
# vcpkg & cmake
# ===============

ENV cmake_version 3.16.1
ENV vcpkg_root /var/local/git/vcpkg
ENV vcpkg ${vcpkg_root}/vcpkg

RUN git clone https://github.com/microsoft/vcpkg.git ${vcpkg_root}
RUN cd ${vcpkg_root} && ./bootstrap-vcpkg.sh
RUN wget -q -O cmake-linux.sh https://github.com/Kitware/CMake/releases/download/v${cmake_version}/cmake-${cmake_version}-Linux-x86_64.sh
RUN sh cmake-linux.sh -- --skip-license --prefix=/usr
RUN rm cmake-linux.sh

# ===============
# gTest & gRpc & Protobuf
# ===============

RUN ${vcpkg} install gtest
RUN ${vcpkg} install grpc
RUN ${vcpkg} install protobuf


RUN ( \
    echo 'LogLevel DEBUG2'; \
    echo 'PermitRootLogin yes'; \
    echo 'PasswordAuthentication yes'; \
    echo 'Subsystem sftp /usr/lib/openssh/sftp-server'; \
  ) > /etc/ssh/sshd_config_test_clion \
  && mkdir /run/sshd

RUN useradd -m user \
  && yes password | passwd user

CMD ["/usr/sbin/sshd", "-D", "-e", "-f", "/etc/ssh/sshd_config_test_clion"]
