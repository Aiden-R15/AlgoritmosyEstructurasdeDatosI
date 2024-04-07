
------------Punto 1------------

--a)

data Carrera = Matematica | Fisica | Computacion | Astronomia

--b)

titulo :: Carrera -> String
titulo Matematica = "Licenciatura en Matematica"
titulo Fisica = "Licenciatura en Física"
titulo Computacion = "Licenciatura en Ciencias de la Computación"
titulo Astronomia = "Licenciatura en Astronomia"

--c)

data NotaBasica = Do | Re | Mi | Fa | Sol | La | Si
 deriving (Eq, Bounded, Ord, Show) --2a)

--d)

cifradoAmericano :: NotaBasica -> Char
cifradoAmericano Do = 'C'
cifradoAmericano Re = 'D'
cifradoAmericano Mi = 'E'
cifradoAmericano Fa = 'F'
cifradoAmericano Sol = 'G'
cifradoAmericano La = 'A'
cifradoAmericano Si = 'B'

------------Punto 3------------

--a)

minimoElemento :: (Ord a, Show a) => [a] -> a
minimoElemento [x] = x
minimoElemento (x:xs) = min x (minimoElemento xs)

--b)

minimoElemento2 :: (Ord a, Bounded a, Show a) => [a] -> a
minimoElemento2 [] = maxBound
minimoElemento2 (x:xs) = min x (minimoElemento xs)

--c)

{-*Main> minimoElemento [Fa, La, Sol, Re, Fa]
Re-}

------------Punto 4------------

--a)

type Altura = Int
type NumCamiseta = Int

data Zona = Arco | Defensa | Mediocampo | Delantera
data TipoReves = DosManos | UnaMano
data Modalidad = Carretera | Pista | Monte | BMX
data PiernaHabil = Izquierda | Derecha


type ManoHabil = PiernaHabil

data Deportista = Ajedrecista | Ciclista Modalidad | Velocista Altura | Tenista TipoReves ManoHabil Altura
                 | Futbolista Zona NumCamiseta PiernaHabil Altura

--b) Ciclista :: Modalidad -> Deportista

--c)

contarVel :: [Deportista] -> Int
contarVel [] = 0
contarVel ((Velocista a):xs) = 1 + contarVel xs
contarVel (_:xs) = contarVel xs

--d)

contarFutb :: [Deportista] -> Zona -> Int
contarFutb [] z = 0
contarFutb ((Futbolista Arco n p a):xs) Arco = 1 + contarFutb xs Arco
contarFutb ((Futbolista Defensa n p a):xs) Defensa = 1 + contarFutb xs Defensa
contarFutb ((Futbolista Mediocampo n p a):xs) Mediocampo = 1 + contarFutb xs Mediocampo
contarFutb ((Futbolista Delantera n p a):xs) Delantera = 1 + contarFutb xs Delantera
contarFutb (x:xs) z = contarFutb xs z

--e)

esFutb :: Zona -> Deportista -> Bool
esFutb Arco (Futbolista Arco n p a) = True
esFutb Defensa (Futbolista Defensa n p a) = True
esFutb Mediocampo (Futbolista Mediocampo n p a) = True
esFutb Delantera (Futbolista Delantera n p a) = True
esFutb x _ = False

contarFutb2 :: [Deportista] -> Zona -> Int
contarFutb2 xs zona = length (filter (esFutb zona) xs)

------------Punto 5------------

--a)

sonidoNatural :: NotaBasica -> Int
sonidoNatural Do = 0
sonidoNatural Re = 2
sonidoNatural Mi = 4
sonidoNatural Fa = 5
sonidoNatural Sol = 7
sonidoNatural La = 9
sonidoNatural Si = 11

--b)

data Alteracion = Bemol | Natural | Sostenido deriving (Eq, Ord)

--c)

data NotaMusical = Nota NotaBasica Alteracion

--d)

