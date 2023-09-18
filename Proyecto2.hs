
---------Ejercicio 1---------

data Carrera = Matematica | Fisica | Computacion | Astronomia

titulo :: Carrera -> String
titulo Matematica = "Licenciatura en Matematica"
titulo Fisica = "Licenciatura en Física"
titulo Computacion = "Licenciatura en Ciencias de la Computación"
titulo Astronomia = "Licenciatura en Astronomia"

data NotaBasica = Do | Re | Mi | Fa | Sol | La | Si
 deriving (Eq, Bounded, Ord, Show)

cifradoAmericano :: NotaBasica -> Char
cifradoAmericano Do = 'C'
cifradoAmericano Re = 'D'
cifradoAmericano Mi = 'E'
cifradoAmericano Fa = 'F'
cifradoAmericano Sol = 'G'
cifradoAmericano La = 'A'
cifradoAmericano Si = 'B'

---------Ejercicio 3---------

minimoElemento :: (Ord a, Show a) => [a] -> a
minimoElemento [x] = x
minimoElemento (x:xs) = min x (minimoElemento xs)

minimoElemento2 :: (Ord a, Bounded a, Show a) => [a] -> a
minimoElemento2 [] = maxBound
minimoElemento2 (x:xs) = min x (minimoElemento xs)

---------Ejercicio 4---------

type Altura = Int
type NumCamiseta = Int

data Zona = Arco | Defensa | Mediocampo | Delantera
data TipoReves = DosManos | UnaMano
data Modalidad = Carretera | Pista | Monte | BMX
data PiernaHabil = Izquierda | Derecha


type ManoHabil = PiernaHabil

data Deportista = Ajedrecista | Ciclista Modalidad | Velocista Altura | Tenista TipoReves ManoHabil Altura
                 | Futbolista Zona NumCamiseta PiernaHabil Altura

contarVel :: [Deportista] -> Int
contarVel [] = 0
contarVel ((Velocista a):xs) = 1 + contarVel xs
contarVel (_:xs) = contarVel xs

contarFutb :: [Deportista] -> Zona -> Int
contarFutb [] z = 0
contarFutb ((Futbolista Arco n p a):xs) Arco = 1 + contarFutb xs Arco
contarFutb ((Futbolista Defensa n p a):xs) Defensa = 1 + contarFutb xs Defensa
contarFutb ((Futbolista Mediocampo n p a):xs) Mediocampo = 1 + contarFutb xs Mediocampo
contarFutb ((Futbolista Delantera n p a):xs) Delantera = 1 + contarFutb xs Delantera
contarFutb (x:xs) z = contarFutb xs z

esFutb :: Zona -> Deportista -> Bool
esFutb Arco (Futbolista Arco n p a) = True
esFutb Defensa (Futbolista Defensa n p a) = True
esFutb Mediocampo (Futbolista Mediocampo n p a) = True
esFutb Delantera (Futbolista Delantera n p a) = True
esFutb x _ = False

contarFutb2 :: [Deportista] -> Zona -> Int
contarFutb2 xs zona = length (filter (esFutb zona) xs)

---------Ejercicio 5---------

sonidoNatural :: NotaBasica -> Int
sonidoNatural Do = 0
sonidoNatural Re = 2
sonidoNatural Mi = 4
sonidoNatural Fa = 5
sonidoNatural Sol = 7
sonidoNatural La = 9
sonidoNatural Si = 11

data Alteracion = Bemol | Natural | Sostenido deriving (Eq, Ord)
data NotaMusical = Nota NotaBasica Alteracion

sonidoCromatico :: NotaMusical -> Int
sonidoCromatico (Nota Do Bemol) = 11
sonidoCromatico (Nota Si Sostenido) = 0
sonidoCromatico (Nota n Bemol) = sonidoNatural n - 1
sonidoCromatico (Nota n Sostenido) = sonidoNatural n + 1
sonidoCromatico (Nota n Natural) = sonidoNatural n

instance Eq NotaMusical where
    Nota n a == Nota n2 a2 = sonidoCromatico (Nota n a) == sonidoCromatico (Nota n2 a2)

instance Ord NotaMusical where
    Nota n a <= Nota n2 a2 = sonidoCromatico (Nota n a) <= sonidoCromatico (Nota n2 a2)

---------Ejercicio 6---------

primerElemento :: [a] -> Maybe a
primerElemento [] = Nothing
primerElemento (x:xs) = Just x

---------Ejercicio 7---------

--a)

data Cola = VaciaC | Encolada Deportista Cola

atender :: Cola -> Maybe Cola
atender VaciaC = Nothing
atender (Encolada d c) = Just c

encolar :: Deportista -> Cola -> Cola
encolar d VaciaC = Encolada d VaciaC
encolar d (Encolada d2 c) = Encolada d (Encolada d2 c)

busca :: Cola -> Zona -> Maybe Deportista
busca VaciaC z = Nothing
busca (Encolada (Futbolista Arco n p a) c) Arco = Just (Futbolista Arco n p a)
busca (Encolada (Futbolista Defensa n p a) c) Defensa = Just (Futbolista Defensa n p a)
busca (Encolada (Futbolista Mediocampo n p a) c) Mediocampo = Just (Futbolista Mediocampo n p a)
busca (Encolada (Futbolista Delantera n p a) c) Delantera = Just (Futbolista Delantera n p a)
busca (Encolada d c) z = busca c z

--b) En este caso, el tipo Cola tiene similitud con el tipo lista, especificamente [Deportista]

---------Ejercicio 8---------

data ListaAsoc a b = Vacia | Nodo a b (ListaAsoc a b)

type Diccionario = ListaAsoc String String
type Padron = ListaAsoc Int String

la_long :: ListaAsoc a b -> Int
la_long Vacia = 0
la_long (Nodo a b (list)) = 1 + la_long list

la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b
la_concat Vacia list = list
la_concat (Nodo a b (lista)) list = (Nodo a b (la_concat list lista))

la_agregar :: Eq a => ListaAsoc a b -> a -> b -> ListaAsoc a b
la_agregar Vacia a1 b1 = (Nodo a1 b1 Vacia)
la_agregar (Nodo a b l) a1 b1 =
    case a of 
        a | a == a1 -> (Nodo a b1 l)
        _ -> (Nodo a b (la_agregar l a1 b1))

la_pares :: ListaAsoc a b -> [(a, b)]
la_pares Vacia = []
la_pares (Nodo a b l) = (a, b):la_pares l

la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b
la_busca Vacia numero = Nothing
la_busca (Nodo a b lista) numero |a == numero = Just b
                                |otherwise = la_busca lista numero 

la_borrar :: Eq a => a -> ListaAsoc a b -> ListaAsoc a b 
la_borrar clave Vacia = Vacia
la_borrar clave (Nodo b c l)    | b == clave = la_borrar clave l
                                | otherwise = (Nodo b c (la_borrar clave l))

