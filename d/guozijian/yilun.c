// Room: /d/guozijian/yilun.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "彝伦堂");
	set("long", @LONG
这里是彝伦堂，是国子监中藏书的地方，这里藏书由于历史
悠久，所以所收藏的书籍也比较全。书架排列得非常整齐，并且
一尘不染。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"up" : __DIR__"yilunup",
		"south" : __DIR__"yongdao4",
]));

	setup();
	replace_program(ROOM);
}
