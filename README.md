# Ray-Tracer
A ray tracing renderer to create 3D environments with different geometries and materials. The output is in PPM format. Everything is implemented from scratch, down to the most simple equation. Its a work in progress and documents my journey learning how ray tracers work. Special thanks to https://raytracing.github.io as this book goes over the math and code to help implement it.

## Configure Environment
- Create and configure materials you want to apply to your geometries (lambertian, metal, dielectric).
- Create and configure geometries with their materials (Only sphere for now)
- Create a hittable_list instance and add all geometries to it so its easy to render
- Create and configure a camera which has many options like: aspect ratio, image dimensions, antialiasing samples, depth, field of view, camera orientation, defocus angle and distance

## Running instructions
- Clone the repo
- Configure and complie main.cpp
- Run the executable and redirect it to a PPM file (example: .\main > image.ppm)

## Progress
- Started by rendering a background that blends blue and white using the Y coordinate of the ray through Linear Interpolation
- Created a sphere by checking if rays were hitting the volume occupied by it based on its center and radius
- Colored the sphere based on the normal vector from its center to the point of intersection (Surface Normal)
![alt text](https://github.com/Terakonta/Ray-Tracer/blob/main/ray%20tracer/png/initialRender.png)
