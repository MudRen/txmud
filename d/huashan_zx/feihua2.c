// Room: guangw.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�ɻ��ر�");
	set("long",@LONG
����һƬ���̵ĳ�ˮ���������Ÿߴ������������������ʱ
���ó���һƬ�ۺ졣���΢������ˮ�������仨�̣�������
��ͽ������ɻ��ء�������һ���������ڳ��ϡ�
LONG
);
	set("exits", ([ /* sizeof() == 1 */
	"west": __DIR__"quqiao",
	"east": __DIR__"guodaoe5",

]));
     //  set("objects", ([
     //  __DIR__"obj/tao" : 6,
     //  ]) );
       setup();

      replace_program(ROOM);
}
