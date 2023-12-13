------------Punto 1------------

esCero :: Int -> Bool
esCero n | n == 0 = True
         | otherwise = False

{-*Main> esCero 3
False
*Main> esCero 0
True-}

esPositivo :: Int -> Bool
esPositivo n | n >= 0 = True
             | n < 0 = False

{-*Main> esPositivo 9
True
*Main> esPositivo (-4)
False-}

esVocal :: Char -> Bool
esVocal c = (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u')

{-*Main> esVocal 'a'
True
*Main> esVocal 'c'
False-}

valorAbsoluto :: Int -> Int
valorAbsoluto n | n >= 0 = n
                | otherwise = n*(-1)

{-*Main> valorAbsoluto 8
8
*Main> valorAbsoluto (-3)
3-}

------------Punto 2------------

paratodo :: [Bool] -> Bool
paratodo [] = True
paratodo (x:xs) = x == True && paratodo xs

{-*Main> paratodo [True,False,True]
False
*Main> paratodo [True,True]
True-}

sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs

{-*Main> sumatoria [3,30,5,(-7)]
31
*Main> sumatoria [1,3,4,5]
13-}

productoria :: [Int] -> Int
productoria [] = 1
productoria (x:xs) = x * productoria xs

{-*Main> productoria [3,30,5,(-7)]
-3150
*Main> productoria [2,5,0]
0-}

factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n-1)

{-*Main> factorial 5
120
*Main> factorial 10
3628800-}

promedio :: [Int] -> Int
promedio xs = div (sumatoria xs) (length xs)

{-*Main> promedio [5,10,20]
11
*Main> promedio [5,1,2,3,600]
122-}

------------Punto 3------------

pertenece :: Int -> [Int] -> Bool
pertenece n [] = False
pertenece n (x:xs) = n == x || pertenece n xs

{-*Main> pertenece 5 [5,4,2,1]
True
*Main> pertenece 9 [5,4,2,1]
False-}

------------Punto 4------------

paratodo' :: [a] -> (a -> Bool) -> Bool
paratodo' [] t = True
paratodo' (x:xs) t = t x && paratodo' xs t

{-ghci> paratodo' [7,3,30] (==3)
False
ghci> paratodo' [4,6,20] (even)   
True-}

existe' :: [a] -> (a -> Bool) -> Bool
existe' [] t = False
existe' (x:xs) t = t x || existe' xs t

{-ghci> existe' [1,2,4,6] (<3)
True
ghci> existe' [1,2,4,6] (==2)
True-}

sumatoria' :: [a] -> (a -> Int) -> Int
sumatoria' [] t = 0
sumatoria' (x:xs) t = t x + sumatoria' xs t

{-ghci> sumatoria' [4,3,8] (+1)
18
ghci> sumatoria' [4,3,8] (*34)
510-}

productoria' :: [a] -> (a -> Int) -> Int
productoria' [] t = 1
productoria' (x:xs) t = t x * productoria' xs t

{-ghci> productoria' [6,2] (+2)
32
ghci> productoria' [3,2,1] (+3)
120-}

------------Punto 5------------

paratodo02 :: [a] -> (a -> Bool) -> Bool
paratodo02 xs t = paratodo' xs t

{-ghci> paratodo02 "aaaaaa" esVocal
True
ghci> paratodo02 [5,6,9] (<10)   
True-}

------------Punto 6------------

--a)

todosPares :: [Int] -> Bool
todosPares xs = paratodo' xs even

{-ghci> todosPares [2,2,4]
True
ghci> todosPares [2,5,4]
False-}

--b)

esMult :: Int -> Int -> Bool
esMult n x = mod x n == 0

hayMultiplo :: Int -> [Int] -> Bool
hayMultiplo n xs = existe' xs (esMult n)

{-ghci> hayMultiplo 2 [3,29,37]
False
ghci> hayMultiplo 2 [2,29,37]
True-}

--c)

