# onnx-juce-example

Minimal project that demonstrates loading an onnx model into C++ and accessing it in a JUCE application. 

You need the onnxrunmtime. Download a build from here: 

https://github.com/microsoft/onnxruntime/releases/

Then edit CMakeLists.txt to reflect the location of the include and lib folders of your build, e.g. if you have it in the current folder:

```
include_directories(./onnxruntime-linux-x64-1.18.0/include/)
link_directories(./onnxruntime-linux-x64-1.18.0/lib/)
```

Then you can build the project:

```
cmake -B build .
cmake --build build --config Debug
```

