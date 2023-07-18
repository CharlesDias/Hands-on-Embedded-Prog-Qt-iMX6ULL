# Hands-On Embedded Programming with Qt and i.MX6ULL

This repository stores some Qt application examples covered in the book [Hands-On Embedded Programming with Qt](https://www.packtpub.com/product/hands-on-embedded-programming-with-qt/9781789952063) and necessary modifications to run on an i.MX6ULL processor.

## Debugging on the Target

Select the **Projects** option on left side. Choose the **Run** and on **Environment**, set the following values to select the correct display when the application launches:

| Variable name | Variable value |
|---------------|----------------|
| DISPLAY       | :0.0           |

In similar way, set the following values for the new Wayland environment to avoid remote launching errors:

| Variable name   | Variable value    |
|-----------------|-------------------|
| WAYLAND_DISPLAY | /run/wayland-0    |
| QT_QPA_PLATFORM | wayland-egl       |
| XDG_RUNTIME_DIR | /tmp/runtime-root |