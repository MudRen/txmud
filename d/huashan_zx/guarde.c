// Room: guarde.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�ŷ�");
	set("long",@LONG
�����ǻ�ɽ�ɵ��ŷ���ֻ��һ���ϵ���ס���������Ƣ��
�Ź֣����ֱ���û��ʲô��֪���������Ǹ���û������֪������
��������ֻ�����ϴ���������Ҳû��ʲô��������������ҵ�
������Ҫ��������������������
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"west" : __DIR__"doorgd",
]));
	set("indoors", "huashan_p");
	set("objects", ([__DIR__"npc/guard":1 ]));
	setup();
	replace_program(ROOM);
}