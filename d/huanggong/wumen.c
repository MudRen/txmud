// Room: /d/huanggong/wumen.c

inherit ROOM;

void create()
{
        set("short", "午门");
        set("long", @LONG
这里你已经进入了皇宫．城门坐落在钟楼之下，每当皇帝举
行大典，这里都要，钟鼓齐鸣，一片喜气洋洋的气氛．巨大的铜
钟高高悬挂在城门之上，充分显示了帝王的气派．在往北就是金
銮殿了。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"daolu1",
  "north" : __DIR__"taihm",
]));
        set("no_clean_up", 0);
	set("outdoors", "huanggong");
       
        setup();
        replace_program(ROOM);
}
