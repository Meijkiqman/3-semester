delimiter //
CREATE TRIGGER FixPirce BEFORE INSERT ON Invoice FOR EACH ROW
BEGIN
 IF NEW.Cash < 0 THEN
     SET new.Cash = 0;
     END IF;
IF NEW.Cash > 1000 THEN
    SET new.Cash = 10000;
    End if;
     END;//
delimiter ;