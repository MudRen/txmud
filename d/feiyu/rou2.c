#include <ansi.h>;

inherit ROOM;

void create()
{
        set("short", "博阅轩");
        set("long", @LONG
信步走来，一座玲珑小楼乍入眼帘，白玉护栏上精雕细凿着
百鸟朝凤图。一张古朴的琴案摆在正中，案上的白玉鼎正散发着
淡淡的桂花清香，诗情画意尽在其中。
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "enter" : "",
]));
        set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"rou3",
  "south" : __DIR__"rou1",
]));

	set(SAFE_ENV,1);
        setup();
}
