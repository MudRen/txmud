// call.c
// Modified by Find.

inherit F_CLEAN_UP;

nomask int main(object me, string arg)
{
        string objname, func, param;
	object obj;
	mixed *args, result;
	int i;

	if(me != this_player(1))
		return 0;

	if( arg )
	{
		seteuid( geteuid(me) );
		if( sscanf(arg, "%s->%s(%s)", objname, func, param)!=3 )
			return notify_fail("指令格式：call <物件>-><函数>( <参数>, ... )\n");
	}
	else
		return notify_fail("指令格式：call <物件>-><函数>( <参数>, ... )\n");

	obj = present(objname, environment(me));
	if(!obj) obj = present(objname, me);
	if(!obj) obj = find_player(objname);
	if(!obj || !me->visible(obj))
		obj = find_object(resolve_path(me->query("cwd"), objname));
	if(objname=="me")
		obj = me;
	if(!obj)
		return notify_fail("找不到指定的物件。\n");

	if( userp(obj) )
	{
		if( obj != me )
			sys_log("call_player",
			sprintf("%s(%s) call %s(%s)->%s(%s) on %s\n",
				me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, param,
				ctime(time()) ) );
	}

	else if( !master()->valid_write( base_name(obj), me, "call" ) ) // by Find.
		return notify_fail("你没有直接呼叫这个物件的函数的权力。\n");

	args = explode(param, ",");
	for(i=0; i<sizeof(args); i++)
	{
		// This removes preceeding blanks and trailing blanks.
		parse_command(args[i], environment(me), "%s", args[i]);
		if( sscanf(args[i], "%d", args[i]) ) continue;
		if( sscanf(args[i], "\"%s\"", args[i]) ) continue;
		//args[i] = restore_variable(args[i]);
	}

	args = ({ func }) + args;

	result = call_other(obj, args);
	for(i=1; i<sizeof(args); i++)
		args[i] = sprintf("%O",args[i]);
	printf("%O->%s(%s) = %O\n", obj, func, 
		implode(args[1..sizeof(args)-1], ", "), result);
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : call <物件>-><函数>(<参数>, ...... )
 
呼叫<物件>里的<函数>并传入相关<参数>.
 
HELP
    );
    return 1;
}
