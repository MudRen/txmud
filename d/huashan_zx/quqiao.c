// Room: huashan quqiao.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","曲桥");
	set("long",@LONG
一座木制的曲桥盘在一池碧水之上，向南连着一座不大的石
亭。池里不时有鱼儿一闪而过，惊起一圈涟漪，四下荡漾开去。
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
