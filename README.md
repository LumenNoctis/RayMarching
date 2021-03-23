# RayMarching
There is nowhere to hide


Basic Raymarching done. Displays a sphere and / or cube.

Raymarching is a technique that consists of using mathematical equations called signed dstance functions (or SDFs for short) to draw objects to the screen;
In this implementation, each pxel is given a ray to "march" trhough. At each step, the algorithm calculate the distance to the closest object and step forward in it's vector in a step equal to this distance. Once the distance is small enough or the number of iterations is too high, the algorithm returns;

Lighting is calculated by aproximating the derivatve of the object's SDF at the point where te object was hit by the ray. This gives us the normal. The lighting coefficient is then just a mater of taking the dot product of the light and normal vector and normalizing it.



```
Move with : WASD | Arrow keys
Shrink / Inflate : R, E
```

---

<br>
<img align="top" height="350" width="350" src="Ressources/Img1.png" />

<img height="350" width="350" src="https://cdn.discordapp.com/attachments/432508907701665802/808649638630522890/unknown.png" />

</br>

## TODO

[] -Cone SDF

[] -Capsule SDF

[] -Taurus SDF

[] -Smoothing

[] -Take control of any shape within simulation

[] -Up down and rotation of selected shape

[] -Select and move object with mouse
