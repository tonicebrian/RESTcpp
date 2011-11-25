debug: dist/Debug/Makefile
	cd dist/Debug; cmake -DCMAKE_BUILD_TYPE=Debug ../..; make

release: dist/Release/Makefile
	cd dist/Release; cmake -DCMAKE_BUILD_TYPE=Release ../..; make

dist/Debug/Makefile: CMakeLists.txt
	mkdir -p dist/Debug

dist/Release/Makefile: CMakeLists.txt
	mkdir -p dist/Release

clean:
	rm -rf dist
