#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"


class sphere : public hittable {
    public:
        sphere(const point3& center, double radius, shared_ptr<material> mat) : center(center), radius(fmax(0,radius)), mat(mat) {
            // TODO: Initialize the material pointer `mat` .
        }

        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
            
            // The intuition is that the vector from ray origin to center of circle is oc.
            // If we dot oc with itself, it is the same as formula for a sphere at center.
            // We use the quadratic formula to see if at any point t, the ray hits the sphere.

            // a and c are length_squared as they are built using dot product of themselves which is the same as length_squared

            // In this case, we have replaced b with -2h to make the quadratic much simpler
    
            // We use negative sign with discriminant as it gives us the smaller solution t, thus point closer to camera

            vec3 oc = center - r.origin();
            auto a = r.direction().length_squared();
            auto h = dot(r.direction(), oc);
            auto c = oc.length_squared() - radius*radius;

            auto discriminant = h*h - a*c;
            if (discriminant < 0)
                return false;

            auto sqrtd = sqrt(discriminant);

            // Find the nearest root that lies in the acceptable range.
            auto root = (h - sqrtd) / a;
            if (!ray_t.surrounds(root)) {
                root = (h + sqrtd) / a;
                if (!ray_t.surrounds(root))
                    return false;
            }

            rec.t = root;
            rec.p = r.at(rec.t);
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);
            rec.mat = mat;

            return true;
        }

    private: 
        point3 center;
        double radius;
        // I believe its better to have this as shared_ptr as multiple hittables can share a single material
        shared_ptr<material> mat;
};

#endif