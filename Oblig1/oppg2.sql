	USE Oblig1;

Select Title,
 Year,
 Genre,
 Price
FROM Film
WHERE Year >= 1988
ORDER BY Price DESC;