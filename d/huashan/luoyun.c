// Room: /d/huashan/zhanqiao.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "���ƹ�");
	set("long", @LONG
������ջ�ŵľ�ͷ����һ����ľ׮��ɵĹذ���ʮ������ɽ
�ɵĵ����ֳֳ��������ţ�����һ������������һ�����ߡ�
LONG
);

	set("exits", ([ /* sizeof() == 2 */
 
  "west" : __DIR__"zhanqiao",
  "southdown":__DIR__"kuang",
]));

	set("outdoors", "huashan");
	setup();
}

void init()
{
	object me = this_player();

	if( me
	&& interactive( me )
	&& !wizardp(me)
	&& (me->query("class") != "huashan") )
	{
		me->move(__DIR__"zhanqiao");
		tell_object(me, HIW"���󵨿�ͽ���Ҵ���ɽ���ء������������������������
  һ�����ڹ̶�ջ�ŵ������ϣ��������һ�ξ������˻�����\n\n"NOR);
	}
}
