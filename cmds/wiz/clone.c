// clone.c
// Modified by Find.

inherit F_CLEAN_UP;

void decide_to_clone(string arg,object me,string file);
void do_clone(object me,string file);

int main(object me, string file)
{
	string err;

	seteuid( geteuid(me) );

        if (!file) file = me->query("cwf");
        if (!file) return notify_fail("你要复制什麽物件？\n");

        file = resolve_path(me->query("cwd"), file);
        if( sscanf(file, "%*s.c") != 1 ) file += ".c";
        me->set("cwf", file);

        if( file_size(file) < 0 )
                return notify_fail("没有这个档案(" + file + ")。\n");

        if(!find_object(file))
	{
                err = catch(call_other(file, "???"));
                if (err)
		{
                        write("载入失败：" + err + "\n");
                        return 1;
                }
        }

	if( file->is_ctl_ob() )
	{
		write("此物件在游戏中的副本数量是受限制的，对于此物件的复制，\n");
		write("会打破此物件在游戏中的平衡，你是否确定要复制？(y/n)");
		input_to( (: decide_to_clone :),me,file);
		return 1;
	}

	do_clone(me,file);
	return 1;
}

void do_clone(object me,string file)
{
	string err,msg;
	object obj;

        err = catch(obj = new(file));
	if(err)
	{
		write("复制失败：" + err + "\n");
		return;
	}

	if(!obj)
	{
		write("无法复制不能移动的物件(" + file + ")。\n");
		return;
	}

	sys_log( "clone", sprintf("(%s) cloned (%s) at %s\n",
		geteuid(me),file,ctime(time())));

#ifdef WIZARD_FLAG // by Find.
	obj->set_flag(1);
#endif

        if( !stringp(msg = me->query("env/msg_clone")) )
                msg = "只见$N伸手凌空一指，变出了$n。\n";

        if( !obj->is_character() && obj->move(me) )
	{
		write(obj->query("name") + "复制成功，放在你的物品栏。\n");
		message_vision(msg + "\n", me, obj);
                return;
        }

        if( obj->move(environment(me)) )
	{
		write(obj->query("name") + "复制成功，放在这个房间。\n");
		message_vision(msg + "\n", me, obj);
                return;
        }

        destruct(obj);
        write("无法复制不能移动的物件(" + file + ")。\n");
}

void decide_to_clone(string arg,object me,string file)
{
	if(arg != "Y" && arg != "y")
	{
		tell_object(me,"ok.\n");
		return;
	}

	write("\n使用完毕后请立刻将此副本删除掉。\n\n");
	do_clone(me,file);
}

int help(object me)
{
  write(@HELP
指令格式 : clone <档名>

利用此指令可复制任何能移动之物件(含怪物)。
HELP
    );
    return 1;
}