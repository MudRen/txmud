// /d/hangzhou/rl3.c

inherit ROOM;

void create()
{
        set("short", "苏来客栈三楼");
        set("long", @LONG
三楼是客栈的高级客房，过道上都铺着红色的毡子，楼梯旁
还站着小二，随时等候客人的差唤，服务如此细心，费用想必很
是可观，可仍有一些富商巨贾长期在这里居住。
LONG
        );
        set("exits", ([ 
            "down"  : __DIR__"rl2",
]));

	set("sleep_room", 1);
	set(SAFE_ENV,1);
	set("hotel",1);
        setup();
        replace_program(ROOM);
}

