// jianjin.c
// 监狱命令。

#include <ansi.h>
inherit F_CLEAN_UP;
private string prison = "/d/wiz/prison",start = "/d/changan/jiulou";

nomask int main(object me, string arg)
{
	object ob;
	int flag,free;

	if(!me
	|| (me != this_player(1))
	|| (wiz_level(me) < wiz_level("(wizard)")) )
		return notify_fail("只有管理员才能执行对玩家的监禁。\n");

	if(!arg || arg == "")
		return notify_fail("你要监禁谁？\n");

	if(sscanf(arg,"-f %s",arg))
		free = 1;

	if( wiz_level(arg) > wiz_level("(player)") )
		return notify_fail("你要监禁谁？\n");

	seteuid(getuid());

	if(!objectp(ob = find_player(arg)))
	{
		ob = new(USER_OB);
		seteuid(arg);

		if(!export_uid(ob))
		{
			seteuid(getuid());
			destruct(ob);
			return notify_fail("设置 euid 失败。\n");
		}
	
		if(!ob->restore() )
		{
			seteuid(getuid());
			destruct(ob);
			return notify_fail("没有"+arg+"这个玩家。\n");
		}
		flag = 1;
	}

	if(free)
	{
		if(ob->query("startroom") != prison)
			write(arg+"并不在监狱中。\n");
		else
		{
			if(!flag)
			{
				if(environment(ob))
					message_vision("\n天空中伸出一只大手把$N抓走了。\n",ob);
				tell_object(ob,sprintf("%s 将你从监狱中释放出来。\n",geteuid(me)));
				ob->move(start);
				if(environment(ob))
					message_vision("\n$N被人从外面扔了进来。\n",ob);
       			 message("channel:chat",
                        HIR"【系统通告】：使用者"+ arg +"在监狱表现良好，提前释放！\n"NOR,users());
			}
			ob->set("startroom",start);
			ob->save();
		}
		log_file("prison",sprintf("%s 将玩家 %s 从监狱中释放。%s\n",geteuid(me),arg,ctime(time())));
	}

	else
	{
		if(ob->query("startroom") == prison)
			write(arg+"已经在监狱中。\n");
		else
		{
			if(!flag)
			{
				if(environment(ob))
					message_vision("\n天空中伸出一只大手把$N抓走了。\n",ob);
				tell_object(ob,sprintf("%s 将你抓进监狱。\n",geteuid(me)));
				ob->move(prison);
				if(environment(ob))
					message_vision("\n$N被人从外面扔了进来。\n",ob);
			}
			ob->set("startroom",prison);
			ob->save();
			log_file("prison",sprintf("%s 将玩家 %s 监禁。%s\n",geteuid(me),arg,ctime(time())));
        message("channel:chat",
                        HIR"【系统通告】：使用者"+ arg +"违反游戏规则，被暂时监禁，并记录在案!\n"NOR,users());
		}
	}

	seteuid(getuid());
	if(flag)
		destruct(ob);


	write("ok。\n");
	return 1;
}
