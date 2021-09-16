// /cmds/usr/xunfu.c
// by Find.

#include <ansi.h>

inherit F_CLEAN_UP;

string *xunmsg = ({
"啊，就你一个在野外生活多苦呀，跟我去过好日子吧。",
"啊，你在这连个伴都没有，多没意思呀。",
"啊，你在这整天吃不饱，和我回去我包你一天三顿加夜宵呀。",
"啊，你在外面冬天还要受冻，和我回去我一定给你盖个大暖棚。",
"啊，跟我回去我一定给你找个伴儿好好繁殖后代。",
"啊，和我回去我一定天天用最好的草料喂你，还要拌鸡蛋！",
"啊，跟我回去我绝对不会让你拉车干活的！",
});

int main(object me,string arg)
{
	int skill;
	object ob;

	if( (skill = me->query_skill("riding",1)) < 20 )
		return notify_fail("你的骑术不够，还无法驯化野兽。\n");

	if( !arg || !objectp(ob = present(arg,environment(me))) )
		return notify_fail("你要驯化什么？\n");

	if( !ob->is_character() || userp(ob) )
		return notify_fail("你要驯化什么？\n");

	if( !ob->is_wild() )
		return notify_fail("那不是野兽。\n");

	tell_object(me,sprintf("你对着%s说道：%s%s\n",ob->name(),ob->name(),xunmsg[random(sizeof(xunmsg))]));
	tell_room(environment(me),sprintf("%s面对着%s%s嘴里絮絮叨叨的不知道在说些什么。\n",
		me->name(),ob->name(),NOR ),({me}));

	if(!living(ob))
		return notify_fail("它现在显然什么也听不见。\n");

	me->start_busy(2);
	ob->been_xunhua(me,skill);
	return 1;
}


int help(object me)
{
        write(@HELP
指令格式 : xunfu <id>

此指令可以让你驯服一些野生的坐骑，如：野马、野驴等。

当然你要有一定的骑术，还要有一些耐心。
要小心由于它们都没有驯化，烦了有可能会和你拼命的。

HELP
    );
    return 1;
}
