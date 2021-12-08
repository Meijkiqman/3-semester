-- conn BBBBBB
set transaction isolation level READ committed;
START TRANSACTION;

select* from ansatt where ansnr=1;
update ansatt set kjønn="m" where ansnr=1;

delete from ansatt
where ansnr=1;

rollback;
commit;