module(..., package.seeall)

function main(player)
    local str1 = "<@(testGRT)TestGRT>"
	--str1 = str1 .. QC.formatQuestState(player)
	str1 = QC.formatQuestState(player)
	return str1
end

--[[
<@(����)��ʾ����>					��NPC�Ի�			<@(func1)����>
<C(��ɫ)�ı�>						�ı��ı���ɫ		<C(FFFF0000)����>
<F(BUSI)�ı�>						�ı��ı���ʽ		B=bold,U=underLine,S=strikeOut,I=italic
<E(�����С)�ı�>					�ı������С		<E(30)����>
<U(http://��ַ)��ʾ����>				������			<U(http://www.hugenstart.com)��ҳ>
<M(��ͼID:x:y:��Ϊ:������)��ʾ����>	Ѱ·���ض���
]]
function testGRT(player)
	return "<C(FF00FF00)may be green color text>\n"
	    .. "<F(BUS)text may have bold and strike and underline style>\n"
	    .. "<E(50)this got a large size text>\n"
	    .. "<C(FF800080)this <F(BUS)shows <E(60) nesting support!>>>\n"
	    .. "<@(main)back>"
end

print("npc1.lua loaded")
