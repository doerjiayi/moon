module(..., package.seeall)

function main(player)
	return QC.formatQuestState(player)
end

function talk()
	return "talk2"
end


print("npc2.lua loaded")
