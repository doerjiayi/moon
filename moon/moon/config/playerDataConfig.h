#pragma once

//人物等级配置
struct CFPlayerLevel
{
	long long expMax;//升级所需经验
	DoerAbilData jobAbils[3];//等级各职业基本属性
};
