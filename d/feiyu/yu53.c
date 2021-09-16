// yu53.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "÷��԰");
	set("long", @LONG
����������÷������ɫ��ǳһ���һ����ٴ�˿������״��
�������ˡ�������һ��С�Ų�֪ͨ���������һ��÷��С
·ͨ��һ�������ĸ�¥��
LONG
);

	set("exits", ([ /* sizeof() == 3 */
	"south" : __DIR__"yu52",
	"northeast" : __DIR__"yu54",
]));

	set("item_desc",([
	"door" : "һ��СС��ľ�ţ��㲻������(knock)һ�£����������Ƿ���㿪����\n",
	"С��" : "һ��СС��ľ�ţ��㲻������(knock)һ�£����������Ƿ���㿪������\n",
]));

	set("objects", ([ /* sizeof() == 4 */
	__DIR__"npc/hufa4" : 1,
]));

	set("outdoors","feiyu");
	setup();
}

void init()
{
        add_action("do_knock","knock");
}

int do_knock(string arg)
{
	object me = this_player();

	if(arg != "door" && arg != "��" && arg != "С��")
		return notify_fail("��Ҫ��ʲô��\n");

	if(query("exits/enter"))
		return notify_fail("���Ѿ��ǿ��ŵ��ˡ�\n");

	if(me->query_temp("mark/huaner_knock"))
		return notify_fail("���Ѿ��ù��ˣ����������ѽ��\n");

	message_vision("$N��������������˼��¡�����\n",this_player());
	me->set_temp("mark/huaner_knock",1);
	call_out("knock",5,me);
	return 1;
}

void knock(object me)
{
	if(!objectp(me) || (environment(me) != this_object()))
		return;

	tell_object(me,"\n�����ﴫ��һ��Ų���������\n");
	call_out("opendoor",2,me);
}

void opendoor(object me)
{
	if(!objectp(me) || (environment(me) != this_object()))
		return;

	tell_object(me,"\n��������߰��Ŵ��ˡ�\n");
	set("exits/enter", __DIR__"fyyg");
	call_out("close_door",6,me);
}

void close_door(object me)
{
	if(query("exits/enter"))
	{
		tell_room(__FILE__,"С�Ź����ˡ�\n");
		delete("exits/enter");
	}

	if(objectp(me))
		me->delete_temp("mark/huaner_knock");
}

int valid_leave(object me, string dir)
{
	object ob;

	if( dir =="northeast"
	&& (me->query("combat_exp") < 600000)
	&& !me->query_temp("mark/louth_meilinge")
	&& !wizardp(me) )
        {
		if(objectp(ob = present("zhang fubing", this_object())) && living(ob))
			return notify_fail("��稱�����û�о������ܹܵ�����˭Ҳ���ܽ���÷�ָ�\n");
	}
	return ::valid_leave(me, dir);
}
