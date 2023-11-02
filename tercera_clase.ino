// creamos las variables correspondientes a los pines a y b donde les asignamos el valor del lector digital del que recibiran la informacion
int a = 2;
int b = 4;

// aqui guardaremos el ultimo valor que tuvo la variable position
int back = 50;

//creamos la variable con el modificador volatile  que la hace global que utilizaremos dentro de las funciones 
volatile int position = 50;

void setup() {

  //inicializamos a y b como entradas 
  pinMode (a, INPUT);
  pinMode (b, INPUT);

  //inicializamos la comunicacion en serie con un valor de 9600
  Serial.begin(9600);

  //iniciamos la interrupcion en a con la funcion encoder que la enviara a low evitando que tenga voltaje
  attachInterrupt (digitalPinToInterrupt (a), encoder, LOW);

  // un mensaje para indicar que se ha logrado el proceso
  Serial.println ("holiii");

}

void loop() {

  //creamos un condicional if que evaluara  si el valor de posicion es diferente al valor de back
  if (position != back) {

    // al cumplirse la condicion se imprimira position y back tomara como nuevo valor el valor de position
    Serial.println(position);
    back = position;

  }

}

// creamos la funcion encoder que nos permitira hacer todo este proceso
void encoder() {

  /*creamos las variables para manejar los rebotes donde unsigned long indica que la variable ouede usar los 32 bits del long, 
  millis calcula el tiempo en mls desde el inicio del programa  y estatic indica que la variable tiene que mantener su valor entre cada llamado*/
  static unsigned long ultima_interrupcion = 0;
  unsigned long tiempo_interrupcion = millis();

  //creamos un if para que el contador no tenga en cuenta los rebotes y evaluamos si la diferencia entre las interrupciones es mayor a 5mls
  if (tiempo_interrupcion - ultima_interrupcion > 5) {

    //creamos un condicional if donde se evaluara si b tiene voltaje 
  if (digitalRead(b) == HIGH) {

    //si la condicion se cumple se le sumara 1 al valor de position
    position ++ ;

  } else {

    //si la condicion no se cumple se le restara 1 al valo de position
    position -- ;
  }

  //le damos un valor minimo y maximo a la funcion para que tenga un tope y no pase de 100 y 0
  position = min (100, max (0, position));

// actualisamos el valor de ultima interrupcion para que al restarlo con el tiempo de la interrupcion para poder calcular
  ultima_interrupcion = tiempo_interrupcion;

  }

}