sumaCuadrados :: Int -> Int
sumaCuadrados n = sumatoria' [0..n] (^2)

--ghci> sumaCuadrados 5
--55
--ghci> sumaCuadrados 2
--5

--d)

esDiv:: Int -> Int -> Bool
esDiv y x = mod y x == 0

existeDivisor :: Int -> [Int] -> Bool
existeDivisor n [] = False
existeDivisor n (x:xs) = existe' (x:xs) (esDiv n)

{-*Main> existeDivisor 50 [5,30,20,10]
True
*Main> existeDivisor 3 [8,6,7,10]
False-}

--e)

esPrimo :: Int -> Bool
esPrimo n = not(existeDivisor n [2..n-1])

{-*Main> esPrimo 5
True
*Main> esPrimo 20
False-}

--f)

factorial02 :: Int -> Int
factorial02 n = productoria' [1..n] id

{-*Main> factorial02 5
120
*Main> factorial02 9
362880-}

--g)

multiplicaPrimos :: [Int] -> Int
multiplicaPrimos xs = productoria (filter esPrimo xs)

--h)

fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib n = fib (n-1) + fib (n-2)

listaFib :: Int -> [Int]
listaFib 0 = []
listaFib 1 = [1]
listaFib n = map fib [0..(n+1)]

esFib :: Int -> Bool
esFib n = existe' (listaFib n) (==n)

{-*Main> esFib 6
False
*Main> esFib 5
True-}

--i)

todosFib :: [Int] -> Bool
todosFib xs = paratodo' xs esFib

{-*Main> todosFib [1,2,3,1,13]
True
*Main> todosFib [1,20,3]
False-}

------------Punto 7------------

{-
i) map es una funcion la cual le aplica un cierto termino a todos los elementose de una lista,
un ejemplo de esto seria:
*Main> map (*2) [1,3,2]
[2,6,4]
filter por otro lado, elimina los elementos de una lista que no cumplen con el termino que le demos, 
un ejemplo:
*Main> filter (<=5)[2,6,5,1,10]
[2,5,1]
ii) La funcion succ dado un un numero, devuelve el siguiente, por lo que seeria lo mismo 
que aplicar (+1) como termino a la funcion map
*Main> map succ [1,3,2]
[2,4,3]
*Main> map (+1) [1,3,2]
[2,4,3]
iii) La funcion esPositivo dice que numeros son mayores o iguales a 0, por lo tanto aplicar filter con 
el termino (>=0) seria equivalente
*Main> filter esPositivo [(-7),3,45,(-2)]
[3,45]
*Main> filter (>=0) [(-7),3,45,(-2)]
[3,45]
-}

------------Punto 8------------

--a)

duplicador :: [Int] -> [Int]
duplicador [] = []
duplicador (x:xs) = x*2 : duplicador xs

{-*Main> duplicador [1,3,0,(-7)]
[2,6,0,-14]
*Main> duplicador [20,5,2]
[40,10,4]-}

--b)

duplicador02 :: [Int] -> [Int]
duplicador02 xs = map (*2) xs

{-*Main> duplicador02 [1,3,0,(-7)]
[2,6,0,-14]
*Main> duplicador02 [20,5,2]
[40,10,4]-}

------------Punto 9------------

--a)

sonPrimos :: [Int] -> [Int]
sonPrimos [] = []
sonPrimos (x:xs) | esPrimo x == True = x : sonPrimos xs
                 | otherwise = sonPrimos xs

{-*Main> sonPrimos [3,5,7,23]
[3,5,7,23]
*Main> sonPrimos [2,3,4]
[2,3]-}

--b)

sonPrimosF :: [Int] -> [Int]
sonPrimosF xs = filter esPrimo xs

{-*Main> sonPrimosF [3,5,7,23]
[3,5,7,23]
*Main> sonPrimosF [2,3,4]
[2,3]-}

--c)

multiplicarPrimos' :: [Int] -> Int
multiplicarPrimos' xs = productoria' (filter esPrimo xs) id

