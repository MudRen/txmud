// Room: /d/huashan/dongkou.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��վ�ڶ��ڣ��������ļ����ٲ������������΢�⣬�㿴��
ʪ¶¶�ĵ������˹������ʯ·ͨ�����档�㰴�಻ס�������
�飬���ȥ������������¡¡�����ٲ������������������ʲô
Ҳ�����������µĶ���ʯ��ˮ��ˢ�ķǳ��⻬��������Ҫ������
����ȥ����һ�����׵����顣
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
          "west" : __DIR__"shitai",
]));

	setup();
}

void init()
{
	add_action("do_enter", ({"jump", "tiao"}));
}
        
int do_enter(string arg)
{
	object me = this_player();

        if( arg != "out" )
		return 0;

	message_vision(HIY"$N���˼�����һ�������ٲ���Ծ�˳�ȥ��\n"NOR, this_player());

	if( me->move(__DIR__"sl_dong") )
		tell_room(environment(me), me->name() + "���ٲ��ߵ���ײײ�����˹�����\n",({me}));
        return 1;
}
