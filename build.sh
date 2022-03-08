#!/usr/bin/bash
Program_files="Main.cpp Includes/Dijkstra.cpp Includes/Node.cpp Includes/Render.cpp Includes/Graph.cpp Includes/ShaderClass.cpp Includes/VAO.cpp Includes/VBO.cpp Includes/EBO.cpp glad.c"
c_flags="-ldl -lglfw"
echo 'Program Compiling...' ; time g++ ${files} ${c_flags} && echo -e '----------\nRunning...'; ./main