{-*Main> multiplicarPrimos' [6,40,3]
3
*Main> multiplicarPrimos' [1,2,4,5,3]
30-}

------------Punto 10------------

--a)

primIgualesA :: (Eq a) => a -> [a] -> [a]
primIgualesA n [] = []
primIgualesA n (x:xs) | n==x = x : primIgualesA n xs
                      | otherwise = []

{-*Main> primIgualesA 3 [3,3,2,1,3]
[3,3]
*Main> primIgualesA 2 [3,3,2,1,3]
[]-}

--b)

primIgualesA02 :: (Eq a) => a -> [a] -> [a]
primIgualesA02 n xs = takeWhile (==n) xs

{-*Main> primIgualesA02 0 [0,2,0,0,0]
[0]
*Main> primIgualesA02 5 [5,5,4,5,9]
[5,5]-}

------------Punto 11------------

--a)

primIguales :: (Eq a) => [a] -> [a]
primIguales [] = []
primIguales (x:xs) | x == head xs = x : primIguales xs
                   | otherwise = x : []

{-*Main> primIguales [5,5,4,5,9]
[5,5]
*Main> primIguales [2,4,2,2,2]
[2]-}

--b)

primIguales02 :: (Eq a) => [a] -> [a]
primIguales02 (x:xs) = primIgualesA x (x:xs)

{-*Main> primIguales02 [2,4,2,2,2]
[2]
*Main> primIguales02 [5,5,4,5,9]
[5,5]-}

------------Punto 12------------


cuantGen :: (b -> b -> b) -> b -> [a] -> (a -> b) -> b
cuantGen op z [] t = z
cuantGen op z (x:xs) t = op (t x) (cuantGen op z xs t)

{-*Main> cuantGen (*) 1 [7,5,3] (mod 2)
8
*Main> cuantGen (*) 1 [7,5,3] (mod 2)
8-}

paraTodoCuan :: [a] -> (a -> Bool) -> Bool
paraTodoCuan xs t = cuantGen (&&) True xs t

{-*Main> paraTodoCuan [2,2,2,2] (==2)
True
*Main> paraTodoCuan [3,2,1,0,5] (>=3)
False-}

existeCuan :: [a] -> (a -> Bool) -> Bool
existeCuan xs t = cuantGen (||) False xs t

{-*Main> existeCuan [True,False,True] id
True
*Main> existeCuan [7,2,1] (<0)
False-}

sumatoriaCuan :: [a] -> (a -> Int) -> Int
sumatoriaCuan xs t = cuantGen (+) 0 xs t

{-*Main> sumatoriaCuan [3,3,21] id
27
*Main> sumatoriaCuan [1,2,3] (*2)
12-}

productoriaCuan :: [a] -> (a -> Int) -> Int
productoriaCuan xs t = cuantGen (*) 1 xs t

{-*Main> productoriaCuan [2,3,(-5)] id
-30
*Main> productoriaCuan [2,3,(-5)] (+(-10))
-840-}

------------Punto 13------------

distanciaEdicion :: [Char] -> [Char] -> Int
distanciaEdicion st [] = length st
distanciaEdicion [] st2 = length st2
distanciaEdicion (c:st) (c2:st2) | c == c2 = distanciaEdicion st st2
                                 | otherwise = 1 + distanciaEdicion st st2

{-*Main> distanciaEdicion "esquina" "escuadra"
5
*Main> distanciaEdicion "cancion" ""
7-}

------------Punto 14------------

primQueCumplen :: [a] -> (a->Bool) -> [a]
primQueCumplen [] t = []
primQueCumplen (x:xs) t | t x == True = x : primQueCumplen xs t
                        | otherwise = []

{-*Main> primQueCumplen "aaabac" (=='a')
"aaa"
*Main> primQueCumplen [2,4,2,3,5] esFib
[2]-}

------------Punto 15------------
------------Punto 16------------

