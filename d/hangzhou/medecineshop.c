// /d/hangzhou/medecineshop.c

inherit ROOM;

void create()
{
        set("short", "玉华堂");
        set("long", @LONG
这里是杭州有名的玉华堂药铺，铺子里到处洋溢着一股中药
的清香。柜台上摆着一台铁秤，柜台后面坐着一位仙风道骨的老
人，那是本地的名医安神医。
LONG
        );
        set("exits", ([ 
            "north"  : __DIR__"changanw3",
]));
        setup();
        replace_program(ROOM);
}

