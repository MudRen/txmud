// kongdi.c
// by dicky

#include <ansi.h>
inherit ROOM;
#include <room.h>
string look_shi();

void create ()
{
  set ("short", "空地");
  set ("long",@LONG
这里是山峰上的一片空地，这里风光秀丽，视野开阔。山峰上远
望四周，把侯集镇景色看的清清楚楚。远处大海如明镜般平整。偶尔
有踏雪山庄的弟子在这里练功习武，相互切磋武艺。空地的北边就是
踏雪山庄。
LONG);

	set("outdoors", "taxue");

	set("exits", ([ /* sizeof() == 3 */
		"north": __DIR__"menfang",
		"south": __DIR__"yashang",
	]));


	setup();
	replace_program(ROOM);
}
