--1) a_

data Video = Pelicula Nombre Director Duracion Año | CapSerie Nombre NroCap Temporada Año deriving Show

type Año = Int
type Nombre = String
type Director = String 
type Duracion = Int
type NroCap = Int
type Temporada = Int 

--b_

odisea2001 :: Video
odisea2001 = Pelicula "2002: Odisea del Espacio" "Stanley Kubrick" 142 1968

theOfficeS02E05 :: Video
theOfficeS02E05 = CapSerie "The Office" 5 2 2005

--c_ 

esDelDirector :: Video -> String -> Bool
esDelDirector (Pelicula n d dur a) dir = dir == d
esDelDirector _ dir = False

--d_

esActual :: Video -> Bool 
esActual (CapSerie n cap t a) = a >= 2020
esActual _ = False

--e_

tiempoPelis :: [Video] -> Int -> Int
tiempoPelis [] año = 0
tiempoPelis ((Pelicula n d dur a):xs) año | a == año = dur + tiempoPelis xs año
                                          | otherwise = tiempoPelis xs año
tiempoPelis (_:xs) año = tiempoPelis xs año

--2)

data ColaVideo = Vacia | Encolada Video ColaVideo deriving Show

elPadrino :: Video
elPadrino = Pelicula "El Padrino" "Francis Coppola" 175 1972

breakingBadS01E01 :: Video
breakingBadS01E01 = CapSerie "Breaking Bad" 1 1 2008


colaReproduccion :: ColaVideo
colaReproduccion = (Encolada elPadrino (Encolada breakingBadS01E01 Vacia))

seriesActuales :: ColaVideo -> ColaVideo
seriesActuales Vacia = Vacia
seriesActuales (Encolada v cr) | esActual v = (Encolada v (seriesActuales cr))
                               | otherwise = seriesActuales cr 