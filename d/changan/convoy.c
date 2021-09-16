// convoy  镖局

#include <room.h>

inherit ROOM;
void create()
{
        set("short", "德威镖局");
        set("long", @LONG
这里是德威镖局的长安分号，三十四年前，“铁枪镇九州”
陈天寿陈老镖师头，在长安开了德威镖局。一杆铁枪威震黑白两
道，黑道人提及德威两个字，绝不敢造次。一进大厅一只巨大的
猛虎下山图，门口两个大花瓶，大厅东厕一个武器架，西厕是御
赐的金匾大字“德威并济”。由此向北是长安城的北大街。
LONG
        );
       set("exits", ([
                "north"           : __DIR__"nroad2",
]) );

	set("objects",([
	__DIR__"npc/tangzi_shou" : 2,
]));

        setup();
	replace_program(ROOM);
}
