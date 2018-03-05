# install GCC
sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
sudo apt-get update -qq
sudo apt-get install -qq g++-7
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-7 90
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-7 90
sudo update-alternatives --install /usr/bin/cpp cpp /usr/bin/cpp-7 90
