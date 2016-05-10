#include "StdAfx.h"
#include "scriptValue.h"


bool ScriptValueList::push( int i )
{
	if (ScriptValueList::MaxValueCount <= count)
		return false;
	values[count++] = i;
	return true;
}

bool ScriptValueList::push( double d )
{
	if (ScriptValueList::MaxValueCount <= count)
		return false;
	values[count++] = d;
	return true;
}

bool ScriptValueList::push( bool b )
{
	if (ScriptValueList::MaxValueCount <= count)
		return false;
	values[count++] = b;
	return true;
}

bool ScriptValueList::push(const char* str )
{
	if (ScriptValueList::MaxValueCount <= count)
		return false;
	values[count++] = str;
	return true;
}

bool ScriptValueList::push( void* ptr )
{
	if (ScriptValueList::MaxValueCount <= count)
		return false;
	values[count++] = ptr;
	return true;
}

bool ScriptValueList::push( const ScriptValue &sv )
{
	if (ScriptValueList::MaxValueCount <= count)
		return false;
	values[count++] = sv;
	return true;
}

bool ScriptValueList::push( CBaseObject* ptr )
{
	if (ScriptValueList::MaxValueCount <= count)
		return false;
	values[count++] = ptr;
	return true;
}

bool ScriptValueList::push( CEntity* ptr )
{
	if (ScriptValueList::MaxValueCount <= count)
		return false;
	values[count++] = ptr;
	return true;
}

bool ScriptValueList::push( CDoer* ptr )
{
	if (ScriptValueList::MaxValueCount <= count)
		return false;
	values[count++] = ptr;
	return true;
}

bool ScriptValueList::push( CPlayer* ptr )
{
	if (ScriptValueList::MaxValueCount <= count)
		return false;
	values[count++] = ptr;
	return true;
}
