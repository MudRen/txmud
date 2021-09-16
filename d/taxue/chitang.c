// chitang.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","池塘");
	set("long", @LONG
一池池水映入你的眼帘，小蓬莱翼然水中，曲折的石桥上架着紫藤花棚。
小池的两边，松树丛生。秋日，置身于小池石桥之上，阵阵桂香，沁人心脾。
轩下，水涧两岸叠石重重，你不禁为此景而赞叹不已。
LONG	);
        set("exits", ([ 
	"west" : __DIR__"houyuan",
	"north" : __DIR__"undertree",
	]));

	set("outdoors", "taxue" );
	set("no_clean_up", 0);

	setup();
        replace_program(ROOM);
}