# Ray-Tracing
A ray tracing program written in c++
Optical ray tracing describes a method of producing visual images constructed in 3D graphics environments. It works by drawing a path with an imaginary eye through each pixel in a virtual screen, and calculating the color of the object visible through it. The scenes in ray tracing are described mathematically.
Each ray should be tested for intersection with a subset of all objects in the scene. Once the closest object is identified, the algorithm estimates the incoming light at the point of intersection, examines the object's material properties, and combines this information to calculate the final pixel color. 

![image](https://user-images.githubusercontent.com/68228290/140061548-c3d2253e-de68-4947-8b03-0d4745679eb4.png)

The intersection of the rays with is calculated using mathematical formulas depending on the shape and properties of the object.
## Intersection with spheres
A sphere is defined by a center c and a radius r.
In vector notation, the equation of a sphere is:

$$\large{\color{green} || x-c ||^2=r^2}$$

Any point on a radius starting from point s and a unit directing vector d can be written as:

$$\large{\color{green}x = s + t.d}$$

Where t is its distance between s and x

In our problem, we want to determine the intersection point x between a radius and a sphere. We replace x in the equation of the sphere, we get:

$$\large{\color{green}\|S + t.d-c\|^2 = r^2}$$

We consider  $\color{green}v = s-c$  to simplify:

$$\large{\color{green}\|V + td\|^2 = r^2}$$

$$\large{\color{green}v^2 + t^2d^2 + 2tdv = r^2}$$

Since d is a unit vector we simplify the expression in order to determine t.

$$\large{\color{green}t^2 + (2vd)t + v^2-r^2 = 0}$$

This equation has for solutions:

$$\large{\color{green}t = -vd \pm \sqrt{(vd)^2-4(v^2-r^2)}}$$

If the quantity under the square root (the discriminant) is negative, then the radius does not intersect the sphere.

The two values of t found by solving this equation are the points where the radius intersects the sphere. If t is positive, we take the smallest value of t.

In order to calculate the reflected radius of a reflecting sphere, we determine the normal of a sphere:

$$\large{\color{green}n = \frac{x-c}{\|x-c\|}}$$

Where x is the point of intersection found before. The direction of reflection can be found by a reflection of d with respect to n, that is

$$\large{\color{green}r = d-2(nd)n}$$

Thus, the reflected ray has the equation:

$$\large{\color{green}y = x + tr}$$


## Intersection with plans

A plane is defined by two vectors which do not have the same direction and a point. (In the case of quadrilateral we take the two vectors width and height and the center c)
We define the normal n to the plane by the vector product of the two vectors contained in the plane
Any point on a radius starting from point s and a unit directing vector d can be written as:

$$\large{\color{green}x = s + td}$$

Where t is its distance between s and x
The vector  $\color{green}x-c$  is perpendicular to the normal vector n:

$$\large{\color{green}(x-c)n = 0}$$

We replace x in the expression we get:

$$\large{\color{green}(s-c + td)n = 0}$$

$$\large{\color{green}t = \frac{(c-s)n}{(dn)}}$$

We then check if the point x belongs to the quadrilateral contained in the plane by projecting it according to the unit director vector of the quadrilateral of width and height and by comparing if it is less than the dimensions of the rectangle.

## UML Diagram

![image](https://user-images.githubusercontent.com/68228290/140061384-8a77fe50-3753-4a45-9e49-803e0252c281.png)

## Results

![image](https://user-images.githubusercontent.com/68228290/140061732-324196d6-176c-4b0f-9ef6-ac4886494a9d.png)
