// Room: guangw.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","飞花池边");
	set("long",@LONG
这是一片碧绿的池水，岸边种着高大的榕树。榕树开花的时
侯，落得池面一片粉红。轻风微拂，池水荡漾，落花烟，所以这
里就叫作“飞花池”。东边一座曲桥盘在池上。
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
