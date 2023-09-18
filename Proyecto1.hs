--Archivo del Proyecto 1 para Algoritmos y Estructura de Datos 1

--Punto 1

esCero :: Int -> Bool
esCero x = x==0

--ghci> esCero 0
--True
--ghci> esCero 45 
--False

esPositivo :: Int -> Bool
esPositivo x = x>0

--ghci> esPositivo 23
--True
--ghci> esPositivo (-2) 
--False

esVocal :: Char -> Bool
esVocal x = x=='a' || x=='e' || x=='i' || x=='o' || x=='u'

--ghci> esVocal 'c'
--False
--ghci> esVocal 'e'
--True

valorAbsoluto :: Int -> Int
valorAbsoluto x | x>=0 = x
                | x<0 = x*(-1)

--ghci> valorAbsoluto (-7)
--7
--ghci> valorAbsoluto (4) 
--4

--Punto 2
paratodo :: [Bool] -> Bool
paratodo [] = True
paratodo (x:xs) = x==True && paratodo xs

--ghci> paratodo [False,False,True]
--False
--ghci> paratodo [True]            
--True

sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs

--ghci> sumatoria [5,5,2]
--12
--ghci> sumatoria [5,-7,34]
--32

productoria :: [Int] -> Int
productoria [] = 1
productoria (x:xs) = x * productoria xs

-- ghci> productoria [6,5,2]
-- 60
-- ghci> productoria [-6,2]  
-- -12

factorial :: Int -> Int
factorial 0 = 1
factorial x = x * factorial (x-1)

--ghci> factorial 6
--720
--ghci> factorial 2
--2

promedio :: [Int] -> Int
promedio [] = 0
promedio (x:xs) = div (sumatoria (x:xs)) (length (x:xs))

-- ghci> promedio [32,5,3]
-- 13
-- ghci> promedio [-32,5,4,3]
-- -5

--Punto 3
pertenece :: Int -> [Int] -> Bool
pertenece y [] = False
pertenece y (x:xs) = y==x || pertenece y xs

--ghci> pertenece 5 [3,4,6]
--False
--ghci> pertenece 10 [5,10,10]
--True

--Punto 4
paratodo' :: [a] -> (a -> Bool) -> Bool
paratodo' [] t = True
paratodo' (x:xs) t = t x && paratodo' xs t

--ghci> paratodo' [7,3,30] (==3)
--False
--ghci> paratodo' [4,6,20] (even)   
--True

existe' :: [a] -> (a -> Bool) -> Bool
existe' [] t = False
existe' (x:xs) t = t x || existe' xs t

--ghci> existe' [1,2,4,6] (<3)
--True
--ghci> existe' [1,2,4,6] (==2)
--True

sumatoria' :: [a] -> (a -> Int) -> Int
sumatoria' [] t = 0
sumatoria' (x:xs) t = t x + sumatoria' xs t

--ghci> sumatoria' [4,3,8] (+1)
--18
--ghci> sumatoria' [4,3,8] (*34)
--510

productoria' :: [a] -> (a -> Int) -> Int
productoria' [] t = 1
productoria' (x:xs) t = t x * productoria' xs t

--ghci> productoria' [6,2] (+2)
--32
--ghci> productoria' [3,2,1] (+3)
--120

--Punto 5

paratodo02 :: [a] -> (a -> Bool) -> Bool
paratodo02 xs t = paratodo' xs t

--ghci> paratodo02 "aaaaaa" esVocal
--True
--ghci> paratodo02 [5,6,9] (<10)   
--True

--Punto 6

todosPares :: [Int] -> Bool
todosPares xs = paratodo' xs even

--ghci> todosPares [2,2,4]
--True
--ghci> todosPares [2,5,4]
--False

esMult :: Int -> Int -> Bool
esMult n x = mod x n == 0

hayMultiplo :: Int -> [Int] -> Bool
hayMultiplo n xs = existe' xs (esMult n)

--ghci> hayMultiplo 2 [3,29,37]
--False
--ghci> hayMultiplo 2 [2,29,37]
--True

sumaCuadrados :: Int -> Int
sumaCuadrados n = sumatoria' [0..n] (^2)

--ghci> sumaCuadrados 5
--55
--ghci> sumaCuadrados 2
--5

existeDivisor :: Int -> [Int] -> Bool
existeDivisor n ls = existe' ls (esMult n)


esPrimo :: Int -> Bool
esPrimo n = not(existe' [2..n-1] (esMult n)) || n == 2

factorial02 :: Int -> Int
factorial02 n = productoria' [1..n] id

multiplicaPrimos :: [Int] -> Int
multiplicaPrimos xs = productoria (filter esPrimo xs)

esFib :: Int -> Bool
esFib n = pertenece n (map fib [0..(n+1)])

fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib n = (fib n-1) + (fib n-2)

todosFib :: [Int] -> Bool
todosFib xs = paratodo' xs esFib

duplicador :: [Int] -> [Int]
duplicador [] = []
duplicador (x:xs) = x*2 : duplicador xs

duplicador02 :: [Int] -> [Int]
duplicador02 xs = map (*2) xs

--Punto 9

sonPrimos :: [Int] -> [Int]
sonPrimos [] = []
sonPrimos (x:xs) | esPrimo x == True = x : sonPrimos xs
                 | otherwise = sonPrimos xs

sonPrimosF :: [Int] -> [Int]
sonPrimosF xs = filter esPrimo xs

primIgualesA :: (Eq a) => a -> [a] -> [a]
primIgualesA n [] = []
primIgualesA n (x:xs) | n==x = x : primIgualesA n xs
                      | otherwise = []

primIgualesA02 :: (Eq a) => a -> [a] -> [a]
primIgualesA02 n xs = takeWhile (==n) xs

primIguales :: (Eq a) => [a] -> [a]
primIguales [] = []
primIguales (x:xs) | x == head xs = x : primIguales xs
                   | otherwise = []

primIguales02 :: (Eq a) => [a] -> [a]
primIguales02 (x:xs) = primIgualesA x xs
