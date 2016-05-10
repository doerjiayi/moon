create table if not exists users
(
	userid bigint(10) not null auto_increment,#�˺�ID
	account varchar(64) not null,#�˺��ַ���
	passwd varchar(48) not null,#�û�����
	spid varchar(16) not null,#��Ӫ��ID
	spuserid bigint(10) not null default 0,#��Ӫ���˺�UD
	createtime datetime not null,#�˺Ŵ���ʱ��
	offlinetime datetime not null,#�˺�����ʱ��

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
