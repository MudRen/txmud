// Room: /d/path2/dilao/enter.c

inherit ROOM;

void create()
{
        set("short", "地牢入口");
        set("long", @LONG
这里是阴森森的地牢，眼前是一扇敞开的大铁门，中间一个
石台上插着一只点燃的火把。
LONG
        );

        set("no_clean_up", 1);
        //setup();
}
