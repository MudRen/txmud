// Room: huashan quqiao.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
һ��ľ�Ƶ���������һ�ر�ˮ֮�ϣ���������һ�������ʯ
ͤ�����ﲻʱ�����һ������������һȦ���������µ�����ȥ��
LONG
);
	set("exits", ([ /* sizeof() == 1 */
	"west": __DIR__"feihua1",
	"east": __DIR__"feihua2",
	"south":__DIR__"ting2",

]));
     //  set("objects", ([
     //  __DIR__"obj/tao" : 6,
     //  ]) );
       setup();

      replace_program(ROOM);
}
