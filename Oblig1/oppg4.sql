USE Oblig1;

Select 
 Genre,
 count(Genre),
 Sum(Price),
 Age,
 Price
FROM Film
group by Genre;