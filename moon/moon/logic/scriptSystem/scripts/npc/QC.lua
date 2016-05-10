module("QC", package.seeall)

--遍历所有任务
function formatQuestState(player)	
	local npcid = player.m_NpcTalk.m_nTalkNpcID;
	npcid = tonumber(npcid)
	local idxRand = math.random(3)
	local defaultRet = "\n<C(FFEDCB5D)"..NpcDefaultTalk[npcid].DefaultTalk[idxRand]..">"
	local strRet = defaultRet
	
	if type(NPCQuest[npcid]) ~= "table" then 
		return strRet
	end
	
	if type(NPCQuest[npcid].accepts) == "table" then 
		local accept = NPCQuest[npcid].accepts
		for k,v in pairs(accept) do
			--调用C++接口查看是否可接
			local quest = QuestData[v]
			local boolean bCanAccept = player.m_Quest:checkCanAccept(v)
			if bCanAccept then
				strRet = strRet .. "\n<@(QC.acceptQuestStep,"
						.. npcid .. ","	.. v .. ","	.. "1)"	.. quest.name
						.. ">"
			end
		end
	end 
	
	if type(NPCQuest[npcid].completes) == "table" then
		local complete = NPCQuest[npcid].completes
		for k,v in pairs(complete) do
			--查看是否可交任务
			local quest = QuestData[v]
			local boolean bCanSubmit = player.m_Quest:checkCanSubmit(v)
			if bCanSubmit then 
				strRet = strRet .. "\n<@(QC.completeQuestStep,"
						.. npcid .. ","	.. v .. ","	.. "1)"	.. quest.name
						.. ">"
			end
		end
	end
	
	return strRet
end

--获取接任务的对话
function acceptQuestStep(player, npcId, questId, talkIdx)
	npcId = tonumber(npcId)
	questId = tonumber(questId)
	talkIdx = tonumber(talkIdx)
	
	local npc = NPCQuest[npcId]
	if type(npc) ~= "table" then
		return "npc is not a table,npcid:".. npcId .. ", questID:" .. questId ..", talkIdx:" .. talkIdx
	end
	
	local qData
	for k,v in pairs(npc.accepts) do
		if questId == v then
			qData = QuestData[v]
			break
		end
	end
	if type(qData) ~= "table" then
		return "questData is not a table,npcid:".. npcId .. ", questID:" .. questId ..", talkIdx:" .. talkIdx 
	end
	
	local curTalkList = qData.acceptTalk
	if type(curTalkList) ~= "table" then
		return "curTalkList is not a table,npcid:".. npcId .. ", questID:" .. questId ..", talkIdx:" .. talkIdx
	end
	
	local curReplyList = qData.acceptReply
	if type(curReplyList) ~= "table" then
		return "curReplyList is not a table,npcid:".. npcId .. ", questID:" .. questId ..", talkIdx:" .. talkIdx
	end
	
	local nTalkCount = #curTalkList
	local strTalk = curTalkList[talkIdx]
	local strReply = curReplyList[talkIdx]
	local strRet

	if talkIdx > nTalkCount then
		--防止网络延时,造成重复接,再做一次判断
		local boolean bCanAccept = player.m_Quest:checkCanAccept(questId)
		if bCanAccept then
			player.m_Quest:acceptQuest(questId)
			--strRet = "<@(close)关闭>"
			player.m_NpcTalk:sendCloseTalk()
			return strRet
		end
	else
		--格式化下一个聊天回复
		strRet = "<C(FFEDCB5D)" .. strTalk .. ">"
				.. "\n\n<@(QC.acceptQuestStep,"
				.. npcId .. ","
				.. questId .. ","
				.. talkIdx+1 .. ")"
				--.. player.m_sName ..":"
				.. "<C(FFFFBA00)" .. strReply	.. ">>"
	end

	return strRet
end

--获取交任务的对话
function completeQuestStep(player, npcId, questId, talkIdx)
	npcId = tonumber(npcId)
	questId = tonumber(questId)
	talkIdx = tonumber(talkIdx)
	
	local questNPC = NPCQuest[npcId]
	if type(questNPC) ~= "table" then
		return "questNPC is not a table,npcid:".. npcId .. ", questID:" .. questId ..", talkIdx:" .. talkIdx
	end

	local qData
	for k,v in pairs(questNPC.completes) do
		if questId == v then
			qData = QuestData[v]
			break
		end
	end
	
	if type(qData) ~= "table" then
		return "questData is not a table,npcid:".. npcId .. ", questID:" .. questId ..", talkIdx:" .. talkIdx
	end
	
	local curTalkList = qData.completeTalk
	if type(curTalkList) ~= "table" then
		return "curTalkList is not a table,npcid:".. npcId .. ", questID:" .. questId ..", talkIdx:" .. talkIdx
	end
	
	local curReplyList = qData.completeReply
	if type(curReplyList) ~= "table" then
		return "curReplyList is not a table,npcid:".. npcId .. ", questID:" .. questId ..", talkIdx:" .. talkIdx
	end

	local nTalkCount = #curTalkList
	local strTalk = curTalkList[talkIdx]
	local strReply = curReplyList[talkIdx]
	local strRet

	if talkIdx > nTalkCount then
		--防止网络延时,造成重复交,再做一次判断
		local boolean bCanSubmit = player.m_Quest:checkCanSubmit(questId)
		if bCanSubmit then
			player.m_Quest:submitQuest(questId)
			--strRet = "<@(close)关闭>"
			player.m_NpcTalk:sendCloseTalk()
			return strRet
		end
	else
		--格式化下一个聊天回复
		strRet = "<C(FFEDCB5D)" .. strTalk .. ">"
				.. "\n\n<@(QC.completeQuestStep,"
				.. npcId 	.. ","
				.. questId 	.. ","
				.. talkIdx+1 .. ")"
				--.. player.m_sName ..":"
				.. "<C(FFFFBA00)" .. strReply	.. ">>"
				
	end

	return strRet
end

