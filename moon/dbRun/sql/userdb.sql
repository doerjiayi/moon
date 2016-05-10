create table if not exists users
(
	userid bigint(10) not null auto_increment,#账号ID
	account varchar(64) not null,#账号字符串
	passwd varchar(48) not null,#用户密码
	spid varchar(16) not null,#运营商ID
	spuserid bigint(10) not null default 0,#运营商账号UD
	createtime datetime not null,#账号创建时间
	offlinetime datetime not null,#账号离线时间

	primary key (userid),
	unique key (account),
	index (createtime),
	index (offlinetime)
);

drop procedure if exists proc_validateuserlogin;

delimiter $$

create procedure proc_validateuserlogin(in sAccount varchar(32), in sPswd varchar(48))
begin
	declare nUserId bigint default null;
	declare sUserPswd varchar(48) default null;
	select userid, passwd into nUserId, sUserPswd from users where account = sAccount;
	if nUserId is null then
		select 1, 0;#user not exists
	else
		if sUserPswd != sPswd then
			select 2, 0;#password error
		else
			select 0, nUserId;
		end if;
	end if;
end $$

delimiter ;
