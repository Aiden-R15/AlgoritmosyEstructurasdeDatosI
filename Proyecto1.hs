--Archivo del Proyecto 1 para Algoritmos y Estructura de Datos 1

--Punto 1
{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{-# HLINT ignore "Redundant ==" #-}
{-# HLINT ignore "Use foldr" #-}
{-# HLINT ignore "Eta reduce" #-}
{-# LANGUAGE TemplateHaskellQuotes #-}
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

valorAbsoluto :: Int -> Int
valorAbsoluto x | x>=0 = x
                | x<0 = x*(-1)

--Punto 2
paratodo :: [Bool] -> Bool
paratodo [] = True
paratodo (x:xs) = x==True && paratodo xs

sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs

productoria :: [Int] -> Int
productoria [] = 1
productoria (x:xs) = x * productoria xs

factorial :: Int -> Int
factorial 0 = 1
factorial x = x * factorial (x-1)

promedio :: [Int] -> Int
promedio [] = 0
promedio (x:xs) = div (sumatoria (x:xs)) (length (x:xs))

--Punto 3
pertenece :: Int -> [Int] -> Bool
pertenece y [] = False
pertenece y (x:xs) = y==x || pertenece y xs

--Punto 4
paratodo' :: [a] -> (a -> Bool) -> Bool
paratodo' [] t = True
paratodo' (x:xs) t = t x && paratodo' xs t

existe' :: [a] -> (a -> Bool) -> Bool
existe' [] t = True
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

--Punto 5

paratodo02 :: [a] -> (a -> Bool) -> Bool
paratodo02 xs t = paratodo' xs t

--Punto 6

todosPares :: [Int] -> Bool
todosPares xs = paratodo' xs even

hayMultiplo :: Int -> [Int] -> Bool
hayMultiplo n (x:xs) = existe' xs 