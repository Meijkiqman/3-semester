-- CONN AAAAAA

set transaction isolation level read committed;

start transaction;

select * from ansatt where ansnr=1;
update ansatt set Kjønn = "f" where ansnr=1;

delete from ansatt
where ansnr=1;

rollback;
commit;