create table if not exists chardesc
(
	charid bigint(20) not null,#��ɫID
	userid bigint(10) not null,#�˺�ID
	account varchar(64) not null,#�˺��ַ���
	charname varchar(48) not null,#��ɫ����
	serverid int(5) not null,#��ɫ����������ID
	chargender tinyint not null default 0,#��ɫ�Ա�
	charlevel int not null default 0,#��ɫ�ȼ�
	charexp bigint(10) not null default 0,#��ɫ����ֵ
	gold int(10) not null default 0,#��ɫ�������
	gamegold int(10) not null default 0,#��ɫԪ������
	guildid bigint(20) not null default 0,#��ɫ�������ID
	charstate int not null default 0,#��ɫ״̬��0x4000��λ��ʾ���û�ɾ����08000��λ��ʾ������Ա���ã�
	createtime datetime not null,#��ɫ����ʱ��
	updatetime datetime default null,#��ɫ������ʱ��
	loginip bigint not null default 0,#��ɫ���һ�ε�¼ip

	primary key (charid),
	unique key (charname),
	index (account),
	index (createtime),
	index (updatetime)
);

create table if not exists guilddesc
(
	guildid bigint(20) not null,#���ID
	guildname varchar(48) not null,#�������
	creatorid bigint(20) not null,#�����߽�ɫID
	masterid bigint(20) not null,#���ΰ�����ɫID
	guildlevel int not null default 1,#���ȼ�
	guildfuns int not null default 0,#����ʽ�
	createtime datetime not null,#��ᴴ��ʱ��
	membercount int not null default 0,#����Ա����

	primary key (guildid),
	unique key (guildname)
);

