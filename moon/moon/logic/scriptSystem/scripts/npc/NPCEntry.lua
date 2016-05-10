npcTable = {}

--点击NPC执行的入口函数，
--实现NPC主函数调用分派
function clickNPC(npcId, player)
	local npc = npcTable[npcId]
	if npc ~= nil then
		return npc.main(player)
	else
		return "missing npc script table"
	end
end

--与NPC对话选择的功能函数入口
function talkNPC(npcId, player, funcName, ...)
	local mDotStart,mDotEnd = string.find(funcName, "QC")
	if mDotStart then
		local mdName = string.sub(funcName, mDotStart, mDotEnd)
		local md = _G[mdName]
		if md then
			funcName = string.sub(funcName, mDotEnd + 2)
			local func = md[funcName]
			if func then
				return func(player, unpack(arg))
			else
				return "missing function " .. funcName .. " at module " .. mdName
			end
		else
			return "missing module " .. mdName
		end
	else
		local npc = npcTable[npcId]

		if npc ~= nil then
			local func = npc[funcName]
			if func ~= nil then
				return func(player, unpack(arg))
			else
				return "missing npc function "..funcName
			end
		else
			return "missing npc script table"
		end
	end
end

function testSceneManager(player)
	print("testSceneManager")
	local duplicateId = 1
	local duplicate = g_DuplicateManager:createDuplicate(duplicateId)
	print(duplicate.m_Guid)
	print(duplicate.m_duplicateId)
	print(duplicate.m_duplicateName)
	print("m_playerNum")
	print(duplicate.m_playerNum)
	duplicate:addPlayerToFirstScene(player)
	print("m_playerNum")
	print(duplicate.m_playerNum)
	duplicate:delPlayer(player)
	print("m_playerNum")
	print(duplicate.m_playerNum)
end


require "./scripts/npc/QC"



