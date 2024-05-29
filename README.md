# onnx-juce-example

Minimal project that demonstrates loading an onnx model into C++ and accessing it in a JUCE application. 

You need the onnxrunmtime. Download a build from here: 

https://github.com/microsoft/onnxruntime/releases/

Then edit CMakeLists.txt to reflect the location of the include and lib folders of your build, e.g. if you have it in the current folder:

```
include_directories(./onnxruntime-linux-x64-1.18.0/include/)
link_directories(./onnxruntime-linux-x64-1.18.0/lib/)
```

Then you need to download JUCE, or if you already have it, edit CMakeLists.txt to reflect where it is. To download:

```
git clone git@github.com:juce-framework/JUCE.git
```

To edit CMakeLists.txt, find this line and change the first JUCE path to where your JUCE folder is:

```
add_subdirectory(./JUCE ./JUCE)
```

Finally, you might want to edit the constructor of the plugin so it can find the onnx model. Find this line and edit it to point at an onnx file on your system: 

```
std::string modelFile = "../../../../models/big-model.onnx";
```

Then you can build the project:

```
cmake -B build .
cmake --build build --config Debug
```

