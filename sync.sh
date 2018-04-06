#!/bin/bash

# Temporary script for synchronizing repos

rsync -av ../envoy-api/envoy ./api/
rsync -av ../envoy-api/bazel ./api/
rsync -av ../envoy-api/VERSION ./
rsync -av ../envoy-api/BUILD ./
#(cd api; 
# replace "\"//envoy/" "\"//api/envoy/";
# replace "//bazel:api_build_system.bzl" "//api/bazel:api_build_system.bzl";
# replace "@envoy_api//api" "//api")
#sed -i "s#load(\"//api#load(\"@envoy//api#" api/bazel/repositories.bzl

