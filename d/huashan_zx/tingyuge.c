// Room: huashan tingyuge.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�����");
	set("long",@LONG
����һ�����辫�µķ��䣬�������������Ϲ��ż����ֻ���
͸�����ӿ��Կ����ϱߵġ��ɻ��ء��������ǻ�ɽ���ŽӴ���Ҫ
���˵Ļ���ҡ�
LONG
);
	set("exits", ([ /* sizeof() == 1 */
	"west":__DIR__"zixiagong",
]));
	set("indoors", "huashan_p");
	
	setup();
	replace_program(ROOM);
}