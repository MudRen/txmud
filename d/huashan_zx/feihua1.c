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
	"east": __DIR__"quqiao",
	"west": __DIR__"shidao3",

]));
     //  set("objects", ([
     //  __DIR__"obj/tao" : 6,
     //  ]) );
       setup();

      replace_program(ROOM);
}
