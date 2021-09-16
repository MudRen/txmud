// Room: /d/wiz/welcome5.c
// by Find.

#include <ansi.h>

#define STARTROOM	"/d/changan/jiulou"
#define BLOCK_CMDS	({"chat","rumor","menpai","tx","save"})

inherit ROOM;

string *enter_msg = ({
HIB+"\n��ֻ������ǰһ����ͻȻʲôҲ��������ʲôҲ������......\n\n"+NOR,
HIB+"ֻ�������岻�ϵ���׹......\n\n"+NOR,
HIB+"׹���޾��ĺڰ�......\n\n"+NOR,
HIB+"��Ȼ�·�һֻ����������һ��......\n\n"+NOR,
HIB+"ڤڤ����Լ�������󶣶�������ײ��......\n\n"+NOR,
HIB+"������һ���������Լ���������һ��������İ��������......\n\n"+NOR,
});

void entering_world(object me,int n);

void create()
{
	set("short", "é����");
	set("long", @LONG
����һ���ª������ݷ���������һ���񴲣����׵�ʯ����
����һλ��ü��Ŀ�����ߣ�ǰ����һ������һ�˸ߵĴ�ͭ��(mirror)��

�������������������� i �����������ʲô������
��ᷢ��������һ����Ԫ��ʦ�͸������(book)��

�� look book ������Կ����Ȿ����ʲô������

������� read book ������Ȿ��

���Ȿ���һ���Ժ���Ϳ����� enter ���������Ϸ�ˡ�

LONG
	);

	set("room_lable","welcome");
	set("no_fight",1);
	set("item_desc",([
	"��ͭ��": "һ������һ�˸ߵĴ�ͭ������ֵ��Ǿ�����һƬ���磬�ղ����κ���Ӱ��\n",
	"ͭ��": "һ������һ�˸ߵĴ�ͭ������ֵ��Ǿ�����һƬ���磬�ղ����κ���Ӱ��\n",
	"mirror": "һ������һ�˸ߵĴ�ͭ������ֵ��Ǿ�����һƬ���磬�ղ����κ���Ӱ��\n",
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
	message_vision("$N����ͭ���ķ�����ȥ��\n",me);
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
		tell_room(environment(me),sprintf(HIY"ͭ���зų�һ���������%s�����%s�����ˡ�\n"NOR,
			me->name(),me->name()),({ me }));
		me->move(STARTROOM);
		tell_room(environment(me),me->name()+"ͻȻ��������ǰ��\n",({me}));
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
