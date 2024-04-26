
output: Raytracer.o Image.o Color.o Vector3D.o Engine.o Ray.o Sphere.o Object3D.o Scene.o
	g++ Raytracer.o Image.o Color.o Vector3D.o Engine.o Ray.o Sphere.o Object3D.o Scene.o -o output

Raytracer.o: Raytracer.cpp
	g++ -c Raytracer.cpp

Image.o: Image.cpp
	g++ -c Image.cpp

Color.o: Color.cpp
	g++ -c Color.cpp

Vector3D.o: Vector3D.cpp
	g++ -c Vector3D.cpp

Engine.o: Engine.cpp
	g++ -c Engine.cpp

Ray.o: Ray.cpp
	g++ -c Ray.cpp

Sphere.o: Sphere.cpp
	g++ -c Sphere.cpp	
	
Object3D.o: Object3D.cpp
	g++ -c Object3D.cpp
	
Scene.o: Scene.cpp
	g++ -c Scene.cpp	


run: output
	./output

clean:
	rm *.o output