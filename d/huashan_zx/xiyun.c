// Room: huashan xiyun.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�����");
	set("long",@LONG
����һ����辫�µķ��䡣��ǽ����һ����̴ľ����ױ̨��
�������λ�֬�۵��������Ů�ӵķ��䡣
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	//"up":__DIR__"ming3f",
	//"down":__DIR__"doorgd",
	//"west" : __DIR__"ming2fw1",
	"east":__DIR__"houdian",
]));
	set("objects", ([
            __DIR__"master/master-zq":1 ]));

    	setup();
	replace_program(ROOM);
}