// Room: huashan huacong.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
������һƬ���ԣ�����̺��׺����ʯ���ߡ�������������
��ɽ�ɵ��������ġ�����̨��������Ժ�м����ʯ����
LONG
);
	set("exits", ([ /* sizeof() == 1 */
	"eastup": __DIR__"yujiantai",
	"west": __DIR__"guodaow5",
	//"south":__DIR__"ting2",

]));
     //  set("objects", ([
     //  __DIR__"obj/tao" : 6,
     //  ]) );
       setup();

      replace_program(ROOM);
}
