// Room: /d/wiz/welcome5.c
// by Find.

#include <ansi.h>

#define STARTROOM	"/d/changan/jiulou"
#define BLOCK_CMDS	({"chat","rumor","menpai","tx","save"})

inherit ROOM;

string *enter_msg = ({
HIB+"\n你只觉得眼前一花，突然什么也听不见，什么也看不见......\n\n"+NOR,
HIB+"只觉得身体不断的下坠......\n\n"+NOR,
HIB+"坠向无尽的黑暗......\n\n"+NOR,
HIB+"忽然仿佛一只大手托了你一下......\n\n"+NOR,
HIB+"冥冥中隐约传来阵阵叮叮当当碰撞声......\n\n"+NOR,
HIB+"你睁眼一看，发现自己已置身于一个喧嚣而陌生的世界......\n\n"+NOR,
});

void entering_world(object me,int n);

void create()
{
	set("short", "茅草屋");
	set("long", @LONG
这是一间简陋而整洁草房，右首是一张竹床，左首的石桌旁
坐着一位慈眉善目的老者，前方是一面足有一人高的大铜镜(mirror)。

来到这里，你可以先试着用 i 命令看看身上有什么东西，
你会发现身上有一本大元仙师送给你的书(book)。

用 look book 命令可以看看这本书是什么东西？

你可以用 read book 命令读这本书

将这本书读一遍以后你就可以用 enter 命令进入游戏了。

LONG
	);

	set("room_lable","welcome");
	set("no_fight",1);
	set("item_desc",([
	"大铜镜": "一面足有一人高的大铜镜，奇怪的是镜子里一片混沌，照不出任何人影。\n",
	"铜镜": "一面足有一人高的大铜镜，奇怪的是镜子里一片混沌，照不出任何人影。\n",
	"mirror": "一面足有一人高的大铜镜，奇怪的是镜子里一片混沌，照不出任何人影。\n",
]));

	set("objects",([
		__DIR__"npc/xianshi" : 1,
]));
	setup();
}

void init()
{
	add_action("block_cmds","",1);
	add_action("do_enter","enter");
}

int block_cmds(string arg)
{
	if(!wizardp(this_player()) && member_array(query_verb(),BLOCK_CMDS) != -1)
		return 1;
	else
		return 0;
}

int do_enter(string arg)
{
	object me = this_player();

	if(!me->query_temp("end_quest"))
		return 0;
	me->delete_temp("end_quest");
	me->set_temp("entering_world",1);
	message_vision("$N向着铜镜的方向走去。\n",me);
	call_out("entering_world",1,me,0);
	return 1;
}

void entering_world(object me,int n)
{
	object paper;

	remove_call_out("entering_world");

	tell_object(me,enter_msg[n]);

	if(n == sizeof(enter_msg)-1)
	{
		paper = present("book",me);
		if(paper)
			destruct(paper);
		me->delete_temp("entering_world");
		tell_room(environment(me),sprintf(HIY"铜镜中放出一道金光罩向%s，随后%s不见了。\n"NOR,
			me->name(),me->name()),({ me }));
		me->move(STARTROOM);
		tell_room(environment(me),me->name()+"突然出现在眼前。\n",({me}));
		me->set("startroom",STARTROOM);
		if(me->query("new_begin"))
			me->delete("new_begin");
		me->set_temp("I_AM_NEWBIE",1);
		me->save();
		return;
	}

	else
	{
		call_out("entering_world",3,me,n+1);
		return;
	}
}
