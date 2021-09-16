// Room: /d/changan/chufang.c

inherit ROOM;

void create()
{
	set("short", "后厨");
	set("long", @LONG
这里是香格里拉的后厨，一位老厨师正在对掌勺的实习厨师
指指点点，旁边有一个大水缸，几个小工不断往里面续水，保证
大师傅们随时有水用。
LONG
	);
        set(SAFE_ENV,1);
	set("exits",([
    "north" : __DIR__"jiulou",
]));
        set("resource/water",1);
	setup();
	replace_program(ROOM);
}
