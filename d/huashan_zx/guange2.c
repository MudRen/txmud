// Room: guange.c by pian
#include <ansi.h>
inherit ROOM;
string look_sign(object me);
void create()
{
	set("short","����Сפ");
	set("long",@LONG
�������ţ����ۼ���Ȼ������һСƬ�յ��м���һ��СС��
��ͤ����ͤ���м����Ѿ���������ɫ���֣�������Сפ�������
����һ��ʫ(shi)��������ͤ���ﴫ������
LONG
);
	set("item_desc",([
	//"sign": (: look_sign :),
	"shi":HIG"
		Ũ��������    ����һͤ��\n
		��¶ճ����    ��ϼ������\n
		�������±�    �컯������\n
		������㾶    ���������\n"NOR,
]));
	set("exits", ([
	"east" : __DIR__"guange3",
	"west":__DIR__"guange1",
	"enter":__DIR__"ting",
]));
	set("outdoors", "huashan_p");

	
	setup();
	replace_program(ROOM);
}