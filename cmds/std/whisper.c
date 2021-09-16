// whisper.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dest, msg, deny_id;
	object ob;

	if(me->query("channel/chat_block")
	&& (time()-me->query("channel/chat_block"))<0 )
		return notify_fail("你的交谈频道被暂时关闭了。\n");

	if( !arg || sscanf(arg, "%s %s", dest, msg)!=2 )
		return notify_fail("你要对谁耳语些什麽？\n");

	ob = present(dest, environment(me));
	if( !ob || !ob->is_character() )
		return notify_fail("你要对谁耳语？\n");

	deny_id = (string)ob->query("env/no_tell");
	if( userp(me) && !wizardp(me) && (deny_id == "all" || deny_id == (string)me->query("id")) )
		return notify_fail(wizardp(ob)?"对方处于封闭工作状态，有事请用 chat 与他联系。\n":
			"对方的 TELL 频道已关闭。\n");

	write( GRN "你在" + ob->name() + "的耳边悄声说道：" + msg + "\n" NOR);
	tell_room( environment(me), me->name() + "在" + ob->name()
		+ "耳边小声地说了些话。\n", ({ me, ob }) );
	if( !userp(ob) ) ob->relay_whisper(me, msg);
	else
		tell_object( ob, GRN + me->name() + "在你的耳边悄声说道：" + msg + "\n" NOR);
	return 1;
}

int help(object me)
{
	write( @TEXT
指令格式：whisper <某人> <讯息>

这个指令可以用来和同一房间中的人耳语，包括 NPC 在内。
TEXT
	);
	return 1;
}
