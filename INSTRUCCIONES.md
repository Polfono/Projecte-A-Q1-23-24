# Projecte-A-Q1-23-24

--------------------- INSTRUCCIONES DE EJECUCIÓN ------------------------

------------------------------ REQUISITOS -------------------------------

Esto es un manual para ejecutar el código del proyecto. Este proyecto
ha utilitzado c++ y python como lenguajes de programación. Por ello, es
necesario tener instalada alguna versión de g++ compatible y alguna 
versión de python3. Además se necesitara tener instalado también "make", 
para poder ejecutar dicho comando. Finalmente, si quiere visualizar el
documento de resultados, donde se han creado las gráficas y se han hecho 
los cáculos, será necesario disponer de jupyter notebook o hacerlo 
mediante google collab.

Para instalar todos los requisitos en linux basta con poner el siguiente
comando por consola:

sudo apt install g++, python3, make, jupyter, python3-pip

pip install numpy, matplotlib, pandas

---ALTERNATIVA:

En caso de no querer instalar jupyter, se puede subir el archivo 
"resultats.ipynb" a un google collab y ejecutarlo desde alli:

https://colab.research.google.com

------------------------------- PASO 1 ----------------------------------

Para compilar todo el codigo del proyecto simplemente tiene que escribir 
el comando "make" por consola.

De esta forma se crearan los archivos Tree.o, main.o y main.exe.

------------------------------- PASO 2 ---------------------------------- 

Ejecutar main.exe:

./main.exe

-Introducir el tipo de árbol: 0 - Standar, 1 - Relaxed, 2 - Squarish
-Introducir la dimensión del árbol
-Introducir el número de nodos que tendrá el árbol
-Introducir el número de árboles de n nodos que se crearan
-Introducir el número de consultas a cada árbol

Como resultado nos dará el número medio de nodos visitados.

------------------------------ PASO 3 ------------------------------------

-------- OPCIÓN 1: Usando jupyter notebook 

Ejecuta el siguiente comando:

jupyter notebook 

Una vez se abra el navegador (se recomienda usar Firefox o Chrome) haga
click en el archivo "resultats.ipynb". En esta notebook podrá ver como se 
han generadoa las gráficas y al final de la libreta podrá visualizar como 
se han obtenido los valores de Z para las distintas k y en los distintos 
árboles.

-------- OPCIÓN 2: Usando google collab

Entre el la siguiente web y inicie sesión con algún correo:

https://colab.research.google.com

Seguidamente pulse a "Archivo", después "Subir cuaderno" y finalmente 
busque y suba el archivo "resultats.ipynb".

