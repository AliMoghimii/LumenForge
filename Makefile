
output: Raytracer.o Image.o Color.o Vector3D.o
	g++ Raytracer.o Image.o Color.o Vector3D.o -o output

Raytracer.o: Raytracer.cpp
	g++ -c Raytracer.cpp

Image.o: Image.cpp
	g++ -c Image.cpp

Color.o: Color.cpp
	g++ -c Color.cpp

Vector3D.o: Vector3D.cpp
	g++ -c Vector3D.cpp

run: output
	./output

clean:
	rm *.o output