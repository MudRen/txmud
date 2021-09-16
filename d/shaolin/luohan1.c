// Room: /d/shaolin/luohan1.c

inherit ROOM;

void create()
{
	set("short", "罗汉阵入口");
	set("long", @LONG
这里是少林寺的罗汉阵入口，当遇到强敌入侵少林时，这里
的罗汉大阵便会开动，所谓罗汉阵是由一百单八的武艺精通的武
僧演动的，其中暗含佛法的玄机。一但开动，势不可档。从这里
向西是青古甬道。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yongdao2",
]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
	object who = this_player();

	if(who && !wizardp(who))
		call_out("come_in",1,who);
	return;
}

void come_in(object who)
{
	if(who && environment(who) == this_object())
	{
		tell_object(who,"\n你只听到一阵“叽噶”乱响，一股强劲的阴风把你从里面推了出来。\n\n");
		who->move(__DIR__"yongdao2");
	}
}
