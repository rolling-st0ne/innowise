SELECT Singer, SUM(Sale) as Sale
FROM Artists
GROUP BY Singer
HAVING SUM(Sale) > 2000000