// zoulang1.c 走廊1
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","走廊");
	set("long",@LONG
	 你好不容易走出花阵，前面豁然开朗，北面一坐大房巍然而立，那就
是踏雪山庄两大巨头之一的，踏雪山庄大庄主日常办公之处。只有踏雪山庄
的得意弟子才能自由出入此地。
LONG);

	set("outdoors","taxue");

	set("exits",([
		"west" : __DIR__"huazhen4",
		"north" : __DIR__"neitang",
	]));
	setup();
	replace_program(ROOM);
}
