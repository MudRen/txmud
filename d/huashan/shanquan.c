// Room: /d/huashan/shanquan.c

inherit ROOM;

void create()
{
	set("short", "山泉");
	set("long", @LONG
林边的青石形成一个洼口，山上流下的泉水在这里汇集成一
潭又向下流去。溪水清凉透底，如果你带着水壶，最好在这里打
(fill)一些。再向东北去，就要到华山的东峰了。南边是华山派
的酿酒房。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"quanshui",
  "eastup" : __DIR__"dongfeng",
  "southwest":__DIR__"jiufang",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
