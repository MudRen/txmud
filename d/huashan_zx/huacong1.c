// Room: huashan huacong.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","花丛");
	set("long",@LONG
这里是一片花丛，姹紫嫣红点缀在青石道边。从这里向西是
华山派弟子练剑的“御剑台”；向东是院中间的青石道。
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
