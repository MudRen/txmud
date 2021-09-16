inherit ROOM;

void create()
{
        set("short", "树林");
        set("long", @LONG
你走进了树林的深处，脚下踩着厚厚的落叶，松松软软。这里
的光线非常阴暗，你几乎什么都看不清了。突然一只松鼠从你眼前的
树枝上猛地跳了过去，吓了你一跳。
LONG
        );
        set("outdoors", "gaibang");
        set("exits", ([
             "west" : __DIR__"tree2",
                "east" : __DIR__"tree3",
        ]));
        //set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
