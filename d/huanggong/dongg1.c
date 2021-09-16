// Room: /d/huanggong/dongg1.c

inherit ROOM;

void create()
{
        set("short", "偏厅");
        set("long", @LONG
这是一间小小的偏厅，窗明几净，朴素典雅，一张古意盎然
的红木书桌，吸引了你的目光，上面摆著一座小小的香炉，几本
善本书整齐的堆放在桌上，可见主人相当的爱惜书本。四面墙壁，
玲珑剔透，富贵气派之中透著一股秀气。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"dongg6",
  "south" : __DIR__"dongg3",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

