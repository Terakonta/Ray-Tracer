# Ray-Tracer
A ray tracing renderer to create 3D environments with different geometries and materials. The output is in PPM format. 

# Setup
- Clone the repo
- Configure and complie main.cpp
- Run the executable and redirect it to a PPM file (example: .\main > image.ppm)

## Configure Environment
- Create and configure materials you want to apply to your geometries (lambertian, metal, dielectric).
- Create and configure geometries with their materials (Only sphere for now).
- Create a hittable_list instance and add all geometries to it so its easy to render.
- Create and configure a camera which has many options like: aspect ratio, image dimensions, antialiasing samples, depth, field of view, camera orientation, defocus angle and distance.
