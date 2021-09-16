//forest0.c 走向东口的原始森林迷宫入口。
inherit ROOM;
void create()
{
        set("short","原始森林");
        set("long", @LONG
走在原始森林中，只见各种树木遮天蔽日。刚经过单调高原
景色的你开始还欣赏满目的绿色，渐渐的也厌烦起来，耳朵里也
充满了安静的声音，你甚至怀疑是不是只有自己一个人在，看着
千篇一律的树木，你只想赶快走出去。
LONG
        );
        set("exits", ([
        "east":__DIR__"lz_ekou",
        "westdown":__DIR__"forest1"
]));
        setup();
}
