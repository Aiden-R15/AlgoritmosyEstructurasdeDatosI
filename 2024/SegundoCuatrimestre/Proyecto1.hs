-- 1)

esCero :: Int -> Bool
esCero x | x==0 = True
         | otherwise = False

esPositivo :: Int -> Bool
esPositivo x = x>=0

esVocal :: Char -> Bool
esVocal x = x=='a' || x=='e' || x=='i' || x=='o' || x=='u'

valorAbsoluto :: Int -> Int
valorAbsoluto x | x>=0 = x
                | otherwise = (-1)*x

--2)

paratodo :: [Bool] -> Bool
paratodo [] = True
paratodo (x:xs) = x && paratodo xs

sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs

productoria :: [Int] -> Int
productoria [] = 1 
productoria (x:xs) = x * productoria xs

factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n-1)

--3)

mayorA0 :: [Int] -> Bool
mayorA0 [] = True
mayorA0 (x:xs) = (x>0) && mayorA0 xs

existeN :: [Int] -> Int -> Bool
existeN [] n = False
existeN (x:xs) n = (x==n) || existeN xs n

todosIguales :: [Int] -> Bool
todosIguales [] = True
todosIguales [x] = True 
todosIguales (x:xs) =  x==(head xs) && todosIguales xs

--4)