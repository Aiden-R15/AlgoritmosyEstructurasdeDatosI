------Parcial 1 Algoritmos y Estructuras de Datos | Tema B------

--1.a)

data Rodado = Moto | Automovil Auto | Bus Ejes Altura | Camion Ejes Altura Peso deriving (Show)
data Auto = SoloA | ConTrailer Ejes Altura deriving (Show)

type Ejes = Int
type Altura = Float
type Peso = Int

--b)

instance Eq Rodado where
    Moto == Moto = True
    Automovil a == Automovil a2 = autosIguales a a2
    Bus e a == Bus e2 a2 = (e==e2 && a==a2) || (e>e2 && a<a2) || (e<e2 && a>a2)
    Camion e a p == Camion e2 a2 p2 = (e==e2 && a==a2) || (e>e2 && a<a2) || (e<e2 && a>a2) 
    _ == _ = False

autosIguales :: Auto -> Auto -> Bool
autosIguales SoloA SoloA = True
autosIguales (ConTrailer e a) (ConTrailer e2 a2) | (e==e2 && a==a2) || (e>e2 && a<a2) || (e<e2 && a>a2) = True
                                                 | otherwise = False
autosIguales _ _ = False

{-ghci> Moto == Camion 5 7.1 900
False
ghci> Camion 6 5.4 800 == Camion 5 7.1 900
True-}

--c)

autosConTrailer :: [Rodado] -> Altura -> [Rodado]
autosConTrailer [] a = []
autosConTrailer (Automovil (ConTrailer e alt):lr) a | alt > a = (Automovil (ConTrailer e alt)) : autosConTrailer lr a
                                                    | otherwise = autosConTrailer lr a
autosConTrailer (_:lr) a = autosConTrailer lr a 

{-ghci> autosConTrailer [Moto,Automovil (ConTrailer 2 3.5),Camion 6 6 800,Automovil (ConTrailer 3 4.9)] 2
[Automovil (ConTrailer 2 3.5),Automovil (ConTrailer 3 4.9)]
ghci> autosConTrailer [Moto,Bus 3 4.5,Camion 6 6 800,Moto] 5
[]-}

--d) 

dosIguales :: [Rodado] -> Bool
dosIguales [] = False
dosIguales [r] = False
dosIguales (r1:r2:lr) = r1==r2 || dosIguales (r2:lr)

{-ghci> dosIguales [Bus 3 4.5,Camion 6 6 800,Moto]
False
ghci> dosIguales [Moto,Moto,Bus 3 4.5,Camion 6 6 800,Moto]
True-}

--2.a)

data Viaje = Unico | ConEscala Tramo Viaje
data Tramo = DefinicionDelTramo Ciudad Ciudad Distancia

type Ciudad = String
type Distancia = Int

--b)

viajePasaPor :: Viaje -> Ciudad -> Bool
viajePasaPor Unico str = False
viajePasaPor (ConEscala (DefinicionDelTramo c c2 d) v) str = (c == str || c2 == str) || viajePasaPor v str

{-ghci> viajePasaPor (ConEscala (DefinicionDelTramo "Buenos Aires" "Asuncion" 500) (ConEscala (DefinicionDelTramo "Asuncion" "Washington" 2000) Unico)) "Asuncion"
True-}

--d)

instance Eq Tramo where
    (DefinicionDelTramo c1 c2 d) == (DefinicionDelTramo c12 c22 d2) = (c1 == c12 && c2 ==c22) || (c1 == c22 && c2 == c12)

{-ghci> DefinicionDelTramo "Cordoba" "Cancun" 900 == DefinicionDelTramo "Cancun" "Cordoba" 900
True-}
