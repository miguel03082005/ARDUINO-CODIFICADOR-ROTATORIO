------------ evidencia

entregar el codigo y la documentacion

------------- conceptos basicos

el codificador rotatorio nos ayudara comodispositivo de entrada para ayudara identificar el giro de su eje

genera señalaes y no resistencias

se requieren 30 paso para dar un giro de 360 grados

no tiene un limite de giro

se activa al conectar el eje

los pines a y b son de señal, el c es la conexion alectrica que conectar con el gnd

los pines de a y b no se conectan entre si ni con c y tienen resistencias 

la direccion de giro sera en direccion a las manecillas del reloj (cw) o en sentido contrario (ccw)

a y b tienen una energia alta y or eso se les colocan las resistencias

cuando a y c se conectan, el punto a entra a voltaje baj. cuando a, b y c se conectan, a y b pasan a voltaje bajo lo que indica que c anula e voltaje de a y b

cuando se gira en direccion horaria primero sera a y luego b, en sentido contrario sera b el que sea primero

-------------- conexion

el gnd del adaptador va al gnd del power de arduino y el otro va al power de 5v

el de en medio esta vacio y los otros 2 van conectados a los lectores digitales 2 y 4
