// Room: /d/huashan/maonv1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"ëŮ����"NOR);
	set("long", @LONG
���ܻ��ȵĿ�������͸�����������������乵�ˮ��Ҳð��
��ɫ���������������ܴ�����ͻȻ���㿴��һ��Ѫ����۾�����
ӨӨ�ĺ�⡣����һֻСţ����С��Ѫ󸣬����һ�������ض���
�㡣
LONG
	);
	set("no_clean_up", 0);
	
	set("exits", ([ /* sizeof() == 1 */
  	//"out" : __DIR__"maonv2",
  	//"southdown":__DIR__"maov3.c",
]));
	set("objects", ([__DIR__"npc/xuechan":1 ]));
	setup();
	set("indoors", "huashan");
	replace_program(ROOM);
}