sonidoCromatico :: NotaMusical -> Int
sonidoCromatico (Nota Do Bemol) = 11
sonidoCromatico (Nota Si Sostenido) = 0
sonidoCromatico (Nota n Bemol) = sonidoNatural n - 1
sonidoCromatico (Nota n Sostenido) = sonidoNatural n + 1
sonidoCromatico (Nota n Natural) = sonidoNatural n

--e)

instance Eq NotaMusical where
    Nota n a == Nota n2 a2 = sonidoCromatico (Nota n a) == sonidoCromatico (Nota n2 a2)

--f)

instance Ord NotaMusical where
    Nota n a <= Nota n2 a2 = sonidoCromatico (Nota n a) <= sonidoCromatico (Nota n2 a2)

------------Punto 6------------

--a)

primerElemento :: [a] -> Maybe a
primerElemento [] = Nothing
primerElemento (x:xs) = Just x

------------Punto 7------------

--a)

data Cola = VaciaC | Encolada Deportista Cola

----1)

atender :: Cola -> Maybe Cola
atender VaciaC = Nothing
atender (Encolada d c) = Just c

----2)

encolar :: Deportista -> Cola -> Cola
encolar d VaciaC = Encolada d VaciaC
encolar d (Encolada d2 c) = Encolada d (Encolada d2 c)

----3)

busca :: Cola -> Zona -> Maybe Deportista
busca VaciaC z = Nothing
busca (Encolada (Futbolista Arco n p a) c) Arco = Just (Futbolista Arco n p a)
busca (Encolada (Futbolista Defensa n p a) c) Defensa = Just (Futbolista Defensa n p a)
busca (Encolada (Futbolista Mediocampo n p a) c) Mediocampo = Just (Futbolista Mediocampo n p a)
busca (Encolada (Futbolista Delantera n p a) c) Delantera = Just (Futbolista Delantera n p a)
busca (Encolada d c) z = busca c z

--b) En este caso, el tipo Cola tiene similitud con el tipo lista, especificamente [Deportista]

------------Punto 8------------

data ListaAsoc a b = Vacia | Nodo a b (ListaAsoc a b)

type Diccionario = ListaAsoc String String
type Padron = ListaAsoc Int String

--a)

type GuiaTelefonica = ListaAsoc String [Int]

--b)

----1)

la_long :: ListaAsoc a b -> Int
la_long Vacia = 0
la_long (Nodo a b (list)) = 1 + la_long list

----2)

la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b
la_concat Vacia list = list
la_concat (Nodo a b (lista)) list = (Nodo a b (la_concat list lista))

----3)

la_agregar :: Eq a => ListaAsoc a b -> a -> b -> ListaAsoc a b
la_agregar Vacia a1 b1 = (Nodo a1 b1 Vacia)
la_agregar (Nodo a b l) a1 b1 =
    case a of 
        a | a == a1 -> (Nodo a b1 l)
        _ -> (Nodo a b (la_agregar l a1 b1))

----4)

la_pares :: ListaAsoc a b -> [(a, b)]
la_pares Vacia = []
la_pares (Nodo a b l) = (a, b):la_pares l

----5)

la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b
la_busca Vacia numero = Nothing
la_busca (Nodo a b lista) numero |a == numero = Just b
                                |otherwise = la_busca lista numero 

----6)

la_borrar :: Eq a => a -> ListaAsoc a b -> ListaAsoc a b 
la_borrar clave Vacia = Vacia
la_borrar clave (Nodo b c l)    | b == clave = la_borrar clave l
                                | otherwise = (Nodo b c (la_borrar clave l))

------------Punto 9------------

data Arbol a = Hoja | Rama (Arbol a) a (Arbol a) deriving Show

--a)

a_long :: Arbol a -> Int
a_long Hoja = 0
a_long (Rama a1 a a2) = 1 + a_long a1 + a_long a2

{-*Main> a_long (Rama (Rama (Rama Hoja "c" Hoja) "b" Hoja) "a" (Rama Hoja "b2" (Rama Hoja "c2" Hoja)))
5-}

