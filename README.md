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
- Colored the sphere based on the normal vector from its center to the point of intersection (Surface Normal). Also added another, larger sphere below to act as ground
![Initial render](https://github.com/Terakonta/Ray-Tracer/blob/main/ray%20tracer/png/initialRender.png)
- Implemented Anti-Aliasing by sampling the square region around the pixel
![Anti-Aliasing](https://github.com/Terakonta/Ray-Tracer/blob/main/ray%20tracer/png/antialiasing.png)
- Created a simple diffuse material and applied it to both the sphere so rays bounce off of geometries in random direction. Currently, 50% of the color is absorbed by the spheres at each bounce, making them appear gray.
![Simple diffuse](https://github.com/Terakonta/Ray-Tracer/blob/main/ray%20tracer/png/gray.png)
- Limit the number of times rays bounce off of objects to save computation. Not much difference in quality of render
![Limited bounce](https://github.com/Terakonta/Ray-Tracer/blob/main/ray%20tracer/png/grayWithReflectionLimit.png)
- Some intersections had floating point rounding errors which would cause origin of bouncing ray to be slightly off. Added a slight increment to make sure it doesnt hit the same surface again causing self-shadowing or Shadow Acne. I believe this is called Shadow Biasing using Normal Offset to be specific but I may be wrong.
![Shadow acne](https://github.com/Terakonta/Ray-Tracer/blob/main/ray%20tracer/png/fixShadowAcne.png)
- Changed the simple diffuse material to follow the Lambertain distribution. While the simpler model scattered the ray in random direction, this is more likely to reflect ray in a direction nea the surface normal. It seems to look more realistic as the shadow is better and the spheres have a slight blue tint from the sky.
![Lambertian spheres](https://github.com/Terakonta/Ray-Tracer/blob/main/ray%20tracer/png/lambertianDistance.png)
- Images with data that are written without being transformed are said to be in linear space, whereas images that are transformed are said to be in gamma space. The image viewer might be expecting "hamma corrected" images as the image is way too dark eventhough only 50% of the color was absorbed at each bounce. Used "gamma 2" to go from linear to gamma space by taking square root of RGB values.
![Gamma correction](https://github.com/Terakonta/Ray-Tracer/blob/main/ray%20tracer/png/gammaCorrection.png)
- Created a new material to look like metal. Using the ray vector and the surface normal, created a new direction vector to reflect off of the surface rather than scatter randomly.
![Metal material](https://github.com/Terakonta/Ray-Tracer/blob/main/ray%20tracer/png/metalAndLambertianWorld.png)
- Added a feature to make reflection a bit fuzzy by creating a small sphere around the original end point and offsetting to a random point on the surface of the sphere. Bigger sphere, fuzzier reflection.
![Fuzzy reflection](https://github.com/Terakonta/Ray-Tracer/blob/main/ray%20tracer/png/fuzzyReflection.png)
- Introduced dielectric material to create clear spheres by randomly either reflecting or refracting ray per interaction. Refracted ray bends based on material's refractive index. When transparent material embedded inside another, we calculate relative refraction index: the refractive index of the object's material divided by the refractive index of the surrounding material. Used the Snell's Law for ray refraction using the refractive indices and angles from surface normal.
![Initial refraction](https://github.com/Terakonta/Ray-Tracer/blob/main/ray%20tracer/png/initialRefraction.png)
