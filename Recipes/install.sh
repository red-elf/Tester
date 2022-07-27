#!/bin/bash

echo "Installing the 'Tester' micro-framework, please wait" && \
  cd Library && \
  rm -rf ./Build && \
  mkdir Build && \
  cd Build && \
  cmake .. && \
  make && \
  sudo make install && \
  echo "The 'Tester' micro-framework has been installed with success"