--b)

a_hojas :: Arbol a -> Int
a_hojas Hoja = 1
a_hojas (Rama a1 a a2) = a_hojas a1 + a_hojas a2

{-*Main> a_hojas (Rama (Rama (Rama Hoja "c" Hoja) "b" Hoja) "a" (Rama Hoja "b2" Hoja))
5-}

--c)

a_inc :: Num a => Arbol a -> Arbol a
a_inc Hoja = Hoja
a_inc (Rama a1 a a2) = (Rama (a_inc a1) (a+1) (a_inc a2))

{-*Main> a_inc (Rama (Rama Hoja 1 Hoja) 0 (Rama Hoja 1 (Rama Hoja 5 Hoja)))
Rama (Rama Hoja 2 Hoja) 1 (Rama Hoja 2 (Rama Hoja 6 Hoja))-}

--d)

a_map :: (a -> b) -> Arbol a -> Arbol b
a_map t Hoja = Hoja
a_map t (Rama a1 a a2) = (Rama (a_map t a1) (t a) (a_map t a2))

{-*Main> a_map (==1) (Rama (Rama Hoja 1 Hoja) 0 (Rama Hoja 1 (Rama Hoja 5 Hoja)))
Rama (Rama Hoja True Hoja) False (Rama Hoja True (Rama Hoja False Hoja))-}

a_incMap :: Num a => Arbol a -> Arbol a
a_incMap (Rama a1 a a2) = a_map (+1) (Rama a1 a a2)

{-*Main> a_incMap (Rama (Rama (Rama Hoja 6 Hoja) 1 (Rama Hoja (-5) Hoja)) 0 (Rama Hoja 1 (Rama Hoja 5 Hoja)))
Rama (Rama (Rama Hoja 7 Hoja) 2 (Rama Hoja (-4) Hoja)) 1 (Rama Hoja 2 (Rama Hoja 6 Hoja))-}

------------Punto 10------------

--a)

data ABB a = VacioABB | RamaABB (ABB a) a (ABB a) deriving Show

--b)

insertarABB :: Ord a => a -> ABB a -> ABB a
insertarABB a VacioABB = (RamaABB VacioABB a VacioABB)
insertarABB a (RamaABB r1 x r2) | a < x = RamaABB (insertarABB a r1) x r2 
                                | a >= x = RamaABB r1 x (insertarABB a r2)

{-*Main> insertarABB 20 (RamaABB (RamaABB VacioABB 5 VacioABB) 10 VacioABB)
RamaABB (RamaABB VacioABB 5 VacioABB) 10 (RamaABB VacioABB 20 VacioABB)-}

--c)

buscarABB :: Eq a => a -> ABB a -> Bool
buscarABB a VacioABB = False
buscarABB a (RamaABB r1 x r2)| a == x = True
                             | otherwise = buscarABB a r1 || buscarABB a r2

--d)

mayor_a_todos :: Ord a => a -> ABB a -> Bool
mayor_a_todos a VacioABB = True
mayor_a_todos a (RamaABB r1 x r2) = a < x && mayor_a_todos a r2

menor_a_todos :: Ord a => a -> ABB a -> Bool
menor_a_todos a VacioABB = True
menor_a_todos a (RamaABB r1 x r2) = a > x && menor_a_todos a r1

verificarABB :: Ord a => ABB a -> Bool
verificarABB VacioABB = True
verificarABB (RamaABB r1 x r2) = menor_a_todos x r1 && mayor_a_todos x r2 && 
                                 verificarABB r1 && verificarABB r2

ejemplo1 = RamaABB (RamaABB VacioABB 10 VacioABB) 2 (RamaABB VacioABB 11 VacioABB)
ejemplo2 = RamaABB (RamaABB (RamaABB VacioABB 1 VacioABB) 3 (RamaABB VacioABB 7 VacioABB)) 5 (RamaABB VacioABB 8 (RamaABB VacioABB 10 VacioABB))