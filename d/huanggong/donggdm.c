// Room: /d/huanggong/donggdm.c

inherit ROOM;

void create()
{
        set("short", "东宫大门");
        set("long", @LONG
绕过养心殿，一座雄伟华丽的大门呈现在你眼前－－东宫大
门。再往里走就是东宫了，门前的庭院种满了无数梅花，婉约娟
秀，别有一番滋味。清风徐来，梅花特有的清香弥漫在风中....
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"dongg2",
  "south" : __DIR__"yangxd",
  "northwest" : __DIR__"dongg3",
]));
        set("no_clean_up", 0);
        set("outdoors", "huanggong");
	setup();
        replace_program(ROOM);
}