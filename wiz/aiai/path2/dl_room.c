// Room: /d/path2/dilao/dl_room.c

inherit ROOM;

void create()
{
        set("short", "地牢");
        set("long", @LONG
这里是一间阴暗潮湿的地牢，四周的石头墙上还钉着几条铁
锁链，铁门上只有一个拳头大小的透气孔。
LONG
        );

        set("no_clean_up", 1);
        //setup();
}
