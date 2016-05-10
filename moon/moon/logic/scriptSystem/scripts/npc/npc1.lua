module(..., package.seeall)

function main(player)
    local str1 = "<@(testGRT)TestGRT>"
	--str1 = str1 .. QC.formatQuestState(player)
	str1 = QC.formatQuestState(player)
	return str1
end

--[[
<@(函数)显示名称>					与NPC对话			<@(func1)进入>
<C(颜色)文本>						改变文本颜色		<C(FFFF0000)文字>
<F(BUSI)文本>						改变文本样式		B=bold,U=underLine,S=strikeOut,I=italic
<E(字体大小)文本>					改变字体大小		<E(30)文字>
<U(http://地址)显示名称>				超链接			<U(http://www.hugenstart.com)主页>
<M(地图ID:x:y:行为:对象名)显示名称>	寻路到特定点
]]
function testGRT(player)
	return "<C(FF00FF00)may be green color text>\n"
	    .. "<F(BUS)text may have bold and strike and underline style>\n"
	    .. "<E(50)this got a large size text>\n"
	    .. "<C(FF800080)this <F(BUS)shows <E(60) nesting support!>>>\n"
	    .. "<@(main)back>"
end

print("npc1.lua loaded")
