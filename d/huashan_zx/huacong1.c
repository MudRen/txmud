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
	"westup": __DIR__"yujiantai",
	"east": __DIR__"shidao3",
	//"south":__DIR__"ting2",

]));
     //  set("objects", ([
     //  __DIR__"obj/tao" : 6,
     //  ]) );
       setup();

      replace_program(ROOM);
}
