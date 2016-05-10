create table if not exists chardesc
(
	charid bigint(20) not null,#角色ID
	userid bigint(10) not null,#账号ID
	account varchar(64) not null,#账号字符串
	charname varchar(48) not null,#角色名称
	serverid int(5) not null,#角色所属服务器ID
	chargender tinyint not null default 0,#角色性别
	charlevel int not null default 0,#角色等级
	charexp bigint(10) not null default 0,#角色经验值
	gold int(10) not null default 0,#角色金币数量
	gamegold int(10) not null default 0,#角色元宝数量
	guildid bigint(20) not null default 0,#角色所属帮会ID
	charstate int not null default 0,#角色状态（0x4000置位表示被用户删除，08000置位表示被管理员禁用）
	createtime datetime not null,#角色创建时间
	updatetime datetime default null,#角色最后更新时间
	loginip bigint not null default 0,#角色最后一次登录ip

	primary key (charid),
	unique key (charname),
	index (account),
	index (createtime),
	index (updatetime)
);

create table if not exists guilddesc
(
	guildid bigint(20) not null,#帮会ID
	guildname varchar(48) not null,#帮会名称
	creatorid bigint(20) not null,#创建者角色ID
	masterid bigint(20) not null,#现任帮主角色ID
	guildlevel int not null default 1,#帮会等级
	guildfuns int not null default 0,#帮会资金
	createtime datetime not null,#帮会创建时间
	membercount int not null default 0,#帮会成员数量

	primary key (guildid),
	unique key (guildname)
);

