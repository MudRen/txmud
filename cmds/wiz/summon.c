// summon.c.
// Modified by Find.

#include <ansi.h>

inherit F_CLEAN_UP;

varargs private void do_summon(object me,object ob,string str);

int main(object me, string str)
{
	object ob;

	if (!str)
		return notify_fail("<Syntax>: Summon <player id>\n");

	ob = LOGIN_D->find_body(str);
	if(!ob)
		return notify_fail(sprintf("目前游戏中没有 %s 这个人存在。\n",str));

#ifdef WIZARD_FLAG
	if(environment(me)->query_wiz_flag()
	&& !wizardp(ob))
		return notify_fail("你不能将玩家抓出玩家区域。\n");
#endif

	if(!wizardp(ob))
	{
		write(HIR"\n请注意：改变玩家的当前位置是违反巫师守则的行为！！
你的这个行为会被记录在案，请说明你的理由：\n"NOR);
		me->edit( (: do_summon , me, ob :) );
		return 1;
	}

	else
		do_summon(me,ob);

	return 1;
}

varargs private void do_summon(object me,object ob,string str)
{
	object obj;

        if( (ob != me) && !wizardp(ob) )
                sys_log("summon",sprintf("(%s) summon (%s) from (%s) to (%s).\n%s",
                        geteuid(me),geteuid(ob),(environment(ob))?
			file_name(environment(ob)):"no environment",
                        file_name(environment(me)),"\t"+str ));

	if(file_name(environment(me)) == PRISON_OB
	&& !wizardp(ob)
	&& file_name(environment(ob)) != PRISON_OB)
		log_file("prison",sprintf("%s 将 %s(%s) 抓进监狱. %s\n",
			geteuid(me),ob->name(),geteuid(ob),ctime(time())));

	else if(file_name(environment(ob)) == PRISON_OB
	&& !wizardp(ob)
	&& file_name(environment(me)) != PRISON_OB)
		log_file("prison",sprintf("%s 将 %s(%s) 从监狱中释放. %s\n",
			geteuid(me),ob->name(),geteuid(ob),ctime(time())));

	if( obj=ob->query_temp("on_rided") )
	{
	tell_room(environment(ob),"天空中伸出一只大手把"+
	(string)ob->query("name")+"和他骑的"+obj->name()+"一起抓了起来, 然後不见了.\n", ob);
	tell_object(ob,"一只手把你抓了起来, 你眼前一阵黑....\n");
	environment(ob)->refresh_guarding(ob); // by Find.
	ob->move(environment(me));
	obj->move(environment(me));
	tell_object(me, "你把"+(string)ob->query("name")+"和他骑的"+obj->name()+"一起抓到你的面前.\n");
	tell_object(ob,".... 醒来时发现是"+(string)me->query("name")+
	"把你弄过来的.\n");
	tell_room(environment(ob),(string)ob->query("name")+"骑着"+obj->name()+"突然出现"+
	"在你眼前\n",({me,ob}));
	}

	else {
	tell_room(environment(ob),"天空中伸出一只大手把"+
	(string)ob->query("name")+"抓了起来, 然後不见了.\n", ob);
	tell_object(ob,"一只手把你抓了起来, 你眼前一阵黑....\n");
	environment(ob)->refresh_guarding(ob); // by Find.
	ob->move(environment(me));
        tell_object(me, "你把"+(string)ob->query("name")+"抓到你的面前.\n");
	tell_object(ob,".... 醒来时发现是"+(string)me->query("name")+
	"把你弄过来的.\n");
	tell_room(environment(ob),(string)ob->query("name")+"突然出现"+
	"在你眼前\n",({me,ob}));
	}
}

int help(object me)
{
write(@HELP
指令格式 : summon <某人>

此指令可让你将某人抓到你面前。
HELP
    );
    return 1;
}