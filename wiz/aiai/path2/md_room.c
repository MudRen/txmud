// Room: /d/path2/dilao/md_room.c

inherit ROOM;

void create()
{
        set("short", "秘道");
        set("long", @LONG
这里是一间阴暗潮湿的秘道，两侧的墙上有火把，
但是好像要熄灭了似的。
LONG
        );

        set("no_clean_up", 1);
        //setup();
}
